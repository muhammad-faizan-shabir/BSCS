#include<iostream>
using namespace std;

template<class T> // template class  
class DoublyLinkedList
{
	struct node // struct to store data, next and previous pointers
	{
		T data;
		node*next;
		node*previous;
		node() // constructor
		{
			next = nullptr;
			previous = nullptr;
		}
	};

	node*head;
	node*tail;
public:
	DoublyLinkedList() // constructor
	{
		head = nullptr;
		tail = nullptr;
	}

	void insertAtHead(T const element) // function to insert at head
	{
		node*temp = new node; // create new node
		temp->data = element; // add data in the new node

		temp->previous = nullptr;
		temp->next = head; // the new node will point to head
		
		if (head == nullptr) // case when list is initially empty
		{
			tail = temp; 
		}
		else // case when list has at least one element
		{
			head->previous = temp;
		}
		
		head = temp; // updating head pointer
	}

	void insertAtTail(T const element) // function to insert at tail
	{
		node*temp = new node; // create new node
		temp->data = element; // add data in new node
		 
		if (tail == nullptr) // case when list is empty
		{
			tail = temp; // tail points to new node
			head = temp; // head points to new node
			temp->next = nullptr; // new node's next point to null
			temp->previous = nullptr; // new node's previous will point to null
		}
		else // case when list has at least one element
		{
			temp->previous = tail; // new node's previous will point to tail
			temp->next = tail->next; // new node will point to next node of tail
			tail->next = temp; // tail's next will point to new node
			tail = temp; // updating tail
		}
	}

	void print() const // function to print the list
	{
		node*current = head; // start from head
		  
		while (current != nullptr) // move till end
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	void printReverse() const // function to print the list in reverse
	{
		node*current = tail; // start from tail
		
		while (current != nullptr) // move till start
		{
			cout << current->data << " ";
			current = current->previous;
		}
		cout << endl;
	}

	void deleteAtStart() // function to delete at head
	{
		if (head != nullptr) // ensuring that list is not already empty
		{
			node* temp = head; // saving address stored in head
			head = head->next; // updating head
			
			if (head == nullptr) // case when only one item in list
			{
				tail = nullptr;
			}
			else // case when more than one item in list
			{
				head->previous = nullptr;
			}
			
			delete temp; // delete the old head
		}
	}

	void deleteAtTail() // function to delete at tail 
	{
		if (tail != nullptr) // ensuring that list is not already empty
		{
			node*temp = tail; // saving address stored in tail
			tail = tail->previous; // updating tail
			
			if (tail == nullptr) // case when only one item in list
			{
				head = nullptr;
			}
			else // case when more than one item in list
			{
				tail->next = nullptr;
			}
			
			delete temp; // delete the old tail
		}
	}

	void deleteAtPosition(int k)
	{
		if (k >= 0) // k should not be negative
		{
			node*current;
			current = head;
			int counter = 0;

			while (current != nullptr && counter < k) // move till the required index poition or till the end of list in case the index does not exist
			{
				current = current->next;
				counter = counter + 1;
			}

			if (current != nullptr) // this if condition checks if index exists in the list 
			{
				if (k == 0) // if index is 0 then deletion at head
				{
					node* temp = head; // save address stored in head
					head = head->next; // update head
					
					if (head == nullptr) // case when the element at the 0th index is the last element in the list
					{
						tail = nullptr;
					}
					else // case when the element at the 0th index is not the last element in the list
					{
						head->previous = nullptr;
					}

					delete temp; // delete node at 0th index
				}
				else // deletion at any index other than 0th index
				{
					current->previous->next = current->next; // adjust next pointer of previous node
					
					if (current->next != nullptr) // ensuring that nullptr is not dereffered in case the last element is to be deleted
					{
						current->next->previous = current->previous;
					}
					
					delete current; // delete the node at kth index
				}
			}
		}
	}

	~DoublyLinkedList() // destructor
	{
		if (head != nullptr)
		{
			node * current, *ahead;
			current = head;
			ahead = nullptr;
			while (current != nullptr)
			{
				ahead = current->next;
				delete current;
				current = ahead;
			}
		}
	}
};

int main()
{
	DoublyLinkedList<int> list; // making an object of the doubly linked list
	
	cout << "After inserting 3 at head: " << endl;
	list.insertAtHead(3); // inserting 3 at head
	list.print();
	cout << endl;
	
	cout << "After inserting 6 at tail: " << endl;
	list.insertAtTail(6); // inserting 6 at tail
	list.print();
	cout << endl;
	
	cout << "Printing list in reverse: " << endl;
	list.printReverse(); // calling printReverse function
	cout << endl;
	
	cout << "After deleting element at start: " << endl;
	list.deleteAtStart(); // calling deleteAtStart function
	list.print();
	cout << endl;
	
	cout << "After deleting element at tail: " << endl;
	list.deleteAtTail(); // calling delete at tail function
	list.print();
	cout << endl;
	
	cout << "After inserting 1,2,3,4,5 in list:" << endl;
	list.insertAtHead(5); // inserting 5 at head
	list.insertAtHead(4); // inserting 4 at head
	list.insertAtHead(3); // inserting 3 at head
	list.insertAtHead(2); // inserting 2 at head
	list.insertAtHead(1); // inserting 1 at head
	list.print();
	cout << endl;
	
	cout << "After deleting element at 2nd index position:" << endl;
	list.deleteAtPosition(2); // calling deleteAtPosition function
	list.print();
	
	cout << endl;
	system("pause");
	return 0;
}