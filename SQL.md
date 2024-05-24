Prezentace: 
	Cast z: [[hand-les05-transformace.pdf]], [[hand-les04-sql-select-1.pdf]], [[hand-les06-sql-select-2.pdf]] a [[hand-les07-sql-dml-ddl-dcl-tcl.pdf]]

### Poznamky
- rikame co ma byt vysledek - ne, jak to ziskat
- non-case sensitive
- ZASADNI rozdil mezi `'` a `"`
- hodne standardizaci (1986, **1992** - SQL 2, 1999, 2003, 2005, 2008, 2011,...)
	- nejvetsi odchylky v datovych typech
	- postupne se na sebe nabaluji (OO, XML,...)

- integritni omezeni (IO)
	- sloupce: NOT NULL, DEFAULT, UNIQUE (alternativni klic), PRIMARY KEY, REFERENCES (cizy klic), CHECK
	- tabulky: stejne jako IO sloupce
	- je vhodne si IO pojmenovat
	- ```
	create table items {
		order_id integer,
		item_id integer,
		amount integer,
		constraint items_pk primary key (order_id, item_id),
		constraint items_pk forein_key (order_id) references orders
			on delete cascade
			on update cascade
		};
	- PRIKLAD: integritni omezeni pro tvoreni tabulky
		- order_id a item_id jsou primarni klice
			- primarni klice jsou unikatni a not NULL!
		- order_id je forein_key (relacni klic - vytvari relaci) a zavislosti se na delete a update taky oddelaji
- SQL komentar `--`
- datove typy
	- numericke (Int), textove (Char, Character), datum a cas, NULL, ...
- prechod z relacni algebry do SQL je vice ukazany na slidech
	- ![[Pasted image 20230215173945.png]]
	- ![[Pasted image 20230215174055.png]]

#### Navrh ukazkove databaze
![[Pasted image 20230215162931.png]]
#### Jazyk pro dotazovani se na data (DQL - Data Query Language)
##### SELECT
- `SELECT co FROM odkud [WHERE podminka] [ORDER BY razeni]`
	- `co` -> {DISTINCT | <u>ALL</u> }  * | {nazev_sloupce \[, nazev_sloupce\]...}
		- DISTINCT se vztahuje na celou SELECT klauzuli
- porovnavaci operatory: `=, !=, <, >, <=, >=, BETWEEN, IN, LIKE, EXISTS`
	- s WHERE muzeme pouzit i `AND, OR, NOT`
		- WHERE se vyhodnocuje jako T/F
	- `LIKE` - je v seznamu hodnot
	- `EXISTS` - je splnen poddotaz
- spojeni s JOIN
	- `misto1 [{LEFT | RIGHT | FULL} [OUTER]] JOIN misto2 ON (podminka)`	
	- `misto1 [{LEFT | RIGHT | FULL} [OUTER]] JOIN misto2 USING (seznam_sloupcu)`
	- `misto1 [{LEFT | RIGHT | FULL} [OUTER]] NATURAL JOIN misto2`
	- `misto1 CROSS JOIN misto2`
		- kartezsky soucin
		- `misto1 , misto2`
	- vnejsi spojeni (outer join)
		- normalni spojeni + leva/prava/obe relace dodaji n-tice kter na "druhe" strane nemaji partnera
	- semi-join
		-  v RA!
		- redukce n-tic na ty ktere jsou spojitelne s nejakou n-tici druhe relace
	- anti-join
		- v RA1 
		- doplnek - redukce n-tic na ty ktere NEjsou spojitelne s zadnou n-tici druhe relace
- kvalifikace, aliasy
	- `SELECT Predstaveni.nazev_k, Filmy.* FROM Filmy F JOIN Predstaveni P ON (F.nazev_f = P.nazev_f) ORDER BY P.nazev_k;`
- spojeni tabulky samo se sebou
	- `SELECT soused1.rod_c AS prvni, soused2.rod_c AS druhy FROM zakaznici soused1 JOIN zakaznici soused2 USING (adresa) WHERE soused1.rod_c < soused2.rod_c;`
		- najdi dvojici zakazniku kteri maji stejnou adresu
- agregacni funkce
	- relacni algebra to uz neumi
	- `COUNT` - bere mnozinu n-tic vyhazuje jednu hodnotu
		- pocet prvku v mnozine
		- `SELECT COUNT(*) FROM filmy WHERE rok BETWEEN 1938 AND 1940;`
		- kolik unikatnich hodnot: `SELECT COUNT (DISTINCT *) FROM rezervace`
		- `COUNT(prazdna_mnozina)=0`
	- `AVG` - prumer
		- `SELECT AVG(cena) FROM vypujcky` - prumerna cena vypujcky (bez ceny NULL)
	- `SUM`, `MIN`, `MAX`,...
	- je potreba davat pozor na hodnotu NULL
		- v `SUM` bude pak vzdycky NULL
- `GROUP BY`
	- seskupovani radku
	- `SELECT jmeno_f, COUNT (rod_c_herce) AS pocet_hercu FROM obsazeni GROUP BY jmeno_f`
		- pro kazdy film spocitat pocet hercu kteri v tom filmu hraji
- `HAVING`
	- `SELECT jmeno_f, COUNT (herec) AS pocet_hercu FROM obsazeni GROUP BY jmeno_f HAVING COUNT (herec)>1`
		- pro kazdy film spocitat pocet hercu kteri v tom filmu hraji + zobraz pouze takove filmy kde hraje 2 a vice hercu
- poradi vyhodnocovani
	- najdi pro kazdy film z roku 1945 pocet hercu kteri v nem hraji + ve vysledku nechat filmy jde jsou dva a vice hercu + vysledek serad podle poctu hercu
		- ```sql
			SELECT filmy.jmeno_f, COUNT (herec) AS pocet_hercu
			FROM obsazeni JOIN filmy USING (jmeno_f)
			WHERE filmy.rok == 1945
			GROUP BY filmy.jmeno_f
			HAVING COUNT (herec) >= 2
			ORDER BY pocet_hercu;
		- poradi kroku: 1. FROM (zdroj a JOIN), 2. WHERE (selekce), 3. GROUP BY (seskupeni), 4. SELECT (agregacni funkci podle vysledku GROUP BY), 5. HAVING (selekce na vysledky agregacni funkce), 6. ORDER BY (razeni)
