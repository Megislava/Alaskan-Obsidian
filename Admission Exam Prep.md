#flashcards

## Flashcards
### Data

informace
?
zprava o tom ze nastal nejaky jev z mnoziny moznych jevu a prijemce snizuje/odstranuje neznalost o tomto jevu
<!--SR:!2024-06-25,9,261-->

data vs informace
?
data = reprezentace skutecnosti; sama o sobe bezvyznamna
informace = vyznam prisouzeny datum; interpretace individualni
<!--SR:!2024-06-20,8,259-->

mira informace a entropie
?
s rostouci informaci klesa entropie a naopak
<!--SR:!2024-06-23,11,288-->

kvalita informace
?
obtizne kvantifikovatelna, kriteria: spolehlivost, duveryhodnost, solidnost, aktualnost,...
<!--SR:!2024-06-23,7,261-->

kodovani vs sifrovani - ucel
?
kodovani = standardizace prenosu, ochrana informace pred chybami pri prenosu, zmenseni velikosti
sifrovani = uchranit info
<!--SR:!2024-06-20,8,243-->

databazovy system
?
nastroj pro uchovavani dat, pro tvorbu DB aplikaci
organizovany soubor dat a nastroju pro praci s daty ulozenymi na pametovem mediu
<!--SR:!2024-06-20,5,241-->

relacni DB (RDB)
?
data v provazanych tabulkach
<!--SR:!2024-06-25,9,261-->

objektove orientovany RDB
?
informace uchovavane ve forme objektu, kazdy objekt ma vlastnosti a pripustne hodnoty, objekty muzou mit funkce (reakce na chovani ostatnich)
<!--SR:!2024-06-21,6,261-->

informacni system
?
sourhn lidi, ICT, dat, program zabezpecujici sber, prenos, zpracovani a uchovavani dat s cilem tvorby, prezentace a distribuce informaci pro koncove uzivatele
<!--SR:!2024-06-20,4,221-->

### Hardware

kodovani v PC
?
posun pres mechanicke->elektro->mechanicke->elektro
elektronika zalozena na principu promenlive elektricke vodivosti (-> 0/1) -> nejvyhodnejsi je dvojkova soustava - jednotka bit
<!--SR:!2024-06-24,9,260-->

spinace pocitacovych generaci (5)
?
generace:
(0.) elektromagneticke rele ->
(1.) elektronka (1945-1950) ->
(2.) transistor (1950-1964) ->
(3.) integrovany obvod (1965->1980) ->
(4.) mikroprocesor (1981->...) ->
?? (kvantum?)
<!--SR:!2024-06-24,9,228-->

zakladni deska
?
obsahuje napajeci obvody, konektory pro pripojeni procesoru, pameti, periferii, radicu, sbernic a dalsich obvodu, dnes i caste integrovane periferie
<!--SR:!2024-06-24,8,261-->

procesor
?
hlavni vypocetni cast PC, vykonava strojovy kod ulozeny v RAM, dnes vicejadrove
<!--SR:!2024-06-22,10,268-->

vnitrni pamet
?
misto k ukladani dat a programoveho kodu (= instrukci), RAM
<!--SR:!2024-06-26,10,281-->

graficka karta
?
zajistuje zobrazuni dotazu na monitoru, integrovana vs dedikovana/externi
<!--SR:!2024-07-01,12,241-->

vnejsi pamet
?
- pevny disk (HDD) - mechanicke disky z magneticky vodiveho materialu, cteni a zapis pomoci elektromagneticke indukce, data organizovana do stop, pomerne velka spotreba elektricke energie
- SSD - flash pamet, bez mechanickych casti, velka rychlost cteni, mala spotreba, malo hluku, mechanicky odolny, nizka zivotnost jednotlivych datovych bunek
- SSHD - HDD + SSD
<!--SR:!2024-07-06,17,262-->

rozhrani PC
?
- ke komunikaci s okolim - vnejsi (periferie) vs vnitrni (jednotlive casti PC) rozhrani
- vnitrni - SATA (disk), PCI+PCI express (rozsiruje karty)
- vnejsi - VGA, HDMI, DVI, RJ45, USB (Universal Serial Bus, limitovany odber ze smernice, zpetna kompatibilita, verze 1.1, 2.0, 3.1, C, 4.0), Bluetooth (parovani 2 zarizeni v 2.4GHz bezlicencnim pasmu), WiFi (nejtypictejsi pripojeni k internetu, v 2.4 a 5GHz bezlicencnim pasmu)
<!--SR:!2024-07-07,18,268-->

Mooruv zakon
?
- pocet transistoru ktere mohou byt umistene na integrovany obvod se pri zachovani stejne ceny zdvojnasobi kazdych 18 mesicu
- typek spoluzakladatel Intelu
<!--SR:!2024-06-26,10,243-->

### Software

