#flashcards

## Flashcards
### Data
informace
?
zprava o tom ze nastal nejaky jev z mnoziny moznych jevu a prijemce snizuje/odstranuje neznalost o tomto jevu

data vs informace
?
data = reprezentace skutecnosti; sama o sobe bezvyznamna
informace = vyznam prisouzeny datum; interpretace individualni

mira informace a entropie
?
s rostouci informaci klesa entropie a naopak

kvalita informace
?
obtizne kvantifikovatelna, kriteria: spolehlivost, duveryhodnost, solidnost, aktualnost,...

kodovani vs sifrovani
?
kodovani = standardizace prenostu, ochrana informace, zmenseni velikosti, zabraneni chybam pri prenostu
sifrovani = uchranit info

databazovy system
?
nastroj pro uchovavani dat, pro tvorbu DB aplikaci
organizovany soubor dat a nastroju pro praci s daty ulozenymi na pametovem mediu

relacni DB (RDB)
?
data v provazanych tabulkach

objektove orientovany RDB
?
informace uchovavane ve forme objektu, kazdy objekt ma vlastnosti a pripustne hodnoty, objekty muzou mit funkce (reakce na chovani ostatnich)

informacni system
?
sourhn lidi, ICT, dat, program zabezpecujici sber, prenos, zpracovani a uchovavani dat s cilem tvorby, prezentace a distribuce informaci pro koncove uzivatele

### Hardware
kodovani v PC
?
posun pres mechanicke->elektro->mechanicke->elektro
elektronika zalozena na principu promenlive elektricke vodivosti (-> 0/1) -> nejvyhodnejsi je dvojkova soustava - jednotka bit

spinace pocitacovych generaci
?
henerace: (0.) elektromagneticke rele -> (1.) elektronka (1945-1950) -> (2.) transistor (1950-1964) -> (3.) integrovany obvod (1965->1980) -> (4.) mikroprocesor (1981->...) -> ?? (kvantum?)

zakladni deska
?
obsahuje napajeci obvody, konektory pro pripojeni procesoru, pameti, periferii, radicu, sbernic a dalsich obvodu, dnes i caste integrovane periferie

procesor
?
hlavni vypocetni cast PC, vykonava strojovy kod ulozeny v RAM, dnes vicejadrove

vnitrni pamet
?
misto k ukladani dat a programoveho kodu (= instrukci), RAM

graficka karta
?
zajistuje zobrazuni dotazu na monitoru, integrovana vs dedikovana/externi

vnejsi pamet
?
pevny disk (HDD) - mechanicke disky z magneticky vodiveho materialu, cteni a zapis pomoci elektromagneticke indukce, data organizovana do stop, pomerne velka spotreba elektricke energie
SSD - flash pamet, bez mechanickych casti, velka rychlost cteni, mala spotreba, malo hluku, mechanicky odolny, nizka zivotnost jednotlivych datovych bunek
SSHD - HDD + SSD

rozhrani PC
?
ke komunikaci s okolim - vnejsi (periferie) vs vnitrni (jednotlive casti PC) rozhrani 
vnitrni - SATA (disk), PCI+PCI express (rozsiruje karty)
vnejsi - VGA, HDMI, DVI, RJ45, USB (Universal Serial Bus, limitovany odber ze smernice, zpetna kompatibilita, verze 1.1, 2.0, 3.1, C, 4.0), Bluetooth (parovani 2 zarizeni v 2.4GHz bezlicencnim pasmu), WiFi (nejtypictejsi pripojeni k internetu, v 2.4 a 5GHz bezlicencnim pasmu) 

Mooruv zakon
?
pocet transistoru ktere mohou byt umistene na integrovany obvod se pri zachovani stejne ceny zdvojnasobi kazdych 18 mesicu
typek spoluzakladatel Intelu

### Software

software
?
uzivatel-SW-HW
obvykle spustitelny kod ktere mohou byt vykonavany procesorem

operacni system
?
zakladni programove vybaveni PC spustene pro zapnuti, zustava v cinnosti az do vypnuti
obvykle s GUI, ma zakladni systemove nastroje, poskytuje jednotle GUI pro uzivatele

3 fce OS
?
ovladani PC, abstrakce HW, sprava prostredku

