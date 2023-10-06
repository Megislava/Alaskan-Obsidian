<<<<<<< HEAD
### UNIX
- OS developed by AT&T Bell Labs in 1970s
- written in C
- now owned by Open Group

### Linux
- = combination of softwares GNU/Linux → OS
	- GNU = free SW providing common UNIX commands
	- Linux - Linux kernel (core of the OS) loaded at boot time and stays running to manage the system
- 1991 - Linus Torvalds
- before  - GNU Project - Richard Stallman (1983)
- open source (duh)
- different flavors  → distributions
	- combination of diffrent kernel, tools a apps
- CLI and GNU

![[Pasted image 20220906151000.png]]


##### Distributions
RedHat
- started as RedHat Package Manager (RPM)
- later shift to server apps → Red Hat Enterprise Linux (RHEL)
	- paid, released on a long release cycle 
	- recompiled RHEL packages → CentOS
		- compatible with RHEL, newer SW, for free
- for shorter release cycle → Fedora Project
- Scientific Linux

SUSE
- originally derived from Slackware
- contains proprietary code → paid
	- openSUSE - open, free, desktop packages similar to CentOS and LinuxMint

Debian
- community product, open source
- ofiginal package management system- `.deb`
- Ubuntu
	- most popular Debian-derived distro
	- made by Canonical
		- makes money from providing support
	- Linux Mint
		- fork of Ubuntu

Android
- sponsored by Google
- uses Dalvik VM with Linux
- for mobile phones and tablets
- generally incompatible with other Linux distros

Others 
- Rasphian
	- for Raspberry Pi
- Linux from Scratch (LFS)

![[Pasted image 20220906160054.png]]

- kernel - air traffic controller
	- decides which program gets blocks of memory, starts and kills apps, handles displaying text/graphics on a monitor
	- can switch between applications - multitasking
	- no difference between process and application (from the point of view of kernel)
- applications - airplanes under it's control
	- makes requests to the kernel, can receive resources (memory, CPU, disk space)


##### Software, processes, tools, application
- server apps
	- no direct communication w/ monitor/keyboard
	- to serve information to other computers (clients)
	- often for hosting web app - web server
		- WordPress, Apache (Apache Software Foundation, Apache HTTPD - deamon/server app programm "serving" web page requests), NGINX
	- private cloud servers (ownCloud, NextCloud), DB servers (MariaDB, Firebird, PostgreSQL)
	- email servers
		- Mail Transfer Agent - Sendmail, Postfix
		- Mail Delivery Agent- Local Delivery Agent = takes care of storing user's emails
		- POP/IMAP Server - Post Office Protocol and Internet Message Access Protocol; eg. Dovecot, Cyrus IMAP, Microsoft Exchange
	- file sharing
		- Samba (allows Linux machine to look and behave like Windows so it can join Windows domain), Netatalk (Linux → Apple Macintosh file server), NFS (Network File System, native file sharing in Linux)
- desktop apps
	- web browser, text editors, .... - apps interacting with user
	- email - Thunderbild, Evolution, KMail; creative - Blender, GIMP, Audacity; productivity - Libre Office, ...; browsers - Opera, Chrome, Firefox,...
- tools
	- for the system to be easier to use
	- shells
		- to accept command and to pass them to kernel for execution
		- 2 families - Bourne shell, C shell; moder versions: Bourne Again Shell (bash), tcsh
		- are created others - Korn shell (ksh), Z shell (zsh)
	- text editors
		- Vi (and more modern Vim) and Emacs - more advanced
		- Pico, Nano - easier
			- *Pico is not open source :D*
- package managers
	- to add, remove, update software
	- package = compressed files containing the application and its dependencies
	- Debian Package Management
		- `.deb`, `dpkg`
		- `apt-get` is a front-end tool for `dpkg`
	- RPM Package Management
		- `.rpm` file for each software package
		- `rpm` install, update, query and remove packages
		- `yum` and `up2date` automate the process of resolving dependency issues
