## Digital Forensics 
- investigating computers that have been compromise by an attacker

### Digital Investigation/Forensics
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

- hardware tools
	- portable, powerful,...
	- antistatic bags, screwdrivers,...
- SF tools -> collections/analysis

1. Preserving data
	- RULE N.1 - DON'T CHANGE YOUR EVIDENCE -> preserving data
	- write blocker
		- use when copying data from target
		- prevents accidental write
		- SF (in regedit in `HKLM/SYSTEM/CurrentControlSet/Control` -> new key `StorageDevicePolicies` -> new DWORD `WriteProtect` `1` ) or HW
	- hashing before and after copying
	- mounting
2. Acquiring data
	- static acquisition
		- [[dd]], [[dcfldd]], [[FTK Imager 1]] or [[Volatility]]
	- live acquisitions
		- encryption
		- volatile data source - RAM
	- remote acquisition
		- network connection
		- client-server architecture
	3. Analysing data
		 - indexing, searching, reporting
		 - [[Autopsy]], [[Hex Workshop 1]], [[OpenStego]]

## Incident Response
1. Prepare for inevitable incident
2. Incident detection and characterisation
3. Data collection
4. Data analysis
5. Remediation

- checklists and forms on [ir3e.com](ir3e.com)


## Links

1. [[Memory Analysis]]
2. [[Malware]]
3. [[Operating System Forensics]]
4. [[User Activity Analysis]]
5. [[Network Forensics]]
6. [[Thread and Vulnerability Management]]
7. [[Reverse Engineering]]
8. [[Autopsy]]
9. [[SIFT]]