firmware
?
ovladaci kod pro nizkourovnove rizeni HW ~ uzce spjat s konkretnim HW

aplikacni SW
?
programove vybaveni PC, GUI/textove rozhrani, kancelarske aplikace, webove prohlizzece, postovni klienti,...

zakazkovy vs typovy SW
?
zakazkovy (custom) = presne podle specifikace, zavislost na dodavateli, delsi doba vyvoje
typovy = muze neco chybet nebo prebyvat, moznost customizace, lepsi cena a delka vyvoje

licencovani SW
?
kazdy SW musi mit licenci (nejcasteji EULA)
dle svobody uzivatele: svobodny, proprietarni

svobodny SW
?
zachovani maximalni svobody uzivatele - moznost sirit, pouzivat za jakymkoli ucelem, menit a prizpusobovat (pri sireni takovychto zmen je prenasi licence) ~ GNU/GPL (R. Stallman)
open-source SW ma mene striktni pozadavky oproti GNU/GPL

proprietarni SW
?
obvykle bez pristupu ke kodu, neda se upravovat
typy: komercni SW (v EU obchodovani s jiz pouzitymi licencemi je povoleno), OEM (Original Equipment Manufacturer; SW dodavany jako komponenta subdodavatelem, vyrobce ho muze dal prodavat pod svoji znackou), shareware (obvykle spojeni trial->nakup licence), freeware (dobrovolne prispevky), public domain (mozne sirit a upravovat, je i v jinych oborech)

SaaS
?
Software as a Service, cloudovy SW, nic neni treba instalovat ani udrzovat, nutno mit internet k pouzivani

malware
?
SW urceny k proniknuti do systemu nebo jeho poskozeni, malicious SW
vir, spyware, keyloggers, adware,...

### Pocitacova grafika

typy pocitacove grafiky
?
vektorova (z objektu) a bitmapovani (z bitu)

