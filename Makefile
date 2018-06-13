obj-m += foo_driver.o
obj-m += gfb_usb_driver.o

all:
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules

install:
	sh -c 'echo 7 > /proc/sys/kernel/printk'
	insmod foo_driver.ko
	insmod gfb_usb_driver.ko

uninstall:
	rmmod foo_driver.ko || true
	rmmod gfb_usb_driver.ko || true

clean:
	make -C /lib/modules/`uname -r`/build M=$(PWD) clean

dump-log:
	dmesg | grep -i 'gfb_usb_' | tail -50 
