#include<iostream>
using namespace std;

template<class T> // template class
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

template<class T> // template class
class SortedSet
{
	node<T> *head;
	node<T> *tail;
public:
	template<class T>
	friend void reverseList(SortedSet<T> &list); // make reverseList() function a friend of this class
	
	SortedSet() // Default Constructor
	{
		head = nullptr; // initialize head with nullptr
		tail = nullptr; // initialize tail with nullptr
	}

	void insert(T const data)
	{
		node<T> *current, *previous;
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
			node<T>*tempNode = new node<T>; // create a new node
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
		node<T>*current = head;

		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	void Union(SortedSet<T>const &otherSet)
	{
		node<T> * previousL1; // this pointer points to the previous node of list 1 (this set)
		node<T>* currentL1;   // this pointer points to the current node of list 1 (this set)
		node<T>* currentL2;   // this pointer points to the current node of list 2 (otherSet)
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
					node<T>*temp = new node<T>; // create a new node
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
				node<T>*temp = new node<T>; // create new node
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
			node<T>*temp;
			while (currentL2 != nullptr) // loop ends when end of list 2 is reached
			{
				temp = new node<T>; // make new node
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
			node<T> * current, *ahead;
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

template<class T>
void reverseList(SortedSet<T> &list) // function to revesre the linked list
{
	if ((list.head != nullptr) && (list.head->next != nullptr)) // if list is empty or if the list has only one item then this 'if' block will not be executed
	{
		node<T> *current, *previous, *ahead;
		current = list.head;
		previous = nullptr;
		
		list.tail = list.head; // tail points to head
		while (current != nullptr)
		{
			ahead = current->next; // temporarily save address of next node
			current->next = previous; // current node will point to previous node
			previous = current; // update previous
			current = ahead; // update current
		}
		list.head = previous; // head points to the last node in the list
	}
}

int main()
{
	{
		SortedSet<int> s1;
		s1.insert(1);
		s1.insert(2);
		s1.insert(3);
		s1.insert(4);
		cout << "Set 's1' before being reversed:" << endl;
		s1.print();
		cout << "Set 's1' after being reversed:" << endl;
		reverseList(s1);
		s1.print();
		cout << endl;

		SortedSet<int> s2;
		s2.insert(1);
		s2.insert(2);
		s2.insert(3);
		s2.insert(4);
		s2.insert(5);
		cout << "Set 's2' before being reversed:" << endl;
		s2.print();
		cout << "Set 's2' after being reversed:" << endl;
		reverseList(s2);
		s2.print();
		cout << endl;
		
		SortedSet<int> s3;
		cout << "Set 's3' before being reversed:" << endl;
		s3.print();
		cout << "Set 's3' after being reversed:" << endl;
		reverseList(s3);
		s3.print();
		cout << endl;
		
		SortedSet<int> s4;
		s4.insert(1);
		cout << "Set 's4' before being reversed:" << endl;
		s4.print();
		cout << "Set 's4' after being reversed:" << endl;
		reverseList(s4);
		s4.print();
	}
	cout << endl;
	system("pause");
	return 0;
}