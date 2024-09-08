#include <stdio.h>

int main(int argc,char * argv[])
{
	if(argc!=2)
	{
		printf("Invalid Parmaters! Give one file name.\n");
		return 0;
	}

	FILE *read = fopen(argv[1], "r");
	if(read==NULL)
	{
		printf("Cannot open input file!\n");
		return 0;
	}

	FILE *write = fopen("PartB_Output.txt", "w"); 
	if(write==NULL)
	{
		printf("Cannot open output file!\n");
		return 0;
	}

	int data=fgetc(read);
	char ch;

	while(data!=EOF)
	{	
		if (data >= 48 && data <= 57)
		{
			ch = (char)data;
			fputc(ch, write);
			fputc(' ', write);
		}
		data=fgetc(read);
	}

	printf("Integer File generated successfully! with the name: 'PartB_Output.txt'\n");
	
	fclose(read);
	fclose(write);
	return 0;
}
