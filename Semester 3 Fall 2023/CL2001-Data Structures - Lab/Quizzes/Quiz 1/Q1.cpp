#include<iostream>
#include<string>
using namespace std;

class LinkedList
{
	struct node
	{
		int StudentID;
		string Name;
		string Email;
		node*next;
		node()
		{
			StudentID = 0;
			Name = "";
			Email = "";
			next = nullptr;
		}
	};
public:
	node*head;
	node*tail;

	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	void insert(int ID = 0, string name = "", string email = "")
	{
		node*temp = new node;
		temp->StudentID = ID;
		temp->Name = name;
		temp->Email = email;
		temp->next = nullptr;

		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	void remove(int ID)
	{
		node*current = head;
		node*previous = nullptr;
		while (current != nullptr&&current->StudentID != ID)
		{
			previous = current;
			current = current->next;
		}

		if (current != nullptr&&current->StudentID == ID)
		{
			if (current == head)
			{
				head = head->next;
				delete current;
			}
			else
			{
				previous->next = current->next;
				delete current;
			}

		}
	}
	void display()
	{
		node*current = head;
		while (current != nullptr)
		{
			cout << "ID: " << current->StudentID << " ,Name: " << current->Name << " ,Email: " << current->Email << endl;
			current = current->next;
		}
		cout << endl;
	}

	LinkedList* commonStudents(LinkedList&list)
	{
		LinkedList*commonList = new LinkedList;
		node*current1 = head;
		node*current2 = list.head;
		while (current1 != nullptr)
		{
			current2 = list.head;
			while (current2 != nullptr)
			{
				if (current1->StudentID == current2->StudentID)
				{
					commonList->insert(current1->StudentID, current1->Name, current1->Email);
				}
				current2 = current2->next;
			}
			current1 = current1->next;
		}
		return commonList;
	}

	LinkedList* merge(LinkedList &list)
	{
		LinkedList *mergedList = new LinkedList;
		node*current1 = head;

		while (current1 != nullptr)
		{
			mergedList->insert(current1->StudentID, current1->Name, current1->Email);
			current1 = current1->next;
		}

		node*current2 = list.head;
		while (current2 != nullptr)
		{
			mergedList->insert(current2->StudentID, current2->Name, current2->Email);
			current2 = current2->next;
		}
		//mergedList->removeduplicates();
		return mergedList;
	}

	/*void removeduplicates()
	{
	node*current1 = head;
	node*current2 = head;
	int Id;
	while (current1 != nullptr)
	{

	Id = current1->StudentID;
	while (current2 != nullptr)
	{
	node*temp = current2;
	current2 = current2->next;
	if (Id == temp->StudentID)
	{
	remove(Id);
	}
	current2 = current2->next;
	}
	insert(Id, Name, email);
	}
	}*/

	~LinkedList() // Destructor
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
	LinkedList event1;
	event1.insert(1, "Ali", "123@gmail.com");
	event1.insert(2, "Hassan", "345@gmail.com");
	event1.insert(3, "Bilal", "789@gmail.com");
	cout << "List after inserting some students:" << endl;
	event1.display();
	event1.remove(2);
	cout << "List after removing student with ID=2:" << endl;
	event1.display();

	LinkedList event2;
	event2.insert(1, "Ali", "123@gmail.com");
	event2.insert(2, "Hassan", "345@gmail.com");
	event2.insert(3, "Bilal", "789@gmail.com");
	cout << "List with students of first event/society:" << endl;
	event2.display();
	LinkedList event3;
	event3.insert(4, "Jawad", "abc@gmail.com");
	event3.insert(1, "Ali", "123@gmail.com");
	event3.insert(5, "Faizan", "efg@gmail.com");
	cout << "List with students of second event/society:" << endl;
	event3.display();
	cout << "The common student from first and second event are:" << endl;
	LinkedList*commonStudents = event2.commonStudents(event3);
	commonStudents->display();

	cout << "After merging the sudents of first event and second event:" << endl;
	LinkedList *merged = event2.merge(event3);
	merged->display();


	delete commonStudents;
	delete merged;
	cout << endl;
	system("pause");
	return 0;
}