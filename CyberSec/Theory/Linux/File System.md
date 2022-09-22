- Filesystem Hierarchy Standart
	- provides guideline for distributions on how to organize files

- `/bin` and `/sbin` - Used for system critical files - DO NOT DELETE
	- home of essential binaries

- `/boot` - files necessary to boot the system

- `/dev` - files representing hardware devices and special filles
	- files making hardware devices available 
	- `/dev/null` and `/dev/zero` - content is removed

- `/etc`  - host configuration
	- `/etc/passwd` - Stores user information - Often used to see all the users on a system
	- `/etc/shadow` - Has all the passwords of these users	
	- `/etc/sudoers` - Used to control the sudo permissions of every user on the system   
	- `/etc/hosts` - contains a table of hostnames to IP addresses, it can be supplement to a DNS server
	- `/etc/resolv.conf` - IP addresses of name servers the system should consult in order to resolve an IP (often DNS servers)
	- `/etc/nsswitch.conf` - used to modify where hostname lookup occurs

- `/home` - The directory where all your downloads, documents etc are. 
	- the equivalent on Windows is `C:\Users\<user>`

- `/lib` and `/lib64` - libraries to support exe files in `bin` and `sbin`

- `/log` - storing logs
	- logging deamons
		- previously `syslogd` + `flogd`
		- nowdays more `rsyslogd`, `journald`
	- `boot.log` (system startup), `cron` (logs for cron jobs), `dmesg` (boot up), `maillog` (email messages sent/received), `messages` (messages from kernel and other processes that don't belong anywhere else; as the system is running), `secure` (from processes requiring auth/auth), `journal` (from default config of `systemd-journald.service` - can be configured), `Xord.0.log` (messages from X Windows (GUI) server)
	- in more modern deamons suffix with date is added when rotating log files

- `/media` - mount point for removable media automatically

- `/mnt` - mount point for temporary mounting filesystems manually

- `/opt` - optional third-party software installation location

- `/proc` - virtual filesystem for the kernel to report (process) info
	- pseudo filesystem
	- read only
	- besides processes contains info about system hardware and kernel config
	- contains numbered direstory for each running process
		- the name if the directory matches PID
	- `/proc/cmdline`, `/proc/meminfo`, `/proc/modules`,...
	- `/proc/loadvg` - load averages 

- `/root` - The root user's home directory 
	- the equivalent on Windows is `C:\Users\Administrator`

- `/run`

- `/sys` - virtual filesystem for information about hardware devices connected ot the system
	- information about hardware devices

- `/tmp` - Every file inside it gets deleted upon shutdown - used for temporary files

- `/usr` - Where all your software is installed 

- `/var` - The Linux miscellaneous directory, a myriad of processes store data in /var
	- `/var/cache` (caching application data), `/var/log` (most log files), `/var/lock` (lock files for shared resources), `/var/spool` (spool files for printing and mail), `/var/tmp` (temp files to be preserved between reboots)
