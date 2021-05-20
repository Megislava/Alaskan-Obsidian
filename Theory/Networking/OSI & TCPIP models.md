#networking
1. ### OSI model
- Open System Interconnection
- to have universal communication in internet
- particular layer “knows” only layer one up or one down from it = sibling dependence
- getting data from one layer to another = ed-/de-capsulation
- __encapsulation__
	 - as data is passed down each layer on the model, more information containing specific to each layer is added  ![[12.jpeg]]
	 - sending data ~ adding headers + layer 2 (data link) adds header on start AND trailer at the end => final: L1H-L2H-L3H-L4H-L5H-L6H-L7H-Data-L2T
	 - in physical level changed to binary signal and send
- __decapsulation__
	- receiving device
	- electrical signal (binary) is changed to a headers+data+trailer situation => L2H and L2T are removed and examined  => headers from layer 3, 4, 5, 6, 7 are removed => the rest is data
- __load balancing__
	- server that balanced incoming traffic load from multiple sources to optimized uses of server resources (traffic cop)
	- layer 7 or 4
	- advantages: availability, scalability
	- approaches:
		- Round Robin - client-side balancing (not a server), requests are distributed across the group of servers sequentially.
		- BGP Anycast - typically used w/ UDP, allows multiple servers to advertise the same IP address, the routing infrastructure of the internet, using BGP, then routes internet traffic to different web servers over the shortest route possible - topographically the closest one
		- Policy-based DNS load balancing - requests are resolved by a DNS nameserver on the basis of policies defined
		- Dedicated Load Balancing - sits in-line between the client resolver and the nameserver, enables you to deploy and configure one or more custom load-balancers within a VPC
- See how it’s done here: https://www.youtube.com/watch?v=hl2xa7Ahy0E
- Please Do Not Throw Sausage Pizza Away ![[1.PNG]]

1. #### Physical Layer
- moves bites between device
- specifies voltage, wire speed and pin-out cables
- binary, decimal and hexadecimal
	- *binary to decimal:*
		- `11000000 = 1*128 + 1*64 + 0*32 + 0*16 + 0*8 + 0*4 + 0*2 + 0*1 = 192`
		- `00010110 = … + 1*16 … + 1*4 + 1*2 … = 22`
	- *decimal to binary:*
		- `210 = 210-128=82 => yes,  82-64=18 => yes, 18-32 => no, 18-16=2 => yes, 2-4 = no, 2-2=0 => yes, 0-1 => no => 1101010`
- 1000BASE-T, DSL, DOCSIS, 802.11a/b/g/n
- cables + wireless connection + hub + switch + twisted pair, coaxial, fiber optic cabel, ...

2. #### Data Link Layer
- combines packets into bytes and bytes into frames
- prived access to media using MAC address
- performs error detection NOT CORRECTION
- switch ~ switching, router ~ routing
- CSMA/CD + CSMA/CA
- duplex: half duplex (one device communicates at a time “= walkie-talkie”) vs. full duplex (“telephone”, collisions are not possible)
- speed - different (from 10Mbps to 40Gbps but 1G, 10G, 40G,... required full duplex)
- different topologies

	###### Ethernet
- internal network
- ethernet packet (layer 1) include ethernet frame (layer 2)
- Ethernet frame
	- frame = mechanism that’s being used to move data across the Ethernet network from one device to other
	- = preamble (7 bytes long, indicating transmission of new message) + start of frame delimiter (1 byte, signifies start of the frame) + destination MAC address (6 byter) + source MAC address (6 bytes) + optional tag (802.1Q Header, optional header, 4 bytes) + frame type (2 bytes, specifying frame type) + payload (46 - 1500 bytes, data itself) + frame check sequence (= frame check sequence, checking wheather the contents of the frame had arrived error free - counted “size” - hash, 4 bytes) + interpacket gap (provides idle time, 12 bytes)
	- MTU - maximum transition unit - part of DATA part of frame - for Ethernet 1500 bytes
	- protocol data unit = PDU - contains the entire frame 
- different network protocols (communication) 
- ethernet, DOCSIS-3, ARP

3. #### Network Layer
- provides logical addressing, which routers use for path determination
- moving traffic to one to other device - must have unique identifier
- MAC address - network interface card (HW) - its manufacturer ID and serial number of given network interface card = HW address

	###### IP addressing
