1. If
	- syntax: 
	- ```c
		if (expression) { command }
		else if (expression) { command }
		else { command }
	- can be nested
	- be careful about logical expressions `(0 < month) < 13` or ` num % 2 == 1`
		- `(0 < month)` as a logical expression results in `1` and `1 < 13` is always TRUE
		- `num` can be also minus, then `mod 2 == -1`
2. Switch
	- more fancy `if` for more expressions
	- syntax:
	- ```c
		switch (i) {
			case 1: printf("Jedna\n");
			case 23: printf("Dvacet tri\n");
			case 10: break;
			default: printf("Neco nedefinovaneho\n");
		}
		- in this case, more `printf`s will happen
3. Cycles
	- different types: `for`, `while`, `do while`
	1. `for`
		- syntax: `for (expression1; expression2; expression3) { commands }`
			- `expression1` is done once - before start of the loop
			- `expression2` is checked at the beginning of every "round" of loop
			- `expression3` is run after every end of "round"
	2. `while` and `do while`
		 - syntax `while` : `while (expression) { command } `
		 - syntax `do while`: `do { command } while (expression)`
	 - cycles can be nested
		 - make sure iterating variables are different in case it is needed
	- `break`
		- ends the whole cycle
	- `continue`
		- will end the current iteration and jump to next one