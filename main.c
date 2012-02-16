#include<stdint.h>


int main(void)
{
	extern unsigned _ebss;
	int *codeaddr,*src,*dest;
/*	
	int (*fp)(void);
	codeaddr=_ebss;
		for(dest=codeaddr,
			src=&_sumfunstart; src<=&_sumfunend;
				src++,dest++)
		{	
			*dest=*src;
		}	
        
//	a=a/i;
        fp=codeaddr;
//	goto *codeaddr;
	fp();	
//	while(1);
*/
	sum();
	while(1);
}



void usage_fault_handler(){

return;
}
