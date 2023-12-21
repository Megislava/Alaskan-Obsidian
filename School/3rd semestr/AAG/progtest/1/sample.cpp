#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include <cassert>
using namespace std;

using State = unsigned int;
using Symbol = char;

struct MISNFA {
    std::set<State> m_States;
    std::set<Symbol> m_Alphabet;
    std::map<std::pair<State, Symbol>, std::set<State>> m_Transitions;
    std::set<State> m_InitialStates;
    std::set<State> m_FinalStates;
};

struct DFA {
    std::set<State> m_States;
    std::set<Symbol> m_Alphabet;
    std::map<std::pair<State, Symbol>, State> m_Transitions;
    State m_InitialState;
    std::set<State> m_FinalStates;

    bool operator==(const DFA& dfa)
    {
        return std::tie(m_States, m_Alphabet, m_Transitions, m_InitialState, m_FinalStates) == std::tie(dfa.m_States, dfa.m_Alphabet, dfa.m_Transitions, dfa.m_InitialState, dfa.m_FinalStates);
    }
};

#endif

set<State> getTransitions(const MISNFA& nfa, State state, Symbol symbol) {
    if (nfa.m_Transitions.find(make_pair(state, symbol)) != nfa.m_Transitions.end()) {
        return nfa.m_Transitions.find(make_pair(state, symbol))->second;
    } else {
        return {};
    }
}

bool isDeterministic(const MISNFA& nfa) {
    for (const auto& transition : nfa.m_Transitions) {
        if (transition.second.size() > 1) {
            return false;
        }
    }
    return true;
}

void initializeDFA(DFA& dfa, MISNFA& nfa, map<set<State>, State>& stateMap, queue<set<State>>& toProcess, State& dfaStateCounter) {
    // Kopírování abecedy a stavů do DFA
    dfa.m_Alphabet = nfa.m_Alphabet;
    dfa.m_States = nfa.m_States;
    dfa.m_FinalStates = nfa.m_FinalStates;

    if (nfa.m_InitialStates.size() > 1) {
        // Vytvoření nového počátečního stavu pro NFA a DFA
        State newInitialState = *max_element(nfa.m_States.begin(), nfa.m_States.end()) + 1;
        nfa.m_States.insert(newInitialState);
        dfa.m_States.insert(newInitialState);

        // Kombinování přechodů ze všech původních počátečních stavů pro každý symbol
        for (const Symbol& symbol : nfa.m_Alphabet) {
            set<State> combinedTransitions;
            for (State initialState : nfa.m_InitialStates) {
                auto it = nfa.m_Transitions.find({initialState, symbol});
                if (it != nfa.m_Transitions.end()) {
                    combinedTransitions.insert(it->second.begin(), it->second.end());
                }
                auto it2 = nfa.m_FinalStates.find(initialState);
                if (it2 != nfa.m_FinalStates.end()) {
                    nfa.m_FinalStates.insert(newInitialState);
                    dfa.m_FinalStates.insert(newInitialState);
                }
            }
            if (!combinedTransitions.empty()) {
                nfa.m_Transitions[{newInitialState, symbol}] = combinedTransitions;
            }
        }

        // Nastavení nového počátečního stavu pro DFA a aktualizace počátečních stavů NFA
        dfa.m_InitialState = newInitialState;
        nfa.m_InitialStates = {newInitialState};

        // Aktualizace stateMap a toProcess pro nový počáteční stav
        stateMap[{newInitialState}] = newInitialState;
        toProcess.push({newInitialState});
        dfaStateCounter = newInitialState + 1; // Aktualizace čítače


    } else {
        // Použití existujícího počátečního stavu, pokud je jen jeden
        dfa.m_InitialState = *nfa.m_InitialStates.begin();

        // Aktualizace stateMap a toProcess pro existující počáteční stav
        stateMap[nfa.m_InitialStates] = *nfa.m_InitialStates.begin();
        toProcess.push(nfa.m_InitialStates);
    }
}


void copyTransitions(DFA& dfa, const MISNFA& nfa) {
    for (const auto& transition : nfa.m_Transitions) {
        if (!transition.second.empty()) {
            dfa.m_Transitions[make_pair(transition.first.first, transition.first.second)] = *transition.second.begin();
        }
    }
}

std::string createStateName(const std::set<State>& states) {
    std::stringstream ss;
    for (auto it = states.begin(); it != states.end(); ++it) {
        if (it != states.begin()) {
            ss << "_"; // Delimiter between state names
        }
        ss << *it; // Append the state identifier
    }
    return ss.str();
}

