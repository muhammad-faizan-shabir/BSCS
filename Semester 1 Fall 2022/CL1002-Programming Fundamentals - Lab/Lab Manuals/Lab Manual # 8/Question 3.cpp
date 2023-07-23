# include <iostream>
using namespace std;
int main()
{
	int arr[10];
	int DistinctArray[10];
	int size=0;
	int temp;
	int num;
	int size2;

	while ((size > 10) || (size <= 0))
	{
		cout << "You can enter upto 10 integers, so how many intgers yoou want to enter: ";
		cin >> size;
	}

	cout << "Enter " << size << " integers: " << endl;

	for (int i = 0; i < size; i++)
	{
		cin >> num;
		arr[i] = num;
	}

	DistinctArray[0] = arr[0];
	size2 = 1;

	for (int i=1; i < size; i++)
	{
		temp = arr[i];
		bool flag = true;

		for (int j = 0; j < size2; j++)
		{
			if (temp == DistinctArray[j])
			{
				flag = false;
				break;
			
			}
		}

		if (flag == true)
		{
			DistinctArray[size2] = temp;
			size2++;
		}
	}


	int n = size2 - 1;
	for (int i = 0; i < size2 - 1;i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (DistinctArray[j]>DistinctArray[j + 1])
			{
				temp = DistinctArray[j];
				DistinctArray[j] = DistinctArray[j + 1];
				DistinctArray[j + 1] = temp;
			}
		}
		n--;
	}
	cout << endl << endl << "Output is: " << endl;

	for (int j = 0; j < size2; j++)
	{
		cout << DistinctArray[j] << endl;
	}

	
	
}