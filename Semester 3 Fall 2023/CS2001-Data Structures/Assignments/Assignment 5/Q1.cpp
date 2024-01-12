#include<iostream>
using namespace std;

class IntervalHeap
{
	int hsize; // size of interval heap
	int maxsize; // max capacity of heap
	int** h; // a pointer to interval heap
	bool left; // flag to know that whether the last node has data at right or left when the number of elements are odd
public:
	IntervalHeap(int s=100) // constructor
	{
		maxsize = s;
		hsize = 0;
		h = new int* [2]; // two pointers, one for min heap and one for max heap
		h[0] = new int[maxsize]; // array for min heap
		h[1] = new int[maxsize]; // array for mac heap
		left = false; 
	}

	bool isFull() // function that tells whether the heap if full or not
	{
		return (hsize) == maxsize;
	}

	bool isEmpty() // function that tells whether the heap is empty or not
	{
		return (hsize) == 0;
	}

	void Insert(int d) // function to insert elements in the heap
	{
		if (!isFull()) // make sure the heap is not full
		{
			if (hsize == 0) // case when the heap is completely empty
			{
				h[0][0] = d; // the data becomes part of min heap by default
				left = true; // left flag becomes true
				hsize++; // update size
			}
			else if (hsize == 1) // case when there is only one element 
			{
				if (h[0][0] <= d) // check i element on left is smaller or equal
				{
					h[1][0] = d; // put data on right side
				}
				else
				{
					h[1][0] = h[0][0]; // else move the left data to right
					h[0][0] = d; // put the data on left side
				}
				hsize++; // update size
			}
			else if (hsize % 2 == 0) // case when more than one elements and they are even numbered
			{
				int parent = ((hsize / 2) - 1) / 2; // calculate parent node of the node in which data is to be inserted
				if (d >= h[0][parent] && d <= h[1][parent]) // case when data is between the range of parent node
				{
					h[0][(hsize / 2)] = d; // the data becomes part of min heap by default
					hsize++; // update size
					left = true; // make left flag true
				}
				else if (d < h[0][parent]) // case when data is less than left bound of parent
				{
					h[0][(hsize / 2)] = d; // the data becomes part of min heap 
					reheapUpMin(h[0], 0, hsize / 2); // call reheapUpMin to restore heap property
					hsize++; // update size
					left = true; // make left flag true
				}
				else // case when data is greater than right bound of parent
				{
					h[1][(hsize / 2)] = d; // the data becomes part of max heap 
					reheapUpMax(h[1], 0, hsize / 2); // call reheapUpMax to restore heap property
					hsize++; // update size
					left = false; // make left flag false
				}
			}
			else // case when more than one elements and they are odd numbered
			{
				int parent = ((hsize / 2) - 1) / 2; // calculate parent node of the node in which data is to be inserted
				if (d >= h[0][parent] && d <= h[1][parent]) // case when data is between the range of parent node
				{
					if (left == true) // case if some data is at left side
					{
						if (d >= h[0][hsize / 2]) // add new data on right side if new data is greater than data on left side 
						{
							h[1][hsize / 2] = d; 
						}
						else // add new data on left side if new data is less than data on left side 
						{
							h[1][hsize / 2] = h[0][hsize / 2];
							h[0][hsize / 2] = d;
						}
						hsize++; // update size
					}
					else // case if some data is at right side
					{
						if (d <= h[1][hsize / 2]) // add new data on left side if new data is less than data on right side 
						{
							h[0][hsize / 2] = d;
						}
						else // add new data on right side if new data is greater than data on right side 
						{
							h[0][hsize / 2] = h[1][hsize / 2];
							h[1][hsize / 2] = d;
						}
						hsize++; // update size
					}
				}
				else if (d < h[0][parent]) // case when data is less than left bound of parent
				{
					if (left == true) // case when there is already some data on the left side
					{
						h[1][hsize / 2] = h[0][hsize / 2]; // move existing left side data to right side
						h[0][hsize / 2] = d; // put new data on the left side
						reheapUpMin(h[0], 0, hsize / 2); // call reheapUpMin to restore heap property
					}
					else // case when there is no data on the left side
					{ 
						h[0][hsize / 2] = d; // put new data on the left side
						reheapUpMin(h[0], 0, hsize / 2); // call reheapUpMin to restore heap property
					}
					hsize++; // update size
				}
				else // case when data is greater than right bound of parent
				{
					if (left == false) // case when there is already some data on the right side
					{
						h[0][hsize / 2] = h[1][hsize / 2]; // move existing right side data to left side
						h[1][hsize / 2] = d; // put new data on the right side
						reheapUpMax(h[1], 0, hsize / 2);  // call reheapUpMax to restore heap property
					}
					else
					{
						h[1][hsize / 2] = d; // put new data on the right side
						reheapUpMax(h[1], 0, hsize / 2); // call reheapUpMax to restore heap property
					}
					hsize++;  // update size
				}
			}
		}
	}

