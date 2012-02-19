# DO NOT CHANGE THE BELOW PART. JUST ADD FILE NAMES AT PROPER PLACE

#commands
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJDUMP = arm-none-eabi-objdump
OBJCOPY = arm-none-eabi-objcopy

# files
mcpu = cortex-m3
linkerscript = linker.ld
SRCS = main.c vector.c sum.c
OBJS = main.o vector.o sum.o
ELF = main.elf
LIST = main.list
LISTDETAIL = maindetail.list
BINARY = main.bin

#flags
CCFLAGS = -mcpu=$(mcpu) -mthumb -g -T $(linkerscript) -c 
LDFLAGS = -T $(linkerscript) -o $(ELF)
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

$(OBJS) : $(SRCS)
	$(CC) $(CCFLAGS) $(SRCS)

clean :
	rm $(OBJS) $(ELF) $(LIST) $(LISTDETAIL) $(BINARY)

