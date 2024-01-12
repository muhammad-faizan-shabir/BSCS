#include<iostream>
using namespace std;

template<class T>
class Heap
{
public:
	T* elements;
	int numElements;

	Heap()
	{
		elements = nullptr;
		numElements = 0;
	}

	void ReheapDown(int root,int bottom)
	{
		int maxChild, rightChild, leftChild;

		leftChild = 2 * root + 1;
		rightChild = 2 * root + 2;

		if(leftChild<=bottom)
		{
			if(leftChild==bottom)
			{
				maxChild = leftChild;
			}
			else
			{
				if(elements[leftChild]>=elements[rightChild])
				{
					maxChild = rightChild;
				}
				else
				{
					maxChild = leftChild;
				}
			}

			if(elements[root]>elements[maxChild])
			{
				T temp = elements[root];
				elements[root] = elements[maxChild];
				elements[maxChild] = temp;
				ReheapDown(maxChild, bottom);
			}
		}
	}

	void ReheapDownIterative(int root,int bottom)
	{
		int maxChild, rightChild, leftChild;
		leftChild = 2 * root + 1;
		rightChild = 2 * root + 2;
		bool flag=false;
		while(leftChild<=bottom&&flag!=true)
		{
			flag = true;
			if (leftChild == bottom)
			{
				maxChild = leftChild;
			}
			else
			{
				if (elements[leftChild] >= elements[rightChild])
				{
					maxChild = rightChild;
				}
				else
				{
					maxChild = leftChild;
				}
			}


			if (elements[root] > elements[maxChild])
			{
				T temp = elements[root];
				elements[root] = elements[maxChild];
				elements[maxChild] = temp;
				flag = false;
			}
			root = maxChild;
			leftChild = 2 * root + 1;
			rightChild = 2 * root + 2;
		}
	}

	void ReheapUp(int root,int bottom)
	{
		int parent;

		if(bottom>root)
		{
			parent = (bottom - 1) / 2;
			if(elements[parent]>elements[bottom])
			{
				T temp = elements[parent];
				elements[parent] = elements[bottom];
				elements[bottom] = temp;
				ReheapUp(root, parent);
			}
		}
	}

	void ReheapUpIterative(int root,int bottom)
	{
		int parent;
		bool flag = false;
		while(bottom>root&&flag!=true)
		{
			flag = true;
			parent = (bottom - 1) / 2;
			if (elements[parent] > elements[bottom])
			{
				T temp = elements[parent];
				elements[parent] = elements[bottom];
				elements[bottom] = temp;
				flag = false;
			}
			bottom = parent;
		}
	}

	void HeapSort(int numItems)
	{
		int index;
		for(index=(numItems/2)-1;index>=0;index--)
		{
			ReheapDown(index, numItems - 1);
		}

		for(index=numItems-1;index>=1;index--)
		{
			T temp = elements[0];
			elements[0] = elements[index];
			elements[index] = temp;
			ReheapDown(0, index - 1);
		}
	}

	
	~Heap()
	{
		delete[] elements;
	}
};


template<class T>
class PQType
{
private:
	int numItems;
	Heap<T> heap;
	int maxItems;

public:
	PQType(int maxItems=10)
	{
		this->maxItems = maxItems;
		heap.elements = new T[maxItems];
		numItems = 0;
	}

	void MakeEmpty()
	{
		numItems = 0;
	}

	void Dequeue(T&item)
	{
		if(!isEmpty())
		{
			item = heap.elements[0];
			heap.elements[0] = heap.elements[numItems - 1];
			numItems--;
			heap.ReheapDownIterative(0, numItems - 1);
		}
	}

	void Enqueue(T newItem)
	{
		numItems++;
		heap.elements[numItems - 1] = newItem;
		heap.ReheapUpIterative(0, numItems - 1);
	}



	bool isFull()
	{
		return numItems == maxItems;
	}

	bool isEmpty()
	{
		return numItems == 0;
	}

	void HeapSort()
	{
		heap.HeapSort(numItems);
	}

	void printHeap()
	{
		for(int i=0;i<numItems;i++)
		{
			cout << heap.elements[i] << " ";
		}
		cout << endl;
	}


};

int main()
{
	PQType<int> q;

	q.Enqueue(40);
	q.Enqueue(60);
	q.Enqueue(6);
	q.Enqueue(30);
	q.Enqueue(70);
	q.Enqueue(12);
	q.Enqueue(10);

	q.printHeap();
	int n; 
	
	q.Dequeue(n);

	q.printHeap();
	q.Enqueue(2);
	q.printHeap();


	
}
