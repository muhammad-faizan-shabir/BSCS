#include<iostream>
using namespace std;

template<class T> // template class
class SortedSet
{
	struct node
	{
	public:
		T data;
		node* next;
		node() // Default Constructor
		{
			next = nullptr; // initialize next with nullptr
		}
	};
	node *head;
	node *tail;
	int size; // to store number of nodes
public:
	SortedSet() // Default Constructor
	{
		head = nullptr; // initialize head with nullptr
		tail = nullptr; // initialize tail with nullptr
		size = 0;
	}

	void insert(T const data)
	{
		node *current, *previous;
		current = head;
		previous = nullptr;

		while (current != nullptr && current->data < data) // either we move till end of list or we stop in the middle somewhere
		{
			previous = current;
			current = current->next;
		}

		if (current != nullptr && (current->data == data)) // making sure that the data to be inserted is not already in the list
		{
			return; // if the data is already in the list, then simply return
		}
		else // case when data is not duplicate
		{
			size = size + 1; // increment number of nodes
			node*tempNode = new node; // create a new node
			tempNode->data = data; // insert data in new node

			if (current == head) // case when new node is to be inserted at the head
			{
				tempNode->next = head; // new node will point to head node
				head = tempNode; // head will point to new node
			}
			else // case when new node is to be inserted other than at the head
			{
				tempNode->next = current; // new node points to current node
				previous->next = tempNode; // previous node points to new node
			}

			if (current == nullptr) // case when either the very first element is added to the list or the element is added at the last
			{
				tail = tempNode; // update tail
			}
		}
	}

	void Delete(int const index)
	{
		if (index >= 0) // if index is negative then deletion not possible
		{
			node*current, *previous;
			current = head;
			previous = nullptr;
			int counter = 0; // counter to reach the required index

			while (current != nullptr && counter < index) // either we reach at required index or we reach the end in which case the index does not exist
			{
				previous = current;
				current = current->next;
				counter = counter + 1;
			}

			if (current != nullptr) // making sure the list is not already empty and index to be deleted exists
			{
				size = size - 1; // decrement number of nodes
				if (counter == 0) // case when deletion at head
				{ 
					head = current->next; // update head
					delete current;  // delete the current node
					if (head == nullptr) // case when list becomes empty after deletion
					{
						tail = nullptr; // update tail
					} 
				}
				else
				{
					previous->next = current->next; // previous node points the node after current 
					delete current; // delete current node
					if (previous->next == nullptr) // case when the node at the last index is deleted
					{
						tail = previous; // update tail
					}
				}
			}
		}
	}

	void print() const
	{
		node*current = head;

		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	void Union(SortedSet<T>const &otherSet)
	{
		node * previousL1; // this pointer points to the previous node of list 1 (this set)
		node* currentL1;   // this pointer points to the current node of list 1 (this set)
		node* currentL2;   // this pointer points to the current node of list 2 (otherSet)
		previousL1 = nullptr; // initialize previousL1 wilh nullptr
		currentL1 = head;     // initialize currentL1 with head of list 1 (this set)
		currentL2 = otherSet.head; // initialize currentL2 with head of list 2 (otherSet)

		while ((currentL1 != nullptr) && (currentL2 != nullptr)) // loop will exit if either currentL1 is nullptr or currentL2 is nullptr
		{
			if (currentL1->data == currentL2->data) // case when element of list 1 matches element of list 2
			{
				currentL2 = currentL2->next; // skip the current elemnent of list 2 and point to the next
			}
			else if (currentL1->data<currentL2->data) // case when element of list 1 < element of list 2
			{
				if (currentL1->next == nullptr) // if (element of list 1 < element of list 2) and (element of list 1 is the at the end) then insertion of element of list 2 will be done at the end of list 1
				{
					node*temp = new node; // create a new node
					temp->data = currentL2->data; // put element of list 2 in new node
					temp->next = nullptr; // new node is inserted at the end so it will point to nullptr
					currentL1->next = temp; // current node of list 1 will point to new node
					currentL2 = currentL2->next; // point to the next element of list 2
					tail = temp; // update tail since new node is inserted at the end
				}
				previousL1 = currentL1; // point previous of list 1 to current node of list 1
				currentL1 = currentL1->next; // update current pointer of list 1
			}
			else // case when (element of list 1 > element of list 2), in which case insert the element of list 2 behind element of list 1
			{
				node*temp = new node; // create new node
				temp->data = currentL2->data; // put element of list 2 in the new node 
				temp->next = currentL1; // new node points to current of list 1
				if (currentL1 == head) // case when insertion at head
				{
					head = temp; // update head
				}
				else // case when insertion other than at head
				{
					previousL1->next = temp; // previous node points the new node
				}
				previousL1 = temp; // update previous
				currentL2 = currentL2->next; // point to next element of list 2
			}
		}

		if ((currentL1 == nullptr) && (currentL2 != nullptr)) // case when list 1 is empty and list 2 has some data
		{
			node*temp;
			while (currentL2 != nullptr) // loop ends when end of list 2 is reached
			{
				temp = new node; // make new node
				temp->data = currentL2->data; // put data of list to in new node
				temp->next = nullptr; // next of new node points to nullptr
				if (tail == nullptr) // case when insertion at head
				{
					head = temp; // update head
				}
				else // case when insertion at tail
				{
					tail->next = temp; // last node points to new node
				}
				tail = temp; // tail points to new node 
				currentL2 = currentL2->next; // point to next element of list 2
			}
		}
	}
	
	void rotate()
	{
		if (head != nullptr)
		{
			if (size == 1)
			{
				cout << "Size of list is 1 so it cannot be rotated" << endl;
			}
			else
			{
				int k; // number of times the list is to be rotated clockwise
				do
				{
					cout << "Enter value of k where k>0 and k<size of list which is " << size << ": ";
					cin >> k;
				} while (k <= 0 || k >= size); // loop will continue if k<=0 OR if k>=size in which case it will be a wrap-around and so rotation will make no sense

				for (int i = 0; i < k; i++) // loop will run k times and rotate the list k times where k>0 and k<size of list
				{
					node*firstNode = head; // temporarily hold the address of first node
					head = head->next; // make the second node as the head
					firstNode->next = tail->next; // original first node will point to next of tail node which is nullptr
					tail->next = firstNode; // tail node will point to the original first node
					tail = firstNode; // tail pointer will point to the original first node
				}
			}
		}
		else
		{
			cout << "List is empty so it cannot be rotated" << endl;
		}
	}

	~SortedSet() // Destructor
	{
		if (head != nullptr) // make sure list is not already empty
		{
			node * current, *ahead;
			current = head;
			ahead = nullptr;
			while (current != nullptr)
			{
				ahead = current->next; // save address of next node
				delete current; // delete current node
				current = ahead; // update current
			} 
		}
	}
};

int main()
{
	{
		SortedSet<int> s1; // create a set s1
		// insert some data in s1
		s1.insert(60);
		s1.insert(50);
		s1.insert(40);
		s1.insert(30);
		s1.insert(20);
		s1.insert(10);
		
		cout << "The set before rotation is:" << endl;
		s1.print(); // print s1 before rotation
		cout << endl;
		
		s1.rotate(); // call rotate function of SortedSet class
		cout << endl;
		cout << "The set after rotation is: " << endl;
		s1.print(); // print s1 after rotation
	}
	cout << endl;
	system("pause");
	return 0;
}