#include<iostream>
#include<stack>
using namespace std;

class minimumStack
{
	stack<int> mainStack;
public:
	void push(int num)
	{
		stack<int> tempStack;

		while(mainStack.empty() == false && mainStack.top()<num)
		{
			tempStack.push(mainStack.top());
			mainStack.pop();
		}

		mainStack.push(num);

		while(tempStack.empty() == false)
		{
			mainStack.push(tempStack.top());
			tempStack.pop();
		}
	}

	int pop(bool &dataFound)
	{
		if(mainStack.empty()==true)
		{
			dataFound = false;
			return 0;
		}
		else
		{
			int num= mainStack.top();
			mainStack.pop();
			return num;
		}
	}
};

int main()
{
	int arraySize = 7;
	int arr[7] = { 39,59,75,89,24,71,83 };

	minimumStack s;

	cout << "Data before insertion into the stack:" << endl;
	for(int i=0;i<arraySize;i++)
	{
		cout << arr[i] << ", ";
	}

	for(int i=0;i<arraySize;i++)
	{
		s.push(arr[i]);
	}

	cout << endl << endl;
	cout << "Data after removal from stack:" << endl;
	bool flag = true;
	int num = 0;

	while(flag==true)
	{
		num=s.pop(flag);
		if (flag == true)
		{
			cout << num << ", ";
		}
	}

	cout << endl;
	return 0;
}