#server-side

- also path traversal
- vulnerability letting the attacker to reaf arbitrary files on the server where the webapp is running
- common obstacles:
	- absolute vs relative path → filename=`/etc/passwd` or `../../../etc/passwd`
	- nested traversal sequences - `....//` or `....\/`
	- encoding → `/ is &252f`
	- requiring the path starting with expected base folder → `filename=/img/web_images/../../etc/passwd`
	- requiring the path ending with specific extension - adding zero byte → `filename=/etc/passwd%00.jgp`

- how to prevent this attack:
	- avoid passing user-supplied input to filesystem APIs, if this cannot be avoided:
		- validating the user input before processing it
		- validate the canonical path