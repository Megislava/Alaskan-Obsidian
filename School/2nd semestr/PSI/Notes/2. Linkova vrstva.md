#### Spolehlivost
- tj. reakce vrstvy na ztraceny (poskozeny, zahozeny) frame
1. nepotvrzovana nespojovana sluzba (unacknowledged connectionless service)
	- neresi se spolehlivost, pripadne chyby se resi ve vyssi vrstve
	- Ethernet
2. potvrzovana nepojovana sluzba (acknowledged connecitionless service)
	- potvrzuje se kazdy ramec (ACK)
	- nepotrvzene ramce jsou opakovane posilany 
	- muze dojit k duplicitnimu prijeti ramcu
		- to pak resi vyssi vrstva
	- 802.11 (wifi)
3. potvrzovana spojovana sluzba (acknowledged connection-oriented service)
	- nejvyssi spolehlivost
	- 3 faze:
		- navazani spojeni => prenos dat => ukonceni
	- ramce jsou cislovane
	- kazdy uzel v ceste si uklada informace o navazanem spojeni
- protokoly zodpovidaji za prenos dat mezi propojovanymi systemy
	- zajisteni spolehlivosti presunu - zarucene doruceni framu, vylouceni duplikaci, spravne poradi ramcu
	- adresace v ramci segmentu - koncove stanice maji adresy, mapovani sitovych adres na liknove adresy (*MAC to IP?*)
##### Chyby 
- castejsi v bezdratovych linkach, vyjimecne v opticke lince
- problemy s `bandwidth * delay`
	- soucit zpozdeni a kapacity = mnozstvi dat "na ceste"
	- ma vliv na volby zpusobu potvrzovani a opakovani ramcu
	- Ethernet 10BaseT (10Mb/s, mene nez jeden ramec), opticka linka (10Gb/s, tisice ramcu v prenosovem kanale)
- detekce chyb
	- parita - detekce chyb v jednom bitu (pocet 1 v sloupci/radku je sudy/lichy)
	- kontrolni soucet (checksum) - soucet hodnot vsech prenesenych bytu/slov
	- CRC (cyclic redundancy check) - zvolen klic G(x), CRC je zbytek po deleni zpravy M(x) klicem G(x)
- oprava chyb
	- samoopravne kody
		- opakovaci kod - kazdy bit je opakovan (napr 3x)
		- Hammingovy kody - linearni samoopravne kody
- potvrzovaci schemata
	1. pozitivni potvrzeni
		- kazdy ramec je potvrzen
			- pokud neprijde potvrzeni do timeout, ramec je poslan znova
	2. negativni potvrzeni (NAK)
		- prijimaci strana potvrzuje prijeti/neprijeti (NAK) framu
		- nedostane-li se NAK ani ACK, ceka se na timeout
	3. cislovani ramcu
		- pakety cyklicky cislovane (0 - n)
		- prijimaci strana potvrzi prijem cislem packetu ktery ocekava
		- snadna identifikace duplicit
	4. klouzave okenko
		- jako u cislovani ramcu ale vysilac muze vyslat vice nez jeden ramec bez cekani na odpoved
		- nezbytne kdyz prenosovy kanal pojme vice ramcu

#### Podvrstvy
1. MAC (Medium Access Control)
	- rizeni pristupu k mediu
	- deterministicky pristup - alokace kanalu
		- staticke vyhrazeni (multiplexing), centralizovane/distribuovane rizeni
		- token ring
			- IBM, IEEE 802.5
			- logicka struktura - jednosmernu okruh
			- ramce (datovy/prikazovy s tokenem)
			- v klidovem stavu probiha jenom token
			- deterministicky pristup k mediu, lepsi pruchodnost nez Ethernet
	- nahodny pristup
		- predchudce - ALOHA sit
		- CSMA
			- vychazu z ALOHA
			- kolize nejsou detekovane
			- nez stanice zacne vysilat, posloucha na lince jestli nekdo uz neco nevysila - kdyz ano, ceka na konec relace pak zacne hned vysilat nebo chvilku ceka
		- CSMA/CD
			- CSMA with Collision Detection
			- kdyz vysila tak zaroven posloucha provoz na lince, v pripade kolize prerusi vysilani
			- vyuziti v Ethernetu
		- CSMA/CA
			- CSMA with Collision Avoidance
			- u radiovych siti
			- nelze poslouchat pri visilani
		- RTS/CTS algoritmus
			- stanice posle RTS (Request To Send), centralni stanice odpovi CTS (Clear To Send)
			- vyuziva se ve wifi
