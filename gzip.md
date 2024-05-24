- compressing files
- source file is overwritten by the product
- can be done over stdin/stdout
	- can be used as a filter

- `-l` - prints the compressing information  (compression ratio)
- `-v` - verbous
- `-d` - decompress
	- or use `gunzip` (+- same flags)

- `gzip <f1 >f1.gz` - compress file from stdin result forward to stdout
- `tar -cf - data | gzip >data.tar.gz` - make archive from file "data" to stdout (`-`), then compress ti to "data.tar.gz"
	- also possible with `tar -czf data.tgz data`
	- `gzip -d <data.tar.gz | tar -xf -` - the other way round - decompress + unpack