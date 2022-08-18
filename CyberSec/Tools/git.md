- version control
	- VCS = Version Control System
- lokalni systemy zpravy verzi - `rcs`
- centralizovane systemy spravy verzi
	- maji i serverovou cast
	- napr. CVS, Subversion, Perforce
	- single point of failure - server na kterem bydli
- distribuovane systemy spravy verzi (DVCS)
	- napr git, Mercurial, Bazaar, Darcs
	- uzivatele nestahuje pouze posledni verzi souboru ale kompletni kopii repa
	- lokalni kopie = checkout

## Git

- jadro Linuxu se vyvyjelo postupne (patche, archivy), zacal se pouzivat Bit-Keeper (2002, jako DVCS), pak se komunika a BitKeeper pohadali, BitKeeper prestal by zadarmo a komunita si vyvinula vlastni nastroj (2005)
- pozadovane vlastnosti:
	- rychlost, jednoduchy design, silna podpora nelinealniho vyvoje (tisice paralelnich vetvi), plna distribuovatelnost, schopnost efektivne spravovat velke projekty (jako linuxove jadro :D)

- ostani VCS (Subversion,...) se divaji na spravu/zmeny soubory jinak nez git
	- Git - sada snimku, pokud soubor nebyl zmenen git neuklada cely soubor znova ale pouze odkaz na identicky soubor predchoziho ulozeni
	- ![[Pasted image 20220818151106.png]]
	- ostatni - seznamy zmen
- => 1.3.3