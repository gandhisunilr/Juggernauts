#include<stdint.h>
__attribute__((section("sumfunstart")))
//sumfunstart=.;
int sum()
{
return 2+1;
}
//sumfunend=.;
__attribute__((section("sumfunend")))
int main(void)
{
	extern unsigned sumfunstart,sumfunend;
	int *codeaddr,*src,*dest;
	
	int (*fp)(void);
	codeaddr=(0x20000097|0x01);
		for(dest=codeaddr,
			src=&sumfunstart; src<=&sumfunend;
				src++,dest++)
		{	
			*dest=*src;
		}	
        
//	a=a/i;
        fp=codeaddr;
//	goto *codeaddr;
	fp();	
	while(1);
}
int sub()
{
return 2-1;
}
void usage_fault_handler(){
return;
}

