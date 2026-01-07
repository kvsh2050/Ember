sudo apt update    

#Dependencies
sudo apt install autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev libncurses-dev

#Install Cross Compilers
sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi gdb-arm-none-eabi
sudo apt install gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf gdb-riscv64-unknown-elf
sudo apt install gcc-avr binutils-avr avr-libc avrdude 

#QEMU 
sudo apt install qemu-system qemu-system-riscv64
sudo apt install qemu-system qemu-system-arm 
sudo apt install qemu-system qemu-system-avr

#GDB dashboard
wget -P ~ https://github.com/cyrus-and/gdb-dashboard/raw/master/.gdbinit