	bool update(int find, int replace) // function to update a value in the interval heap
	{
		bool found = false; // flag to know whether the data is found
		int n; // the index till which to traverse
		int i = 0; 
		if (hsize % 2 == 0) // case when even number of elements in the heap
		{
			n = (hsize / 2) - 1; // last index for both arrays is (hsize / 2) - 1
		}
		else // case when odd number of elements in the heap
		{
			if (left == true)  // case when more elements in min heap
			{
				n = (hsize / 2); // last index for min array
			}
			else // case when more elements in max heap
			{
				n = (hsize / 2) - 1; // last index for min array
			}
		}

		for (i = 0; (i <= n) && (found == false); i++) // traverse till last index of min array
		{
			if (h[0][i] == find)
			{
				found = true; // set the flag if data to be updated is found
			}
		}

		i--;
		if (found == true) // case when data is found in min heap
		{
			updateMin(i, replace); // call updateMin() 
			return true;
		}

		if (hsize % 2 == 0) // case when even number of elements in the heap
		{
			n = (hsize / 2) - 1; // last index for both arrays is (hsize / 2) - 1
		}
		else // case when odd number of elements in the heap
		{
			if (left == true)   // case when more elements in min heap
			{ 
				n = (hsize / 2) - 1; // last index for max array
			}
			else // case when more elements in max heap
			{
				n = (hsize / 2); // last index for max array
			}
		}

		for (i = 0; (i <= n) && (found == false); i++) // traverse till last index of max array
		{
			if (h[1][i] == find)
			{
				found = true; // set the flag if data to be updated is found
			}
		}

		i--;
		if (found == true) // case when data is found in max heap
		{
			updateMax(i, replace); // call updateMax()  
			return true;
		}

		return false; // return false if the data to be updated is not found in the heap
	}

	void updateMin(int i, int replace) // function to update an element in the min heap
	{
		if ((hsize % 2 != 0) && (i == (hsize / 2))) // case when there are odd number of elements and the node with only one element is to be updated
		{
			h[0][i] = replace; // update the data
			reheapUpMin(h[0], 0, i); // call reheapUpMin to restore heap property
		}
		else // case when the data is somewhere in the middle in the min heap and not at the last index
		{
			if (replace > h[1][i]) // case when replacement is greater than right bound
			{
				int n;
				if (hsize % 2 == 0)  // case when even number of elements in the heap
				{
					n = (hsize / 2) - 1; // last index for both arrays is (hsize / 2) - 1
				}
				else // case when odd number of elements in the heap
				{
					if (left == true) // case when more elements in min heap
					{
						n = (hsize / 2); // last index for min array
					}
					else // case when more elements in max heap
					{ 
						n = (hsize / 2) - 1;  // last index for min array
					}
				}
				h[0][i] = h[1][i]; // the right bound becomes the left bound
				h[1][i] = replace; // the replacement data becomes the right bound
				reheapUpMax(h[1], 0, i); // call reheapUpMax to restore max heap property
				ReHeapDownMin(h[0], h[1], i, n); // call ReHeapDownMin to restore min heap property
			}
			else if ((replace > h[0][i]) && (replace <= h[1][i])) // case when replacement data is within the two bounds
			{
				int n; 
				if (hsize % 2 == 0) // case when even number of elements in the heap
				{
					n = (hsize / 2) - 1; // last index for both arrays is (hsize / 2) - 1
				}
				else // case when odd number of elements in the heap
				{
					if (left == true) // case when more elements in min heap
					{
						n = (hsize / 2); // last index for min array
					}
					else // case when more elements in max heap
					{
						n = (hsize / 2) - 1; // last index for min array
					}
				}
				h[0][i] = replace; // replacement data becomes the left bound
				ReHeapDownMin(h[0], h[1], i, n); // call ReHeapDownMin to restore min heap property
			}
			else if (replace < h[0][i]) // case when replacement data is less than the left bound
			{
				h[0][i] = replace; // replacement data becomes the left bound
				reheapUpMin(h[0], 0, i); // call reheapUpMin to restore min heap property
			}
		}
	}

