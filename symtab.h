
	typedef struct symtab
	 {
				int value;
		int size;
	}symtab;
	
	__attribute__((section(".symtab"))) symtab symbols[1000]= { {0x0, 0} ,
{0x8000000, 0} ,
{0xc0000000, 0} ,
{0x20000000, 0} ,
{0x80003e8, 0} ,
{0x80001e4, 0} ,
{0x54, 0} ,
{0x10, 0} ,
{0xc0000018, 0} ,
{0x108, 0} ,
{0x80003d9, 16} ,
{0x80003d8, 0} ,
{0x80003e4, 0} ,
{0xc0000038, 0} ,
{0x80003b5, 10} ,
{0x80003cd, 10} ,
{0x20000004, 4} ,
{0x8002360, 0} ,
{0x80003c1, 10} ,
{0x8002328, 0} ,
{0xc0000019, 16} ,
{0x20000008, 4} ,
{0xc000000d, 10} ,
{0x20000010, 0} ,
{0x80001e5, 112} ,
{0x2000000c, 4} ,
{0x8000255, 126} ,
{0x80002d5, 224} ,
{0xc0000001, 10} ,
{0x400, 0} ,
{0x2000fc00, 0} ,
{0x20010000, 0} ,
{0xc0000029, 16} 
	};
	
	#define SYMTAB	