bitmapova grafika
?
obrazek rozlozen do malych bodu = pixel, usporadane do mrizky
pixel uchovava informace o barve, rozliseni,...
:) lze robrazovat i slozite predlohy, snadne porizeni
:( velky objem dat, ztrata informaci pri upravach

bitmapovy SW
?
gimp (open-source, free), Adobe Photoshop (zakladni kresleni, vybery, tvorby, zmeny barvy, vrstvy,...), Malovani, InfraView (prohlizeni, lehke upravy, nakresleni jednoducheho obrazce, komprese)

bitmapove formaty
?
.jpg, .jpeg - rozdeli obrazek na ctverce 8x8, komprimace s kosinovou transformaci (ztrate detailu, kompresni artefakty kolem hran), vhodne na foto, nevhodne pro texty s ostrou hranou 
.gif - patent (od 1995 potreba licence), pouze 8bitu kodovani barev, nevhodne pro foto, vhodne ne obrazky s malym poctem barev, umi animace
.png - patentove nechraneny format, 1-64 bitu/pixel, umi i pruhlednost, nevhodne pro foto, obvykle pro skenovani dokumentu
.bmp - ulozeni nekomprimovanych dat, 1/4/8/24 bitu/pixel, uz se skoro nepouziva; .tiff - lepsi nez .bmp, umi i kompresi
.xcf - format gimpu, podporuje vrstvy; .psd - Photoshop format

vektorova grafika
?
obrazek z nekolika jasne definovanych objektu (bod, primka, krivna), reprezentace rozmery a umistenim
:) libovolne skalovani, mozno pracovat s jednotlivymi objekty, mensi pametova narocnost
:( nevhodny pro zapis slozitych barevnych ploch, slozitejsi na porizeni obrazku

vektorove SW
?
svobodny: Inkscape, OpenOfficeDraw
proprietarni: Adobe Illustrator, Coredraw, Zoner, CAD,...

vektorove formaty (ne pro multimediove kontejnery)
?
nativni: .ai (Adobe Illustrator), .cdr (Corel Draw), .zmt (Zoner callisto)
aplikacne nezavisle formaty: .svg, .psa, .eps (postscrit, pro tiskarny), .odf
jednotlive formaty maji ruzny pristup k objektum -> slozity prenos

vektorove multimedialni kontejnery
?
jedna/vice stop (zvuk, video, text s titulky)
do kontejneru lze ukladat data v ruznych formatech

formaty vektorovych multumedialnich kontejneru
?
.avi - zastaraly, vysoka kompatibilita, digitalni foto
.mpeg - Motion Picture Experts Group, vice formatu a kontejneru, bitmap 24bit/pixel, max 4096x4096 obrazovych bodu, max 30 snimku, kosinova ztratova komprese
.heif, .heic, .hevc - foto v telefonech, F - titulky a zvuk, VC - video s pouzitim DVB-T2
.mp3 - MPEG-1, MPEG-2, hlavne hudba na PC, princip casoveho a frekvencniho mapovani, ztratova komprese, nevhodny pro mluvenou rec
.mp4 - MPEG-4 part 14, nastupce .avi, vice titulku/zvukovych stop/3D objektu, streamovane videa, mp3 komprese, vychazi z nej 3GPP na mobilech 
.vp9 - od Google, otevreny, podpora browseru, mobily, tablety, telefize, kamery,...
.ogg - projekt pro tvorbu svobodneho SW -> .oflac, .ogg, .opus, .speex, .ogv

RBG, CMYK,...
?
RBG - 3 barevne svetla - Red+Blue+Green, skladani, monitory
CMYK - Cyanth+Magenta+Yellow+Key, na barevne pigmenty svitime bilym svetlem, neco se obrazi neco se pohlti, na tisk
taky: HSV (HueSaturationValue), HSB (Brightness), HSL (Lumination), HSI (Intensity),...

barevny gamut
?
barvy dosazitelne v prislusnem modelu, mimo model se barvy zobrazi pouze priblizne -> gamut zarizeni - barvy ktere je zarizeni schopno zobrazit


### Podnikove informacni systemy

Podnikovy informacni sytem (EIS = Enterprise Information System) (definice, ucel, cil)
?
= k podpore rizeni, koordinace disponibilnich podnikovych zdroju a aktivit, propojuje podnikove procesy
ucel: sprava informaci a znalosti a integrace do podnikovych procesu, celistvy pohleld na financovani organizace, zisk a zpracovani informaci potrebnych k manazerskemu rozhodovani
cil: zvyseni celkove efektivity a navaznosti pracovnich procesu, zlepseni pracovnich navyku a chovani useru

historie EIS
?
MRP (= Material Resource Planning) - 60.leta 20. stoleti, vazano na konkretni HW, neinteraktivni, jeden system, pouze planovani materialu 
MRP II. - 80.l.20.stoleti, vazano na konkretni OS, klient-server, textovy modularni system, rizeni a optimalizace vyroby, HR
ERP (= Enterprise Resource Planning) - 90.l.20.stoleti, prenositelnost mezi OS, DB-server-klient, GUI, rizeni i nevyrobnich podniku, optimalizace, systemy na miru
ERP II. - zacatek 21.stoleti, real-time access, multimedia, webapps, dodavatelsko-odberatelske retezce, CRM, BI (Business Intelligence), propojene systemy
postmodern ERP - dnes, vicevrstve, cloud, prozakaznicky orientovane, balikove systemy pro ruzne podniky

oblasti postmoder EPR
?
finance - ucetnictvni vs managerske, sprava podnihovych aktiv (EAM = Enteprise Asset Management)
HR - HRM - pracovni doba, mzdy, skoleni, benefity, komunikace
vyroba, logistika, provoz, projektovani - rizeni kvality, procesu, jakosti, IT; planovani vyroby, zasoby skladu, rizeni dodavatelskeho retezce (SCM = Supply Chain Mgmt, SRM = Supplier Relation Mgmt), sprava majetku
marketing a prodej - PIM (Product Information Mgmt), CRM (Customer Relation Mgmt - rizeni vztahu se zakazniky), cenova politika, rizeni a zpracovani objednavek, servis

zakladni moduly postmoder EPR
?
BI+CRM+SCM
casta kombinace HRM+EAM (Enterprise Asset Mgmt)+ECM (Enterprise Content Mgmt)

vyrobci EIS
?
SAP - 1.verze v 60.l.20.stoleti, ruzne OS a DB, NetWeaver, BusinessOne, SAP R/3
ORACLE - EPR - E-Business Suite, Cloud ERP
Infor, Microsoft, IBM, Asecco Solution, ABRA,...

### eGovernment

eGovernment
?
vuuziti informaci a komunikacnich technologii s cilem zlepseni a nebo posileni ucinnosti a efektivity poskytovanych sluzeb ve verejnem sektoru

komunikacni kanaly eGovernmentu
?
G2B, G2C, C2G, G2E, G2G

uskali eGovernmentu
?
koexistence elektronicke a neelektonicke komunikace, rovny pristup vsech obyvetelu k eletro sluzbam, bezpecnost, ochrana pred zneuzitim

pristup k informacim a komunikace eGovernmentu
?
datova schranka, zakladni registry, CzechPoint, informativni webove strankyy, verejna sprava, elektronicke podpisy

datova schranka - uvod a technicne reseni
?
ISDS = Integrovany System Datovych Schranek - informacni system verejne spravy, zrizene podle zakona c 300/2008, elektronicke uloziste zvlastniho typu, stavy: funcni, neexistuje, znepristupnena a zrusena
zrizuje a spravuje MVCR, provozovatel je CeskaPosta
webapp ~ SOAP+HTTPs, dalsi proprietarni SW pro komunikaci
bezpecnost - ID+heslo (5 pokusu/hodina, potom deaktivace), po 30minutach neaktivity odhlaseni, OTP (mobilni klid ISDS, cip na obcance, auth cert)

datova zprava datove schranky
?
obsahuje elektronickou znacku (e-razitko) a casovou znacku (kvalifikovane casove razitko)
telo obsahuje formu prilohy, pro vlozeni zpravy - avizo SMS (za penize), nebo email (zadarmo)

vlastnosti datove schranky
?
neomezena velikost, dorucenka (potvrzeni doruceni, precteni, fikce doruceni), od precteni se zprava uchovava 90 dnu (pro delsi platnost: datovy trezor, datove uloziste)

pravni uprava elektronicky ukonu eGovernmentu
?
zavaznost - pravni vaha stejna jako u fyzickeho doruceni do vlastnich rukou
garantovane doruceni - doruceni = adresat se prihlasi do sve datovky
pravni fikce doruceni - pokud se adresat do 10 dnu neprihlasi, zprava je povazovana do dorucenou
pomijivost - zpravy se po 90 dnech mazou
pokuty - 10M za nevyzadany dokument, 20M za skodlivy SW

ISZR = Integrovany System Zakladnich Registru
?
spravce MVRT, prvozovatel Spravce Zakladnich Registru, spravce Urad pro Ochranu Osobnich Udaju
ORG = prevodnik identifikatoru fyzickych osob - ochrana osobnich udaju v registrech - nepouziva se RC, v kazdem systemu je jiny identifikator, v ORG pouze ID

registry ISZD
?
registr osob - spravuje Cesky Statisticky Urad, eviduje udaje o fyzickych a pravnich osobach a organech verejne moci
registr obyvatel - spravuje MVCR, eviduje aktualni udaje o obcanech CR, cizincich s povolenim k pobytu a zahranicnich vlasnicich nemovitosti
registr uzemni identifikace adres a nemovitosti - spravuje Cesky Urad Zememericsky a Katastralni, udaje o zakladnich uzemnich prvcich
registr prav a povinnosti - spravce MVCR, evidence udaju o pusobnosti organu statni moci, pravech a povinnostech osob

CzechPoint
?
cesky podaci, overovaci a informacni nerodni terminal
asistovane misto vykonu verejske moci - kdokoli muze ziskat informace o udajich ktere o nem stat vede, lze ucinit podani ke statu

Czech Point - vystupy
?
overene vystupy z registru (zivnostensky, obchodni, katastr nemovitosti, trestu)
overeni podpisu, automaticka konverze dokumentu z/do elektronicke podoby a zaslani do datovky (autorizovany, overuje se specialnim podpisem, presne specifikovane kdo to muze delat) 

### IT Governance

IT Governance
?
nastaveni pravidel ve kterych muzou ostatni efektivne pracovat
vs Management - pravidelna cinnost obsahujici provozni rozhodnuti v ramci danych pravidel
soucasti je i merici a kontrolni system
cil: vybavit firmu/organizaci jasne definovavymi pravidly pro efektivni plneni cilu
<!--SR:!2024-06-05,1,230-->

role ve firme/organizaci
?
vlastnik - otazky a naslouchani
manager - chain of command, carrot & stick
Board of Directors - vybira je majitel (ne CEO), lidi s ruznymi zkusenostmi a transparetni minulosti, 

co se ocekava od board of directors
?
challenging executive management, managing risk, steering on long term & strategic level

corporate (enterprise) governance
?
system, kterym je vedena cela spolecnost - definuje distribuci prav a povinnosti mezi zainterestovanymi stranami spolecnosti (akcionari, vykonny management, statutarni organy, zamestnanci, zakaznici)
soubor pravnich a exekutivnich metod a postupu zavazujici zejmena verejne obchodovatelne spolecnost udrzovat vyvazeny zvtah mezi spolecnosti a osobami kteri ji tvori
IT governance je podmnozinou

historie IT governance
?
do 1996 - audit IT, co ma IT delat
do 1998 - rizeni IT, co ma mamangement ocekavat od IT
kolem 2000 - vykonnost IT, jak to merit
kolem 2005 - IT Governance, zavadeni pravidel pro IT
kolem 2012 - tesne propojeni business a IT (~ EGIT)

EGIT = Enterprise Governance IT
?
pokryva vsechny pozadovane procesy a IT zdroje tak aby IT vhodne podporovalo spolecnosti pri vytvareni hodnot a naplnovani ocekavani zaintersovanych stran
oblasti: risk managemnt, performance management, IT strategic alighment, IT value delivery
ocekavani: zvyseni transparentnosti, dosazeni souladu s relevantnimi zakony, regulacemi a politikami, nastaveni kontrolnich mechanizmu a reportovani, vcasna identifikace a elimikace rizika vyplivajici z IT, zlepseni rizeni IT v souladu s best practise

propojeni businessu a IT
?
Enterprise Balance Source Card = metoda vytvarejini vazbu mezi strategii a operativnimi cinnostmi s durazem na mereni vykonu;; finance->procesy->uceni se a rust->zakaznim->financee->...
IT BSC - tabulky s objectives a measures, cile, projekty a aktivity ktere tyto cile a jejich dozazeni zajitit

system
?
celek slozeny z casti ktere na sebe vzajemne pusobi, mezi castmi mohou byt toky informaci a energie

rozdeleni systemovych metod rizeni
?
otevrene vs uzavrene, deterministicke vs stochasticke, spojite vs diskretni, staticke vs dynamicke, mekke vs tvrde (dobre strukturovane vs nepresne definovane)
fishbone diagram
Occamova britva

COBIT
?
uzivatele: manageri, auditori, vlastnici, IT a sec specialiste,...
audit (1996) + control (1998) + management (2000) + IT governance (2005/2007) + governance of IT enterprise (2012)
framework na enabling processes a implementace

proces
?
ucelne neplanovani a relalizovana posloupnost cinnosti ve kterem za pomoci odpovidajicich zdroju probita transformace vstupu na pozadovane vystupy

procesni rizeni
?
vs projektove rizeni = jednorazova zmena
podnikove procesy: hlavni - vedlejsi - podpurne
zralost a CMMI (= Capability Maturity Model Integration) - neexistujici -> nahodny -> formalizovany -> meritelny -> optimalizovatelny

zlepsovani procesu
?
eliminace zbytecnych cinnosti, paralelizace cinnosti, centralizace ztroju, spojovani cinnosti, jedno kontaktni misto, delegace pravomoci, duvera mezi subjekty, zvyseni urovne znalosti pracovniku, automatizace

Business Process Management = BPM
?
snaha o uchopeni struktury firmy, jeji architektury a rizeni prostrednictvim podnikoveho modelu zachycujici zakladni rozmery podnikani (cile, hodnotvorne procesu, informacni, organizacni a znalosti infrastruktura, podpurne technologie)
rada nastroju a metod

ITIL - v3 vs v4
?
v3 - lifecycle view - 26 procesu v 5 domenach (service strategy, service design, service transition, service operations, continual service improvement)
v4 - comprehensive, reflects changing world of IT

organizacni modely
?
zakladni fce a procesy management: planovani, organizovani, personalni zajistovani, vedeni a motivace, kontrolovani
deleni: stabilni vs fleziboni struktura, alternativni (cloud)

informacni model podniku
?
pyramida: technologie -> data -> applikace -> informace -> business
data (fakta popisujici realitu nezaujate) -> informace (data v kontextu) -> znalost (informace s vyznamem, pro prakticke rozhodovani situace) -> moudrost (znalost + vhled)

Data Security Life-cycle
?
Create -> Store -> Use -> Share -> Archive -> Destroy -> ...

organizovani
?
kazdy system hleda rovnovahu
-> omezeni rozmanitosti systemu, struktura, teorie chaosu a prechodove jevy. dynamicka rovnovaha

projektove rizeni
?
WBS = Work Breakdown Structure
OBS = Organization BS
Agile vs Waterfall
Gantt Chart - pruhovy diagram, graficke znazorneni naplanovani posloupnosti cinnosti v case

rizeni lidi
?
management vs leadership

rizeni tymu
?
typy tymu: diverzita, samotatnost, lokalizace, typologie clenu, pracovni role
nastroje - startup, sociomapovani

risk management
?
identification-assessment-mitigation plan-implementation & monitoring-review & update plans

protection
?
perimetr, data & privacy, process, application
security consulting - risk analysis, security audit, IT Governance,...

etika
?
prakticka filozofie, hleda odpoved na otazku jak spravne zit
individualni moralka, spolecensky mrav, hledani nejlepsiho
aplikovana etika, podnikatelska etika

firemni kultura
?
zmena: analyza situace -> tvorba vize -> projekt zmeny
akteri: iniciatori, leafer, reprezentanti, podporovatele, odpurni, neutralni
nastroje: vize, projekt zmen, personalni a organizacni zmeny, vzdelani s vycvik, zmeny v odmenovani a pridelovani zdroju, technicka zmena

firemni dokumenty
?
smlouvy, zapisy z jednani, organizacni normy, prodejni a reklamni dokumentace, projetova dokumentace, ...
rizena vs nerizena

Enterprise Content Management (ECM)
?
podnikovy IS zabyvajici se spravou podnikovych informaci
cile: zajistovani dostupnosti informaci, zvyseni informacni bezpecnosti, snicheni chybovosti, uspory
elektronicke, papirove dokumenty, rizeni a sprava veskereho informacniho obsahu
strkturovana vs nestruktorovana data, vsechny typy elektronickych dokumentu, proces digitalizace

normy - kaskady vzniku
?
globalni kaskada impupzu pro vznik/zmenu norem: EU uroven -> CR uroven -> firemni uroven
firemni kaskada: complience, best practise, quality management

norma o norme
?
zakladni norma o tom jak psat normy (tvori se jako prvni)
stanovi e struktura obsahu a forma

normy - vyznam
?
tvorba normativniho modelu organizace (pravidla o tom jak ma stravne fungovat aby splnila sve cile)
v souladu s normou se tvori a upravuje system rizeni organizace
nastaveni normativniho chovani jje efektivni ale pozor na balanc formalnosti vs kreativity

normy - druhy
?
smernice, narizeni, rozhodnuti reditele, opatreni, normativni smernice, rad,...
kategorizace podnikovych norem: pravni, technicke, ekonomicko-provozni, organizacni, ridici,...


### Informacni bezpecnost a kryptografie

### Zaklady odborne prace

analyticke mysleni
?
rozdeleni celku na samostatne casti a zabyvani se jimi zvlast

synteticke mysleni
?
snaha o poskladani a potom pochopeni celku

informacni etika
?
vytvareni hranic a definic
nutno informacim porozumet, overit a pak pouzit v kontextu

citace
?
norma APA (ISO 690) - povinne: autor, nazev dila, rok vydani, misto, nakladatelstvi
nutno uvest vsechny pouzite zdroje, presne a uplne citace, odkazy v textu do seznamu literatury
doslovna vs parafraze

struktura odborne prace
?
uvod-metody-vysledky-diskuze
uvod - proc bylo tema zvoleno, zasadit do kontextu, necisluje se
abstrakt (anotace, teze), klicova slova
text-zaver-seznam literatury a zdroju
metodika - promysleny postup pri praci


## PDF
![[Repetitorium-pro-Informacni-management.pdf]]
