#include<iostream>
using namespace std;

template<class T> // template class
class UndoStack
{
	int topOfStackPointer; // pointer to top of stack
	int size; // current size of stack
	T StackArray[100]; // array with capacity of 100
public:
	UndoStack()
	{
		topOfStackPointer = -1; // initially nothing is at the top of stack
		size = 0; // initial size is zero
		for(int i=0;i<100;i++) 
		{
			StackArray[i] = 0; // put zero at every index to represent an empty slot
		}
	}

	void push(T const data) // function to put data on top of stack
	{
		topOfStackPointer = (topOfStackPointer + 1) % 100; // increment the top of stack pointer while considering wraparound
		StackArray[topOfStackPointer] = data; // put data at top of stack
		if(size!=100) // if size is already 100 then no need to increment it
		{
			size++;
		}
	}

	bool pop(T &data) // function to pop data from top of stack into a reference sent as parameter
	{
		if (size != 0) // make sure the stack is not already empty
		{
			data = StackArray[topOfStackPointer]; // get data from top of stack
			StackArray[topOfStackPointer] = 0; // make top of stack zero to represent empty slot
			topOfStackPointer = topOfStackPointer - 1; // decrement top of stack pointer
			if(topOfStackPointer==-1) // take care of wrap around
			{
				topOfStackPointer = 99;
			}
			size--; // decrement size
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEmpty() // function to tell whether the stack is empty or not
	{
		if(size==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void print() // function to print the stack
	{
		for(int i=0;i<100;i++)
		{
			cout << StackArray[i] << " ";
		}
		cout << endl;
		cout << "Top Of Stack Index: " << topOfStackPointer << endl;
	}
};

int main()
{
	UndoStack<int> s1;
	cout << "The stack(100 capacity) is intially empty, zeros represent empty slots: " << endl;
	s1.print();
	cout << endl;

	cout << "The stack after pushing numbers from 1 to 100: " << endl;
	for(int i=0;i<100;i++)
	{
		s1.push(i+1);
	}
	s1.print();
	cout << endl;

	cout << "After making the 101th push with 200:" << endl;
	s1.push(200);
	s1.print();
	cout << endl;

	cout << "Popping and printing all elements: " << endl;
	int data = -1;
	for(int i=0;i<100;i++)
	{
		s1.pop(data);
		cout << data << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}