- vnorene dotazy
	- relacni algebra to neumi
	- vztazene vs nevztazene poddtazy (correlated vs non-correlated subqueries)
	- nevztazene
		- vyber filmy ktere maji stejneho rezisera jako ma film Svadlenka (ve WHERE)
			- ```sql
				SELECT F1.jmeno_f
				FROM filmy F1
				WHERE F1.reziser = (SELECT reziser 
								    FROM filmy F2
								    WHERE F2.jmeno_f = 'Svadlenka');
		- nejvyssi cena vypujcky a ktere vypucky se na takovou cenu uskutecnili
			- `SELECT * FROM vypujcky WHERE cena = (SELECT MAX(cena) FROM vypujcky)`
	- vztazene poddotazy
		- vyhodnoceni "je drazsi"
		- vyber jmena a adresy kin kde maji na programu vice nez 8 fimu
			- ```sql
				SELECT k.nazev_k, k.adresa
				FROM kina k 
				WHERE (SELECT COUNT(jmeno_f) 
					   FROM predstaveni P
					   WHERE p.nazev_k=k.nazev_k) > 8;`
	- poddotaz v klauzuli SELECT
		- vypis seznam vsech filmu a u kazdeho uved pocet jeho kopii
			- vysledkem jsou i filmy bez kopii
			- ```sql
				SELECT F.*,(SELECT COUNT (c_kopie)
							FROM kopie k
							WHERE k.jmeno_f=f.jmeno_f) as pocet_kopii
				FROM filmy f;
	- poddotaz v klauzuli FROM
		- najdi prumernou cenu z minimalnich cen kopii pro kazdeho zakaznika
			- ```sql
				SELECT AVG(t.minim_c)
				FROM (SELECT MIN(cena)
					FROM vypujcky
					GROUP BY rod_c) AS T(minim_c);
- vnejsi spojeni
	- taky **dulezite**, taky za moznostma relacni algebry
	- napr: vypis seznam vsech filmu a u kazdeho uved pocet jeho kopii a dej tam i filmy bez kopii (ale pomoci vnejsiho spojeni ne vnoreneho poddotazu)
		- ```sql
			SELECT jmeno_f, COUNT (c_kopie) as pocet_kopii
			FROM kopie k RIGHT OUTER JOIN filmy USING (jmeno_f)
			GROUP BY jmeno_f;
