# DO NOT CHANGE THE BELOW PART. JUST ADD FILE NAMES AT PROPER PLACE AND LIBRARY PATH

#commands
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJDUMP = arm-none-eabi-objdump
OBJCOPY = arm-none-eabi-objcopy
ELFDUMP = elfdump
GCC = gcc

# files
mcpu = cortex-m3
linkerscript = stm32f10x_cl_flash_offset.ld
SRCS = main.c startup_stm32f10x_cl.c sum.c
OBJS = main.o startup_stm32f10x_cl.o sum.o
ELF = main.elf
LIST = main.list
LISTDETAIL = maindetail.list
BINARY = main.bin
SYMTAB = symtab
SYMTABGEN = symtabgen
THUMBPATH = "/home/sunil/Documents/CodeSourcery/Sourcery_G++_Lite/lib/gcc/arm-none-eabi/4.4.1/thumb2/"
LIBRARYPATH = "/home/sunil/Documents/CodeSourcery/Sourcery_G++_Lite/arm-none-eabi/lib"

#flags
CCFLAGS = -mcpu=$(mcpu) -mthumb -g -T $(linkerscript) -c 
LDFLAGS = -T $(linkerscript) -L $(THUMBPATH) -lgcc -L $(LIBRARYPATH) -lc -o $(ELF)
DUMPFLAGS = -D -S
DUMPFLAGSDETAIL = -D
OBJCOPYFLAGS = -O

all : $(LISTDETAIL)

$(LISTDETAIL) $(LIST) $(BINARY): $(ELF)
	$(OBJDUMP) $(DUMPFLAGSDETAIL) $(ELF) > $(LISTDETAIL)
	$(OBJDUMP) $(DUMPFLAGS) $(ELF) > $(LIST)
	$(OBJCOPY) $(OBJCOPYFLAGS) binary $(ELF) $(BINARY)

$(ELF) : $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -Map ./map.map  

#$(OBJS) : $(SRCS)
#	$(CC) $(CCFLAGS) $(SRCS)
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

clean :
	rm $(OBJS) $(ELF) $(LIST) $(LISTDETAIL) $(BINARY) $(SYMTAB)

attachsymtab:
	./${ELFDUMP} -s $(ELF) > $(SYMTAB)
	$(GCC) $(SYMTABGEN).c -o $(SYMTABGEN)
	./$(SYMTABGEN)
	rm $(BINARY) $(ELF) startup_stm32f10x_cl.o 
	
