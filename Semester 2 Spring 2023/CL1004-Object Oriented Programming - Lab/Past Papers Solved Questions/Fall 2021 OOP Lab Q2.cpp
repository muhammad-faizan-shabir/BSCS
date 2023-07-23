#include<iostream>
using namespace std;

const int NAMELEN = 10;
const int NUMBERLEN = 8;
const int ADDRESSLEN = 30;

class MyDirectory
{
	int Id;
	char Name[NAMELEN];
	char TelephoneNumber[NUMBERLEN];
	char Address[ADDRESSLEN];
public:
	MyDirectory()
	{
		Id = 0;
		Name[0] = '\0';
		for (int i = 0; i < NUMBERLEN; i++)
		{
			TelephoneNumber[i] = '0';
		}
		Address[0] = '\0';
	}

	MyDirectory(int id, char * name, char* number, char* address)
	{
		Id = id;
		int i;
		for (i = 0; name[i] != '\0'; i++)
		{
			Name[i] = name[i];
		}
		Name[i] = '\0';

		for (int j = 0; j < 8; j++)
		{
			TelephoneNumber[j] = number[j];
		}

		for (i = 0; address[i] != '\0'; i++)
		{
			Address[i] = address[i];
		}
		Address[i] = '\0';
	}

	MyDirectory(const MyDirectory&obj)
	{
		Id = obj.Id;
		int i;
		for (i = 0; obj.Name[i] != '\0'; i++)
		{
			Name[i] = obj.Name[i];
		}
		Name[i] = '\0';

		for (int j = 0; j < 8; j++)
		{
			TelephoneNumber[j] = obj.TelephoneNumber[j];
		}

		for (i = 0; obj.Address[i] != '\0'; i++)
		{
			Address[i] = obj.Address[i];
		}
		Address[i] = '\0';
	}

	friend ostream& operator<<(ostream &strm, const MyDirectory &obj)
	{
		strm << obj.Id << endl;
		strm << obj.Name << endl;
		for (int i = 0; i <8; i++)
		{
			cout << obj.TelephoneNumber[i];
		}
		cout << endl;
		strm << obj.Address << endl;
		return strm;
	}

	friend istream& operator>>(istream &strm, MyDirectory &obj)
	{
		cout << "Enter Id: ";
		strm >> obj.Id;
		cout << "Enter name: ";
		strm.ignore();
		strm.getline(obj.Name, NAMELEN);
		cout << "Enter TelephoneNumber(must be eight digits): ";
		char arr[9];
		strm.getline(arr, 9);
		for (int i = 0; i < 8; i++)
		{
			obj.TelephoneNumber[i] = arr[i];
		}
		cout << "Enter Address: ";
		strm.getline(obj.Address, ADDRESSLEN);
		return strm;
	}

	char& operator[](int i)
	{
		return TelephoneNumber[i];
	}

	MyDirectory operator=(const MyDirectory &obj)
	{
		if (this != &obj)
		{
			Id = obj.Id;
			int i;
			for (i = 0; obj.Name[i] != '\0'; i++)
			{
				Name[i] = obj.Name[i];
			}
			Name[i] = '\0';

			for (int j = 0; j < 8; j++)
			{
				TelephoneNumber[j] = obj.TelephoneNumber[j];
			}

			i = 0;
			for (; obj.Address[i] != '\0'; i++)
			{
				Address[i] = obj.Address[i];
			}
			Address[i] = '\0';
		}
		return obj;
	}
};



int main()
{
	MyDirectory directory(20, "FAST Nu", "11112812", "Block B,Faisal Town");
	cout << directory;
	directory[3] = '9';
	cout << directory;
	char x = directory[5];
	cout << x << endl;

	MyDirectory directory1;

	directory1 = directory;
	cout << directory1;

	MyDirectory directory2;
	cin >> directory2;
	cout << directory2;
	cout << endl;
	system("pause");
}