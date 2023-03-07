- vulnerability scanner

- Nessus Essential vs Professional
	- Essential - free, up to 16 IP addresses to scan
	- Professional - unlimited, more functionality

- tenable.sc
	- build-up for Nessus
	- dashboard webapp for tracking vulnerabilities across scanners 
- tenable.io
	- cloud-based approach to vulnerability scanning based upon Nessus

- to use you need to register and get activation code
- download and install (`sudo dpkg -i <packet_file>`)
- run the service `sudo systemctl start nessusd.service`
	- → Nessus is running on localhost :8834
- set up the scanner
	- create user
	- packages will be downloaded and Nessus will setup

- new scan
	- different possible pre-configrured scans
	- set up targets
	- add schedule of the scan and how to notify
	- many other settings (brute force, false alarms,...)
	- enable plugins
	- add credentials for authorized scan

- different scan results for scan from different perspactive
	- inside scan, outside scan (attackers view), DMZ located scan
	- agent-based scanning - installs SW on each target device
	- credentialed scannign

- don't forget to update Nessus

