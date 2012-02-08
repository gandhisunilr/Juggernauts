
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -g -T linker.ld -c main.c vector.c 
arm-none-eabi-ld -T linker.ld main.o vector.o -o main.elf 
arm-none-eabi-objdump -D -S main.elf > main.list 
arm-none-eabi-objcopy -O binary main.elf main.bin 

