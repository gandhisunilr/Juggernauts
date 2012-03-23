echo .gdbinit is a hidden file. Press Ctrl-H in the current working directory to see it.\n
# Connect to OpenOCD
	target remote localhost:3333
monitor reset halt

define bpl
    info breakpoints
end
document bpl
	List all breakpoints.
end