- agregace a prazdne mnoziny
	- napr: najdi vedouci kin kteri maji zaregistrovane vypujcky kopii na mene nez 2000
		- ```sql
			SELECT DISTINCT jmeno_v
			FROM kina k JOIN zakaznici z (k.jmeno_v=z.jmeno)
			WHERE (SELECT SUM (v.cena)
					FROM vypujcky v
					WHERE v.rod_c = z.rod_c) < 2000;
- CASE
	- `CASE <prepinac> WHEN <hodnota1> THEN <vyraz1> WHEN <hodnota2> THEN <vyraz2> ELSE <vyraz3> END`
	- libovolny pocet argumentu
	- napr: hraje se nekde film Falesna kocicka + chceme specificke odpovedi
		- ```sql
			SELECT 'Film falesna kocicka se' ||
				(CASE COUNT(**)
				WHEN 0 THEN ' ne'
				ELSE ' '
				END) || 'hraje'
			FROM predstaveni
			WHERE jmeno_f='Falesna kocicka';
- COALESCE
	- podobna jako CASE ale `WHEN <hodnota> IS NOT NULL THEN <vyraz>`
	- napr: nekteri zamestnanci nemaji plat, vypis seznam a misto NULL zobraz 0
		- `SELECT osobni_c, jmeno COALESCE (PLAT,0) AS mesicni_prijem FROM zamestnanci;`
- LIKE
		- napr: najdi platy zamestnancu kteri jsou z kolina
			- `SELECT z.plat FROM zamestnanci z WHERE z.adresa LIKE '%Kol_n'`
		- `%` skupina znaku, `_` prave jeden znak
		- `ESCAPE` - zruseni specialnich znaku
- radkove vyrazy
	- napr: `(r.cena, r.datum) = (s.cena, s.datum)` atd (s `=, <, >,...`)
- IS NULL
	- `IS [NOT] NULL` (`IS [NOT] TRUE`, `IS [NOT] FALSE` se spise nepozivaji)
	- napr. vypujcky na nekonecne dlouho: `SELECT c_zak FROM vypujcky WHERE datum_v IS NULL;`
- mnozinovy predikat IN
	- napr: najdi filmy podle seznamu reziseru: `SELECT jmeno_f FROM filmy WHERE reziser IN ('Menzel', 'Chytilova', 'Kachyna');`
- ANY, ALL, SOME
	- `> SOME`, `< SOME`, `<> SOME`, `= SOME`
	- `> ALL`, `< ALL`, `<> ALL`, `= ALL`
	- `ANY == SOME`, `SOME == IN`, `<> ALL == NOT IN`
- UNIQUE
	- `UNIQUE(prazdna_mnozina) == TRUE`, `UNIQUE(NULL) == TRUE` (EXISTS to ma naopal)
	- napr: jmena a adresy zakazniku kteri maji nejvyse jednu vypujcku
		- ```sql
			SELECT z.jmeno, z.adresa
			FROM zakaznici z
			WHERE UNIQUE (SELECT *
						FROM vypujcka v
						WHERE v.rod_c=z.rod_c);
- kvantifikace
	- existencni kvantifikator `[NOT] EXISTS`
	- casto implementovane pomoci dvojite negace: (∀x)(P(x)) ≡ ¬(∃x)(¬P(x))
	- napr: jmena zakazniku kteri maji rezervovany film
		- ```sql
			SELECT jmeno
			FROM zakaznik z
			WHERE EXISTS (SELECT 1
						FROM rezervace
						WHERE rod_c=z.rod_c);
