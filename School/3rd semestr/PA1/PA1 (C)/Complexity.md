- time and space complexity
	- function dependant on size of input data
- we need problem, algorithm, program

1. SSN duplicities (social security number )
	1. Brute force
		- space complexity: $O(n+r)$
		- time complexity: $i=1∑n−1​i=2n∗(n−1)​$
	2. Better algorithms
		- first sort SSNs
		- for each number, look left and right and if they are same print
		- space complexity: $O(n)$
		- time complexity: $O(1,39⋅n⋅logn)$ (quicksort) + linear go thought -> $O(1,39⋅n⋅logn+n+r)$ 
	3. Algorithm 3
		- list of all SSNs and connected linked list of same SSNs
		- space complexity: $O(X+n)$ (for Czech SSNs X is 146 400 000 to save, n = number of numbers)
		- time complexity: $O(X)$ (initialize list of numbers) plus $O(n+r)$ (input numbers, when duplicity print) -> $O(146400000+n+r)$
	4. Hash table
		- the fastest algorithm
		- space AND time complexity: $O(n+r)$

#### Time complexity - best, average, worst
- problem: finding a value in array of numbers
	- sequence search
		- best case (only one iteration): $T(N)=1$
		- words case (is not in array or on last place): $T(N)=N$
- bubble sort
	- best case: $T(N)=(N-1)$
	- worst case:  $T(N)=(N-1)^2$
- quick sort
	- best case: $O(N⋅logN)$
	- worst case:  $T(N)=(N^2)$

## How to count complexity
#### Easier
```c
for (int i = 0; i < N; i ++) {
	/* O(1) operace */
}
```
- $T(N)=N∈O(N)$
```c
for (int i = 0; i < N; i += 10) {
	/* O(1) operace */
}
```
- cycle will run $N/10$ times 
	- if `N` is not an exact multiple of `10` last iteration will be done "one over"
- therefore round up: $T(N)=⌈\frac {N} {10}​⌉∈O(N)$
```c
for (int i = 0; i < N * N; i += 3) {
	/* O(1) operace */
}
```
- cycle though $N^2$ (`N` squared)
- $T(N)=⌈\frac{N^2}{3}​⌉∈O(N2)$
```c
for (int i = 0; i < N * N; i += N) {
	/* O(1) operace */
}
```
- even though the `N` is squared, to `i` is added `N` at the end of every round
- $T(N)=N∈O(N)$
```c
for (int i = 1; i < N; i *= 2)
	/* O(1) operace */
}
```
- the cycle will run $log(N)$ times, `i` grows by `2` (`2, 4, 8, 16,...`)
	- therefore the $i=2^k$ where the cycle ends with $k=log(N)$
	- if `N` is not a square of two then there will be one more iteration
- $T(N)=⌈log_2​N⌉∈O(logN)$
```c
for (int i = 1; i < N; i += i) {
	/* O(1) operace */
}
```
- same as previous example
	- `i` will be `1, 2, 4, 8, 16,...`
- $T(N)=⌈log_2​N⌉∈O(logN)$
```c
for (int i = 1; i < N; i <<= 1) {
	/* O(1) operace */
}
```
- again same code -> $T(N)=⌈log_2​N⌉∈O(logN)$
```c
for (int i = 1; i < N * N; i *= 5)
	/* O(1) operace */
}
```
- $N^2$, `i` grows by `5` (`1, 5, 25, 125, ...`)
	- cycle ends with $i=5^k$ while $5^k≥N^2$ when $k=log_5(N^2)$
	- again round up
- $T(N)=⌈log_5​(N^2)⌉∈O(logN)$
```c
int i = 5 * N;
while (i) {
	/* O(1) operace */
	i /= 3;
}
```
- `i` is first set to $i=5N$ the shrinks by `N, N/3, N/9,...`until `0`
	- number of iterations is: $k=log_3(5*N)$
		- *in previous case the whole cycle is $N*N$ and here is it $5*N$ that's why it is inside of brackets*
	- round down for `0` and add `1`
- $T(N)=⌊log_3​(5*N)+1⌋∈O(logN)$
#### More difficult
1. Non-dependant nested cycles
```c
for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
		/* O(1) vypocet */
	}
}
```
- outer and inner both run $N$ times no matter the `i`/`j` value
- $T(N)=N⋅N∈O(N^2)$
```c
for (int i = 0; i < N; i ++) {
	for (int j = 0; j < N; j += 20) {
		/* O(1) vypocet */
	}
}
```
- outer runs $N$ times non dependant on `i`, inner runs $\frac{N}{20}$times
- $T(N)=N⋅⌈\frac{N}{20}​⌉∈O(N^2)$
```c
for (int i = 0; i < N; i++) {
	for (int j = 1; j < N; j *= 3) {
		/* O(1) vypocet */
	}
}
```
- outer $T(N)=N$, inner $T(N)=log_3N$
- $T(N)=N⋅⌈log_3​(N)⌉∈O(N⋅logN)$
```c
for (int i = 1; i < N * N; i *= 2) {
	for (int j = N * N * N; j; j--) {
		/* O(1) vypocet */
	}
}
```
- outer is $T(N)=log(N^2)$ ($log_2$ is natural so $log$ is sufficient), inner runs $T(N)=N^3$
- $T(N)=⌈log2​(N2)⌉⋅N^3∈O(logN⋅N^3)$
```c
for (int i = N * N; i; i--) {
	for (int j = N * N; j; j >>= 2) {
		/* O(1) vypocet */
	}
}
```
- outer: $T(N)=N^2$, inner: $T(N)=log_4(N^2)$ (`j` shrinks from  `N*N, ..., 16, 4, 1, 0`)
	- inner cycle goes to zero, add `1`, round down
