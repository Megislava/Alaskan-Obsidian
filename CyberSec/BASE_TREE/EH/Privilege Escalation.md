<<<<<<< HEAD
1. `sudo -l` - lists sudo right on folders, files (binaries)
2.  `find / -perm -o=s 2>/dev/null` → SUID files
3. [[enum4linux]]
4. [[LinEnum]]
5. LinPEAS

- GTFOBins = binaries that are easily exploited (CTF, Pentest) [link](https://gtfobins.github.io/)
	- eg.: `sudo -l` (NOPASSWD to vi) > `sudo vi`> `:!sh` (privilege escalation to shell as root)

##### Breaking passwords
- [[Hydra]]
- [[hashcat]]
- [[John the Ripper]]

Need [[xfreerdp]]?
=======
1. `sudo -l` - lists sudo right on folders, files (binaries)
2.  `find / -perm -o=s 2>/dev/null` → SUID files
3. [[enum4linux]]
4. [[LinEnum]]
5. LinPEAS

- GTFOBins = binaries that are easily exploited (CTF, Pentest) [link](https://gtfobins.github.io/)
	- eg.: `sudo -l` (NOPASSWD to vi) > `sudo vi`> `:!sh` (privilege escalation to shell as root)

##### Breaking passwords
- [[Hydra]]
- [[hashcat]]
- [[John the Ripper]]

Need [[xfreerdp]]?
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
