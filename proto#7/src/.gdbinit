echo .gdbinit is a hidden file. Press Ctrl-H in the current working directory to see it.\n
# Connect to OpenOCD
target remote localhost:3333
monitor reset halt
b virtual_com_port_init
b main
condition 1 i==1000

define myinit 
	info registers
	printf "hello"
end
