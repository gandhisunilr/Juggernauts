#!bin/bash

arm-none-eabi-gcc -nostartfiles -nostdlib -mthumb -mcpu=cortex-m3 -g  -I../inc -c  


#arm-none-eabi-gcc -nostartfiles -nostdlib -mthumb -mcpu=cortex-m3 -g -c printf.c hw_config.c  misc.c  otgd_fs_dev.c  otgd_fs_pcd.c  stm32_eval.c  stm32f10x_bkp.c  stm32f10x_cec.c  stm32f10x_dac.c  stm32f10x_dma.c     stm32f10x_flash.c  stm32f10x_gpio.c  stm32f10x_it.c   stm32f10x_pwr.c   stm32f10x_rtc.c  stm32f10x_spi.c   stm32f10x_usart.c  usb_desc.c  usb_init.c  usb_istr.c  usb_prop.c  usb_regs.c core_cm3.c   main.c  otgd_fs_cal.c  otgd_fs_int.c  stm32f10x_adc.c  stm32f10x_can.c  stm32f10x_crc.c  stm32f10x_dbgmcu.c  stm32f10x_exti.c   stm32f10x_fsmc.c  stm32f10x_i2c.c  stm32f10x_iwdg.c  stm32f10x_rcc.c  stm32f10x_sdio.c  stm32f10x_tim.c    stm32f10x_wwdg.c  system_stm32f10x.c  usb_core.c  usb_endp.c usb_mem.c   usb_pwr.c   usb_sil.c startup_stm32f10x_cl.c -I../inc

#arm-none-eabi-ld -T stm32f10x_cl_flash_offset.ld printf.o hw_config.o  misc.o  otgd_fs_dev.o  otgd_fs_pcd.o  stm32_eval.o  stm32f10x_bkp.o  stm32f10x_cec.o  stm32f10x_dac.o  stm32f10x_dma.o     stm32f10x_flash.o  stm32f10x_gpio.o  stm32f10x_it.o   stm32f10x_pwr.o   stm32f10x_rtc.o  stm32f10x_spi.o   stm32f10x_usart.o  usb_desc.o  usb_init.o  usb_istr.o  usb_prop.o  usb_regs.o core_cm3.o   main.o  otgd_fs_cal.o  otgd_fs_int.o  stm32f10x_adc.o  stm32f10x_can.o  stm32f10x_crc.o  stm32f10x_dbgmcu.o  stm32f10x_exti.o   stm32f10x_fsmc.o  stm32f10x_i2c.o  stm32f10x_iwdg.o  stm32f10x_rcc.o  stm32f10x_sdio.o  stm32f10x_tim.o    stm32f10x_wwdg.o  system_stm32f10x.o  usb_core.o  usb_endp.o  usb_mem.o   usb_pwr.o   usb_sil.o startup_stm32f10x_cl.o -o main.elf -L"/root/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/lib/gcc/arm-none-eabi/4.6.1/thumb2" -lgcc -L"/root/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/arm-none-eabi/lib/thumb2" -lc

#arm-none-eabi-objcopy -O binary main.elf main.bin 

#arm-none-eabi-objdump -D -S main.elf > main.list

gnome-terminal --geometry=165x40+100+200 --tab -e "

#sudo openocd -f /root/CodeSourcery/openocd-0.5.0/tcl/interface/ -f /root/CodeSourcery/openocd-0.5.0/tcl/board/olimex_stm32_h107.cfg

#" --tab -e "sudo telnet localhost 4444" --tab -e "arm-none-eabi-gdbtui main.elf"  

