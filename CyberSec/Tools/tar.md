= TApe aRchive
- archive can in file, stdin or stdout

- 3 modes/actions
	- Create (`-c`)
	- Extract (`-x`)
	- List (`-t`)
- syntax: `tar <action> [options] [agruments]`

- `--show-defaults` - show how the tar is by default set-up
- `-c` - create
- `-f ARCHIVE` - use file, ARCHIVE is name of resulting archive file
- `-t` - list files in the archive
- `-x` - extract
- `-C` - will extract to specific place
- `-v` - verbous
- `-u` - update
	- adds to the end of file an update
- `-z` - compress/decompress using [[gzip]]
- `-j` - compress/decompress using [[bzip2]]