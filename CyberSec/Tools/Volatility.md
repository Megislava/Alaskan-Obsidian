###### Intro
-  install: `apt-get install volatility`
-  volatility = memory  forensic tool, wildly expandable via plugins
-  obtain memory capture:
	- [[CyberSec/Tools/FTK Imager]], [[dd]], [[dcfldd]]
	- Redline
	- Dumplt.exe
	- win32dd.exe / win64dd.exe
- typical output in .raw (most common memory file type)
- offline machines can have memory pulled easily if the drives are not encrypted, it can be done with pulling %SystemDrive%/hiberfil.sys
- hiberfil.sys - Windows hibernation file containing compressed memory image from previous boot
- virtual machines memory capture:
	- VMWare - .vmem file
	- Hyper-V - .bin file
	- Parallels - .mem file
	- VirtualBox - .sav file (only a partial memory file!)
	
###### Volatility, how to:
- `volatility -f MEMORY_FILE.raw` - base command
- `imageinfo`- provides a number of profiles that we can test with (only one is correct)
- `--profile=PROFILE pslist` - testing the profiles that was provided by imageinfo, and lists what processes are within the image 
- `--profile=PROFILE netscan` - view active internet connections at the time of the image creation
- `psxview` - view hidden processes
- `drmodules` - more comprehensive processes info, the view is splitted into 3 columns - if there is any 'False' in any of these columns it's bad
- `apihooks` - view unexpected patches in the standard system DLLs, if there is `Hooking module <unknown>` it's bad
- `--profile=PROFILE malfind -D <Destination Directory>` - looks for injected code and dumps it into Destination Folder
- `dlllist` - view all the DLLs loaded into memory
- `--profile=PROFILE --pid=PID dlldump -D <Destination Directory>` - pull all DLLs into the Destination Folder