software
?
- uzivatel-SW-HW
- obvykle spustitelny kod ktere muze byt vykonavany procesorem
<!--SR:!2024-06-26,11,259-->

operacni system
?
zakladni programove vybaveni PC spustene pro zapnuti, zustava v cinnosti az do vypnuti
obvykle s GUI, ma zakladni systemove nastroje, poskytuje jednotle GUI pro uzivatele
<!--SR:!2024-06-27,11,281-->

3 fce OS
?
ovladani PC, abstrakce HW, sprava prostredku
<!--SR:!2024-06-25,9,248-->

firmware
?
ovladaci kod pro nizkourovnove rizeni HW ~ uzce spjat s konkretnim HW
<!--SR:!2024-06-26,10,281-->

aplikacni SW
?
programove vybaveni PC, GUI/textove rozhrani, kancelarske aplikace, webove prohlizzece, postovni klienti,...
<!--SR:!2024-06-20,8,263-->

zakazkovy vs typovy SW
?
zakazkovy (custom) = presne podle specifikace, zavislost na dodavateli, delsi doba vyvoje
typovy = muze neco chybet nebo prebyvat, moznost customizace, lepsi cena a delka vyvoje
<!--SR:!2024-06-24,8,261-->

licencovani SW
?
kazdy SW musi mit licenci (nejcasteji EULA)
dle svobody uzivatele: svobodny, proprietarni
<!--SR:!2024-06-22,6,261-->

svobodny SW
?
- GNU/GPL (R. Stallman) - zachovani maximalni svobody uzivatele
	- moznost sirit, pouzivat za jakymkoli ucelem, menit a prizpusobovat (pri sireni takovychto zmen je prenasi licence)	-
- open-source SW ma mene striktni pozadavky oproti GNU/GPL
<!--SR:!2024-06-23,8,242-->

proprietarni SW
?
- obvykle bez pristupu ke kodu, neda se upravovat
- typy:
	- komercni SW - v EU obchodovani s jiz pouzitymi licencemi je povoleno
	- OEM - Original Equipment Manufacturer; SW dodavany jako komponenta subdodavatelem, vyrobce ho muze dal prodavat pod svoji znackou
	- shareware - obvykle spojeni trial->nakup licence
	- freeware - dobrovolne prispevky
	- public domain - mozne sirit a upravovat, je i v jinych oborech
<!--SR:!2024-06-22,4,199-->

SaaS
?
Software as a Service, cloudovy SW, nic neni treba instalovat ani udrzovat, nutno mit internet k pouzivani
<!--SR:!2024-06-21,9,259-->

malware
?
SW urceny k proniknuti do systemu nebo jeho poskozeni, malicious SW
vir, spyware, keyloggers, adware,...
<!--SR:!2024-06-23,7,261-->

### Pocitacova grafika

typy pocitacove grafiky
?
vektorova (z objektu) a bitmapovani (z bitu)
<!--SR:!2024-06-20,8,259-->