	void updateMax(int i, int replace) // function to update an element in the max heap
	{
		if ((hsize % 2 != 0) && (i == (hsize / 2))) // case when there are odd number of elements and the node with only one element is to be updated
		{
			h[1][i] = replace; // update the data
			reheapUpMax(h[1], 0, i); // call reheapUpMax to restore heap property
		}
		else // case when the data is somewhere in the middle in the max heap and not at the last index
		{
			if (replace < h[0][i]) // case when replacement is lesser than left bound
			{
				int n;
				if (hsize % 2 == 0) // case when even number of elements in the heap
				{
					n = (hsize / 2) - 1; // last index for both arrays is (hsize / 2) - 1
				}
				else // case when odd number of elements in the heap
				{
					if (left == true) // case when more elements in min heap
					{
						n = (hsize / 2) - 1; // last index for max array
					} 
					else // case when more elements in max heap
					{
						n = (hsize / 2); // last index for max array
					}
				}
				h[1][i] = h[0][i]; // the left bound becomes the right bound
				h[0][i] = replace; // the replacement data becomes the left bound
				reheapUpMin(h[0], 0, i); // call reheapUpMin to restore min heap property
				ReHeapDownMax(h[1], h[0], i, n); // call ReHeapDownMax to restore max heap property
			}
			else if ((replace >= h[0][i]) && (replace < h[1][i])) // case when replacement data is within the two bounds
			{
				int n; 
				if (hsize % 2 == 0) // case when even number of elements in the heap
				{
					n = (hsize / 2) - 1; // last index for both arrays is (hsize / 2) - 1
				}
				else // case when odd number of elements in the heap
				{
					if (left == true)  // case when more elements in min heap
					{
						n = (hsize / 2) - 1; // last index for max array
					}
					else // case when more elements in max heap
					{
						n = (hsize / 2); // last index for max array
					}
				}
				h[1][i] = replace; // replacement data becomes the right bound
				ReHeapDownMax(h[1], h[0], i, n);  // call ReHeapDownMax to restore max heap property
			}
			else if (replace > h[1][i]) // case when replacement data is greater than the right bound
			{
				h[1][i] = replace; // replacement data becomes the right bound
				reheapUpMax(h[1], 0, i); // // call reheapUpMax to restore max heap property
			}
		}
	}

	bool deleteMin(int& min) // function to delete minimum element from min heap
	{
		if (isEmpty()) // case when the heap is empty
		{
			return false;
		}
		else // case when the heap is not empty
		{
			if (hsize == 1) // case when there is only one element in the heap
			{
				if (left == true) // case when that one element is the left bound
				{
					min = h[0][0]; // get that left bound
					hsize--; // update size
					return true;
				}
				else // case when that one element is the right bound
				{
					min = h[1][0];  // get that right bound
					hsize--; // update size
					return true;
				}
			}
			else if (hsize % 2 == 0) // case when more than one elements in the heap and they are even numbered
			{ 
				min = h[0][0]; // get the left bound from top node
				h[0][0] = h[0][(hsize / 2) - 1]; // put the last element from min array at the top
				left = false; // make left flag false
				ReHeapDownMin(h[0], h[1], 0, (hsize / 2) - 2); // call ReHeapDownMin() to restore min heap property
				hsize--; // update size
				return true;
			}
			else // case when more than one elements in the heap and they are odd numbered
			{
				if (left == true) // case when more elements in min heap
				{
					min = h[0][0]; // get the left bound from top node
					h[0][0] = h[0][hsize / 2]; // put the last element from min array at the top
					ReHeapDownMin(h[0], h[1], 0, (hsize / 2) - 1); // call ReHeapDownMin() to restore min heap property
					hsize--; // update size
					return true; 
				}
				else // case when more elements in max heap
				{
					min = h[0][0]; // get the left bound from top node
					h[0][0] = h[1][hsize / 2]; // put the last element from min array at the top
					ReHeapDownMin(h[0], h[1], 0, (hsize / 2) - 1); // call ReHeapDownMin() to restore min heap property
					hsize--; // update size
					return true;
				}
			}
		}
	}

