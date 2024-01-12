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
public:
	SortedSet() // Default Constructor
	{
		head = nullptr; // initialize head with nullptr
		tail = nullptr; // initialize tail with nullptr
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
			node*tempNode =new node; // create a new node
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
				if (counter == 0) // case when deletion at head
				{
					head = current->next; // update head
					delete current; // delete the current node
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

		while ((currentL1!=nullptr)&&(currentL2 != nullptr)) // loop will exit if either currentL1 is nullptr or currentL2 is nullptr
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
		SortedSet<int> a; // make a set named 'a'
		// add data to set 'a'
		a.insert(18);
		a.insert(14);
		a.insert(12);
		a.insert(19);
		a.insert(16);
		a.insert(10);
		a.insert(11);
		cout << "Set 'a' after inserting some integers: " << endl;
		a.print(); // print set 'a'
		cout << endl;
		
		cout << "Set 'a' after deleting item at index 1: " << endl;
		a.Delete(1); // delete element at index 1 in set 'a'
		a.print();
		cout << endl;
		
		cout << "Set 'a' after deleting item at index 5: " << endl;
		a.Delete(5); // delete element at index 5 in set 'a'
		a.print();
		cout << endl;
		
		SortedSet<int> b; // make a set named 'b'
		// add data to set 'b'
		b.insert(25);
		b.insert(22);
		b.insert(18);
		b.insert(17);
		b.insert(16);
		b.insert(15);
		b.insert(14);
		b.insert(10);
		b.insert(3);
		b.insert(2);
		b.insert(1);

		cout << "Set 'b' after inserting some integers: " << endl;
		b.print(); // print set 'b'
		cout << endl;

		cout << "Current condition of set 'a': " << endl;
		a.print(); // print set 'a'
		cout << endl;
		
		cout << "Current condition of set 'b': " << endl;
		b.print(); // print set 'a'
		cout << endl;
		
		cout << "After taking union of set 'a' and set 'b':" << endl;
		a.Union(b); // call the union fucntion of set 'a' with set 'b' as parameter
		a.print(); // print set 'a' after performing union
	}
	cout << endl;
	system("pause");
	return 0;
}