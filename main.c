#include<stdint.h>

int a=0;
__attribute__ ((section(".handlerfunctions")))
int main(void)
{

	sum();
	while(1);
}



void usage_fault_handler(){

return;
}

