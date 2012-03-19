BINARY 		= main

LIBNAME		= libvcp

PREFIX		= arm-none-eabi
AR		= $(PREFIX)-ar
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

OBJS		= core_cm3.o     otgd_fs_dev.o           stm32_eval.o     stm32f10x_crc.o     stm32f10x_flash.o  stm32f10x_iwdg.o  stm32f10x_spi.o     usb_core.o \
		  usb_istr.o  usb_sil.o hw_config.o    otgd_fs_int.o           stm32f10x_adc.o  stm32f10x_dac.o     stm32f10x_fsmc.o   stm32f10x_pwr.o  \
		  stm32f10x_tim.o     usb_desc.o  usb_mem.o     otgd_fs_pcd.o           stm32f10x_bkp.o  stm32f10x_dbgmcu.o  stm32f10x_gpio.o  \
		  stm32f10x_rcc.o   stm32f10x_usart.o   usb_endp.o  usb_prop.o misc.o         printf.o                stm32f10x_can.o  stm32f10x_dma.o    \
		  stm32f10x_i2c.o    stm32f10x_rtc.o   stm32f10x_wwdg.o    usb_init.o  usb_pwr.o otgd_fs_cal.o  startup_stm32f10x_cl.o  stm32f10x_cec.o \
		  stm32f10x_exti.o    stm32f10x_it.o     stm32f10x_sdio.o  system_stm32f10x.o  usb_int.o   usb_regs.o main.o



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
	$(OBJDUMP) -S $(*).elf > $(BINARY).list

%.elf: $(OBJS) $(LDSCRIPT)
	@printf "  LD      $(subst $(shell pwd)/,,$(@))\n"
	$(LD) $(LDFLAGS)  $(OBJS) -L"/home/swapnil/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/lib/gcc/arm-none-eabi/4.6.1/thumb2" -lgcc -L"/home/swapnil/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/arm-none-eabi/lib/thumb2" -lc -o $(BINARY).elf

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