int performDeterminization(DFA& dfa, const MISNFA& nfa, map<set<State>, State>& stateMap, queue<set<State>>& toProcess, State& dfaStateCounter) {
    map<string, State> originalToNewStateMap;

    if (isDeterministic(nfa)) {
        std::cout << "NFA is already deterministic." << std::endl;
        copyTransitions(dfa, nfa);
        return -1;
    }

    // Resetting the final states for DFA
    dfa.m_FinalStates.clear();

    // Initialize the DFA states for the initial states
    string initialKey = createStateName(nfa.m_InitialStates);
    originalToNewStateMap[initialKey] = dfaStateCounter;
    stateMap[nfa.m_InitialStates] = dfaStateCounter++;
    toProcess.push(nfa.m_InitialStates);

    while (!toProcess.empty()) {
        set<State> current = toProcess.front();
        toProcess.pop();

        for (Symbol symbol : nfa.m_Alphabet) {
            set<State> nextStates;
            for (State s : current) {
                set<State> transitions = getTransitions(nfa, s, symbol);
                nextStates.insert(transitions.begin(), transitions.end());
            }

            if (nextStates.empty()) continue;

            string nextKey = createStateName(nextStates);
            State mappedState;

            // Check if this set of states already exists
            if (originalToNewStateMap.find(nextKey) == originalToNewStateMap.end()) {
                mappedState = dfaStateCounter;
                originalToNewStateMap[nextKey] = mappedState;
                stateMap[nextStates] = mappedState;
                dfa.m_States.insert(mappedState);
                toProcess.push(nextStates);

                // Mark as final state if it contains any of the original final states
                for (State s : nextStates) {
                    if (nfa.m_FinalStates.find(s) != nfa.m_FinalStates.end()) {
                        dfa.m_FinalStates.insert(mappedState);
                        break;
                    }
                }

                dfaStateCounter++;  // Increment only after all uses of the current counter value
            } else {
                mappedState = originalToNewStateMap[nextKey];
            }

            dfa.m_Transitions[make_pair(stateMap[current], symbol)] = mappedState;
        }
    }

    // Updating the initial state of the DFA
    auto initialStateIt = originalToNewStateMap.find(createStateName(nfa.m_InitialStates));
    if (initialStateIt != originalToNewStateMap.end()) {
        dfa.m_InitialState = initialStateIt->second;
    } else {
        dfa.m_InitialState = *nfa.m_InitialStates.begin();  // Default to first initial state of NFA
    }

    dfa.m_States.insert(dfa.m_InitialState);

    // Ensure initial state is also marked as final if it was final in the NFA
    if (!nfa.m_InitialStates.empty() && nfa.m_FinalStates.find(*nfa.m_InitialStates.begin()) != nfa.m_FinalStates.end()) {
        dfa.m_FinalStates.insert(dfa.m_InitialState);
    }

    // Logging state name mapping
    std::cout << "State Name Mapping:" << std::endl;
    for (const auto& pair : originalToNewStateMap) {
        std::cout << "Original: {" << pair.first << "} -> New: " << pair.second << std::endl;
    }

    return 1;  // Indicate determinization occurred
}



set<State> identifyReachableStates(const DFA& dfa) {
    set<State> reachableStates;
    queue<State> toProcessQueue;
    toProcessQueue.push(dfa.m_InitialState);
    reachableStates.insert(dfa.m_InitialState);

    while (!toProcessQueue.empty()) {
        State current = toProcessQueue.front();
        toProcessQueue.pop();

        for (const auto& transition : dfa.m_Transitions) {
            if (transition.first.first == current) {
                State nextState = transition.second;
                if (reachableStates.insert(nextState).second) {
                    toProcessQueue.push(nextState);
                }
            }
        }
    }

    return reachableStates;
}

set<State> identifyNecessaryStates(const DFA& dfa) {
    set<State> necessaryStates;
    queue<State> toCheckQueue;

    for (const State& finalState : dfa.m_FinalStates) {
        toCheckQueue.push(finalState);
        necessaryStates.insert(finalState);
    }

    while (!toCheckQueue.empty()) {
        State currentState = toCheckQueue.front();
        toCheckQueue.pop();

        for (const auto& transition : dfa.m_Transitions) {
            if (transition.second == currentState) {
                State prevState = transition.first.first;
                if (necessaryStates.insert(prevState).second) {
                    toCheckQueue.push(prevState);
                }
            }
        }
    }

    return necessaryStates;
}

void removeUnreachableOrUnnecessaryStates(DFA& dfa, const set<State>& reachableStates, const set<State>& necessaryStates) {
    // Determine states to be removed: those not in both reachable and necessary sets
    set<State> statesToRemove;
    for (const State& state : dfa.m_States) {
        if (reachableStates.find(state) == reachableStates.end() || necessaryStates.find(state) == necessaryStates.end()) {
            statesToRemove.insert(state);
        }
    }

    statesToRemove.erase(dfa.m_InitialState);

    // Remove these states from the DFA's states and final states
    for (const State& state : statesToRemove) {
        dfa.m_States.erase(state);
        dfa.m_FinalStates.erase(state);
    }

    // Remove transitions involving the removed states
    for (auto it = dfa.m_Transitions.begin(); it != dfa.m_Transitions.end();) {
        if (statesToRemove.find(it->first.first) != statesToRemove.end() || statesToRemove.find(it->second) != statesToRemove.end()) {
            it = dfa.m_Transitions.erase(it);
        } else {
            ++it;
        }
    }
}

