<<<<<<< HEAD
- tool for static acquisition

- `dd if=/dev/sdb of=./usb_image.dd` - input file is `/dev/sdb` and output file is USB image

=======
- tool for static acquisition

- `dd if=/dev/sdb of=./usb_image.dd` - input file is `/dev/sdb` and output file is USB image

>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
- `dd if=/dev/sdb | split -b 650m - usbimage.` - creating split-disk image with size of 650m