- development languages
	- compiled 
		- translated all at once 
		- C, C++, Java (imagines a CPU = Java Virtual Machine (JVM) and then compiles all the codeto that)
	- interpreted
		- translates as it runs, usually hae more feature then compiled languages (less code is needed),
		- JavaScript, Perl, PHP, Ruby, Python, OpenSSL


##### Open Source Software and Licencing
- EULA
	- End User Licence Agreeent
	- Microsoft Windows
- GPLv2
	- GNU General Public Licence version 2
	- Linux
	- you can take the code and do whatever you want with it, but products made from GPLv2 licenced code has to have the same licence, plus the changes must be made public with the code (copyleft provision)
- FOSS (Free and Open Source Software), MIT licence, Apache Foundation licence,...
- Free Software Foundation
	- founded by Richard Stallman (in 1985)
	- with goal of free software (with the freedom to share, study and modify)
	- has their own licences based on the GNU General Public Licence (GPL)
- Open Source Initiative
	- founded by Bruce Perens and Eric Raymond
	- they believed that FSF was too politicaly charged
	- alternative licence - BSD (Berkeley Software Distribution) - simpler then GPL, basically saying "do what you want with this code just don't say you wrote it"
	- became **Free and Open Source Software** (FOSS) - "free as in speech" →libre → Free/Libre/Open Source Software (FLOSS)
- Creative Commons
	- Attribution (BY) = require that reator must be given credit, w/o implying that the creator endorces the use
	- ShareAlike (SA) = allows others to copy, distribute, perform and modify the work but under SOME terms
	- NonCommercial (NC) = allows to distribute, display, perform and modify for any purpose then commercially
	- NoDerivatives (ND) = allows to distribute, display, perform pnly the original coppies of the work; the creator's permission is a must
	- 6 main licences: Attribution (CC BY), Attribution ShareAlike (CC BY-AS), Attribution NoDerivs (CC BY-ND), Attribution-NonCommercial (CC BY-NC), Attribution-NonCommercial-ShareAlike (CC BY-NC-SA), Attribution-NonCommercial-NoDerivs (CC BY-NC-ND), No Rights Reserved (CC0 - public domain)





=======
### UNIX
- OS developed by AT&T Bell Labs in 1970s
- written in C
- now owned by Open Group

### Linux
- = combination of softwares GNU/Linux → OS
	- GNU = free SW providing common UNIX commands
	- Linux - Linux kernel (core of the OS) loaded at boot time and stays running to manage the system
- 1991 - Linus Torvalds
- before  - GNU Project - Richard Stallman (1983)
- open source (duh)
- different flavors  → distributions
	- combination of diffrent kernel, tools a apps
- CLI and GNU

![[Pasted image 20220906151000.png]]


##### Distributions
RedHat
- started as RedHat Package Manager (RPM)
- later shift to server apps → Red Hat Enterprise Linux (RHEL)
	- paid, released on a long release cycle 
	- recompiled RHEL packages → CentOS
		- compatible with RHEL, newer SW, for free
- for shorter release cycle → Fedora Project
- Scientific Linux

SUSE
- originally derived from Slackware
- contains proprietary code → paid
	- openSUSE - open, free, desktop packages similar to CentOS and LinuxMint

Debian
- community product, open source
- ofiginal package management system- `.deb`
- Ubuntu
	- most popular Debian-derived distro
	- made by Canonical
		- makes money from providing support
	- Linux Mint
		- fork of Ubuntu

Android
- sponsored by Google
- uses Dalvik VM with Linux
- for mobile phones and tablets
- generally incompatible with other Linux distros

Others 
- Rasphian
	- for Raspberry Pi
- Linux from Scratch (LFS)

![[Pasted image 20220906160054.png]]

- kernel - air traffic controller
	- decides which program gets blocks of memory, starts and kills apps, handles displaying text/graphics on a monitor
	- can switch between applications - multitasking
	- no difference between process and application (from the point of view of kernel)
- applications - airplanes under it's control
	- makes requests to the kernel, can receive resources (memory, CPU, disk space)


