#include<iostream>
using namespace std;

template<class T> // template class 
class CircularLinkedList
{
public:
	struct node // node struct to store data and next pointer
	{
		T data;
		node* next;
		node() // constructor
		{
			next = nullptr;
		}
	};

	class iterator // iterator class
	{
	public:
		node* p; // node pointer

		iterator() // constructor
		{
			p = nullptr;
		}

		iterator(node* n) // parameterized constructor
		{
			p = n;
		}

		iterator(const iterator& i) // copy constructor
		{
			this->p = i.p;
		}

		iterator& operator++() // overloaded + operator
		{
			p = p->next;
			return *this;
		}

		T operator*() // overloaded * operator
		{
			return p->data;
		}

		T& operator[] (int index) // overloaded [] operator
		{
			for (int i = 0; i < index; i++)
			{
				p = p->next;
			}
			return p->data;
		}

		bool operator==(const iterator& i) // overloaded == operator
		{
			return this->p == i.p;
		}

		bool operator!=(const iterator& i) // overloaded != operator
		{
			return this->p != i.p;
		}
	};

private:
	node* head; // head pointer

public:
	template<class T>
	friend void split(CircularLinkedList<T>& list); // making split function a friend of this class

	CircularLinkedList() // constructor
	{
		head = nullptr;
	}

	void insertAtEnd(T data) // function to insert at end
	{
		node* temp = new node; // make new node
		temp->data = data;
		temp->next = nullptr;

		if (head == nullptr) // case when list is initially empty
		{
			head = temp;
			temp->next = head;
		}
		else if (head->next == head) // case when  only one element in list
		{
			head->next = temp;
			temp->next = head;
		}
		else // case when more than one elements on the list
		{
			node* current = head;
			current = current->next;
			while (current->next != head)
			{
				current = current->next;
			}
			current->next = temp;
			temp->next = head;
		}
	}

	int search(int n) // function to search index position of given integer n
	{
		if (head != nullptr) // make sure list is not empty
		{
			int counter = 0;
			if (head->next == head && head->data == n) // case when only one element in list and integer found at start
			{
				return counter;
			}
			else
			{
				if (head->data == n) // case when more than one element in the list and integer found at start
				{
					return counter;
				}
				else // case when more than one element in the list and integer found at any position other than start
				{
					node* current = head->next;
					counter = counter + 1;
					while (current != head && current->data != n)
					{
						current = current->next;
						counter = counter + 1;
					}
					if (current != head) // case when integer is found
					{
						return counter;
					}
					else // case when integer is not found
					{
						return -1;
					}
				}
			}
		}
	}

	iterator Begin()  // function to return head of list
	{
		return iterator(head);
	}

	iterator End() // function to return end of list
	{
		return iterator(head);
	}

	~CircularLinkedList() // destructor
	{
		if (head != nullptr)
		{
			node* current = head;
			node* ahead;
			ahead = current->next;
			delete current;
			current = ahead;

			while (current != head)
			{
				ahead = current->next;
				delete current;
				current = ahead;
			}
		}
	}
};

template<class T>
void split(CircularLinkedList<T>& list) // function to split even and odd positioned elements
{
	CircularLinkedList<T> evenList; // list to store even positioned elements
	CircularLinkedList<T> oddList; // list to store odd positioned elements

	if (list.head != nullptr) // make sure list is not empty
	{
		CircularLinkedList<int>::node* current = list.head; // start from the head of list
		oddList.insertAtEnd(current->data); // move first element in the odd list
		current = current->next; // move to second element
		bool turnOfEven = true; // flag to indicate the array in which element is to be put

		while (current != list.head) // traverse the whole list
		{
			if (turnOfEven == true) // flag tells if the current elemnent is even positioned or not
			{
				turnOfEven = false; // update flag so that next time odd positioned element can be indicated
				evenList.insertAtEnd(current->data); // update even list
				current = current->next; // move to next element
			}
			else
			{
				turnOfEven = true; // update flag so that next time even positioned element can be indicated
				oddList.insertAtEnd(current->data); // update odd list
				current = current->next; // move to next element
			}
		}
	}

	cout << "Even-positioned nodes list: ";
	CircularLinkedList<int>::iterator i = evenList.Begin(); // print even list using iterators
	cout << *i << "-> ";
	++i;
	for (; i != evenList.End(); ++i)
	{
		cout << *i << "-> ";
	}
	cout << endl;

	cout << "Odd-positioned nodes  list: ";
	CircularLinkedList<int>::iterator j = oddList.Begin(); // print odd list using iterators
	cout << *j << "-> ";
	++j;
	for (; j != oddList.End(); ++j)
	{
		cout << *j << "-> ";
	}
	cout << endl;
}

int main()
{
	cout << "-------------------TASK 1-------------------" << endl;
	CircularLinkedList<int> list1;
	list1.insertAtEnd(1);
	list1.insertAtEnd(2);
	list1.insertAtEnd(3);
	list1.insertAtEnd(4);
	list1.insertAtEnd(5);
	list1.insertAtEnd(6);
	list1.insertAtEnd(7);
	list1.insertAtEnd(8);
	list1.insertAtEnd(9);

	cout << "List before splitting is:" << endl;
	CircularLinkedList<int>::iterator j = list1.Begin();
	cout << *j << "-> ";
	++j;
	for (; j != list1.End(); ++j)
	{
		cout << *j << "-> ";
	}
	cout << endl;

	cout << "List after splitting:" << endl;
	split<int>(list1);
	cout << endl;

	cout << "-------------------TASK 2-------------------" << endl;
	cout << "The list is:" << endl;
	CircularLinkedList<int>::iterator k = list1.Begin();
	cout << *k << "-> ";
	++k;
	for (; k != list1.End(); ++k)
	{
		cout << *k << "-> ";
	}
	cout << endl;

	cout << "Integer 6 in the above list is found at index: " << list1.search(6) << endl << endl;

	cout << "-------------------TASK 3-------------------" << endl;
	cout << "The list before insertion of 22 at tail: " << endl;
	CircularLinkedList<int>::iterator l = list1.Begin();
	cout << *l << "-> ";
	++l;
	for (; l != list1.End(); ++l)
	{
		cout << *l << "-> ";
	}
	cout << endl;

	list1.insertAtEnd(22);

	cout << "The list after insertion of 22 at tail: " << endl;
	CircularLinkedList<int>::iterator m = list1.Begin();
	cout << *m << "-> ";
	++m;
	for (; m != list1.End(); ++m)
	{
		cout << *m << "-> ";
	}
	cout << endl << endl;

	cout << "-------------------TASK 4-------------------" << endl;
	cout << "The list before insertion of 33 at index 6:" << endl;
	CircularLinkedList<int>::iterator n = list1.Begin();
	cout << *n << "-> ";
	++n;
	for (; n != list1.End(); ++n)
	{
		cout << *n << "-> ";
	}
	cout << endl;

	CircularLinkedList<int>::iterator o = list1.Begin();
	o[6] = 33;

	cout << "The list after insertion of 33 at index 6:" << endl;
	CircularLinkedList<int>::iterator p = list1.Begin();
	cout << *p << "-> ";
	++p;
	for (; p != list1.End(); ++p)
	{
		cout << *p << "-> ";
	}
	cout << endl;

	cout << endl;
	system("pause");
	return 0;
}