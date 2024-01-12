#include<iostream>
#include<string>
using namespace std;

struct node
{
	char station;
	node* next;
	node* previous;

	node(char station=' ')
	{
		this->station = station;
		next = nullptr;
		previous = nullptr;
	}
};


class DoublyLinkedList
{
public:
	node* head;
	node* tail;
	int size;

	DoublyLinkedList()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void InsertAtEnd(char data)
	{
		node* temp = new node(data);
		size++;
        if(head==nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = nullptr;
			temp->previous = tail;
			tail->next = temp;
			tail = temp;
		}
	}

	void print()
	{
		node* current = head;

		while(current!=nullptr)
		{
			cout << current->station;
			if(current->next!=nullptr)
			{
				cout << "<->";
			}
			current = current->next;
		}
		cout << endl;
	}

	void MagiReverso(int k)
	{
		node* current = head;
		node* first=nullptr;
		node* previous = nullptr;
		node* prev=nullptr;
		if(current!=nullptr&&k<=size)
		{
			while(current!=nullptr)
			{
				if (current == head)
				{
					first = head;
					previous = nullptr;
					node* ahead = nullptr;
					for (int i = 0; current != nullptr && i < k; i++)
					{
						ahead = current->next;
						current->next = previous;
						previous = current;
						current = ahead;
					}
					head = previous;
					first->next = current;
				}
				else
				{
					first = current;
					prev = current->previous;
					node* ahead = nullptr;
					for (int i = 0; current != nullptr && i < k; i++)
					{
						ahead = current->next;
						current->next = previous;
						previous = current;
						current = ahead;
					}
					prev->next = current;
					first->next = previous;
				}
			}
		}
		else
		{
			cout << "Cannot do Magi Reverse" << endl;
		}
	}




	~DoublyLinkedList()
	{
		node* current = head;
		node* ahead = nullptr;

		while(current!=nullptr)
		{
			ahead = current->next;
			delete current;
			current = ahead;
		}
	}

};

int main()
{
	DoublyLinkedList list;
	list.InsertAtEnd('A');
	list.InsertAtEnd('B');
	list.InsertAtEnd('C');
	list.InsertAtEnd('D');
	list.InsertAtEnd('E');
	list.InsertAtEnd('F');
	list.InsertAtEnd('G');
	list.InsertAtEnd('H');
	cout << "Original Transport Sytem:" << endl;
	list.print();
	//list.MagiReverso(3);
	//list.print();

	cout << endl;
	system("pause");
	return 0;
}