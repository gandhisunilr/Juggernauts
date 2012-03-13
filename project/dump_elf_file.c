
#include <stdio.h>
#include <malloc.h>



typedef struct symtab
{
	int value;
	int size;
}symtab;


symtab symbols[1000];

void main(int argcc, char * argv[])
{
	FILE *file, *fileout;
	char *buffer;
	int sno, value, size, shndx,i;
	char name[50], info[50];
	int entry_exist_flag, j;
	
	//Open file7
	file = fopen("symtab", "rb");
	if (!file)
	{
		fprintf(stderr, "Unable to open file");
		return;
	}
	
	fileout = fopen("symtab.h","w");

	fscanf(file,"\nsymbol table (.symtab):\n");



	fprintf(fileout, "\n	\
typedef struct symtab\n	 \
{\n			\
	int fun_start_address;\n	\
	int fun_size;\n	\
}symtab;\n	\
\n	\
__attribute__((section(\".symtab\"))) symtab symbols[200]= { \
");

	i=0;
	fscanf(file, "entry: %d \n%[^\n] st_value:%x st_size:%d st_info:%[^\n] st_shndx:%d\n", &sno, name, &symbols[i].value, &symbols[i].size, info, &shndx);
	fprintf(fileout, "{0x%x, %d} ", symbols[i].value, symbols[i].size);

	for (i=1; i<1000; i++ )	
	{
	
		if( fscanf(file, "entry: %d \n%[^\n] st_value:%x st_size:%d st_info:%[^\n] st_shndx:%d\n", &sno, name, &symbols[i].value, &symbols[i].size, info, &shndx) == EOF )
			break;
		printf("entry: %d\n\tst_name:%s\n\tst_value:%x\n\tst_size:%d\n\tst_info:%s\n\tst_shndx:%d\n", sno, name, symbols[i].value, symbols[i].size, info, shndx); 
		//fprintf(fileout, "\n\tsymbols[%d].value = 0x%x; \n\tsymbols[%d].size = %d;", i, symbols[i].value, i, symbols[i].size);
		entry_exist_flag = 0;

		for (j=0; j < i ; j++ )
		{
			if(symbols[i].value == symbols[j].value)
			{
				entry_exist_flag = 1;
				break;
			}
		}
		if ( entry_exist_flag == 0 )
			fprintf(fileout, ",\n{0x%x, %d} ", symbols[i].value, symbols[i].size);

		
	}

	fprintf(fileout, "\n	\
};\n	\
\n	\
#define SYMTAB	\
");

	fclose(file);
	fclose(fileout);
}





