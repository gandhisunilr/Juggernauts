
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -g -T linker.ld -c main.c vector.c sum.c
arm-none-eabi-ld -T linker.ld main.o vector.o sum.o -o main.elf 
arm-none-eabi-objdump -D -S main.elf > main.list 
arm-none-eabi-objcopy -O binary main.elf main.bin 
#sudo openocd -f /home/swapnil/CodeSourcery/openocd-0.5.0/tcl/interface/ -f /home/swapnil/CodeSourcery/openocd-0.5.0/tcl/board/olimex_stm32_h107.cfg


