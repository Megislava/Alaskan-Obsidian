- volatile vs non-volatile memory

1. Random Access Memory
	- RAM
	- 32-bit architecture - up to 4GB of RAM
	- 64-architecture - more
	- when system is low on RAM, memory is virualized by swap space
		- temporaty store data 
	- `free`  - information about RAM
		- running w/o any options -> snapshot of the memory being used at the moment
		- `-s 10` - memory usage over time (in seconds)
		- `-m`/`/g` - output in MB/GB

2. HDD = Hard drives
	- can be divided into partitions
		- logical divisions on a hard drive
		- partitioning technology: Master Boot Record (MBR), GUID Pertitioning Table (GPT)
	- `fdrive`, `cfdrive`, `sfdrive` - gives info about HDDs; supported bt MBR
	- `fdisk`, `gdisk`, `cgdisk`, `sgdisk` - supported by GPT
	- `parted`, `gparted` - supported by both
	- device file name is stored in `/dev`, containing:
		- file type - `hd` (IDE = Intelligent Drive Electronics), `sd` (SATA = Serial Advanced Technology Attachement; or SCSI = Small Computer System Interface)
		- device order - alfphabetical -> first: `/dev/hda`, second: `/dev/hdb`
		- partitions - numerical value -> first: `/dev/hda1`, second: `/dev/hda2`
3. SSD = solid state drive
	 - basically bigger USBs 
4. Optical Drives
	- CD-ROMs, DVDs, Blu-Ray,...
	- removable
	- various writtable/rewrittable standarts
		- CD-R, CD+R, DVD+RW, DVD-RW
	- usually mounted in `/media`; in older systems in `/mnt`
	- 