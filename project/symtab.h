
	typedef struct symtab
	 {
				int fun_start_address;
		int fun_size;
	}symtab;
	
	__attribute__((section(".symtab"))) symtab symbols[200]= { {0x0, 0} ,
{0x8000441, 16} ,
{0x800041d, 10} ,
{0x8000435, 10} ,
{0x20000004, 4} ,
{0x8000429, 10} ,
{0xc0000019, 16} ,
{0x20000008, 4} ,
{0xc000000d, 10} ,
{0x80001e5, 112} ,
{0x2000000c, 4} ,
{0x8000255, 126} ,
{0x80002d5, 328} ,
{0xc0000001, 10} ,
{0xc0000029, 16} 
	};
	
	#define SYMTAB	