	bool deleteMax(int& max) // function to delete maximum element from max heap
	{
		if (isEmpty()) // case when the heap is empty
		{
			return false;
		}
		else // case when the heap is not empty
		{
			if (hsize == 1) // case when there is only one element in the heap
			{
				if (left == true) // case when that one element is the left bound
				{ 
					max = h[0][0]; // get that left bound
					hsize--; // update size
					return true;
				}
				else // case when that one element is the right bound
				{
					max = h[1][0]; // get that right bound
					hsize--; // update size
					return true;
				}
			}
			else if (hsize % 2 == 0) // case when more than one elements in the heap and they are even numbered
			{
				max = h[1][0]; // get the right bound from top node
				h[1][0] = h[1][(hsize / 2) - 1]; // put the last element from max array at the top
				left = true; // make left flag true
				ReHeapDownMax(h[1], h[0], 0, (hsize / 2) - 2); // call ReHeapDownMax() to restore max heap property
				hsize--; // update size
				return true;
			}
			else // case when more than one elements in the heap and they are odd numbered
			{ 
				if (left == true) // case when more elements in min heap
				{
					max = h[1][0]; // get the right bound from top node
					h[1][0] = h[0][hsize / 2]; // put the last element from max array at the top
					ReHeapDownMax(h[1], h[0], 0, (hsize / 2) - 1); // call ReHeapDownMax() to restore max heap property
					hsize--; // update size
					return true;
				}
				else // case when more elements in max heap
				{
					max = h[1][0]; // get the right bound from top node
					h[1][0] = h[1][hsize / 2]; // put the last element from max array at the top
					ReHeapDownMax(h[1], h[0], 0, (hsize / 2) - 1); // call ReHeapDownMax() to restore max heap property
					hsize--; // update size
					return true;
				}
			}
		}
	}

	void print() // function print the interval heap
	{
		if (!isEmpty()) // make sure the heap is not empty 
		{ 
			if (hsize % 2 == 0) // case when there are even number of elements in the heap
			{
				cout << "Min: ";
				for (int i = 0; i < hsize / 2; i++) // traverse till last index of min array
				{
					cout << h[0][i];
					if (h[0][i] > 9) // if two digit number then less spacing
					{
						cout << " "; 
					}
					else // if one digit number then more spacing
					{
						cout << "  ";
					}
				}
				cout << endl;
				cout << "Max: ";
				for (int i = 0; i < hsize / 2; i++) // traverse till last index of max array
				{
					cout << h[1][i];
					if (h[1][i] > 9) // if two digit number then less spacing
					{
						cout << " ";
					}
					else // if one digit number then more spacing
					{
						cout << "  ";
					}
				}
				cout << endl;
			}
			else // case when there are odd number of elements in the heap
			{
				cout << "Min: ";
				for (int i = 0; i < (hsize / 2); i++) // traverse till n elements in min array
				{
					cout << h[0][i];
					if (h[0][i] > 9) // if two digit number then less spacing
					{ 
						cout << " ";
					}
					else // if one digit number then more spacing
					{
						cout << "  ";
					}
				}
				if (left == true) // case when min array has n+1 elements
				{
					cout << h[0][(hsize / 2)]; // print (n+1)th element in the min array
				}
				cout << endl;
				cout << "Max: ";
				for (int i = 0; i < (hsize / 2); i++) // traverse till n elements in max array
				{
					cout << h[1][i];
					if (h[1][i] > 9) // if two digit number then less spacing
					{
						cout << " ";
					}
					else // if one digit number then more spacing
					{
						cout << "  ";
					}
				}
				if (left == false) // case when max array has n+1 elements
				{
					cout << h[1][(hsize / 2)]; // print (n+1)th element in the max array
				} 
				cout << endl;
			}
		}
	}

