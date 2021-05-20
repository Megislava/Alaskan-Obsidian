- connecting to Burp:
	1. FoxyProxy: IP 127.0.0.1
	2. download certificate from http://localhost:8080
	3. import certificate

1. ###### Proxy
- allows to funnel traffic through Burp for further analysis
2. ###### Target
- specifies the information about target - site map, scope,...
- some sites can be excluded
3. ###### Intruder
- field fuzzing, credential stuffing,...
	a. Sniper 
	- cycles through our selected positions, putting the next available payload (item from our wordlist) in each position in turn
	- uses only one set of payloads (one wordlist).
	b. Battering Ram
	- uses only one set of payloads
	- puts every payload into every selected position
	c. Pitchfork
	- use multiple payload sets (one per position selected) and iterate through both payload sets simultaneously
	- if we select two positions (say a username field and a password field), we can provide a username and password payload list
	- intruder will cycle through the combinations of usernames and passwords, resulting in a total number of combinations equalling the smallest payload set provided. 
	d. Cluster Bomb
	- allows us to use multiple payload sets (one per position selected) and iterate through all combinations of the payload lists we provide
- if we select two positions (username + password), we can provide a username and password payload list
- intruder will then cycle through the combinations of usernames and passwords, resulting in a total number of combinations equalling usernames x passwords
4. ###### Repeater
- allows to repeat request that have previously been made w/ or w/o modification
5. ###### Sequencer
- analyzes randomness present in parts of the webapp which are intended to be unpredictable
- usually testing session cookies
6. ###### Decoder
- allows to perform various transforms on a data
- decoding/encoding to various bases, URL encoding 
7. ###### Comparer
- comparing different responses or other piece of data (site maps, proxy histories)
- similar to diff
8. ###### Extender
- similar to adding mods
- adding component, tool integration, additional scan definitions,...
9. ###### Scanner
- automated web vulnerability scanner
- highlights area of application for further manual investigation or possible exploitation