void printFinalDFA(const DFA& dfa) {
    std::cout << "Final DFA:" << std::endl;

    std::cout << "Initial State: " << dfa.m_InitialState << std::endl;

    std::cout << "Final States: ";
    for (const State& finalState : dfa.m_FinalStates) {
        std::cout << finalState << " ";
    }
    std::cout << std::endl;

    std::cout << "States: ";
    for (const State& state : dfa.m_States) {
        std::cout << state << " ";
    }
    std::cout << std::endl;

    std::cout << "Transitions:" << std::endl;
    for (const auto& transition : dfa.m_Transitions) {
        std::cout << "From State " << transition.first.first << " on Symbol '" << transition.first.second << "' to State " << transition.second << std::endl;
    }
}


DFA determinize(const MISNFA& nfa) {
    DFA dfa;
    MISNFA nfaDupl = nfa;
    map<set<State>, State> stateMap;
    queue<set<State>> toProcess;
    State dfaStateCounter = 0;
    set<State> reachableStates, necessaryStates;

    // Nastavení abecedy a inicializace počátečního stavu (including removing E-transitions)
    initializeDFA(dfa, nfaDupl, stateMap, toProcess, dfaStateCounter);

    // Determinizace NKA
    if(performDeterminization(dfa, nfaDupl, stateMap, toProcess, dfaStateCounter) == -1) {
        // Identifikace dosažitelných stavů pouze kdyz neprobehla determinizace
        reachableStates = identifyReachableStates(dfa);
    } else {
        // all are reachable if determinization happen
        reachableStates = dfa.m_States;
    }

    cout << "STATES ARE?" << endl;
    printFinalDFA(dfa);

    // Identifikace potřebných stavů
    necessaryStates = identifyNecessaryStates(dfa);

    std::cout << "Reachable States: ";
    for (const State& state : reachableStates) {
        std::cout << state << " ";
    }
    std::cout << std::endl;

    std::cout << "Necessary States: ";
    for (const State& state : necessaryStates) {
        std::cout << state << " ";
    }
    std::cout << std::endl;

    removeUnreachableOrUnnecessaryStates(dfa, reachableStates, necessaryStates);

    // Výpis finálního DKA
    cout << "FINAL DFA: " << endl;
    printFinalDFA(dfa);

    return dfa;
}


