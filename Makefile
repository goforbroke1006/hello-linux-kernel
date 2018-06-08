obj-m += foo_driver.o

all:
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules

install:
	sh -c 'echo 7 > /proc/sys/kernel/printk'
	insmod foo_driver.ko

remove:
	rmmod foo_driver.ko

clean:
	make -C /lib/modules/`uname -r`/build M=$(PWD) clean

dump-log:
	dmesg | tail -20
