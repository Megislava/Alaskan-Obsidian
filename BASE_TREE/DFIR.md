## Digital Forensics + Incident Response

- investigating computers that have been compromise by an attacker

- Digital Investigation
	-  it's hard to know where to start + there is a lot of places to look
	-  solution:
		1. Break into Smaller Questions
		2. Artifact Categories
		-> the question that needs to be answered - Is it specific enough to completely answer with a single artifact category? if not -> break it down and repeat on each of those new questions 
	[[14.PNG]]
	- plus prioritization
	[[15.PNG]]
	- 4 questions:	
		- Are there malicious hardware-related changes? (firmware, BIOS)
		- Are there malicious OS configuration changes? (services enabled, logging disabled,...)
		- Are there malicious programs? (backdoors, keystroke loggers, ...)
		- Is there malicious user activity? (account takeover, insider thread,...)

- tools -> collections/analysis

1. [[Memory Analysis]]
2. [[Malware]]
3. [[OS Configuration Changes]]
4. [[User Activity Analysis]]
5. [[Network Analysis]]
6. [[Thread Management]]