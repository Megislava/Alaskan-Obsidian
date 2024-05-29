
#### Historie
- 60. leta 20.stoleti - USA armada chce novou technologii telefonnich siti (connectionless)
- 70. + 80. leta - podpora pocitacovych siti Al Gore
- 1962 - ARPA (Advanced Research Projects Agency)
	- 1969 - ARPANET
		- 4 uzly: UCLA, UCSB, SRI, University of Utah
		- NCP protokol
	- 1972 - ARPANET ma 29 uzlu + email
	- 1973 - ARPANET v EU
- 1973/1974 - TCP/IP vytvoreno (V. Cerf, R. Kahn)
	- 1983 - jediny protokol v ARPANETU
- 1981 - IPv4
- 1983 - DNS
- 1990 - EARN (internet v CS)
	- linka Praha-Linec (9.6kb/s)
- 1991 - vznik www
- 13.2.1992 - Ceskoslovensko pripojeno do internetu (Praha-Linec 19.2 kb/s)
	- FESNET -> CESNET (+ 1993 SANET)
	- 1993 - .cs -> .cz + .sk
- 15. ledna 2000 - CESNET - linka Praha-Brno 2.5Gb/s (unikat)
- 3. unor 2011 - IPv4 vycerpani
- RCF - S. Crocker (autor), J. Postel (editor)

#### Organizace
- registratori domen a IP adres
	- IANA - root domain, adresy IPv3, cisla protokolu
	- RIPE (EU)
	- CZ.NIC (.cz)
- standardy
	- IETF - Internet Engineering Taskforce
		- vydava RFC standady internetu
	- ISO - Internation Standards Organization
	- ITU-T - part of Internation Telecommunication Union
	- IEEE - Institude of Electrical and Electronics Engineers
	- NIST - Nation Institude of Standartds and Technology

#### Taxonomie
- prepojovani: okruhu, paketu
- architektura: peer-to-peer, client-server
- pouziti: verejna, privatni
- rozlehlost: PAN (~1m), LAN (~100m), MAN (~10km), WAN (~1000km)
- topologie: sbernice, hvezda, kruh,...
	- ![[Pasted image 20230302132806.png]]
- vrstvy
	- dekompozice systemu, zjednoduseni navrhu, nezavislost implementace a moznost vymeny
	- funkce:
		- primo interaguji se sousednimi vrstvami (poskytuji sluzby vyssim vrstvam, vuyzivaji sluzeb nizsich vrstev)
		- komunikuji se stejnymi vrstvami
- protokoly 
	- vztahuji se k urcite vrstve
	- definuje zpusob komunikace

- OSI model
	- 7 vrstev: Physical (fyzicka), Data Link (spojova, linkova), Network (sitova), Transport (transportni), Session (relacni), Prezentation (prezentacni), Application (aplikacni)
	- zapouzdreni (data encapsulation) a odpouzdreni (decapsulation)
	- dobry pro popis siti a protokolu
		- ALE neni universalnim standartem realnych siti (spatne nacasovani, nedostatecna technologie, neuspecna implementace)
	- komunikace mezi vrstvami:
		- ![[Pasted image 20230307123021.png]]
	1. Fyzicka vrstva
		- prenos bitu kanalem (modulace 0 nebo 1)
		- definuje elektricke a mechanicke vlastnosti rozhrani
			- predepisuje vlastnosti media, urcuje zpusob sdileni media
		- Ethernet 10BaseT, RS232, ADSL
	2. Spojova (linkova) vrstva
		- poskytuje spolehlive spojeni (detekce, pripadne korekce chyb)
		- formatovani dat do ramcu
		- rizeni pristupu k lince a toku na lince
		- jednoznacna adresa - MAC v Enthenetu
		- PPP, LLC 802.2, Ethernet
	3. Sitova vrstva
		- adresace a smerovani dat pres sitove prvky
		- jednoznacna adresa - IP
		- sitova sluzka bez/se spojenim
		- IP, (X.25, IPX)
	4. Transportni vrstva
		- rozklad dat na pakety a usporadani podle poradi
		- *multiplexuje a demultiplexuje*
		- koncove rizeni toku
			- adresa, port
		- UDP, TCP
	5. Relacni vrstva
		- vytvareni logickeho rozhrani pro aplikace
			- prihlaseni, udrzeni relace
		- synchronizace spojeni
		- RPC, sdileni disku
	6. Prezentacni vrstva
		- formatovani a prezentace dat, transpformace dat (de/komprese)
		- kodovani, sifrovani
		- ASCII, XDR, ASN.1
	7. Aplikacni vrstva
		- zpusob komunikace aplikaci (protokoly), podpurne funkce aplikacim
		- interface pro uzivatele
		- SMTP, HTTP
- TCP/IP model
	- oproti ISO/OSI:
		- vynechano prezentacni, relacni
		- slouceno linkova + fyzicka
		- => network interface, network, transport, application
	- encapsulace, decapsulace
	- akademicky model, globalne uspecny
	- nejdriv byly protokoly, potom mode (bottom-up approach)
	- problemy:
		- neni obecny (neni vhodny pro popis jinych siti), nerozlisuje mezi fyzickou a linkovou vrstvou, nektere protokoly vznikaly "nahodne"
	- 