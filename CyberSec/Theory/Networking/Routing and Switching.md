- CSMA/CD
	- carrier sense multiple access with collision detection
	- +5/-5/0 Volts - creates pulse of ones and zeros
	- all devices “hear” the message that is being send
	- all devices shares the same wire
	- if two devices at the same time send a impulse the impulses gets added to each other - +10 Volts signal become - other computes know that 10 == collision → stop the communication, wait a random amount of time and start again
	- **collision domain** = a group of networked devices that will simultaneously detect a voltage spike

###### Routing
- connecting switches (LANs)
- they are “just” deciding where to forward packets - reads destination IP address to decide how to handle the packet → route lookup
- route lookup - looking for suitable destination and route to it, if no route is found, the packet is dropped and error message is send to the message sender
- public IP address
	- limited in number → solution to address exhaustion:
		- private IP addresses
		- network address translation (NAT, home network with x’s of devices can hide behind single public IP)
		- IPv6
		
###### Switching
- single geography, no router, Local Area Network
- on layer-2
- uses MAC address as addressing
- 3 different types of traffic:
	- unicast (1:1)
	- multicast (1:many but not all)
	- broadcast (1:all; if destination MAC address is all F’s then == broadcast)
- break up collisions
- multiple switches can be linked together - using trunk links (collection of wires which simultaneously carry multiple frames from one switch to another)
- issue with scaling → one of solutions:
	- create several LAN (local area network), then connect them via router (ideal for intermediate size network) - still issue with scaling
	- big network → creating a virtual LANs (even on a single switch), creating logical separators (not hardware ones), then can be used trunk links
![[9.PNG]]
![[10.PNG]]
- switch
	- read the frame headers, found out the MAC source address, saves them into MAC address table and next time some message come the switch look into the table at the destination MAC address and decide where the message should be send - no other device will hear it
	- ![[11.PNG]]
- layer-3 broadcast address (MAC) - not really used
- connecting switches - 
- broadcast storm = too much to processing → crash → spanning tree protocol
- spanning tree protocol - shuts down redundancy - shutting down ports with too much traffic
- VLANs - too much 