- $T(N)=N^2⋅⌊log_4​(N^2)+1⌋∈O(N^2logN)$
```c
for (int i = 1; i < N; i <<= 1) {
	for (int j = N * N; j; j /= 3) {
		/* O(1) vypocet */
	}
}
```
- outer: $T(N)=log_2(N)$, inner: $T(N)=log_3(N^2)$
	- round down plus `1`
	- *for `+/i` is operation is `/` the number, for `divide/multiply` it's logarithm*
- $T(N)=⌈log_2​(N)⌉⋅⌊log_3​(N^2)+1⌋∈O(log^2N)$

2. Dependant cycles
- is solved with sum function
```c
for (int i = 0; i < N; i++) {
	for (int j = i; j < N; j++) {
		/* O(1) vypocet */
	}
}
```
- outer: $T(N)=N$
- inner: `N, N-1, N-2, .., 1` times
- $T(N)=\sum_{i=1}^{N}i=\frac{N+1}{2}​⋅N∈O(N^2)$
```C
for (int i = 0; i < 2*N; i += 3) {
	for (int j = 2*i; j < 5*i; j += 2) {
		/* O(1) vypocet */
	}
}
```
- outer: $T(N)=\frac{2N}{3}$, `i` will be `0, 3, 6, 9, ..., 2*N-3`
- inner: `i` will run `0, 5, 9, 14, 18, 23,...`times
	- for simplicity we are thinking that always `i/3`
$$T(N)=\sum_{i=0}^{\frac{N}{3}-1}9i+\sum_{i=0}^{\frac{N}{3}-1}(5+9i) = \frac{N}{3}​\biggl(\frac{9(\frac{N}{3}-1)}{2}+\frac{5+5+9(\frac{N}{3}-1)}{2}​\biggr)$$
$T(N)=N^2-\frac{8}{6}N∈O(N^2)$
```c
for (int i = 0; i < 2*N; i++) {
	if ( i < N ) {
		for (int j = 0; j < 10 * i; j += 2)
			/* O(1) vypocet */
	}
	else {
		for (int j = i; j; j--)
			/* O(1) vypocet */
	}
}
```
- two possibilities of running:
	- for `i < N`: `i` runs `0, 5, 10, ..., 5*N-5`times -> $\sum_{i=0}^{N-1}5i$
	- for other `i`: `N, N+1, N+2,..., 2*N-1`times -> $\sum_{i=N}^{2N-1}i$
$$T(N)=\sum_{i=0}^{N-1}5i+\sum_{i=N}^{2N-1}i=N\frac{0+5N-5}{2}+N\frac{N+2N-1}{2}=4N^2-3N ∈O(N2)$$
```c
for (int i = 0; i < N; i++) {
	for (int j = 1; j < i * i; j *= 2) {
		/* O(1) vypocet */
	}
}
```
- outer cycle is linear, inner cycle is logarithmic (because `i*i`)
- didn't get the calculation
```c
for (int i = 1; i <= N; i *= 2) {
	for ( j = 0; j < i; j ++ ) {
		/* O(1) vypocet */
	}
}
```
- inner: `i` grows exponentially, if `N` is natural number then: $T(N)=1+2+4+8+...+N$
- geometric line with quotient of `2`: $T(N)=\sum_{k=0}^{logN}2^k=\frac{2N-1}{2-1}=2N-1∈O(N)$
- if `N` is not a natural number on power `2` then we presume `X` value instead of `N` which is a number to power of `2`
	- then $X<N<2X$
- there is no difference between number of runs between `X` and `N`
```c
for (int i = 1; i <= N; i *= 3) {
	for (int j = i; j < N; j ++ ) {
		/* O(1) vypocet */
	}
}
```
- calculation again is made from inner cycle
- let's simplify `N` to be as a number of a power of `3`; then:
	- $T(N)=(N−1)+(N−3)+(N−9)+(N−27)+⋯+(N−N/3)+(N−N)$
- $T(N)=N⋅logN−\frac{3N-1}{3-1}​∈O(N⋅logN)$