#include<stdint.h>

int a;
//__attribute__ ((section (".flashfun")))
__attribute__ ((section (".sumfun")))
void sum() 
{

	a=a+1;
	
	return;
}


//__attribute__ ((section (".ramfun")))
__attribute__ ((section (".subfun")))
void sub()
{
	a=a-1;
	return;
}

extern unsigned ramfunstart, main_end, main_start, myfun_start, myfun_end;
__attribute__ ((section (".ramfun")))
void ramfun()
{
		volatile unsigned *src,*dest;

	for(dest= (&ramfunstart - &myfun_start + &myfun_end), src= &main_start; src<= &main_end; src++, dest++){
			*dest=*src;
		}

	return;
}


__attribute__((section("mainfun")))
//__attribute__((section(".XNregion")))
int main(void)
{
	
	a=10;
	
	a=a+1;
}


void usage_fault_handler(){

	

	
	return;
}
