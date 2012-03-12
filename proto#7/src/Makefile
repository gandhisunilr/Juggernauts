BINARY 		= main

LIBNAME		= libvcp

PREFIX		= arm-none-eabi
AR		= $(PREFIX)-ar
#LD		= $(PREFIX)-gcc
LD		= $(PREFIX)-ld
OBJCOPY		= $(PREFIX)-objcopy
OBJDUMP		= $(PREFIX)-objdump

CC		= $(PREFIX)-gcc
CFLAGS		=  -g -Wall -Wextra -I../inc -fno-common \
		  -mcpu=cortex-m3 -mthumb  \
		  -ffunction-sections -fdata-sections
ARFLAGS		= rcs
LDSCRIPT	= stm32f10x_cl_flash_offset.ld
LDFLAGS		= -T$(LDSCRIPT) 

OBJS		= main.o sum.o startup_stm32f10x_cl.o 

#all: $(OBJS)
.SUFFIXES: .elf .bin .hex .srec .list .images
.SECONDEXPANSION:
.SECONDARY:


all:  images

images: $(BINARY).images
#$(LIBNAME).a $(BINARY).images

%.images: %.bin %.hex %.srec %.list
	@#echo "*** $* images generated ***"

%.bin : %.elf
	@printf "  OBJCOPY $(*).bin\n"
	$(OBJCOPY) -Obinary $(BINARY).elf $(*).bin

%.hex: %.elf
	@printf "  OBJCOPY $(*).hex\n"
	$(OBJCOPY) -Oihex $(BINARY).elf $(*).hex

%.srec: %.elf
	@printf "  OBJCOPY $(*).srec\n"
	$(OBJCOPY) -Osrec $(BINARY).elf $(*).srec

%.list: %.elf
	@printf "  OBJDUMP $(*).list\n"
	$(OBJDUMP) -S -D $(*).elf > $(BINARY).list

%.elf: $(OBJS) $(LDSCRIPT)
	@printf "  LD      $(subst $(shell pwd)/,,$(@))\n"
	$(LD) $(LDFLAGS)  $(OBJS) -L"/home/swapnil/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/lib/gcc/arm-none-eabi/4.6.1/thumb2" -lgcc -L"/home/swapnil/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/arm-none-eabi/lib/thumb2" -lc -L"/home/swapnil/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/arm-none-eabi/lib/thumb2" -lm -o $(BINARY).elf

#$(LIBNAME).a: $(OBJS)
#	@printf "  AR      $(subst $(shell pwd)/,,$(@))\n"
#	$(AR) $(ARFLAGS) $@ $^
	
%.o: %.c
	@printf "  CC      $(subst $(shell pwd)/,,$(@))\n"
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@printf "  CLEAN   lib/stm32\n"
	rm -f *.o
	rm -f *.elf
	rm -f *.bin
	rm -f *.hex
	rm -f *.srec
	rm -f *.list
	
#.PHONY: images clean
