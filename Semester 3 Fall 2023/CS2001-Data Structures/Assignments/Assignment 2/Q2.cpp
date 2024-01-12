#include<iostream>
using namespace std;

template<class T> // template class
class stack
{
	int currentSize; // to hold current size of stack
	int MaxSize; // when this size is reached, the capacity is doubled and when less than half of this size is reached the capacity is halved
	int topOfStackPtr; // pointer to the element on top of stack
	int baseOfStackPtr; // pointer to the element at the bottom of the stack
	T* stackArray; // pointer to hold address of array
	bool flipped; // to tell whether stack is flipped or not. If stack is not flipped it grows rightwards and if it is flipped then it grows leftwards
public:
	stack(int s=10) // constructer
	{
		MaxSize = s;
		stackArray = new T[MaxSize]; // make array for stack
		topOfStackPtr = -1; // initially the stack is empty
		baseOfStackPtr = 0; // base is initially zero
		currentSize = 0; // current size is initially zero
		flipped = false; // the stack is initially not flipped
		for (int i = 0; i < MaxSize; i++)
		{
			stackArray[i] = 0; // put zero at every index to represent empty slot in the array
		}
	}

	void flipStack() // function to flip stack in constant time
	{
		flipped = !flipped; // when stack if flipped, the flipped flag is inverted
		int temp = topOfStackPtr; // temporarily store topOfStackPtr
		topOfStackPtr = baseOfStackPtr; // put baseOfStackPtr in topOfStackPtr
		baseOfStackPtr = temp; // put topOfStackPtr in baseOfStackPtr
	}

	void logicalIncrementOfTop() // function to update topOfStackPtr
	{
		if(flipped==false) // case when stack is not flipped in which case stack grows rightwards
		{
			topOfStackPtr = (topOfStackPtr + 1) % MaxSize; // increment topOfStackPtr by taking wraparound into account 
		}
		else // case when stack is flipped in which case stack grows leftwards
		{
			topOfStackPtr--; // decrement topOfStackPtr
			if(topOfStackPtr<0) // take wraparound into account
			{
				topOfStackPtr = MaxSize - 1;
			}
		}
	}
	
	void logicalDecrementOfTop() // function to update topOfStackPtr
	{
		if(flipped==false) // case when stack is not flipped in which case stack shrinks leftwards
		{
			topOfStackPtr--; // decrement topOfStackPtr
			if (topOfStackPtr < 0) // take wraparound into account
			{
				topOfStackPtr = MaxSize - 1;
			}
		}
		else // case when stack is flipped in which case stack shrinks rightwards
		{
			topOfStackPtr = (topOfStackPtr + 1) % MaxSize; // take wraparound into account
		}
	}

	void doubleCapacity() // function to double the capacity of the stack
	{
		T* tempStack = new T[MaxSize * 2]; // make a new array of double size
		for (int i = 0; i<MaxSize * 2; i++)
		{
			tempStack[i] = 0; // put zero at every index to represent empty slot in the array
		}
		T data; // variable to get popped data
		int index = currentSize - 1; // start adding data from rigth to left
		while(index>=0) // move data from old array to new array till every data item is moved
		{
			data=specialPop(); // pop data from old array
			tempStack[index] = data; // put data in new array
			index--; // decrement index
		}
		
		delete[] stackArray; // delete old array
		flipped = false; // make flipped as flase since now stack will grow towards right
		topOfStackPtr = currentSize-1; // topOfStackPtr will be the right most element in the new array
		baseOfStackPtr = 0; // baseOfStackPtr will be the left most element in the new array
		MaxSize = MaxSize * 2; // capacity is doubled
		stackArray = tempStack; // the stack pointer points to the new array
	}

	void halfCapacity() // function to half the capacity of stack
	{
		T* tempStack = new T[MaxSize/2]; // make new array of half size
		for (int i = 0; i < MaxSize / 2; i++)
		{
			tempStack[i] = 0; // put zero at every index to represent empty slot in the array
		}
		T data; // variable to get popped data
		int index = currentSize - 1; // start adding data from rigth to left
		while (index>=0) // move data from old array to new array till every data item is moved
		{
			data=specialPop(); // pop data from old array
			tempStack[index] = data; // put data in new array
			index--; // decrement index
		}
		
		delete[] stackArray; // delete old array
		flipped = false; // make flipped as flase since now stack will grow towards right
		topOfStackPtr = currentSize - 1; // topOfStackPtr will be the right most element in the new array
		baseOfStackPtr = 0; // baseOfStackPtr will be the left most element in the new array
		MaxSize = MaxSize/2; // capacity is halved
		stackArray = tempStack; // the stack pointer points to the new array
	}

	bool isEmpty() // function to tell whether the stack is empty or not
	{
		if(currentSize==0) 
		{
			return true; // return true if size is zero
		}
		else
		{
			return false; // return false if size is not zero
		}
	}
	
