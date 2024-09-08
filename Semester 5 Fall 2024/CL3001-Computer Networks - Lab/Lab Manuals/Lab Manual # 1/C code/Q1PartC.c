#include <stdio.h>

int main(int argc,char * argv[])
{
	if(argc!=2)
	{
		printf("Invalid Parameters! Give one file name.\n");
		return 0;
	}

	FILE *read = fopen(argv[1], "r");
	if(read==NULL)
	{
		printf("Cannot open input file!\n");
		return 0;
	}

	FILE *write = fopen("PartC_Output.txt", "w"); 
	if(write==NULL)
	{
		printf("Cannot open output file!\n");
		return 0;
	}
	
	char buff[200];
	int data = fscanf(read, "%s", buff);

	while(data!=EOF)
	{
		int i = 0;
		int alphabetsPresent = 0;

		for(i = 0; buff[i] != '\0'; i++)
		{
			if ((buff[i] >= 'A' && buff[i] <= 'Z') || (buff[i] >= 'a' && buff[i] <= 'z'))
				alphabetsPresent = 1;
		}
		
		if (alphabetsPresent==0)
		{
			fputs(buff, write);
			fputc(' ', write);
		}
		data = fscanf(read, "%s", buff);
	}	

	printf("Non-alphabet word file generated successfully! with the name: 'PartC_Output.txt'\n");

	fclose(read);
	fclose(write);
	return 0;
}
