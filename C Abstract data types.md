- main goal is simplification and better readability of code
- all ADTs can be realized as a library
- can be specified mathematically with hep of axioms
- includes: set, list, queue, priority queue, stack, associative array

### Set (mnozina)
- keeps data of same type
- no element can be repeated in the set
- typical operations: print all elements, insert element, remove element, find element in set,...
- order of elements is not important
- implementation with (different methods bring different time complexity):
	- array
		- has constant length, can be resized with `realloc`
			- is better to resize in line with `+1, +2, +3, +4, +5, ... +N`
			- most often by `*1.5` 
	- sorted array
		- effective binary search, ineffective insert and remove of elements
	- linked list
		- removes issues connected with resizing of set size
		- increases code complexity and length
	- sorted linked list
		- does not allow for binary search
		- effective set operations (prunik, sjednoceni, doplnek,...)
	- bit vector
		- good only for sets where we know the maximum number of elements and the number is reasonably big
- time complexity:

|Operace|Pole|Usp. pole|Sp. seznam|Usp. sp. seznam|Bit. pole|
|---|---|---|---|---|---|
|Vypsání všech prvků|O(n)O(n)|O(n)O(n)|O(n)O(n)|O(n)O(n)|O(x)O(x)|
|Vložení prvku, bez kontroly přítomnosti prvku|O(1)O(1)|O(n)O(n)|O(1)O(1)|O(n)O(n)|O(1)O(1)|
|Vložení prvku, s kontrolou přítomnosti prvku|O(n)O(n)|O(n)O(n)|O(n)O(n)|O(n)O(n)|O(1)O(1)|
|Odebrání prvku|O(n)O(n)|O(n)O(n)|O(n)O(n)|O(n)O(n)|O(1)O(1)|
|Zjištění, zda je prvek v množině|O(n)O(n)|O(log⁡n)O(logn)|O(n)O(n)|O(n)O(n)|O(1)O(1)|
|Sjednocení dvou množin|O(n2)O(n2)|O(n)O(n)|O(n2)O(n2)|O(n)O(n)|O(x)O(x)|
|Průnik dvou množin|O(n2)O(n2)|O(n)O(n)|O(n2)O(n2)|O(n)O(n)|O(x)O(x)|
|Rozdíl dvou množin|O(n2)O(n2)|O(n)O(n)|O(n2)O(n2)|O(n)O(n)|O(x)O(x)|
|Symetrická diference dvou množin|O(n2)O(n2)|O(n)O(n)|O(n2)O(n2)|O(n)O(n)|O(x)O(x)|
|Doplněk množiny|O(x⋅n)O(x⋅n)|O(x)O(x)|O(x⋅n)O(x⋅n)|O(x)O(x)|O(x)O(x)|

### List (seznam)
- elements can repeat and the order is important
- typical operations: print all elements, print element on an index, insert element, insert element to specific position (index), remove element, find if element is contained in list, previous/next element,...
- implementation with:
	- array
		- again issues with resizing -> ideal resize number is `*1.5`
	- linked list

### Queue (fronta)
- FIFO = first come first out
- typical operations: insert new element (to the end of queue; push), remove element (from start; pop), find out if queue is empty, find number of elements in queue
- implementation with:
	- array with number of elements defined by a constant
		- to keep constant time complexity of push and pop we cannot move elements -> two pointers
			- 1: most recently added element
			- 2: first open space
		- when array is full is will be filled again from the start
	- dynamically reallocated array
	- one-way linked list
		- two pointers - one points to start, second points to end
		- is good to remember the length of queue 

### Priority queue (prioritni fronta)
- each element has defined priority number
- order of picking number is made by priority of numbers
- typical operations are same as of queue

### ADT stack (ADT zasobnik)
- stack and push-down store
- LIFO = last in, first out
- typical operations: push, pop, if stack is empty, initialize stack, get element from the top of stack (but don't pop), duplication of the stack top, swap top of stack element with one underneath it
- implementation with:
	- array
		- pointer to first empty space, at the same time the last pushed (aka first to pop) is `-1`
		- resizing same as for sets
	- linked list
		- more complicated, but time complexity same

### Associative array (asociativni pole)
- also hash array, associative array, map, symbol table, dictionary
- keeps key:value pair
	- each key is unique, can be different data type
- typical operations: insert element, remove element, change value of key, find if map contains element with some key