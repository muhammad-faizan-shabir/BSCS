#include<iostream>
#include<string>
using namespace std;

class year
{
public:
	int yearData;
	int status; // status 0 means empty, status 1 means deleted status 2 means occupied
	year()
	{
		yearData = 0;
		status = 0;
	}
};

class city
{
public:
	string cityName;
	int status;
	year yearArr[7];
	city()
	{
		cityName = "";
		status = 0;
	}
};


class HashMap
{
public:
	city cityArr[10];
	int rows;
	int cols;
	HashMap()
	{
		rows = 10;
		cols = 7;
	}

	void insert(string city, int year)
	{
		int indexForCity = (city.length()) % rows;

		if (cityArr[indexForCity].cityName != city&&cityArr[indexForCity].status != 2)
		{
			cityArr[indexForCity].cityName = city;
			cityArr[indexForCity].status = 2;
		}
		else if (!(cityArr[indexForCity].cityName == city&&cityArr[indexForCity].status == 2))
		{
			int i = 1;
			while (cityArr[indexForCity].status == 2)
			{
				indexForCity = (city.length() + (i*i)) % rows;
				i++;
			}

			cityArr[indexForCity].cityName = city;
			cityArr[indexForCity].status = 2;
		}

		int indexForYear = year%cols;

		if (cityArr[indexForCity].yearArr[indexForYear].yearData != year&&cityArr[indexForCity].yearArr[indexForYear].status != 2)
		{
			cityArr[indexForCity].yearArr[indexForYear].yearData = year;
			cityArr[indexForCity].yearArr[indexForYear].status = 2;
		}
		else
		{
			int i = 1;
			while (cityArr[indexForCity].yearArr[indexForYear].status == 2)
			{
				indexForYear = (indexForYear + i) % cols;
				i++;
			}

			cityArr[indexForCity].yearArr[indexForYear].yearData = year;
			cityArr[indexForCity].yearArr[indexForYear].status = 2;
		}
	}

	void deleteYear(string city, int year)
	{
		int indexForCity = (city.length()) % rows;

		if (cityArr[indexForCity].cityName == city&&cityArr[indexForCity].status == 2)
		{
			int indexForYear = year%cols;
			if (cityArr[indexForCity].yearArr[indexForYear].yearData == year&&cityArr[indexForCity].yearArr[indexForYear].status == 2)
			{
				cityArr[indexForCity].yearArr[indexForYear].status = 1;
			}
			else
			{
				int i = 0;
				while (cityArr[indexForCity].yearArr[indexForYear].status != 0 && cityArr[indexForCity].yearArr[indexForYear].yearData!=year)
				{
					indexForYear = (indexForYear + i) % cols;
					i++;
				}
				
				if (cityArr[indexForCity].yearArr[indexForYear].yearData == year&&cityArr[indexForCity].yearArr[indexForYear].status == 2)
				{
					cityArr[indexForCity].yearArr[indexForYear].status = 1;
				}
			}
		}
		else
		{
			int i = 0;
			while (cityArr[indexForCity].cityName != city&&cityArr[indexForCity].status !=0)
			{
				indexForCity = (city.length() + (i*i)) % rows;
				i++;
			}

			if (cityArr[indexForCity].cityName == city&&cityArr[indexForCity].status == 2)
			{
				int indexForYear = year&cols;
				if (cityArr[indexForCity].yearArr[indexForYear].yearData == year&&cityArr[indexForCity].yearArr[indexForYear].status == 2)
				{
					cityArr[indexForCity].yearArr[indexForYear].status = 1;
				}
				else
				{
					int i = 0;
					while (cityArr[indexForCity].yearArr[indexForYear].status != 0 && cityArr[indexForCity].yearArr[indexForYear].yearData != year)
					{
						indexForYear = (indexForYear + i) % cols;
						i++;
					}

					if (cityArr[indexForCity].yearArr[indexForYear].yearData == year&&cityArr[indexForCity].yearArr[indexForYear].status == 2)
					{
						cityArr[indexForCity].yearArr[indexForYear].status = 1;
					}
				}
			}
		}
	}


	bool search(string city, int year,int &data)
	{
		int indexForCity = (city.length()) % rows;

		if (cityArr[indexForCity].cityName == city&&cityArr[indexForCity].status == 2)
		{
			if (cityArr[indexForCity].yearArr[year].status==2)
			{
				data = cityArr[indexForCity].yearArr[year].yearData;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			int i = 0;
			while (cityArr[indexForCity].cityName != city&&cityArr[indexForCity].status != 0)
			{
				indexForCity = (city.length() + (i*i)) % rows;
				i++;
			}

			if (cityArr[indexForCity].cityName == city&&cityArr[indexForCity].status == 2)
			{
				if (cityArr[indexForCity].yearArr[year].status == 2)
				{
					data = cityArr[indexForCity].yearArr[year].yearData;
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}

	void showHashmap()
	{
		for (int i = 0; i < rows; i++)
		{
			cout << cityArr[i].cityName << ": ";
			for (int j = 0; j < cols; j++)
			{
				cout << cityArr[i].yearArr[j].yearData << " ";
			}
			cout << endl;
		}
	}
};


int main()
{
	HashMap h1;
	cout << "After Inserting Information about Faisalabad city" << endl << endl;
	h1.insert("Faisalabad", 70);
	h1.insert("Faisalabad", 71);
	h1.insert("Faisalabad", 72);
	h1.insert("Faisalabad", 73);
	h1.insert("Faisalabad", 74);
	h1.insert("Faisalabad", 75);
	h1.insert("Faisalabad", 76);
	h1.showHashmap();
	cout << endl;
	system("pause");
}

