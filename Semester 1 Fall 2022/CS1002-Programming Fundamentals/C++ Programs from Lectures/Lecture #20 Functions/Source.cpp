//Delete item from array. One function for deletion. One function for diplaying. One function for finding item
#include <iostream>
using namespace std;

void Delete(int a[],int index)
{
	a[index] = -1;
}

void display(int a[])
{
	for(int i=0;i<9;i++)
	{
		cout << a[i] << " ";
	}
}

int find(int a[],int item)
{
	int i;
	bool found=false;
	for( i =0;i<9;i++)
	{
		if(a[i]==item)
		{
			found = true;
			break;
		}
	}

	if(found==true)
	{
		return i;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int a[] = { 0,1,3,4,5,6,7,8,10 };
	int item;

	cout << "Array before deletion: " << endl;

	display(a);

	cout << endl<<"Enter item to be deleted: ";
	cin >> item;

	if(find(a,item)!=-1)
	{
		Delete(a, find(a, item));
		cout << endl;
		cout << "The array after deletion: " << endl;
		display(a);
	}
	else
	{
		cout << "Item not found";
	}


}