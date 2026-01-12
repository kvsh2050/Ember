cpu ?= cortex-m
target ?= stm32vldiscovery

.PHONY = qemu gdb compile 

compile:
	arm-none-eabi-as boot.S -o boot.o 

linking:
	arm-none-eabi-ld -Tmap.ld boot.o -o boot.elf 

qemu:
	qemu-system-arm -S boot.elf -gdb tcp::1234 -machine $(target)

gdb:
	gdb-multiarch -pid tcp::1234
