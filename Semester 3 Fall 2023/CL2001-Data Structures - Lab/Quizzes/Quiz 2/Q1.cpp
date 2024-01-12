#include<iostream>
#include<string>
using namespace std;

class Book // Part 1 Managing books
{
public:
	string isbn;
	string title;
	string author;
	bool available;
	Book*next;

	Book(string isbn="",string title="",string author="",bool availability=true)
	{
		this->isbn = isbn;
		this->title = title;
		this->author = author;
		this->available = availability;
		this->next = nullptr;
	}
};
class Queue // Part 5 waiting list
{
	Book* front;
	Book *end;
	int size;
public:
	Queue()
	{
		front = nullptr;
		end = nullptr;
		size = 0;
	}

	bool IsEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void enqueue(Book &data)
	{
		Book *temp = new Book;
		temp->isbn = data.isbn;
		temp->title = data.title;
		temp->available = data.available;
		temp->author = data.author;
		temp->next = nullptr;
		size++;
		if (end == nullptr)
		{
			end = temp;
			front = temp;
		}
		else
		{
			end->next = temp;
			end = temp;
		}
	}

	void dequeue(Book &data)
	{
		if (!IsEmpty())
		{
			Book*temp = front;
			front = front->next;
			data.isbn = temp->isbn;
			data.title = temp->title;
			data.author = temp->author;
			data.available = temp->available;
			data.next = nullptr;
			delete temp;
			size--;
		}
	}

	void print()
	{
		if (size != 0)
		{
			Book *current = front;
			while (front != nullptr)
			{
				cout << "Book isbn: " << current->isbn << ", Book title: " << current->title << " ,Book author: " << current->author << " ,Book availability status: " << current->available << endl;
				current = current->next;
			}
		}
	}

	~Queue()
	{
		Book data;
		while (!IsEmpty())
		{
			dequeue(data);
		}
	}


};
class Patron // Part 2 Managing Patrons
{
	string ID;
	string name;
	Queue listOfreservedBooks;
	int totalBooksReserved;


public:
	Patron(string  id = "", string name = "")
	{
		ID = id;
		this->name = name;
		totalBooksReserved = 0;
	}

	void reserveBook(Book &data)
	{
		if (data.available == true&&totalBooksReserved<3) // Part 5	Complex Reservation Logic
		{
			listOfreservedBooks.enqueue(data);
			totalBooksReserved++;
			cout << "Book reserved successfully" << endl;
		}
		else
		{
			if (data.available == false)
			{
				cout << "The book is already reserved so cannot reserve for this patron" << endl;
			}
			else
			{
				cout << "The patron do not have fewer than three books so this book cannot be reserved " << endl;
			}
			
		}
	}

	void unreserveBook()
	{
		if (totalBooksReserved > 0)
		{
			Book data;
			listOfreservedBooks.dequeue(data);
		}
	}
};


Queue waitingList; // Part 4 waiting list 


void DisplayAndNotifications() // part 7 Display and Notifications
{
	waitingList.print();
}

int main()
{
	cout << "The library system";
	cout << endl;
	system("pause");
	return 0;
}