	void ReHeapDownMin(int* arrMin, int* arrMax, int root, int bottom) // function to restore min heap property when violation at parent/root
	{
		if (arrMin[root] > arrMax[root]) // case when left bound is greater than the right bound
		{
			int temp = arrMin[root];
			arrMin[root] = arrMax[root];
			arrMax[root] = temp;
		}
		int minChild, rightChild, leftChild;
		leftChild = 2 * root + 1; // left child index
		rightChild = 2 * root + 2; // right child index
		if (leftChild < bottom) // make sure to stay within the bounds of min array
		{
			if (leftChild == bottom) // case when left child is the last element in the min array
			{ 
				minChild = leftChild;
			}
			else
			{
				if (arrMin[leftChild] < arrMin[rightChild]) // case when left child is smaller than right child
				{
					minChild = leftChild;
				}
				else // case when right child is smaller or equal to the left child
				{
					minChild = rightChild;
				}
			}
			if (arrMin[root] > arrMin[minChild]) // case when maxChild is less than parent
			{
				int temp = arrMin[root];
				arrMin[root] = arrMin[minChild];
				arrMin[minChild] = temp;
				ReHeapDownMin(arrMin, arrMax, minChild, bottom); // recursive call to ReHeapDownMin()
			}
		}
	}

	void ReHeapDownMax(int* arrMax, int* arrMin, int root, int bottom) // function to restore max heap property when violation at parent/root
	{
		if (arrMin[root] > arrMax[root]) // case when left bound is greater than the right bound
		{
			int temp = arrMin[root];
			arrMin[root] = arrMax[root];
			arrMax[root] = temp;
		}
		int maxChild, rightChild, leftChild;
		leftChild = 2 * root + 1; // left child index
		rightChild = 2 * root + 2; // right child index
		if (leftChild < bottom) // make sure to stay within the bounds of max array
		{
			if (leftChild == bottom) // case when left child is the last element in the max array
			{
				maxChild = leftChild;
			}
			else
			{
				if (arrMax[leftChild] > arrMax[rightChild]) // case when left child is greater than right child
				{
					maxChild = leftChild;
				}
				else // case when right child is greater or equal to the left child
				{
					maxChild = rightChild;
				}
			}
			if (arrMax[root] < arrMax[maxChild]) // case when maxChild is greater than parent
			{
				int temp = arrMax[root];
				arrMax[root] = arrMax[maxChild];
				arrMax[maxChild] = temp;
				ReHeapDownMax(arrMax, arrMin, maxChild, bottom); // recursive call to ReHeapDownMax()
			}
		}
	}

	void reheapUpMin(int *arr, int root,int bottom) // function to restore min heap property when violation at bottom/child
	{
		int parent;
		if(bottom>root) // make sure to stay within the bounds of min array
		{
			parent = (bottom - 1) / 2; // parent index
			if(arr[parent]>arr[bottom]) // case when bottom/child is less than parent
			{
				int temp = arr[parent];
				arr[parent] = arr[bottom];
				arr[bottom] = temp;
				reheapUpMin(arr, root, parent); // recursive call to reheapUpMin()
			}
		}
	}

	void reheapUpMax(int* arr, int root, int bottom) // function to restore max heap property when violation at bottom/child
	{
		int parent;
		if (bottom > root) // make sure to stay within the bounds of max array
		{
			parent = (bottom - 1) / 2; // parent index
			if (arr[parent] < arr[bottom]) // case when bottom/child is greater than parent
			{
				int temp = arr[parent];
				arr[parent] = arr[bottom];
				arr[bottom] = temp;
				reheapUpMax(arr, root, parent); // recursive call to reheapUpMax()
			}
		}
	}

