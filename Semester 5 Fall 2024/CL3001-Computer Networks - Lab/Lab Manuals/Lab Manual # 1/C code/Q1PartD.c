#include <stdio.h>
#include <string.h>

void invert(char * buff,int size)
{
	int s=0;
	int e=size-1;

	while(s<e)
	{
		char temp=buff[s];
		buff[s]=buff[e];
		buff[e]=temp;
		s=s+1;
		e=e-1;
	}
}

int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		printf("Invalid parameters! Give one file name.\n");
		return 0;
	}

	FILE *read = fopen(argv[1], "r");
	if(read==NULL)
	{
		printf("Cannot open input file!\n");
		return 0;
	}

	FILE *write = fopen("PartD_Output.txt", "w"); 
	if(write==NULL)
	{
		printf("Cannot open output file!\n");
		return 0;
	}

	char buff[200];
	int status = fscanf(read, "%s", buff);
	
	while(status!=EOF)
	{
		int i = 0;
		int vowelFound = 0;

		for(i = 0; buff[i] != '\0'; i++)
		{
			if ((buff[i] == 'a') || (buff[i] == 'e') ||
			 (buff[i] == 'i') || (buff[i] == 'o') || (buff[i] == 'u') || 
			 (buff[i] == 'A') || (buff[i] == 'E') ||
			 (buff[i] == 'I') || (buff[i] == 'O') || (buff[i] == 'U'))
			 {
				vowelFound = 1;
			 }
		}
		
		if (vowelFound==1)
		{
			invert(buff,strlen(buff));
		}
		
		fputs(buff, write);
		fputc(' ', write);
		status= fscanf(read, "%s", buff);
	}
	
	printf("Inverted word file generated successfully! with the name: PartD_Output.txt\n");
	
	fclose(read);
	fclose(write);
	return 0;
}


