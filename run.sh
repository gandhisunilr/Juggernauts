
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -g -T linker.ld -c main.c vector.c sum.c
arm-none-eabi-ld -T linker.ld main.o vector.o sum.o -o main.elf -Map ./map.txt  
arm-none-eabi-objdump -D -S main.elf > main.list 
arm-none-eabi-objdump -D main.elf > maindetailed.list 
arm-none-eabi-objcopy -O binary main.elf main.bin 

