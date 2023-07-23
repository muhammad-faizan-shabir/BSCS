#include <iostream>
using namespace std;
void Encrypt(char MessageBlock[],char Encrypted_Message[])
{
	char block[5][5];
	int index = 0;

	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(MessageBlock[index]==' ')
			{
				block[i][j] = '.';
				index++;
			}
			else if(MessageBlock[index]=='\0')
			{
				block[i][j] = '$';
			}
			else
			{
				block[i][j] = MessageBlock[index];
				index++;
			}
		}
	}
	index = 0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			Encrypted_Message[index] = block[j][i];
			index++;
		}
	}

	Encrypted_Message[index] = '\0';
}

void Decrypt(char Encrypted_Message[], char decrypted_message[])
{
	char block[5][5];
	int index = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			block[j][i]=Encrypted_Message[index];
			index++;
		}
	}
	index = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (block[i][j] == '.')
			{
				decrypted_message[index] = ' ';
				index++;
			}
			else if (block[i][j] == '$')
			{
				decrypted_message[index] = '\0';
				j = 6;
				i = 6;
			}
			else
			{
				decrypted_message[index]= block[i][j];
				index++;
			}
		}
	}

}

int main()
{
	char message[26] = "Protect this message";
	char messageEnc[26];
	char decrypted_message[26];
	cout << "Original message is:  ";
	cout << message << endl << endl;

	Encrypt(message, messageEnc);
	cout << "Encrypted message is: ";
	cout << messageEnc << endl << endl;

	Decrypt(messageEnc, decrypted_message);
	cout << "Decrypted message is: ";
	cout << decrypted_message << endl << endl;
}