- mnozinove operace
	- **dulezite**, diky tomu je SQL silnejsi nez RA
	- UNION
	- INTERSECT
	- EXCEPT (v Oracle MINUS)
	- UNION ALL
	- napr:
		- kina ktera nic nehraji - `(SELECT nazev_k FROM kina) EXCEPT (SELECT nazev_k FROM predstaveni);`
		- filmy ktere jsou rezervovane nebo pujcene: `(SELECT jmeno_f FROM rezervace) UNION (SELECT jmeno_f FROM vypujcky JOIN filmu USING(c_kopie));`
		- filmy ktere jsou rezervovane a pujcene: `(SELECT jmeno_f FROM rezervace) INTERSECT (SELECT jmeno_f FROM vypujcky JOIN filmu USING(c_kopie));`
		- filmy ktere jsou rezervovane a nejsou pujcene: `(SELECT jmeno_f FROM rezervace) EXCEPT (SELECT jmeno_f FROM vypujcky JOIN filmu USING(c_kopie));`
- napr: 
	- `SELECT reziser, rok FROM filmy;` - muze obsahovat duplicity (zalezi na zdroji)
	- `SELECT reziset, rok FROM filmy ORDER BY reziser, rok;` - razi se podle rezisera, pak roku (A->Z, 1->...)
		-  `SELECT reziset, rok FROM filmy ORDER BY reziser ASC, rok DESC;` - reziser (A->Z), rok (...->1)
	- `SELECT DISTINCT reziser, rok FROM filmy;` - oddelaji se duplicity z prvniho prikladu
	- `SELECT * FROM filmy WHERE rok < 1940` - vsechny filmy pred 1940
	- `SELECT * FROM filmy WHERE rok>=1938 AND rok<=1940;`
		- da se napsat jako:  `SELECT * FROM filmy WHERE rok BETWEEN 1938 AND 1940;`
			- nebo treba `NOT BETWEEN`, haha spousta moznosti
	- `SELECT DISTINCT reziser FROM filmy JOIN rezervace ON (filmy.nazev_f=rezervace.nazev_f);`
		- alternativa1: `SELECT DISTINCT reziser FROM filmy JOIN rezervace USING (nazev_f);` 
		- alternativa2: `SELECT DISTINCT reziser FROM filmy NATURAL JOIN rezervace;`
		- alternativa3: `SELECT DISTINCT reziser FROM filmy, rezervace WHERE filmy.nazev_f=rezervace.nazev_f;`
	- 

#### Jazyk pro definici dat (DDL - Data Definition Language)
- CREATE TABLE
	- `CREATE TABLE tabulka ( sloupec datovy_typ [ io_sloupce, [ io_sloupce ]], ... );`
- ALTER TABLE
	- `ADD sloupec, DROP sloupec, ALTER sloupec, ADD CONSTRAINT io, DROP CONSTRAINT io`
- DROP TABLE
	- `DROP TABLE tabulka [CASCADE];`
	- pokud se pouzije bez CASCADE a na tabulce je zavisla jina tabulka, tak vyhodi chybu -> musi se pustit s CASCADE
- TRUNCATE

#### Jazyk pro manipulaci dat (DML - Data Manipulation Language)
- INSERT
- UPDATE
- DELETE
- CALL
- EXPLAIN CALL
- LOCK
#### Jazyk pro prirazeni pristupovych prav (DCL - Data Control Language)
- GRANT
- REVOKE
#### Jazyk pro rizeni transakci (TCL - Transaction Control Language)
- COMMIT
- SAVEPOINT
- ROLLBACK
- SET transaction
- SET Contstraint