	void push(T const data) // function to push data on the top of stack
	{
		logicalIncrementOfTop(); // update the topOfStackPtr according to whether the stack is flipped or not
		stackArray[topOfStackPtr] = data; // put data on top of stack
		currentSize++; // increment size
		if(currentSize==MaxSize)  // if size reaches maximum capacity then double the capacity
		{
			doubleCapacity();
		}
	}
	
	bool pop(T &data) // function that pops data from top of stack into a reference sent as parameter
	{
		if(!isEmpty()) // make sure the stack is not empty
		{
			data = stackArray[topOfStackPtr]; // put data at top of stack into the reference sent as parameter
			stackArray[topOfStackPtr] = 0; // put zero at top of stack to represent empty slot
			logicalDecrementOfTop(); // update the topOfStackPtr according to whether the stack is flipped or not
			currentSize--; // decrement size
			if (currentSize < (MaxSize / 2)) // if half of the stack becomes empty then half the capacity
			{
				halfCapacity();
			}
			return true; 
		}
		return false;
	}

	T specialPop() // a special function to pop element, this function does not affect the size of the stack because when halving/doubling the capacity we do not want the size of stack to change
	{
		T data; // data to be returned
		data = stackArray[topOfStackPtr]; // put data at top of stack into the variable to be returned
		logicalDecrementOfTop(); // update the topOfStackPtr according to whether the stack is flipped or not
		return data; // return data at top of stack
	}

	void print() // function to print the stack
	{
		for(int i=0;i<MaxSize;i++) 
		{
			cout << stackArray[i] << " ";
		}
		cout << endl;
		cout << "TopIndex: " << topOfStackPtr << " BottomIndex: " << baseOfStackPtr << " Flipped status: " << flipped <<" Size: "<<currentSize <<endl;
	}
	
	~stack() // destructor
	{
		delete [] stackArray; // delete the array
	}
};

int main()
{
	stack<int> s1(5); // make a stack of 5 capacity
	int poppedData; // variable to get popped data
	// the following sequence of lines test the stack class for different cases
	cout << "The stack(capacity 5) before pushing anything, zeros represent empty space:" << endl;
	s1.print();
	cout << endl;
	
	cout << "The stack after pushing 6,3,9,4 elements:" << endl;
	s1.push(6);
	s1.push(3);
	s1.push(9);
	s1.push(4);
	s1.print();
	cout << endl;
	
	cout << "The stack after flipping:" << endl;
	s1.flipStack();
	s1.print();
	cout << endl;
	
	cout << "The stack after popping two elements:" << endl;
	s1.pop(poppedData);
	s1.pop(poppedData);
	s1.print();
	cout << endl;
	
	cout << "The stack after pushing 8,1:" << endl;
	s1.push(8);
	s1.push(1);
	s1.print();
	cout << endl;

	cout << "The stack after flipping again:" << endl;
	s1.flipStack();
	s1.print();
	cout << endl;

	cout << "After pushing 5th value 7, the doubled capacity stack is:" << endl;
	s1.push(7);
	s1.print();
	cout << endl;

	cout << "The stack after flipping again:" << endl;
	s1.flipStack();
	s1.print();
	cout << endl;

	cout << "After popping one element, the halved capacity stack is:" << endl;
	s1.pop(poppedData);
	s1.print();
	cout << endl;

	cout << "The stack after flipping again:" << endl;
	s1.flipStack();
	s1.print();
	cout << endl;

	cout << "The stack after popping two elements:" << endl;
	s1.pop(poppedData);
	s1.pop(poppedData);
	s1.print();
	cout << endl;

	cout << "The stack after flipping again:" << endl;
	s1.flipStack();
	s1.print();
	cout << endl;

	cout << "The stack after pushing 5,7:" << endl;
	s1.push(5);
	s1.push(7);
	s1.print();
	cout << endl;

	cout << "The stack after popping two elements:" << endl;
	s1.pop(poppedData);
	s1.pop(poppedData);
	s1.print();
	cout << endl;

	cout << "The stack after flipping again:" << endl;
	s1.flipStack();
	s1.print();
	cout << endl;

	cout << "The stack after pushing 4:" << endl;
	s1.push(4);
	s1.print();
	cout << endl;

	cout << "The stack after flipping again:" << endl;
	s1.flipStack();
	s1.print();
	cout << endl;

	cout << "The stack after popping one element:" << endl;
	s1.pop(poppedData);
	s1.print();
	cout << endl;
	
	cout << "The stack after flipping again:" << endl;
	s1.flipStack();
	s1.print();
	cout << endl;

	cout << "The stack after pushing 5,7:" << endl;
	s1.push(5);
	s1.push(7);
	s1.print();
	cout << endl;

	cout << "The stack after popping two elements:" << endl;
	s1.pop(poppedData);
	s1.pop(poppedData);
	s1.print();
	cout << endl;
	system("pause");
	return 0;
}