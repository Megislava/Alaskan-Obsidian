- tool for static acquisition

- `dd if=/dev/sdb of=./usb_image.dd` - input file is `/dev/sdb` and output file is USB image

- `dd if=/dev/sdb | split -b 650m - usbimage.` - creating split-disk image with size of 650m