##### Software, processes, tools, application
- server apps
	- no direct communication w/ monitor/keyboard
	- to serve information to other computers (clients)
	- often for hosting web app - web server
		- WordPress, Apache (Apache Software Foundation, Apache HTTPD - deamon/server app programm "serving" web page requests), NGINX
	- private cloud servers (ownCloud, NextCloud), DB servers (MariaDB, Firebird, PostgreSQL)
	- email servers
		- Mail Transfer Agent - Sendmail, Postfix
		- Mail Delivery Agent- Local Delivery Agent = takes care of storing user's emails
		- POP/IMAP Server - Post Office Protocol and Internet Message Access Protocol; eg. Dovecot, Cyrus IMAP, Microsoft Exchange
	- file sharing
		- Samba (allows Linux machine to look and behave like Windows so it can join Windows domain), Netatalk (Linux → Apple Macintosh file server), NFS (Network File System, native file sharing in Linux)
- desktop apps
	- web browser, text editors, .... - apps interacting with user
	- email - Thunderbild, Evolution, KMail; creative - Blender, GIMP, Audacity; productivity - Libre Office, ...; browsers - Opera, Chrome, Firefox,...
- tools
	- for the system to be easier to use
	- shells
		- to accept command and to pass them to kernel for execution
		- 2 families - Bourne shell, C shell; moder versions: Bourne Again Shell (bash), tcsh
		- are created others - Korn shell (ksh), Z shell (zsh)
	- text editors
		- Vi (and more modern Vim) and Emacs - more advanced
		- Pico, Nano - easier
			- *Pico is not open source :D*
- package managers
	- to add, remove, update software
	- package = compressed files containing the application and its dependencies
	- Debian Package Management
		- `.deb`, `dpkg`
		- `apt-get` is a front-end tool for `dpkg`
	- RPM Package Management
		- `.rpm` file for each software package
		- `rpm` install, update, query and remove packages
		- `yum` and `up2date` automate the process of resolving dependency issues
- development languages
	- compiled 
		- translated all at once 
		- C, C++, Java (imagines a CPU = Java Virtual Machine (JVM) and then compiles all the codeto that)
	- interpreted
		- translates as it runs, usually hae more feature then compiled languages (less code is needed),
		- JavaScript, Perl, PHP, Ruby, Python, OpenSSL


##### Open Source Software and Licencing
- EULA
	- End User Licence Agreeent
	- Microsoft Windows
- GPLv2
	- GNU General Public Licence version 2
	- Linux
	- you can take the code and do whatever you want with it, but products made from GPLv2 licenced code has to have the same licence, plus the changes must be made public with the code (copyleft provision)
- FOSS (Free and Open Source Software), MIT licence, Apache Foundation licence,...
- Free Software Foundation
	- founded by Richard Stallman (in 1985)
	- with goal of free software (with the freedom to share, study and modify)
	- has their own licences based on the GNU General Public Licence (GPL)
- Open Source Initiative
	- founded by Bruce Perens and Eric Raymond
	- they believed that FSF was too politicaly charged
	- alternative licence - BSD (Berkeley Software Distribution) - simpler then GPL, basically saying "do what you want with this code just don't say you wrote it"
	- became **Free and Open Source Software** (FOSS) - "free as in speech" →libre → Free/Libre/Open Source Software (FLOSS)
- Creative Commons
	- Attribution (BY) = require that reator must be given credit, w/o implying that the creator endorces the use
	- ShareAlike (SA) = allows others to copy, distribute, perform and modify the work but under SOME terms
	- NonCommercial (NC) = allows to distribute, display, perform and modify for any purpose then commercially
	- NoDerivatives (ND) = allows to distribute, display, perform pnly the original coppies of the work; the creator's permission is a must
	- 6 main licences: Attribution (CC BY), Attribution ShareAlike (CC BY-AS), Attribution NoDerivs (CC BY-ND), Attribution-NonCommercial (CC BY-NC), Attribution-NonCommercial-ShareAlike (CC BY-NC-SA), Attribution-NonCommercial-NoDerivs (CC BY-NC-ND), No Rights Reserved (CC0 - public domain)





>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