- IPv4 (32-bit address), IPv6
- 4 number ~ 203.0.113.10, every 0-255 => cca 4 million possible IPs
- 0, 10, and 127 are blocks that are entirely reserved.
- 120, 170, 173, 192, 198 and 203 are blocks that are partially reserved (eg. not all of the 192 block is reserved, but some of it is)
- 224 - 239 is set aside for IP multicast.
- 240 - 255 was originally set aside for "future use" but was effectively lost due to being blocked as invalid
- 5 IP address classes:
	- Class A: 1 - 127
	- Class B: 128 - 191
	- Class C: 192 - 223
	- Class D: 224 - 239
	- Class E: 240 - 255
- Private Address Space:
	- Class A: 10.0.0.0
	- Class B: 172.16.0.0 - 172.31.255.255
	- Class C: 192.168.0.0 - 192.168.255.255
- CIDR = classless interdomain routing = IP address / subnet mask
- are the devices on the same network? (subnetting)
	- 192.117.66.237/22 && 192.117.64.101/22
![[2.PNG]]
	- convert the IP address and the subnet mask to binary (https://www.browserling.com/tools/ip-to-bin) and add (AND) them together => u get the first address (https://www.browserling.com/tools/bin-to-ip) => u get the “last” IP address by looking at the first octet in subnet mask which has zeros (in this case 11111100) there are 2 zeros at the end - 2 zeros represent 4 possible numbers 2^2 = 4 so: 64, 65, 66, 67 THAT’S IT 
- first 3 octecs - network portion
- last octet - host portion
- classtful (95 and before) vs classless addressing (from 1995 to present):
	- classless addressing: has subnet mask, network/host portion can be anywhere (even in the middle of number)
	- classful addressing: w/o subnet mask, unicast, multicast
- address types
	- network address:
		- identifier for a group of devices, like ZIP code
		- has “Network Prefix”
		- all binary zeros in host portion (of IP address, not subnet mask)
	- broadcast address:
		- identifier for all devices on a network
		- all binary ones in host portion
	- host address:
		- identifies unique device on a network
		- in host portion everything except of all zeros/ones
		- in between network and broadcast address
	- ipconfig, ping \[IP\]

__IPv6__
- 128 bits long eg. 2001 : 0DB8 : 0002 : 008D : 0000 : 0000 : 00A5 : 52F5
- network portion 64 bits, interface identifier 64 bits
- ![[3.PNG]]
- shortening:
	=> eliminate leading 0’s eg. => 2001 : DB8 : 2 : 8D : 0 : 0 : A5 : 52F5 
	=> eliminate 0’s with ::  => 2001 : DB8 : 2 : 8D : : A5 : 52F5
	- we can use only one double common
- how many IPv6 addresses:
	- in interface identifier 64 bits = 2^64
- address acquisition: SLAACK, manual config, IPv6 DHCP server
- IPv6 tunneling

###### subnetting 
- /XX = mask:
	- 10.0.0.0/8 = 10.0.10.0/24 = 10.0.16.0/22 = 10.1.0.0/16 = 10.2.0.0/30
	=> variable length subnet masking = VLSM
	- *10.0.0.0/8  => can be 10.0.0.0 - 10.255.255.255 (too much)
	- if 10.0.10.0/24 then 10.0.10.0 - 10.0.10.255*
- IP (addressing + routing) + ICMP
![[4.PNG]]

4. #### Transport Layer
- provides reliable/unreliable connection
- performs error correction before transit
- segments and reassembles data into a data stream
- connection-oriented VS connectionless
- __TCP__ = transmission control protocol
	- 3-way connect = handshake - syn (like sync) message send and waiting for a reply from the server, reply from server to client is syn-ack (acknowledgment of synchronization), send ack message from client to server => session established => protocol (HTTP/https) to contact the server
	- 4-way disconnect - device send FIN message, the other one FIN-ACK message, first again FIN and second FIN-ACK to shut down session OR TCP reset == RST
- __UDP__ = user datagram protocol
	- w/o 3 way handshake - more like shouting to the world

5. #### Session Layer
- setting up, managing and tearing down session between the presentation layer entities 
- provides dialog control between devices/nodes
- coordinates communication between systems and serves to organize their communication by offering 3 modes: 
	- simplex
	- half duplex
	- full duplex
=> keeps different applications data separate
- sockets

6. #### Presentation Layer
- presents data to the application layer
- handles processing = encrypting/decrypting, compressing/decompressing, data translation, code formatting
- SSL + TSL (ASCII => hexadecimal)

7. #### Application Layer
- provides a user interface
- http/https; DNS

![[5.png]]

2. ### TCP/IP
- Transmission Control Protocol / Internet Protocol
- similar to OSI
- older
- 4 layers:
	- Application
	- Transport
	- Internet
	- Network
- ![[13.png]]
- process of encapsulation and decapsulation is the same
