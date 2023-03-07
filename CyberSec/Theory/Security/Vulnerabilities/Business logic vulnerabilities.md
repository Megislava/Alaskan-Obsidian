#server-side 

- flawed assumptions about user behavior
- flaws in design and implementation of an application allowing attacker to to unintended behavior
- various business impact

- __examples__
	1. excessive trust in client-side controls
		- tampering with the data after sending (mid transmission)
	2. failing to handle unconventional input
		- changing data type of some variable/parameter
		- sending correct data type but in bad range (`-1`, `a big number`)
	3. making flawed assumptions about user behavior
		- 
	4. domain-specific flaws
		- 
	5. providing an encryption oracle
		- 

- __how to prevent__
	- make sure that developers and testers undertand the domain that the application server
	- avoid makin assumptions about user behavior or behavior of other parts of the app
	- plus:	
		- maintain clear documentation, data flows for transactions and workflows
		- writting clear code
		- be aware of dependencies

