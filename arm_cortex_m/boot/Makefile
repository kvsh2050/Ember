cpu ?= cortex-m3
target ?= stm32vldiscovery

.PHONY = qemu gdb compile clean objdump

compile:
	arm-none-eabi-as -g boot.S -o boot.o 

linking:
	arm-none-eabi-ld -Tmap.ld boot.o -o boot.elf 

objdump:
	arm-none-eabi-objdump -S boot.o -o boot.txt

qemu:
	qemu-system-arm -S boot.elf -s -machine $(target) -cpu $(cpu)

gdb:
	gdb-multiarch -pid tcp::1234

clean:
	rm -rf *.o *.elf