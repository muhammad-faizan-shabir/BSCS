#include<iostream>
using namespace std;

class StudentMaxHeap;

class Student // Question1
{
	friend class StudentMaxHeap;
private:
	int rollNo;
	double cgpa;
	Student(int rollNo=0,double cgpa=0) // constructor
	{
		this->rollNo = rollNo;
		this->cgpa = cgpa;
	}
};

class StudentMaxHeap
{
	Student* st;
	int currSize;
	int maxSize;
public:
	StudentMaxHeap(int maxSize=10) // Question1
	{
		this->maxSize = maxSize;
		st = new Student[maxSize];
		currSize = 0;
	}

	bool isEmpty() // Question1
	{
		return currSize == 0;
	}

	bool isFull() // Question1
	{
		return currSize == maxSize;
	}

	bool insert(int rollNo, double cgpa) // Question2
	{
		if (!isFull()) // make sure heap is not full
		{
			currSize++; // update size
			Student data(rollNo, cgpa); // make object of student
			st[currSize - 1] = data; // put student in array/heap
			ReheapUp(0, currSize - 1); // call ReheapUp() function to restore heap property
			return true;
		}
		else // case when array/heap is full
		{
			return false;
		}
	}

	bool removeBestStudent(int& rollNo, double& cgpa) // Question3
	{
		if (!isEmpty()) // make sure heap is not empty
		{
			rollNo = st[0].rollNo; // get roll number 
			cgpa = st[0].cgpa;  // get cgpa
			st[0] = st[currSize - 1];  // put last element on top of heap
			currSize--; // update size
			ReheapDown(0, currSize - 1); // call ReheapDown() function to restore heap property
		}
		else // case when array/heap is empty
		{
			return false;
		}
	}

	void ReheapDown(int root, int bottom) // Question4
	{
		int maxChild, rightChild, leftChild;

		leftChild = 2 * root + 1; // calculate left child index
		rightChild = 2 * root + 2; // calculate right child index

		if (leftChild <= bottom) // make sure you are within the bounds of the heap
		{
			if (leftChild == bottom) // case when left child is the last element of the array
			{
				maxChild = leftChild;
			}
			else
			{
				if (st[leftChild].cgpa >= st[rightChild].cgpa) //case when left child is greater or equal
				{
					maxChild = leftChild;
				}
				else if(st[leftChild].cgpa < st[rightChild].cgpa) // case when right child is greater
				{
					maxChild = rightChild;
				}
			}

			if (st[root].cgpa < st[maxChild].cgpa) // check if a swap of root is needed with its MaxChild
			{
				Student temp = st[root]; // swap root and MaxChild
				st[root] = st[maxChild];
				st[maxChild] = temp;
				ReheapDown(maxChild, bottom); // call ReheapDown() function for the MaxChild
			}
			else if(st[root].cgpa==st[maxChild].cgpa) // case when cgpas of root and MaxChild are same
			{
				if(st[root].rollNo>st[maxChild].rollNo) // decide on the basis of roll number
				{
					Student temp = st[root]; // swap based on roll numbers
					st[root] = st[maxChild];
					st[maxChild] = temp;
					ReheapDown(maxChild, bottom); // call ReheapDown() function for the MaxChild
				}
			}
		}
	}

	void ReheapUp(int root, int bottom) // Question4
	{
		int parent;

		if (bottom > root) // make sure we do not exceed the root of tree
		{
			parent = (bottom - 1) / 2; // caluculate parent for the current index
			if (st[parent].cgpa < st[bottom].cgpa) // check if parent needs to be swapped with its child
			{
				Student temp = st[parent]; // swap parent and child
				st[parent] = st[bottom];
				st[bottom] = temp;
				ReheapUp(root, parent); // call ReheapUp function for the parent
			}
			else if(st[parent].cgpa == st[bottom].cgpa) // case when cgpas of root and child are same
			{
				if(st[parent].rollNo>st[bottom].rollNo) // decide on the basis of roll number
				{ 
					Student temp = st[parent]; // swap parent and child
					st[parent] = st[bottom];
					st[bottom] = temp;
					ReheapUp(root, parent); // call ReheapUp function for the parent
				}
			}
		}
	}

	void buildHeap() // Question4
	{
		for(int index=(currSize/2)-1;index>=0;index--) // run loop in reverse
		{
			ReheapDown(index, currSize - 1); // call ReheapDown function for each non-leaf node starting from bottom
		}
	}

	void heapSort() // Question5
	{
		buildHeap(); // first build the heap before sorting
		for(int index=currSize-1;index>=1;index--) // run loop in reverse
		{
			Student temp = st[0]; // swap top element with bottom element
			st[0] = st[index];
			st[index] = temp;
			ReheapDown(0, index - 1); // call ReheapDown function for root with updated bottom
		}
	}

	void print() // function to print the heap
	{
		cout << "CGPAs: ";
		for(int i=0;i<currSize;i++)
		{
			cout << st[i].cgpa << " ";
		}
		cout << endl;

		cout << "Roll#: ";
		for (int i = 0; i < currSize; i++)
		{
			cout << st[i].rollNo<< "  ";
		}
		cout << endl;
	}

	~StudentMaxHeap() // Question1
	{
		delete [] st;
	}
};

int main()
{
	StudentMaxHeap heap;

	cout << "The heap after inserting some data: " << endl;
	heap.insert(13,2.3);
	heap.insert(14, 2.3);
	heap.insert(12, 1.3);
	heap.insert(10, 2.1);
	heap.insert(11, 1.2);
	heap.print();
	cout << endl;

	cout << "The heap after deleting student on top:" << endl;
	int rollNum;
	double cgpa;
	heap.removeBestStudent(rollNum, cgpa);
	heap.print();
	cout << endl;

	cout << "The heap after deleting student on top:" << endl;
	heap.removeBestStudent(rollNum, cgpa);
	heap.print();
	cout << endl;

	cout << "The heap after inserting two more students:" << endl;
	heap.insert(13, 3.1);
	heap.insert(14,3.5);
	heap.print();
	cout << endl;

	cout << "The heap after being sorted:" << endl;
	heap.heapSort();
	heap.print();

	cout << endl;
	system("pause");
	return 0;
}