bitmapova grafika
?
- obrazek rozlozen do malych bodu = pixel, usporadane do mrizky
- pixel uchovava informace o barve, rozliseni,...
:) lze robrazovat i slozite predlohy, snadne porizeni
:( velky objem dat, ztrata informaci pri upravach
<!--SR:!2024-06-20,5,241-->

bitmapovy SW
?
- gimp (open-source, free)
- Adobe Photoshop (zakladni kresleni, vybery, tvorby, zmeny barvy, vrstvy,...)
- Malovani
- InfraView (prohlizeni, lehke upravy, nakresleni jednoducheho obrazce, komprese)
<!--SR:!2024-06-28,11,248-->

bitmapove formaty (6)
?
.jpg, .jpeg, .gif, .png, .bmp, .xcf (format gimpu, podporuje vrstvy), .tiff (lepsi nez .bmp, umi i kompresi), .psd (Photoshop format)
<!--SR:!2024-06-23,7,240-->

.jpg, .jpeg vlastnosti
?
- rozdeli obrazek na <span style="background:#d3f8b6">ctverce 8x8</span>
- komprimace s kosinovou transformaci (ztrata detailu, kompresni artefakty kolem hran)
- vhodne na foto, nevhodne pro texty s ostrou hranou
<!--SR:!2024-06-21,2,221-->

.gif vlastnosti
?
- <span style="background:#d3f8b6">patent</span> (od 1995 potreba licence)
- pouze 8bitu kodovani barev, umi animace
- nevhodne pro foto, vhodne na obrazky s malym poctem barev
<!--SR:!2024-06-21,6,241-->

.png vlastnosti
?
- <span style="background:#d3f8b6">patentove nechraneny</span> format
- <span style="background:#d3f8b6">1-64 bitu/pixel</span>
-  umi i pruhlednost
- nevhodne pro foto, obvykle pro skenovani dokumentu
<!--SR:!2024-06-24,7,241-->

.bmp vlastnosti
?
- <span style="background:#d3f8b6">ulozeni nekomprimovanych dat</span>
- <span style="background:#d3f8b6">1/4/8/24 bitu/pixel</span>
- uz se skoro nepouziva
<!--SR:!2024-06-23,4,201-->

vektorova grafika
?
obrazek z nekolika jasne definovanych objektu (bod, primka, krivna), reprezentace rozmery a umistenim
:) libovolne skalovani, mozno pracovat s jednotlivymi objekty, mensi pametova narocnost
:( nevhodny pro zapis slozitych barevnych ploch, slozitejsi na porizeni obrazku
<!--SR:!2024-07-02,14,248-->

vektorove SW
?
svobodny: Inkscape, OpenOfficeDraw
proprietarni: Adobe Illustrator, Coredraw, Zoner, CAD,...
<!--SR:!2024-06-28,9,241-->

vektorove formaty (ne pro multimediove kontejnery)
?
- nativni: .ai (Adobe Illustrator), .cdr (Corel Draw), .zmt (Zoner callisto)
- aplikacne nezavisle formaty: .svg, .psa, .eps (postscript, pro tiskarny), .odf
- jednotlive formaty maji ruzny pristup k objektum -> slozity prenos
<!--SR:!2024-06-23,5,221-->

vektorove multimedialni kontejnery - uvod
?
jedna/vice stop (zvuk, video, text s titulky)
do kontejneru lze ukladat data v ruznych formatech
<!--SR:!2024-06-24,8,261-->

formaty vektorovych multimedialnich kontejneru
?
.avi - zastaraly, vysoka kompatibilita, digitalni foto
.mpeg - Motion Picture Experts Group, vice formatu a kontejneru, bitmap 24bit/pixel, max 4096x4096 obrazovych bodu, max 30 snimku, kosinova ztratova komprese
.heif, .heic, .hevc - foto v telefonech, F - titulky a zvuk, VC - video s pouzitim DVB-T2
.mp3 - MPEG-1, MPEG-2, hlavne hudba na PC, princip casoveho a frekvencniho mapovani, ztratova komprese, nevhodny pro mluvenou rec
.mp4 - MPEG-4 part 14, nastupce .avi, vice titulku/zvukovych stop/3D objektu, streamovane videa, mp3 komprese, vychazi z nej 3GPP na mobilech
.vp9 - od Google, otevreny, podpora browseru, mobily, tablety, telefize, kamery,...
.ogg - projekt pro tvorbu svobodneho SW -> .oflac, .ogg, .opus, .speex, .ogv
<!--SR:!2024-06-22,4,208-->

RBG, CMYK,...
?
RBG - 3 barevne svetla - Red+Blue+Green, skladani, monitory
CMYK - Cyan+Magenta+Yellow+Key, na barevne pigmenty svitime bilym svetlem, neco se obrazi neco se pohlti, na tisk
taky: HSV (HueSaturationValue), HSB (Brightness), HSL (Lumination), HSI (Intensity),...
<!--SR:!2024-06-20,6,240-->

barevny gamut
?
barvy dosazitelne v prislusnem modelu, mimo model se barvy zobrazi pouze priblizne -> gamut zarizeni - barvy ktere je zarizeni schopno zobrazit
<!--SR:!2024-07-02,14,248-->


### Podnikove informacni systemy

Podnikovy informacni sytem (EIS = Enterprise Information System) (definice, cil)
?
= sprava informaci a znalosti o firme a integrace do podnikovych procesu a k manazerskemu rozhodovani
- cile:
	- podpora rizeni
	- koordinace disponibilnich podnikovych zdroju a aktivit
	- propojeni a navaznost podnikovych a pracovnich procesu
	- zvyseni celkove efektivity
	- zlepseni pracovnich navyku a chovani useru
<!--SR:!2024-06-21,4,188-->

historie EIS
?
1. MRP (= Material Resource Planning) - 60.leta 20. stoleti, vazano na konkretni HW, neinteraktivni, jeden system, pouze planovani materialu
2. MRP II. - 80.l.20.stoleti, vazano na konkretni OS, klient-server, textovy modularni system, rizeni a optimalizace vyroby, HR
3. ERP (= Enterprise Resource Planning) - 90.l.20.stoleti, prenositelnost mezi OS, DB-server-klient, GUI, rizeni i nevyrobnich podniku, optimalizace, systemy na miru
4. ERP II. - zacatek 21.stoleti, real-time access, multimedia, webapps, dodavatelsko-odberatelske retezce, CRM, BI (Business Intelligence), propojene systemy
5. postmodern ERP - dnes, vicevrstve, cloud, prozakaznicky orientovane, balikove systemy pro ruzne podniky
<!--SR:!2024-06-27,8,201-->

oblasti postmoder EPR
?
- finance - ucetnictvni vs managerske, sprava podnihovych aktiv (EAM = Enteprise Asset Management)
- HR - HRM - pracovni doba, mzdy, skoleni, benefity, komunikace
- vyroba, logistika, provoz, projektovani - rizeni kvality, procesu, jakosti, IT; planovani vyroby, zasoby skladu, rizeni dodavatelskeho retezce (SCM = Supply Chain Mgmt, SRM = Supplier Relation Mgmt), sprava majetku
- marketing a prodej - PIM (Product Information Mgmt), CRM (Customer Relation Mgmt - rizeni vztahu se zakazniky), cenova politika, rizeni a zpracovani objednavek, servis
<!--SR:!2024-06-28,13,280-->

zakladni moduly postmoder EPR
?
BI+CRM+SCM
casta kombinace HRM+EAM (Enterprise Asset Mgmt)+ECM (Enterprise Content Mgmt)
<!--SR:!2024-06-26,8,219-->

vyrobci EIS
?
SAP - 1.verze v 60.l.20.stoleti, ruzne OS a DB, NetWeaver, BusinessOne, SAP R/3
ORACLE - EPR - E-Business Suite, Cloud ERP
Infor, Microsoft, IBM, Asecco Solution, ABRA,...
<!--SR:!2024-07-02,14,239-->

### eGovernment

eGovernment
?
vyuziti informaci a komunikacnich technologii s cilem zlepseni a nebo posileni ucinnosti a efektivity poskytovanych sluzeb ve verejnem sektoru
<!--SR:!2024-06-26,7,203-->

komunikacni kanaly eGovernmentu (x2y)
?
G2B, G2C, C2G, G2E, G2G
<!--SR:!2024-06-25,10,260-->

uskali eGovernmentu
?
koexistence elektronicke a neelektonicke komunikace, rovny pristup vsech obyvetelu k eletro sluzbam, bezpecnost, ochrana pred zneuzitim
<!--SR:!2024-06-28,12,281-->

metody pristupu k informacim a komunikace v eGovernmentu
?
datova schranka, zakladni registry, CzechPoint
informativni webove stranky, verejna sprava, elektronicke podpisy
<!--SR:!2024-06-20,6,240-->

datova schranka - uvod a technicne reseni
?
- ISDS = Integrovany System Datovych Schranek - informacni system verejne spravy, zrizene podle zakona c 300/2008
- elektronicke uloziste zvlastniho typu
- zrizuje a spravuje MVCR, provozovatel je CeskaPosta
- mozne stavy schranky: funcni, neexistuje, znepristupnena a zrusena
- webapp ~ SOAP+HTTPs, dalsi proprietarni SW pro komunikaci
- bezpecnost - ID+heslo (5 pokusu/hodina, potom deaktivace), po 30minutach neaktivity odhlaseni, OTP (mobilni klid ISDS, cip na obcance, auth cert)
<!--SR:!2024-06-28,9,241-->

datova zprava datove schranky - obsah
?
obsahuje elektronickou a casovou znacku (kvalifikovane razitko)
telo obsahuje formu prilohy
pro vlozeni zpravy - avizo SMS (za penize), nebo email (zadarmo)
<!--SR:!2024-06-22,4,208-->

vlastnosti datove schranky
?
neomezena velikost
dorucenka (potvrzeni doruceni, precteni, fikce doruceni)
od precteni se zprava uchovava 90 dnu (pro delsi platnost: datovy trezor, datove uloziste)
<!--SR:!2024-07-05,17,268-->

pravni uprava elektronicky ukonu eGovernmentu v Datove Schrance
?
zavaznost - pravni vaha stejna jako u fyzickeho doruceni do vlastnich rukou
garantovane doruceni - kdyz adresat se prihlasi do sve datovky
pravni fikce doruceni - pokud se adresat do 10 dnu neprihlasi, zprava je povazovana do dorucenou
pomijivost - zpravy se po 90 dnech mazou
pokuty - 10M za nevyzadany dokument, 20M za skodlivy SW
<!--SR:!2024-06-20,8,243-->

ISZR = Integrovany System Zakladnich Registru
?
spravce MVCT, provozovatel Spravce Zakladnich Registru, spravce Urad pro Ochranu Osobnich Udaju
- ORG = prevodnik identifikatoru fyzickych osob ~ ochrana osobnich udaju v registrech
	- nepouziva se RC, v kazdem systemu je jiny identifikator
	- v ORG pouze ID
<!--SR:!2024-06-27,9,218-->

registry ISZR
?
registr osob - spravuje Cesky Statisticky Urad, eviduje udaje o fyzickych a pravnich osobach a organech verejne moci
registr obyvatel - spravuje MVCR, eviduje aktualni udaje o obcanech CR, cizincich s povolenim k pobytu a zahranicnich vlasnicich nemovitosti
registr uzemni identifikace adres a nemovitosti - spravuje Cesky Urad Zememericsky a Katastralni, udaje o zakladnich uzemnich prvcich
registr prav a povinnosti - spravce MVCR, evidence udaju o pusobnosti organu statni moci, pravech a povinnostech osob
<!--SR:!2024-06-24,8,261-->

CzechPoint
?
cesky podaci, overovaci a informacni narodni terminal
asistovane misto vykonu verejske moci - kdokoli muze ziskat informace o udajich ktere o nem stat vede, lze ucinit podani ke statu
<!--SR:!2024-06-21,6,261-->

Czech Point - vystupy
?
overene vystupy z registru (zivnostensky, obchodni, katastr nemovitosti, trestu)
overeni podpisu, automaticka konverze dokumentu z/do elektronicke podoby a zaslani do datovky (autorizovany, overuje se specialnim podpisem, presne specifikovane kdo to muze delat)
<!--SR:!2024-06-22,7,261--> 

### IT Governance

IT Governance
?
nastaveni pravidel ve kterych muzou ostatni efektivne pracovat
vs Management - pravidelna cinnost obsahujici provozni rozhodnuti v ramci danych pravidel
soucasti je i merici a kontrolni system
cil: vybavit firmu/organizaci jasne definovavymi pravidly pro efektivni plneni cilu
<!--SR:!2024-07-01,14,230-->

role ve firme/organizaci
?
vlastnik - otazky a naslouchani
manager - chain of command, carrot & stick
Board of Directors - vybira je majitel (ne CEO), lidi s ruznymi zkusenostmi a transparetni minulosti,
<!--SR:!2024-06-24,9,261--> 

co se ocekava od board of directors
?
challenging executive management, managing risk, steering on long term & strategic level
<!--SR:!2024-07-02,14,248-->

corporate (enterprise) governance
?
- soubor pravnich a exekutivnich metod a postupu zavazujici zejmena verejne obchodovatelne spolecnosti
- definuje distribuci <span style="background:#d3f8b6">prav a povinnosti</span> mezi zainterestovanymi stranami spolecnosti (akcionari, vykonny management, statutarni organy, zamestnanci, zakaznici)
- IT governance je podmnozinou
<!--SR:!2024-06-20,1,130-->

historie IT governance
?
<span style="background:#d3f8b6">do 1996 - audit IT</span>
<span style="background:#d3f8b6">do 1998 - management IT, co se ma ocekavat od IT</span>
<span style="background:#d3f8b6">kolem 2000 - vykonnost a monitorin IT, jak IT merit</span>
<span style="background:#d3f8b6">kolem 2005 - IT Governance ~ zavadeni pravidel pro IT</span>
<span style="background:#d3f8b6">kolem 2012 - tesne propojeni business a IT (~ EGIT)</span>
<!--SR:!2024-06-22,3,161-->

EGIT = Enterprise Governance IT
?
- pokryva vsechny pozadovane procesy a IT zdroje tak aby IT vhodne podporovalo spolecnosti pri vytvareni hodnot a naplnovani ocekavani zaintersovanych stran
- oblasti: risk managemnt, performance management, IT strategic alighment, IT value delivery
- ocekavani: zvyseni transparentnosti, dosazeni souladu s relevantnimi zakony, regulacemi a politikami, nastaveni kontrolnich mechanizmu a reportovani, vcasna identifikace a elimikace rizika vyplivajici z IT, zlepseni rizeni IT v souladu s best practise
<!--SR:!2024-06-22,3,161-->

propojeni businessu a IT - Enterprise Balance Source Card
?
metoda vytvarejini vazbu mezi strategii a operativnimi cinnostmi s durazem na mereni vykonu
finance->procesy->uceni se a rust->zakaznim->financee->..
IT BSC - tabulky s objectives a measures, cile, projekty a aktivity ktere tyto cile a jejich dozazeni zajitit
<!--SR:!2024-06-20,1,130-->

system (vseobecna definice)
?
celek slozeny z casti ktere na sebe vzajemne pusobi, mezi castmi mohou byt toky informaci a energie
<!--SR:!2024-07-04,16,263-->

COBIT
?
framework na vytvareni procesu pro efektivni vyuziti zdroju a minimalizace IT rizik
audit (1996) + control (1998) + management (2000) + IT governance (2005/2007) + governance of IT enterprise (2012)
uzivatele: manageri, auditori, vlastnici, IT a sec specialiste,...
<!--SR:!2024-06-24,6,208-->

proces
?
- ucelne naplanovani a realizovana posloupnost cinnosti ve kterem za pomoci odpovidajicich zdroju probita transformace vstupu na pozadovane vystupy
<!--SR:!2024-06-23,7,239-->

procesni rizeni vs projektove rizeni
?
projekt - jednorazova zmena
proces - kontinualni
<!--SR:!2024-06-20,8,260-->

rozdeleni podnikovych procesu
?
hlavni - vedlejsi - podpurne
<!--SR:!2024-06-24,6,261-->

proces - zralost a CMMI (= Capability Maturity Model Integration)
?
neexistujici -> nahodny -> formalizovany -> meritelny -> optimalizovatelny
<!--SR:!2024-06-24,7,241-->

jak zlepsit proces (8)
?
- eliminace nebo spojovani zbytecnych cinnosti
- paralelizace
- centralizace zdroju
- jedno kontaktni misto
- vzdelani - zvyseni urovne znalosti pracovniku
- delegace pravomoci
- duvera mezi subjekty
- automatizace
<!--SR:!2024-06-23,4,201-->

Business Process Management = BPM
?
- design -> model -> execute -> monitor -> optimize -> ...
- snaha o uchopeni struktury firmy, jeji architektury a rizeni prostrednictvim podnikoveho modelu zachycujici zakladni rozmery podnikani
- rada nastroju a metod
<!--SR:!2024-06-21,2,161-->

ITIL - v3 vs v4
?
- v3 - lifecycle view - 26 procesu v 5 domenach:
	- service strategy | service design, service transition, service operation | continual improvement
- v4 - comprehensive, reflects changing world of IT
<!--SR:!2024-06-21,2,159-->

co dela management?
?
- planovani
- organizovani
- personalni zajistovani
- vedeni a motivace
- kontrolovani
deleni: stabilni vs flexibilni struktura, alternativni
<!--SR:!2024-06-21,6,218-->

informacni model podniku
?
(1) technologie -> data -> aplikace -> informace -> business
(2) data (fakta popisujici realitu nezaujate) -> informace (data v kontextu) -> znalost (informace s vyznamem, pro prakticke rozhodovani situace) -> moudrost (znalost + vhled)
<!--SR:!2024-06-23,7,228-->

Data Security Life-cycle
?
Create -> Store -> Use -> Share -> Archive -> Destroy -> ...
<!--SR:!2024-06-23,6,241-->

organizovani
?
kazdy system hleda rovnovahu
-> omezeni rozmanitosti systemu, struktura, teorie chaosu a prechodove jevy
dynamicka rovnovaha
<!--SR:!2024-06-20,5,241-->

projektove rizeni - styl prace
?
WBS = Work Breakdown Structure
OBS = Organization BS
Agile vs Waterfall
Gantt Chart - pruhovy diagram, graficke znazorneni naplanovani posloupnosti cinnosti v case
<!--SR:!2024-06-27,12,248-->

rizeni lidi
?
management vs leadership
<!--SR:!2024-06-25,13,280-->

rizeni tymu
?
typy tymu: diverzita, samotatnost, lokalizace, typologie clenu, pracovni role
nastroje - startup, sociomapovani
<!--SR:!2024-06-25,9,248-->

risk management - process
?
- identification ->
- assessment ->
- mitigation plan ->
- implementation & monitoring ->
- review & update plans
<!--SR:!2024-06-20,1,130-->

typy ochrany (prevence)
?
perimetr, data & privacy, process, application
security consulting - risk analysis, security audit, IT Governance,...
<!--SR:!2024-06-20,6,228-->

etika
?
- prakticka filozofie - hleda odpoved na otazku jak spravne zit
- individualni moralka, spolecensky mrav
- aplikovana etika, podnikatelska etika
<!--SR:!2024-06-25,9,240-->

zmena firemni kultury (proces, akteri, nastroje)
?
- analyza situace -> tvorba vize -> projekt zmeny
- akteri: iniciatori, leafer, reprezentanti, podporovatele, odpurni, neutralni
- nastroje: vize, projekt zmen, personalni a organizacni zmeny, vzdelani a vycvik, zmeny v odmenovani a pridelovani zdroju, technicka zmena
<!--SR:!2024-06-20,4,221-->

firemni dokumenty
?
smlouvy, zapisy z jednani, organizacni normy, prodejni a reklamni dokumentace, projetova dokumentace, ...
rizena vs nerizena
<!--SR:!2024-06-28,11,243-->

Enterprise Content Management (ECM)
?
- podnikovy IS zabyvajici se spravou podnikovych informaci
- cile: zajistovani dostupnosti informaci, zvyseni info bezpecnosti, snizeni chybovosti, uspory
- vsechny typy elektronickych a papirovych dokumenty, rizeni a sprava veskereho informacniho obsahu, proces digitalizace
<!--SR:!2024-06-22,7,228-->

normy - kaskady vzniku
?
globalni kaskada impupzu pro vznik/zmenu norem: EU uroven -> CR uroven -> firemni uroven
firemni kaskada: complience, best practise, quality management
<!--SR:!2024-06-28,9,241-->

norma o norme
?
zakladni norma o tom jak psat normy (tvori se jako prvni)
stanovi e struktura obsahu a forma
<!--SR:!2024-06-22,7,261-->

normy - vyznam
?
- tvorba normativniho modelu organizace (pravidla o tom jak ma stravne fungovat aby splnila sve cile)
- v souladu s normou se tvori a upravuje system rizeni organizace
- efektivni; pozor na balanc formalnosti vs kreativity
<!--SR:!2024-06-27,9,219-->

normy - druhy
?
smernice, narizeni, rozhodnuti reditele, opatreni, normativni smernice, rad,...
kategorizace podnikovych norem: pravni, technicke, ekonomicko-provozni, organizacni, ridici,...
<!--SR:!2024-06-26,7,220-->


### Informacni bezpecnost a kryptografie

bezpecnost informaci
?
ochrana informaci ve vsech jejich formach a po cely zivotni cyklus
<!--SR:!2024-06-24,9,261-->

CIA
?
Confidentiality - ochrana pred neautorizovaym pristupem, uzitim, vyzrazenim; ochrana v systemu, pri transferu, pri zpracovani; fyzicka bezpecnost, sifrovani, autorizace, autentikace
Availability - zajisteni dostupnosti systemu/sluzeb/iformaci, akceptovatelna uroven vykonnosti, prevence ztraty a zniceni; redundance ulozeni/zpracovani/pristupu k datum, zalohovani a obnova dat, plany obnovy, aktualizace a patchovani
Integrity - detekce nezadoucich zmen pri vlozeni/prenosu/zpracovani; digitalni podpis, hashovani, audit operaci, odolnost vuci chybam uzivatele
<!--SR:!2024-06-23,9,260-->

kyberneticka bezpecnost
?
sourhn pravnich, organizacnich, technickych a vzdelavacich prostredku smerujici k zajisteni ochrany kybernetickeho prostoru
<!--SR:!2024-06-20,5,241-->

bezpecnost informaci vs kyberneticka bezpecnost
?
BI chrani i fyzicke informace pred jinymi nez kyber hrozbami (povodne), KB chrani i jina akrtiva nez jenom nformace (soukromi, identity)
<!--SR:!2024-06-24,12,279-->

krypto-grafie/analyza/primitiva
?
kryptografie - matematicke metody ve vztahu s prvky BI, cile: duvernost, integrita, autentizace, nepopiratelnost
kryptoanalyza - analyza odolnosti kryptografickych systemu a jejich pentestovani
kryptoprimitiva - algoritmy se zakladnimi krypto vlastnostmi - bez klicu, sdilene klice (symetric, asymetric), verejne klice
<!--SR:!2024-06-20,5,241-->

hashovani
?
jednosmerna hashovaci funkce prevede libovolny retezec na otisk o pevne delce
na overovani hesel, overeni integrity zprav a souboru, generovani a overerni digitalniho podpisu, identifikatory souboru,...
<!--SR:!2024-06-29,13,281-->

utok na hash
?
nalezeni 1. vzoru -> nalezeni 2. vzoru -> nalezeni kolice
<!--SR:!2024-06-28,12,248-->

symetricka sifra
?
- pro sifrovani i desifrovani se pouziva stejny klic -> pozadavky na bezpecny sifrovaci algoritmus a bezpecne predani klice
- typ: blokove (rozdeleni otevreneho textu na bloky), proudove (prubezne sifrovani)
- eg.: AEAE (Authenticated Encryption w/ Associated Data, sifrovani a pocitani MAC), GMC (blokova, v TLS1.3), CCM (blokova, v TLS1.2), POLY1305 (proudova, v TLS1.2 a TLS1.3)
<!--SR:!2024-06-27,8,219-->

asymetricka sifra
?
- kombinace public a private klice, na sifrovani, podepisovani
- matematicky narocnejsi
- 3 skupiny
	- rozdeleni velkeho cisla na soucin prvocisel (RSA)
	- diskretni logaritmus (Diffie-Hellman, DSA, Elgamal)
	- elipticke krivky (ECDM, ECDSA, ECIES,...)
<!--SR:!2024-06-28,9,183-->

certifikat - obsah
?
identifikacni udaje, platnost, verejny klic, rozsirujici info, digitalni podpis od cert autority (duvoeryhodna cert autorita - eIDAS)
<!--SR:!2024-07-01,12,228-->

eIDAS
?
- cilem je uznavani autentizace mezi staty EU
- vytvoreni standartu pro elektronicke podpisy, kvalifikovane digitalni certifikaty, elektronicke peceti, casova razitka,...
- ruzna uroven zaruky (nizka, znacna, vysoka)
<!--SR:!2024-06-21,3,168-->

elektonicky podpis
?
kvalifikovany certifikat (vydany CA, musi byt pravdivy), kvalifikovany prostredek
<!--SR:!2024-06-27,10,242-->

elektronicka pecet
?
technicky stejna jako elektricky **podpis**, ale ma jine certifikaty a jine pravni dusledky
kvalifikovana, uznavana, elektronicka
<!--SR:!2024-06-21,4,201-->

casova razitka/znacky
?
Time Stamp Authority k otisku prida casovou znacku, poradove cislo a celek digitalne podepise
<!--SR:!2024-06-25,6,221-->

identifikace
?
akt/proces kdy entita predlozi systemu identifikator na jehoz zaklade muze rozeznat danou entitu
<!--SR:!2024-06-25,6,241-->

autentizace
?
provedeni testu a rozpoznani a potvrzeni entity
<!--SR:!2024-06-23,8,260-->

autorizace
?
udeleni prav podle pristupovych prav
<!--SR:!2024-06-28,12,248-->

identita
?
fyzicka - jedna, ale muze mit vice elektronickych identit
<!--SR:!2024-06-20,8,258-->

faktory autentizace
?
vim + mam + jsem
<!--SR:!2024-06-24,12,283-->

prihlasovani heslem
?
nejcastejsi, nejjednodussi na implementaci, jednoduchy a znamu pro uzivatele, nejmene bezpecny
-> omezeni poctu pokusu, chranit hesla uzivatelu, pomahat s vytvarenim hesel, skolit uzivatele,...
<!--SR:!2024-06-23,11,288-->

single-sign on
?
- oddeleni aplikace od autentizace uzivatele (uspesny utok na aplikaci nevede k prozrazeni hesel)
- uzivatel si nemusi pamatolik tolik hesel, uspora casu
- typy: webove (cookies), federovane authentizacni protokoly (SAML, OpenID Connect), Kerberos (na lokalni siti)
<!--SR:!2024-06-29,12,239-->

NIA = Narodni bod pro identifikaci a autentizaci
?
muze pouzivat jenom statni sprava, eidentita.cz
<!--SR:!2024-06-20,5,228-->

penetracni testovani
?
planovani a priprava -> ohodnoceni (recon, mapping, vuln check, initial breach, privilege escalation, C&C, post exploitation) -> reportovani
<!--SR:!2024-06-26,11,280--> 

firewall
?
- blokuje/povoluje navazovani komunikace na zakladni preddefinovane/dynamicke pravidla a politiky, chrani zarizeni
- blokovani pomoci: drop, reject, TCP reset
- typy: nezstavove (1. generace, pouze filtrovani), stavove (2. generace), aplikacni FW (3. generace, na aplikacni vrstve OSI modelu), FW nove generace
- umisteni: na hranici site, mezi subnety, v OS, v aplikaci
<!--SR:!2024-06-20,4,221-->

proxy
?
- forward proxy - pri filtrovani pristupu a obsahu, urychleni odpovedi, prokazani souladu s pravidly, skryti interni site, anonymizace
- reverse proxy - pri LB, podpora TLS, SSL, offload, SSL acceleration, caching, taky zrychluje odpovedi, slouceni obsahu z vice aplikaci, podpora SSO
<!--SR:!2024-06-26,8,218-->

IDS = Intrusion Detection System
?
- detekce neobvykle aktity ktera by mohla vest k naruseni bezpecnosti
- analyza, detekce, alertovani
- casta kombinace s IPS
<!--SR:!2024-06-25,13,279-->

IPS = Intrusion Prevention System
?
- detekce skodlive cinnosti, zablokovani a alertovani
- casta kombinace s IDS
<!--SR:!2024-07-04,15,259-->

VPN = Virtual Private Network
?
authentikace + sifrovani provozu pres otevrenou sit
typy: public VPN, site-to-site, Remote Access
<!--SR:!2024-06-20,5,228-->


### Zaklady odborne prace

analyticke mysleni
?
rozdeleni celku na samostatne casti a zabyvani se jimi zvlast
<!--SR:!2024-06-22,10,279-->

synteticke mysleni
?
snaha o poskladani a potom pochopeni celku
<!--SR:!2024-06-22,10,279-->

informacni etika
?
- vytvareni hranic a definic
- nutno informacim porozumet, overit a pak pouzit v kontextu
<!--SR:!2024-06-20,4,221-->

citace
?
norma APA (ISO 690) - povinne: autor, nazev dila, rok vydani, misto, nakladatelstvi
nutno uvest vsechny pouzite zdroje, presne a uplne citace, odkazy v textu do seznamu literatury
doslovna vs parafraze
<!--SR:!2024-06-21,9,268-->

struktura odborne prace
?
uvod-metody-vysledky-diskuze
uvod - proc bylo tema zvoleno, zasadit do kontextu, necisluje se
abstrakt (anotace, teze), klicova slova
text-zaver-seznam literatury a zdroju
metodika - promysleny postup pri praci
<!--SR:!2024-06-22,6,261-->


## PDF
![[Repetitorium-pro-Informacni-management.pdf]]
