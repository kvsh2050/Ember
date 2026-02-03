cpu ?= cortex-m3
board ?= stm32vldiscovery

.PHONY = qemu gdb compile clean objdump

compile:
	arm-none-eabi-as -mthumb -mcpu=$(cpu) -g -c boot.S -o boot.o 

linking:
	arm-none-eabi-ld -Tlink.ld boot.o -o boot.elf 

objdump:
	arm-none-eabi-objdump -S boot.o > boot.elf.lst
	arm-none-eabi-readelf -a boot.elf > main.elf.debug

qemu:
	qemu-system-arm -S -gdb tcp::1234 -M $(board) -cpu $(cpu) -nographic -kernel boot.elf

gdb:
	gdb-multiarch -q boot.elf -ex "target remote localhost:1234"

clean:
	rm -rf *.o *.elf