	~IntervalHeap() // Destructor
	{
		delete[] h[0];
		delete[] h[1];
		delete[] h;
	}
};

int main()
{	
	IntervalHeap heap;
	int num;

	cout << "--------------------TEST 1--------------------" << endl;
	cout << "After inserting some elements into the interval heap: " << endl;
	heap.Insert(2);
	heap.Insert(30);
	heap.Insert(3);
	heap.Insert(17);
	heap.Insert(4);
	heap.Insert(15);
	heap.Insert(4);
	heap.Insert(12);
	heap.Insert(3);
	heap.Insert(11);
	heap.Insert(5);
	heap.Insert(10);
	heap.Insert(6);
	heap.Insert(15);
	heap.Insert(4);
	heap.Insert(10);
	heap.Insert(5);
	heap.Insert(11);
	heap.Insert(5);
	heap.Insert(9);
	heap.Insert(4);
	heap.Insert(7);
	heap.Insert(8);
	heap.Insert(8);
	heap.Insert(7);
	heap.Insert(9);
	heap.print();
	cout << endl;
	cout << "--------------------TEST 2--------------------" << endl;
	cout << "After inserting 40" << endl;
	heap.Insert(40);
	heap.print();
	cout << endl;
	cout << "--------------------TEST 3--------------------" << endl;
	cout << "After Updating 4 with 50" << endl;
	heap.update(4, 50);
	heap.print();
	cout << endl;
	cout << "--------------------TEST 4--------------------" << endl;
	cout << "After Updating 7 with 15 " << endl;
	heap.update(7, 15);
	heap.print();
	cout << endl;
	cout << "--------------------TEST 5--------------------" << endl;
	cout << "After Updating 2 with 2" << endl;
	heap.update(2, 2);
	heap.print();
	cout << endl;
	cout << "--------------------TEST 6--------------------" << endl;
	cout << "After Updating 3 with 1" << endl;
	heap.update(3, 1);
	heap.print();
	cout << endl;
	cout << "--------------------TEST 7--------------------" << endl;
	cout << "After Deleting Max element" << endl;
	heap.deleteMax(num);
	heap.print();
	cout << "Deleted Max Item is: " << num << endl;
	cout << endl;
	cout << "--------------------TEST 8--------------------" << endl;
	cout << "After Deleting Max element" << endl;
	heap.deleteMax(num);
	heap.print();
	cout << "Deleted Max Item is: " << num << endl;
	cout << endl;
	cout << "--------------------TEST 9--------------------" << endl;
	cout << "After Updating 9 with 7" << endl;
	heap.update(9, 7);
	heap.print();
	cout << endl;
	cout << "--------------------TEST 10--------------------" << endl;
	cout << "After Updating 12 with 2" << endl;
	heap.update(12, 2);
	heap.print();
	cout << endl;
	cout << "--------------------TEST 11--------------------" << endl;
	cout << "After Updating 17 with 16" << endl;
	heap.update(17, 16);
	heap.print();
	cout << endl;
	cout << "--------------------TEST 12--------------------" << endl;
	cout << "After Updating 15 with 15" << endl;
	heap.update(15, 15);
	heap.print();
	cout << endl;
	cout << "--------------------TEST 13--------------------" << endl;
	cout << "After Updating 16 with 18" << endl;
	heap.update(16, 18);
	heap.print();
	cout << endl;
	cout << "--------------------TEST 14--------------------" << endl;
	cout << "After Deleting Min element" << endl;
	heap.deleteMin(num);
	heap.print();
	cout << "Deleted Min Item is: " << num << endl;
	cout << endl;
	cout << "--------------------TEST 15--------------------" << endl;
	cout << "After Deleting Min element" << endl;
	heap.deleteMin(num);
	heap.print();
	cout << "Deleted Mix Item is: " << num << endl;
	cout << endl;
	cout << "--------------------TEST 16--------------------" << endl;
	cout << "After Updating 15 with 17" << endl;
	heap.update(15, 17);
	heap.print();
	cout << endl;
	system("pause");
	return 0;
}