#ifndef __PROGTEST__
MISNFA in0 = {
    {0, 1, 2},
    {'e', 'l'},
    {
        {{0, 'e'}, {1}},
        {{0, 'l'}, {1}},
        {{1, 'e'}, {2}},
        {{2, 'e'}, {0}},
        {{2, 'l'}, {2}},
    },
    {0},
    {1, 2},
};
DFA out0 = {
    {0, 1, 2},
    {'e', 'l'},
    {
        {{0, 'e'}, 1},
        {{0, 'l'}, 1},
        {{1, 'e'}, 2},
        {{2, 'e'}, 0},
        {{2, 'l'}, 2},
    },
    0,
    {1, 2},
};
MISNFA in1 = {
    {0, 1, 2, 3},
    {'g', 'l'},
    {
        {{0, 'g'}, {1}},
        {{0, 'l'}, {2}},
        {{1, 'g'}, {3}},
        {{1, 'l'}, {3}},
        {{2, 'g'}, {1}},
        {{2, 'l'}, {0}},
        {{3, 'l'}, {1}},
    },
    {0},
    {0, 2, 3},
};
DFA out1 = {
    {0, 1, 2, 3},
    {'g', 'l'},
    {
        {{0, 'g'}, 1},
        {{0, 'l'}, 2},
        {{1, 'g'}, 3},
        {{1, 'l'}, 3},
        {{2, 'g'}, 1},
        {{2, 'l'}, 0},
        {{3, 'l'}, 1},
    },
    0,
    {0, 2, 3},
};
MISNFA in2 = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {'l', 'm'},
    {
        {{0, 'l'}, {1}},
        {{0, 'm'}, {2}},
        {{1, 'l'}, {3}},
        {{2, 'l'}, {4}},
        {{2, 'm'}, {5}},
        {{3, 'l'}, {3}},
        {{4, 'l'}, {3}},
        {{4, 'm'}, {6}},
        {{5, 'l'}, {7}},
        {{5, 'm'}, {6}},
        {{6, 'l'}, {7}},
        {{6, 'm'}, {8}},
        {{7, 'l'}, {9}},
        {{7, 'm'}, {10}},
        {{8, 'l'}, {6}},
        {{8, 'm'}, {10}},
        {{9, 'l'}, {7}},
        {{9, 'm'}, {8}},
        {{10, 'l'}, {11}},
        {{10, 'm'}, {4}},
        {{11, 'l'}, {12}},
        {{11, 'm'}, {9}},
        {{12, 'l'}, {6}},
        {{12, 'm'}, {10}},
    },
    {0},
    {1, 3},
};
DFA out2 = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {'l', 'm'},
    {
        {{0, 'l'}, 1},
        {{0, 'm'}, 2},
        {{1, 'l'}, 3},
        {{2, 'l'}, 4},
        {{2, 'm'}, 5},
        {{3, 'l'}, 3},
        {{4, 'l'}, 3},
        {{4, 'm'}, 6},
        {{5, 'l'}, 7},
        {{5, 'm'}, 6},
        {{6, 'l'}, 7},
        {{6, 'm'}, 8},
        {{7, 'l'}, 9},
        {{7, 'm'}, 10},
        {{8, 'l'}, 6},
        {{8, 'm'}, 10},
        {{9, 'l'}, 7},
        {{9, 'm'}, 8},
        {{10, 'l'}, 11},
        {{10, 'm'}, 4},
        {{11, 'l'}, 12},
        {{11, 'm'}, 9},
        {{12, 'l'}, 6},
        {{12, 'm'}, 10},
    },
    0,
    {1, 3},
};
MISNFA in3 = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {'a', 'b'},
    {
        {{0, 'a'}, {1}},
        {{0, 'b'}, {2}},
        {{1, 'a'}, {3}},
        {{1, 'b'}, {4}},
        {{2, 'a'}, {5}},
        {{2, 'b'}, {6}},
        {{3, 'a'}, {7}},
        {{3, 'b'}, {8}},
        {{4, 'a'}, {9}},
        {{5, 'a'}, {5}},
        {{5, 'b'}, {10}},
        {{6, 'a'}, {8}},
        {{6, 'b'}, {8}},
        {{7, 'a'}, {11}},
        {{8, 'a'}, {3}},
        {{8, 'b'}, {9}},
        {{9, 'a'}, {5}},
        {{9, 'b'}, {5}},
        {{10, 'a'}, {1}},
        {{10, 'b'}, {2}},
        {{11, 'a'}, {5}},
        {{11, 'b'}, {5}},
    },
    {0},
    {5, 6},
};
DFA out3 = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {'a', 'b'},
    {
        {{0, 'a'}, 1},
        {{0, 'b'}, 2},
        {{1, 'a'}, 3},
        {{1, 'b'}, 4},
        {{2, 'a'}, 5},
        {{2, 'b'}, 6},
        {{3, 'a'}, 7},
        {{3, 'b'}, 8},
        {{4, 'a'}, 9},
        {{5, 'a'}, 5},
        {{5, 'b'}, 10},
        {{6, 'a'}, 8},
        {{6, 'b'}, 8},
        {{7, 'a'}, 11},
        {{8, 'a'}, 3},
        {{8, 'b'}, 9},
        {{9, 'a'}, 5},
        {{9, 'b'}, 5},
        {{10, 'a'}, 1},
        {{10, 'b'}, 2},
        {{11, 'a'}, 5},
        {{11, 'b'}, 5},
    },
    0,
    {5, 6},
};
MISNFA in4 = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    {'e', 'j', 'k'},
    {
        {{0, 'e'}, {1}},
        {{0, 'j'}, {2}},
        {{0, 'k'}, {3}},
        {{1, 'e'}, {2}},
        {{1, 'j'}, {4}},
        {{1, 'k'}, {5}},
        {{2, 'e'}, {6}},
        {{2, 'j'}, {0}},
        {{2, 'k'}, {4}},
        {{3, 'e'}, {7}},
        {{3, 'j'}, {2}},
        {{3, 'k'}, {1}},
        {{4, 'e'}, {4}},
        {{4, 'j'}, {8}},
        {{4, 'k'}, {7}},
        {{5, 'e'}, {4}},
        {{5, 'j'}, {0}},
        {{5, 'k'}, {4}},
        {{6, 'e'}, {7}},
        {{6, 'j'}, {8}},
        {{6, 'k'}, {4}},
        {{7, 'e'}, {3}},
        {{7, 'j'}, {1}},
        {{7, 'k'}, {8}},
        {{8, 'e'}, {2}},
        {{8, 'j'}, {4}},
        {{8, 'k'}, {9}},
        {{9, 'e'}, {4}},
        {{9, 'j'}, {0}},
        {{9, 'k'}, {4}},
    },
    {0},
    {1, 6, 8},
};
DFA out4 = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    {'e', 'j', 'k'},
    {
        {{0, 'e'}, 1},
        {{0, 'j'}, 2},
        {{0, 'k'}, 3},
        {{1, 'e'}, 2},
        {{1, 'j'}, 4},
        {{1, 'k'}, 5},
        {{2, 'e'}, 6},
        {{2, 'j'}, 0},
        {{2, 'k'}, 4},
        {{3, 'e'}, 7},
        {{3, 'j'}, 2},
        {{3, 'k'}, 1},
        {{4, 'e'}, 4},
        {{4, 'j'}, 8},
        {{4, 'k'}, 7},
        {{5, 'e'}, 4},
        {{5, 'j'}, 0},
        {{5, 'k'}, 4},
        {{6, 'e'}, 7},
        {{6, 'j'}, 8},
        {{6, 'k'}, 4},
        {{7, 'e'}, 3},
        {{7, 'j'}, 1},
        {{7, 'k'}, 8},
        {{8, 'e'}, 2},
        {{8, 'j'}, 4},
        {{8, 'k'}, 9},
        {{9, 'e'}, 4},
        {{9, 'j'}, 0},
        {{9, 'k'}, 4},
    },
    0,
    {1, 6, 8},
};
MISNFA in5 = {
    {0, 1, 2, 3},
    {'e', 'n', 'r'},
    {
        {{0, 'e'}, {1}},
        {{0, 'n'}, {1}},
        {{0, 'r'}, {2}},
        {{1, 'e'}, {2}},
        {{1, 'n'}, {3}},
        {{1, 'r'}, {3}},
        {{2, 'e'}, {3}},
        {{2, 'n'}, {3}},
        {{2, 'r'}, {1}},
        {{3, 'e'}, {1}},
        {{3, 'n'}, {1}},
        {{3, 'r'}, {2}},
    },
    {0},
    {0, 3},
};
DFA out5 = {
    {0, 1, 2, 3},
    {'e', 'n', 'r'},
    {
        {{0, 'e'}, 1},
        {{0, 'n'}, 1},
        {{0, 'r'}, 2},
        {{1, 'e'}, 2},
        {{1, 'n'}, 3},
        {{1, 'r'}, 3},
        {{2, 'e'}, 3},
        {{2, 'n'}, 3},
        {{2, 'r'}, 1},
        {{3, 'e'}, 1},
        {{3, 'n'}, 1},
        {{3, 'r'}, 2},
    },
    0,
    {0, 3},
};
MISNFA in6 = {
    {0, 1, 2, 3, 4, 5, 6, 7},
    {'e', 't', 'x'},
    {
        {{0, 'e'}, {1}},
        {{0, 't'}, {2}},
        {{0, 'x'}, {3}},
        {{1, 'e'}, {1}},
        {{1, 't'}, {4}},
        {{1, 'x'}, {5}},
        {{2, 'e'}, {3}},
        {{2, 't'}, {6}},
        {{2, 'x'}, {2}},
        {{3, 'e'}, {3}},
        {{3, 't'}, {7}},
        {{3, 'x'}, {4}},
        {{4, 'e'}, {4}},
        {{4, 't'}, {4}},
        {{4, 'x'}, {7}},
        {{5, 'e'}, {5}},
        {{5, 't'}, {5}},
        {{5, 'x'}, {5}},
        {{6, 'e'}, {5}},
        {{6, 't'}, {2}},
        {{6, 'x'}, {0}},
        {{7, 'e'}, {5}},
        {{7, 't'}, {5}},
        {{7, 'x'}, {5}},
    },
    {0},
    {0, 3},
};
DFA out6 = {
    {0, 2, 3, 6},
    {'e', 't', 'x'},
    {
        {{0, 't'}, 2},
        {{0, 'x'}, 3},
        {{2, 'e'}, 3},
        {{2, 't'}, 6},
        {{2, 'x'}, 2},
        {{3, 'e'}, 3},
        {{6, 't'}, 2},
        {{6, 'x'}, 0},
    },
    0,
    {0, 3},
};
MISNFA in7 = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {'d', 'm', 't'},
    {
        {{0, 'd'}, {2}},
        {{0, 'm'}, {0}},
        {{0, 't'}, {3}},
        {{1, 'd'}, {9}},
        {{1, 'm'}, {0}},
        {{1, 't'}, {2}},
        {{2, 'd'}, {3}},
        {{2, 'm'}, {7}},
        {{4, 'd'}, {7}},
        {{4, 'm'}, {1}},
        {{5, 'd'}, {5}},
        {{5, 'm'}, {5}},
        {{5, 't'}, {0}},
        {{6, 'd'}, {7}},
        {{8, 'm'}, {7}},
        {{8, 't'}, {7}},
        {{9, 'd'}, {7}},
        {{9, 'm'}, {1}},
        {{10, 'd'}, {7}},
    },
    {1},
    {0, 5, 6, 10},
};
DFA out7 = {
    {0, 1, 9},
    {'d', 'm', 't'},
    {
        {{0, 'm'}, 0},
        {{1, 'd'}, 9},
        {{1, 'm'}, 0},
        {{9, 'm'}, 1},
    },
    1,
    {0},
};
MISNFA in8 = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {'h', 'm', 'q'},
    {
        {{1, 'h'}, {4}},
        {{1, 'm'}, {3}},
        {{1, 'q'}, {2}},
        {{2, 'h'}, {0}},
        {{2, 'm'}, {0}},
        {{2, 'q'}, {0}},
        {{3, 'q'}, {4}},
        {{4, 'h'}, {7}},
        {{4, 'm'}, {0}},
        {{4, 'q'}, {8}},
        {{5, 'q'}, {9}},
        {{6, 'h'}, {5}},
        {{6, 'm'}, {8}},
        {{6, 'q'}, {6}},
        {{7, 'h'}, {7}},
        {{7, 'q'}, {8}},
        {{9, 'q'}, {4}},
        {{10, 'h'}, {0}},
        {{10, 'm'}, {0}},
        {{10, 'q'}, {0}},
    },
    {1},
    {0, 5, 6},
};
DFA out8 = {
    {0, 1, 2, 3, 4},
    {'h', 'm', 'q'},
    {
        {{1, 'h'}, 4},
        {{1, 'm'}, 3},
        {{1, 'q'}, 2},
        {{2, 'h'}, 0},
        {{2, 'm'}, 0},
        {{2, 'q'}, 0},
        {{3, 'q'}, 4},
        {{4, 'm'}, 0},
    },
    1,
    {0},
};
MISNFA in9 = {
    {0, 1, 2, 3, 4},
    {'h', 'l', 'w'},
    {
        {{0, 'l'}, {1, 2, 3}},
        {{0, 'w'}, {4}},
        {{1, 'h'}, {1}},
        {{1, 'l'}, {3, 4}},
        {{1, 'w'}, {0, 2}},
        {{2, 'h'}, {3}},
        {{2, 'l'}, {1}},
        {{2, 'w'}, {0}},
        {{3, 'h'}, {3}},
        {{3, 'l'}, {0, 3}},
        {{3, 'w'}, {0, 2}},
        {{4, 'l'}, {1, 2, 3}},
        {{4, 'w'}, {4}},
    },
    {1},
    {0, 1, 2, 3, 4},
};
DFA out9 = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
    {'h', 'l', 'w'},
    {
        {{0, 'h'}, 0},
        {{0, 'l'}, 1},
        {{0, 'w'}, 2},
        {{1, 'h'}, 3},
        {{1, 'l'}, 4},
        {{1, 'w'}, 5},
        {{2, 'h'}, 3},
        {{2, 'l'}, 6},
        {{2, 'w'}, 7},
        {{3, 'h'}, 3},
        {{3, 'l'}, 8},
        {{3, 'w'}, 2},
        {{4, 'h'}, 9},
        {{4, 'l'}, 10},
        {{4, 'w'}, 5},
        {{5, 'h'}, 3},
        {{5, 'l'}, 6},
        {{5, 'w'}, 7},
        {{6, 'h'}, 9},
        {{6, 'l'}, 11},
        {{6, 'w'}, 2},
        {{7, 'l'}, 6},
        {{7, 'w'}, 12},
        {{8, 'h'}, 3},
        {{8, 'l'}, 4},
        {{8, 'w'}, 5},
        {{9, 'h'}, 9},
        {{9, 'l'}, 13},
        {{9, 'w'}, 2},
        {{10, 'h'}, 9},
        {{10, 'l'}, 10},
        {{10, 'w'}, 5},
        {{11, 'h'}, 9},
        {{11, 'l'}, 10},
        {{11, 'w'}, 5},
        {{12, 'l'}, 6},
        {{12, 'w'}, 12},
        {{13, 'h'}, 3},
        {{13, 'l'}, 4},
        {{13, 'w'}, 5},
    },
    0,
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
};
MISNFA in10 = {
    {0, 1, 2, 3, 4, 5, 6},
    {'j', 'k', 'w'},
    {
        {{0, 'j'}, {0, 5}},
        {{0, 'k'}, {1, 2}},
        {{0, 'w'}, {2}},
        {{1, 'j'}, {0, 1, 2}},
        {{1, 'k'}, {4, 5}},
        {{1, 'w'}, {2}},
        {{2, 'j'}, {0, 1, 2}},
        {{2, 'w'}, {0}},
        {{3, 'j'}, {0, 2}},
        {{3, 'k'}, {4, 6}},
        {{3, 'w'}, {0}},
        {{4, 'j'}, {5}},
        {{5, 'j'}, {5}},
        {{6, 'j'}, {0, 2}},
        {{6, 'k'}, {3, 4}},
        {{6, 'w'}, {0}},
    },
    {2},
    {0, 1, 3, 6},
};
DFA out10 = {
    {0, 1, 2, 3, 4, 5, 6, 7},
    {'j', 'k', 'w'},
    {
        {{0, 'j'}, 1},
        {{0, 'w'}, 2},
        {{1, 'j'}, 3},
        {{1, 'k'}, 4},
        {{1, 'w'}, 5},
        {{2, 'j'}, 6},
        {{2, 'k'}, 7},
        {{2, 'w'}, 0},
        {{3, 'j'}, 3},
        {{3, 'k'}, 4},
        {{3, 'w'}, 5},
        {{4, 'j'}, 3},
        {{4, 'w'}, 5},
        {{5, 'j'}, 3},
        {{5, 'k'}, 7},
        {{5, 'w'}, 5},
        {{6, 'j'}, 6},
        {{6, 'k'}, 7},
        {{6, 'w'}, 0},
        {{7, 'j'}, 1},
        {{7, 'w'}, 5},
    },
    0,
    {1, 2, 3, 4, 5, 6, 7},
};
MISNFA in11 = {
    {0, 1, 2, 3, 4, 5, 6},
    {'b', 'i', 'r'},
    {
        {{0, 'b'}, {2}},
        {{0, 'i'}, {1, 2, 4}},
        {{0, 'r'}, {0}},
        {{1, 'b'}, {1, 2, 5}},
        {{1, 'i'}, {0}},
        {{1, 'r'}, {1, 6}},
        {{2, 'b'}, {2, 4}},
        {{2, 'r'}, {1, 2}},
        {{3, 'b'}, {2}},
        {{3, 'i'}, {2}},
        {{3, 'r'}, {1, 3, 4}},
        {{4, 'r'}, {6}},
        {{5, 'b'}, {2}},
        {{5, 'i'}, {1, 2, 4}},
        {{5, 'r'}, {0}},
        {{6, 'r'}, {6}},
    },
    {1},
    {0, 1, 2, 5},
};
DFA out11 = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {'b', 'i', 'r'},
    {
        {{0, 'b'}, 1},
        {{0, 'i'}, 2},
        {{0, 'r'}, 3},
        {{1, 'b'}, 4},
        {{1, 'i'}, 5},
        {{1, 'r'}, 6},
        {{2, 'b'}, 7},
        {{2, 'i'}, 8},
        {{2, 'r'}, 2},
        {{3, 'b'}, 1},
        {{3, 'i'}, 2},
        {{3, 'r'}, 3},
        {{4, 'b'}, 4},
        {{4, 'i'}, 5},
        {{4, 'r'}, 6},
        {{5, 'b'}, 4},
        {{5, 'i'}, 5},
        {{5, 'r'}, 6},
        {{6, 'b'}, 4},
        {{6, 'i'}, 5},
        {{6, 'r'}, 6},
        {{7, 'b'}, 9},
        {{7, 'r'}, 10},
        {{8, 'b'}, 4},
        {{8, 'i'}, 2},
        {{8, 'r'}, 11},
        {{9, 'b'}, 9},
        {{9, 'r'}, 11},
        {{10, 'b'}, 4},
        {{10, 'i'}, 2},
        {{10, 'r'}, 11},
        {{11, 'b'}, 4},
        {{11, 'i'}, 2},
        {{11, 'r'}, 11},
    },
    0,
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
};
MISNFA in12 = {
    {0, 1, 2, 3, 4, 5, 6},
    {'l', 'q', 't'},
    {
        {{0, 'l'}, {2, 4, 5}},
        {{0, 'q'}, {2}},
        {{0, 't'}, {1}},
        {{1, 'l'}, {0, 2}},
        {{1, 'q'}, {1, 4}},
        {{1, 't'}, {0, 2}},
        {{2, 'l'}, {5}},
        {{2, 'q'}, {0, 4}},
        {{2, 't'}, {0}},
        {{3, 'l'}, {3, 4}},
        {{3, 'q'}, {0}},
        {{3, 't'}, {0, 2}},
        {{4, 't'}, {4}},
        {{5, 'l'}, {0, 2}},
        {{5, 'q'}, {4, 5}},
        {{5, 't'}, {0, 2}},
        {{6, 'l'}, {4, 6}},
        {{6, 'q'}, {0}},
        {{6, 't'}, {0, 2}},
    },
    {2, 4},
    {0, 1, 3, 5, 6},
};
DFA out12 = {
    {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26},
    {'l', 'q', 't'},
    {
        {{8, 'l'}, 9},
        {{8, 'q'}, 10},
        {{8, 't'}, 10},
        {{9, 'l'}, 11},
        {{9, 'q'}, 12},
        {{9, 't'}, 11},
        {{10, 'l'}, 13},
        {{10, 'q'}, 14},
        {{10, 't'}, 15},
        {{11, 'l'}, 13},
        {{11, 'q'}, 16},
        {{11, 't'}, 17},
        {{12, 'l'}, 11},
        {{12, 'q'}, 12},
        {{12, 't'}, 16},
        {{13, 'l'}, 18},
        {{13, 'q'}, 19},
        {{13, 't'}, 16},
        {{14, 'l'}, 9},
        {{14, 'q'}, 10},
        {{14, 't'}, 20},
        {{15, 'l'}, 11},
        {{15, 'q'}, 15},
        {{15, 't'}, 16},
        {{16, 'l'}, 13},
        {{16, 'q'}, 16},
        {{16, 't'}, 21},
        {{17, 'l'}, 22},
        {{17, 'q'}, 23},
        {{17, 't'}, 24},
        {{18, 'l'}, 22},
        {{18, 'q'}, 22},
        {{18, 't'}, 24},
        {{19, 'l'}, 22},
        {{19, 'q'}, 13},
        {{19, 't'}, 25},
        {{20, 'l'}, 13},
        {{20, 'q'}, 14},
        {{20, 't'}, 26},
        {{21, 'l'}, 22},
        {{21, 'q'}, 23},
        {{21, 't'}, 25},
        {{22, 'l'}, 22},
        {{22, 'q'}, 22},
        {{22, 't'}, 25},
        {{23, 'l'}, 18},
        {{23, 'q'}, 21},
        {{23, 't'}, 16},
        {{24, 'l'}, 22},
        {{24, 'q'}, 25},
        {{24, 't'}, 24},
        {{25, 'l'}, 22},
        {{25, 'q'}, 25},
        {{25, 't'}, 25},
        {{26, 'l'}, 11},
        {{26, 'q'}, 15},
        {{26, 't'}, 11},
    },
    8,
    {9, 10, 11, 12, 13, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26},
};
MISNFA in13 = {
    {0, 1, 2, 3, 4, 5, 6},
    {'o', 'r'},
    {
        {{0, 'o'}, {0, 1, 4}},
        {{0, 'r'}, {5}},
        {{1, 'o'}, {4}},
        {{1, 'r'}, {2}},
        {{2, 'o'}, {0, 1}},
        {{2, 'r'}, {0, 5}},
        {{3, 'r'}, {2, 5}},
        {{5, 'o'}, {0, 1}},
        {{5, 'r'}, {0, 5}},
        {{6, 'r'}, {2}},
    },
    {2, 5},
    {0},
};
DFA out13 = {
    {8, 9, 10, 11, 12},
    {'o', 'r'},
    {
        {{8, 'o'}, 9},
        {{8, 'r'}, 10},
        {{9, 'o'}, 11},
        {{9, 'r'}, 12},
        {{10, 'o'}, 11},
        {{10, 'r'}, 10},
        {{11, 'o'}, 11},
        {{11, 'r'}, 12},
        {{12, 'o'}, 9},
        {{12, 'r'}, 10},
    },
    8,
    {9, 10, 11},
};
MISNFA in14 = {
        {0, 1, 2},
        {'a', 'b', 'c'},
        {
         {{0, 'a'}, {0}},
         {{1, 'b'}, {1}},
         {{2, 'c'}, {2}},
        },
        {0, 1, 2},
        {0, 1, 2},
};
DFA out14 = {
        {0, 1, 2, 3},
        {'a', 'b', 'c'},
        {
                {{0, 'a'}, {0}},
                {{1, 'b'}, {1}},
                {{2, 'c'}, {2}},
                {{3, 'a'}, {0}},
                {{3, 'b'}, {1}},
                {{3, 'c'}, {2}},
        },
        { 3 },
        {0, 1, 2, 3},
};
MISNFA in15 = {
        {0, 1, 2},
        {'a'},
        {
         {{0, 'a'}, {2}},
        },
        {0, 1},
        {2},
};
DFA out15 = {
        {2, 3},
        {'a'},
        {
        {{3, 'a'}, {2}},
        },
        { 3 },
        {2},
};
MISNFA in16 = {
        {0},
        {'a', 'b'},
        {},
        {0},
        {},
};
DFA out16 = {
        {0},
        {'a', 'b'},
        { },
        {0},
        {},
};
MISNFA in17 = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
        {'b', 'w'},
        {
            {{0, 'b'}, {1, 2, 11}},
            {{0, 'w'}, {2}},
            {{1, 'b'}, {0, 2}},
            {{3, 'b'}, {0, 4, 7}},
            {{3, 'w'}, {0, 2, 3, 5, 8, 13}},
            {{4, 'b'}, {7, 8, 12}},
            {{4, 'w'}, {4, 6, 7, 10}},
            {{5, 'b'}, {4, 8, 9, 10}},
            {{5, 'w'}, {20, 4}},
            {{6, 'b'}, {5, 6}},
            {{6, 'w'}, {2, 4, 11}},
            {{7, 'b'}, {0, 5}},
            {{7, 'w'}, {2, 3}},
            {{8, 'b'}, {0, 12}},
            {{8, 'w'}, {1, 2, 13}},
            {{9, 'b'}, {6}},
            {{9, 'w'}, {0, 7, 9}},
            {{10, 'b'}, {4, 9}},
            {{10, 'w'}, {3, 9}},
            {{12, 'b'}, {0, 4, 7}},
            {{12, 'w'}, {0, 2, 5, 8, 11, 12}},
        },
        {1, 11, 13},
        {1, 2, 3, 5, 8, 9, 10, 12},
};
DFA out17 = {
        {15, 16, 17, 18},
        {'b', 'w'},
        {
                {{15, 'b'}, {16}},
                {{16, 'b'}, {17}},
                {{16, 'w'}, {18}},
                {{17, 'b'}, {16}},
        },
        {15},
        {15, 16, 17, 18},
};

int main()
{
    assert(determinize(in1) == out1);
    assert(determinize(in2) == out2);
    assert(determinize(in3) == out3);
    assert(determinize(in4) == out4);
    assert(determinize(in5) == out5);
    assert(determinize(in6) == out6);
    assert(determinize(in7) == out7);
    assert(determinize(in8) == out8);
    assert(determinize(in9) == out9);
    assert(determinize(in10) == out10);
    assert(determinize(in11) == out11);
    assert(determinize(in12) == out12);
    assert(determinize(in13) == out13);
    assert(determinize(in14) == out14);
    assert(determinize(in15) == out15);
    assert(determinize(in16) == out16);
    assert(determinize(in17) == out17);

    return 0;
}
#endif
