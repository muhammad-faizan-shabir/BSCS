#include<iostream>
using namespace std;

template<class T> // template class  
class DoublyLinkedList
{
public:
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
			cout << current->data;
			if (current->next != nullptr)
			{
				cout << "->";
			}
			current = current->next;
		}
		cout << endl;
	}
	
	void deleteRandom(int k) // function to delete element at given index
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

			if (current != nullptr) // this 'if' condition checks if index exists in the list or not
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

	void insertSorted(T const element) // function insert elements in sorted way
	{
		node*newNode = new node; // make new node
		newNode->data = element;
		newNode->next = nullptr;
		newNode->previous = nullptr;
		node*current = head;
		node*previous = nullptr;

		while (current != nullptr&&current->data < element) // move till the required place in the list
		{
			previous = current;
			current = current->next;
		}

		if (head == nullptr) // case if list is initially empty
		{
			head = newNode;
			tail = newNode;
		}
		else if (current == head) // case if insertion at head
		{
			newNode->next = head;
			head->previous = newNode;
			head = newNode;
		}
		else if (current == nullptr) // case if insertion at tail
		{
			newNode->previous = previous;
			previous->next = newNode;
			tail = newNode;
		}
		else // case if insertion is at any place other than head and tail
		{
			newNode->next = current;
			newNode->previous = previous;
			current->previous = newNode;
			previous->next = newNode;
		}
	}

	void DeleteDuplicates() // function to delete duplicate nodes
	{
		if (head != nullptr) // make sure list is not empty
		{
			node*current = head;

			while (current!= nullptr) // traverse whole array
			{
				if (current->next!=nullptr&&current->data == current->next->data) // check for duplication
				{
					node*temp = current->next;
					current->next = current->next->next; // break connections
					
					if (current->next != nullptr)
					{
						current->next->previous = current; // break connections
					}
					if (temp->next == nullptr)
					{ 
						tail = current; // update tail if needed
					}
					delete temp; // delete duplicate node
				}
				else
				{
					current = current->next; // move to next node if no duplication
				}
			}
		}
	}

	void swapNodes(int n) // function to swap nodes
	{
		if (head != nullptr && n>0) // the list should not be empty and n should be greater than 0
		{
			if (n == 1) // case if head and tail are to be swapped
			{
				tail->previous->next = head;
				head->next->previous = tail;
				tail->next = head->next;
				head->previous = tail->previous;
				head->next = nullptr;
				tail->previous = nullptr;
			}
			else // case if nodes other than head and tail are to be swapped
			{
				node*current1 = head;
				int counter = 1;
				while (current1 != nullptr&&counter < n) // move till the nth node from start
				{
					current1 = current1->next;
					counter++;
				}

				counter = 1;
				node*current2 = tail;
				while (current2 != nullptr&&counter < n) // move till the nth node from end
				{
					current2 = current2->previous;
					counter++;
				}
				
				if (current1 != nullptr&&current2 != nullptr) // make sure that value of n was not too large that caused the list to end
				{
					if (current1 != current2) // no need to swap if the two nodes are the same
					{
						node*next1 = current1->next;
						node*previous1 = current1->previous;
						
						node*next2 = current2->next;
						node*previous2 = current2->previous;
						
						current1->next = next2; // swap next pointer 
						current1->previous = previous2; // swap previous pointer
						
						current2->next = next1; // swap next pointer
						current2->previous = previous1; // swap previous pointer
						
						current1->next->previous = current1; // adjust pointer for the node that is ahead
						current1->previous->next = current1; // adjust pointer for the node that is previous
						
						current2->next->previous = current2; // adjust pointer for the node that is ahead
						current2->previous->next = current2; // adjust pointer for the node that is previous
					}
				}
			}
		}
	}

	node* Get_nth_node_from_end(int n) // function to get nth node from end
	{
		if (tail != nullptr) // make sure list is not empty
		{
			node*current = tail;
			int counter = 1;
			while (current != nullptr&&counter < n) // move till nth node from end
			{
				current = current->previous;
				counter++;
			}

			if (current != nullptr) // make sure start of list is not reached
			{
				return current;
			}
			else // if start of list is reached then return nullptr
			{
				return nullptr;
			}
		}
	}

	void Partition(int n) // function to partition the list
	{
		node*current;
		current = head;

		while (current != nullptr) // traverse the whole list
		{
			if (current->data<n) // put all elements less than n at the start of the list
			{
				node*temp = current;
				current = current->next;
				if (temp != head) // if the current node is already at start/head then node need to move it at start/head
				{
					if (temp == tail) // case if last element id to be moved at start
					{
						temp->previous->next = nullptr;
						temp->previous = nullptr;
						temp->next = head;
						head = temp;
					}
					else // case when any element other than head and tail is to be moved at the start of list
					{
						temp->previous->next = temp->next;
						temp->next->previous = temp->previous;
						temp->previous = nullptr;
						temp->next = head;
						head = temp;
					}
				}
			}
			else
			{
				current = current->next; // move to next element if the current element>=n
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
	cout << "-------------------TASK 1-------------------" << endl;
	DoublyLinkedList<int> list1;
	cout << "After inserting 5 at head:" << endl;
	list1.insertAtHead(5);
	list1.print();
	cout << "After inserting 9 at tail: " << endl;
	list1.insertAtTail(9);
	list1.print();
	cout << "After inserting 3 at tail: " << endl;
	list1.insertAtTail(3);
	list1.print();
	cout << "After deleting node at index 1:" << endl;
	list1.deleteRandom(1);
	list1.print();
	cout << endl;

	cout << "-------------------TASK 2-------------------" << endl;
	DoublyLinkedList<int> list2;
	cout << "After inserting 10, 20, 40: " << endl;
	list2.insertSorted(10);
	list2.insertSorted(20);
	list2.insertSorted(40);
	list2.print();
	cout << "After inserting 30 :" << endl;
	list2.insertSorted(30);
	list2.print();
	cout << endl;

	cout << "-------------------TASK 3-------------------" << endl;
	DoublyLinkedList<int> list3; // making an object of the doubly linked list
	cout << "Before removal of duplicate entries:" << endl;
	list3.insertSorted(1);
	list3.insertSorted(5);
	list3.insertSorted(5);
	list3.insertSorted(6);
	list3.insertSorted(9);
	list3.insertSorted(9);
	list3.insertSorted(9);
	list3.print();
	cout << "After removal of duplicate entries: " << endl;
	list3.DeleteDuplicates();
	list3.print();
	cout << endl;
	
	cout << "-------------------TASK 4-------------------" << endl;
	DoublyLinkedList<int> list4;
	list4.insertSorted(2);
	list4.insertSorted(3);
	list4.insertSorted(5);
	list4.insertSorted(9);
	list4.insertSorted(10);
	list4.insertAtTail(7);
	cout << "Before swapping: " << endl;
	list4.print();
	cout << "After swapping with n=2 " << endl;
	list4.swapNodes(2);
	list4.print();
	cout << endl;

	cout << "-------------------TASK 5-------------------" << endl;
	DoublyLinkedList<int> list5;
	list5.insertAtTail(1);
	list5.insertAtTail(7);
	list5.insertAtTail(6);
	list5.insertAtTail(5);
	list5.insertAtTail(2);
	cout << "The list is:" << endl;
	list5.print();
	cout << "Getting nth node from end for n=2:" << endl;
	DoublyLinkedList<int>::node*ptr = list1.Get_nth_node_from_end(2);
	if (ptr != nullptr)
	{
		cout << "Returned value is: " << ptr->data << endl;
	}
	else
	{
		cout << "Error" << endl;
	}
	cout << endl;
	
	cout << "-------------------TASK 6-------------------" << endl;
	DoublyLinkedList<int> list6;
	list6.insertAtTail(3);
	list6.insertAtTail(5);
	list6.insertAtTail(10);
	list6.insertAtTail(2);
	list6.insertAtTail(8);
	list6.insertAtTail(2);
	list6.insertAtTail(1);
	cout << "List before partition is:" << endl;
	list6.print();
	cout << "List after partition is:" << endl;
	list6.Partition(5);
	list6.print();
	
	cout << endl;
	system("pause");
	return 0;
}