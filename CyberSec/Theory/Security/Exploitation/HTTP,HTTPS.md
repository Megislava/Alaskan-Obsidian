- browser
	- enumerate hostnames within domain using DNS:
		```
		#!/bin/bash
		i="0"
		while [ $i -lt "255" ]
		do nslookup 10.11.1.$i 
		10.11.1.XX | grep -v "NXDOMAIN" | grep name | cut -f1,3 -d" "
        i=$[ $i+1 ]
		done 
		```
 
#server-side #client-side 