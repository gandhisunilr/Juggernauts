arm-none-eabi-gcc -g -mcpu=cortex-m3 -mthumb -I../inc -c main.c hw_config.c core_cm3.c misc.c otgd_fs_cal.c otgd_fs_dev.c otgd_fs_int.c otgd_fs_pcd.c stm32f10x_rcc.c system_stm32f10x.c usb_core.c usb_desc.c usb_endp.c usb_init.c usb_istr.c usb_prop.c usb_pwr.c usb_sil.c vector.c stm32f10x_gpio.c stm3210e_eval.c


arm-none-eabi-ld -T linker.ld main.o hw_config.o core_cm3.o misc.o otgd_fs_cal.o otgd_fs_dev.o otgd_fs_int.o otgd_fs_pcd.o stm32f10x_rcc.o system_stm32f10x.o usb_core.o usb_desc.o usb_endp.o usb_init.o usb_istr.o usb_prop.o usb_pwr.o usb_sil.o vector.o stm32f10x_gpio.o -o main.elf


main.o hw_config.o core_cm3.o misc.o otgd_fs_cal.o otgd_fs_dev.o otgd_fs_int.o otgd_fs_pcd.o stm32f10x_rcc.o system_stm32f10x.o usb_core.o usb_desc.o usb_endp.o usb_init.o usb_istr.o usb_prop.o usb_pwr.o usb_sil.o vector.o 
