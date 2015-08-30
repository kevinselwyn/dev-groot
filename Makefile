NAME  := dev-groot
obj-m := $(NAME).o
KDIR  := /lib/modules/$(shell uname -r)/build
PWD   := $(shell pwd)

all: build

build: $(NAME).c
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -f .*.cmd *.ko *.mod.c *.o *.symvers *.order
	rm -rf .tmp_versions

install: build
	cp groot.rules /etc/udev/
	chmod +x /etc/udev/groot.rules
	ln -s /etc/udev/groot.rules /etc/udev/rules.d/010_groot.rules
	insmod ./$(NAME).ko

uninstall:
	rm -f /etc/udev/groot.rules
	rm -f /etc/udev/rules.d/010_groot.rules
	rmmod $(NAME)