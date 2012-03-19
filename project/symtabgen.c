
#include <stdio.h>
#include <malloc.h>


#define TRUE 1
#define FALSE 0

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
	int sno, value, size, shndx;
	char name[50], info[50];
	int i,j;
	int entry_exist_flag;
	
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
	uint32_t fun_start_address;\n	\
	uint32_t fun_size;\n	\
	int load_time_address;\n\
	int presentbit;\n\
}symtab;\n\
\n	\
__attribute__((section(\".symtab\"))) symtab symbols[200]= { \
");

	i=0;
	fscanf(file, "entry: %d \n%[^\n] st_value:%x st_size:%d st_info:%[^\n] st_shndx:%d\n", &sno, name, &symbols[i].value, &symbols[i].size, info, &shndx);
	fprintf(fileout, "{0x%x, %d} ", symbols[i].value, symbols[i].size);

	for (i=1; i<200; i++ )	
	{
	
	if( fscanf(file, "entry: %d \n%[^\n] st_value:%x st_size:%d st_info:%[^\n] st_shndx:%d\n", &sno, name, &symbols[i].value, &symbols[i].size, info, &shndx) == EOF )
			break;

		entry_exist_flag = FALSE;
		for (j=0; j < i ; j++ )
		{
			if(symbols[i].value == symbols[j].value)
			{
				entry_exist_flag = TRUE;
				break;
			}
		}
		if ( (entry_exist_flag == FALSE)  && (symbols[i].size != 0) )
			fprintf(fileout, ",\n{0x%x, %d, 0, 0} ", symbols[i].value, symbols[i].size);

		
	}

	fprintf(fileout, "\n	\
};\n	\
\n	\
#define SYMTAB	\
");

	fclose(file);
	fclose(fileout);
}





