#include <stdio.h>

int main(int argc,char * argv[])
{
	if(argc!=2)
	{
		printf("Invalid parameters passed! Give one file name.\n");
		return 0;
	}
	
	FILE * filePtr = fopen(argv[1], "r");

	if(filePtr==NULL)
	{
		printf("Cannot open file!\n");
		return 0;		
	}
	
	char ch;
	int data=fgetc(filePtr);

	while(data!=EOF)
	{	
		ch = (char)data;
		printf("%c", ch);
		data=fgetc(filePtr);
	}

	printf("\n");
	
	fclose(filePtr);
	return 0;
}
