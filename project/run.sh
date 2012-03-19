#THUMBPATH       = "/home/swapnil/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/lib/gcc/arm-none-eabi/4.6.1/thumb2/"
#LIBRARYPATH     = "/home/swapnil/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/arm-none-eabi/lib/"

make -f swa_Makefile
make -f swa_Makefile attachsymtab
make -f swa_Makefile 
make -f swa_Makefile attachsymtab
make -f swa_Makefile 



#sudo openocd -f /home/swapnil/CodeSourcery/openocd-0.5.0/tcl/interface/olimex-arm-usb-tiny-h.cfg -f /home/swapnil/CodeSourcery/openocd-0.5.0/tcl/board/olimex_stm32_h107.cfg