1. LLC (Logical Link Control)
	- podporuje sdileni linkove vrstvy s ruznymi sitovymi vrstvami
		- mechanizmus pro existenci rozdilnych sitovych protokolu nad spolecnou MAC adresou
	- obsahuje rizeni datoveho toku a kontrolu chyb
	- standardizovano v IEEE 802.5
	- rozdeleni proudu bity do ramce (frame)
		- hranice pomoci: explicitni pocet (stejna delka framu), mezera na konci ramce, doplnkovy znak (byte stuffing, flag), doplnkovy bit (bit stuffing)
	- HDLC
		- High Level Data Link Control, ISO 13239
		- rozsahla norma, ruzne implementace s omezenou kompatibilitou
		- bitove orientovany protokol, synchronni i asynchronni
		- v seriovych linkach
		- format:
			- ![[Pasted image 20230307162520.png]]
	- SLIP
		- Serial Line IP
		- pocatek 80.let
		- definuje; pouze encapsulaci paketu na seriove lince
		- nedefinuje: adresaci, typ paketu, detekci chyb, kompresi
	- PPP
		- Point to Point Protocol, podmnozina HDLC
		- asynchronni, bitove i znakove synchronni
		- umoznuje soubeh nekolika protokolu
		- bit stuffing
	- Ethernet
		- 2 ruzne normy Ethernetovych ramcu (mohou se vyskytovat najednou):
			- Ethernet II
				- puvodni verze konzorcia DIX (Digital, Intel, Xerox)
				- v Internetu je podpora povinna
				- ![[Pasted image 20230307164014.png]]
			- IEEE 802.3
				- misto pole Typ je Delka
				- ![[Pasted image 20230307164055.png]]
		- klasicky
			- 10Base5 - koaxialni kabel (tlusty), adaptery s odbockami, max 500m, 50 Ohm
			- 10Base2 - koax kabel RG-58 (tenky), T spojka u kazde sitove karty, max 185 m, 50 Ohm
			- 10Base-T - kroucena dvoulinka, propojeno na hub (kolize) nebo switch (bezkolizni)
		- prepinany
			- 100Mb/s - 100Base-Tx (kroucena dvoulinka), 100Base-FX (opticke vlakno)
			- 1Gb/s - 1000Base-SX (opticke vlakno, dosah 500m-5km), 1000Base-FX (UTP)
			- 10Gb/s - 10GBase-SR (opticke vlakno, dosah 300m-40km)
		- vysokorychlostni
			- 40Gb/s, 100Gb/s (v CR malo instalaci), Terabit Ethernet (malo implementaci, v CR pouze CESNET, standardizace pokracuje)
		- 802.11 - WiFi
			- vyuziva CSMA/CA
			- 2 typy stanic - klient + AP (Access Point)
			- komunikace: AP-klient, klient-klient
			- rozdilny dosah stanic
			- autentizacni protokoly: volny pristup, WAP, WPA, WPA2,...
			- implementace: 802.11a (5GHz, 54Mb/s), 802.11b (2.4GHz, 11Mb/s), 802.11g (2.4Ghz, 54Mb/s), 802.11h (5/2.4GHz, 100Mb/s a vic)
		- Bluetooth
			- IEEE 802.15.1, Ericsson, PAN - personal area network
			- architektura: piconet (rozsah cca 10m, mas 7 aktivnich klientu, max 255 neaktivnich klientu), scatternet (propojeny piconetu spolecnym klientem)