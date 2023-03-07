// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector
#include <set>
using namespace std;

class CMail {
public:
	CMail(int x) : m_data(x) {}
	bool operator<(const CMail & second) const {
		if (m_data < second.m_data) return true;
		else return false;
	}
	
	int m_data;
};

#define SIZE 100

int main () {
	multiset<CMail> v;
	int array[] = {3, 4, 4, 5, 6, 6, 8};
	for (int i = 0; i < 7; i++) {
		v.insert(CMail(array[i]));
	}
	
	CMail lowMail(3);
	CMail highMail(7);

  auto low = v.lower_bound(lowMail);
  auto up  = v.upper_bound(highMail); 

  for (auto const & i : v) cout << i.m_data << " ";
  cout << "\n------" << endl;
  for (auto i = low; i != up; ++i) cout << (*i).m_data << " ";
  
//  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
//  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}