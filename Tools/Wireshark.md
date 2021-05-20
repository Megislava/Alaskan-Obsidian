#networking

- tool to capture and analyze network packet capture files
- common extension: .pcap
- 2 modes:
	- live packet capture
		- first you need to specify interface(s) and apply filters
		- you can stop the capturing with red square and begin analysis
	- analysis
		- load a PCAP file
- each packet includes: packet number, time, source, destination, protocol, length, packet info 
- packet info has 5 pieces of information:
	- Frame 1
		- shows details of physical layer of OSI model (Network l. of TCP/IP) ~ the size of packet received in terms of bytes
	- Ethernet II
		- details from Data Link layer of OSI model (Network l. of TCP/IP) ~ transmission medium, source and destination MAC addreses
	- Internet Protocol Version 4
		- details from Network layer of OSI (Internet l. of TCP/IP) ~ source and destination IP addresses
	- Transmission Control Protocol
		- details of Transport layer of OSI and TCP/IP ~ what protocol was used (TCP/UDP)
	- Hypertext Transfer Protocol
		- details of Application layer of OSI and TCP/IP model ~ HTTP GET request

- packets that are seen as a dangerous (are somehow anomalious) are colored

- methods of packet collection:
	- network tap:
		- physical device which is physically tap between a cable
			1. using hardware to tap the wire and intercept the traffic as it comes through
			2. inline network tap - plant between or 'inline' two network devices, tap will replicate packtes as they pass the tap
	- MAC floods
		- active packet sniffing
		- stressing the switch and filling the CAM table => the CAM table is filled (the switch will no longer accept new MAC addresses) => the switch will send out packets to all ports of the switch (in order to keep the network alive)
	- ARP poisoning
		- active packet sniffing
		- redirecting the traffic from the host(s) to the monitored machine

- packet filtering:

Expression | Meaning
------------  | ------------ 
ip | IPv4 only
tcp | TCP only