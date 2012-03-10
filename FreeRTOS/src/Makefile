BINARY 		= main

LIBNAME		= libvcp

PREFIX		= arm-none-eabi
AR		= $(PREFIX)-ar
LD		= $(PREFIX)-gcc
#LD		= $(PREFIX)-ld
OBJCOPY		= $(PREFIX)-objcopy
OBJDUMP		= $(PREFIX)-objdump

CC		= $(PREFIX)-gcc
CFLAGS		=  -g -Wall -Wextra -I../inc -fno-common \
		  -mcpu=cortex-m3 -mthumb  \
		  -ffunction-sections -fdata-sections
ARFLAGS		= rcs
LDSCRIPT	= stm32_flash.ld
LDFLAGS		= -T$(LDSCRIPT) 

OBJS		= flop.o stm3210e_eval_lcd.o tasks.o queue.o syscalls.o main.o timertest.o stm32f10x_it.o  serial.o port.o heap_2.o  list.o\
	semtest.o recmutex.o integer.o flash.o dynamic.o death.o comtest.o blocktim.o QPeek.o PollQ.o GenQTest.o BlockQ.o \
	stm32f10x_usart.o stm32f10x_tim.o stm32f10x_spi.o stm32f10x_sdio.o stm32f10x_rcc.o stm32f10x_i2c.o stm32f10x_gpio.o \
	stm32f10x_fsmc.o stm32f10x_flash.o stm32f10x_exti.o stm32f10x_dma.o misc.o system_stm32f10x.o startup_stm32f10x_cl.o \
			core_cm3.o stm32_eval_spi_flash.o fonts.o stm3210e_eval_fsmc_sram.o stm3210e_eval_fsmc_nor.o \
			stm3210e_eval_fsmc_nand.o stm3210e_eval.o ParTest.o

# AltPollQ.o  crhook.o  AltQTest.o AltBlock.o AltBlckQ.o countsem.o IntQueue.o crflash.o 


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
