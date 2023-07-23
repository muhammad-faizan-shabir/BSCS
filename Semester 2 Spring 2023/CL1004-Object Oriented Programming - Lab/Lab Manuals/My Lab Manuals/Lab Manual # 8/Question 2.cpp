#include<iostream>
#include<string>
using namespace std;

class Author; //forward declaration
class Book; // forward declaration

class Author
{
	string name;
	string email;
	char gender;
public:
	Author();
	Author(const string&, const string&, char);
	string getName() const;
	string getEmail() const;
	void setEmail(const string&);
	char getGender() const;
	void print() const;
};

Author::Author()
{
	name = " ";
	email = " ";
	gender = ' ';
}

Author::Author(const string&name, const string&email, char gender)
{
	this->name = name;
	this->email = email;
	this->gender = gender;
}

string Author::getName() const
{
	return name;
}

string Author::getEmail() const
{
	return email;
}

void Author::setEmail(const string&email)
{
	this->email = email;
}

char Author::getGender() const
{
	return gender;
}

void Author::print() const
{
	cout << name << " (" << gender << ") at " << email << endl;
}

class Book
{
	string name;
	Author author;
	double price;
	int qtyInStock;
public:
	Book(string,Author,double,int);
	string getName();
	Author getAuthor();
	double getPrice();
	void setPrice(double);
	int getQtyInStock();
	void setQtyInStock(int);
	void print();
	string getAuthorName();
};

Book::Book(string name, Author author, double price, int qtyInStock=0)
{
	this->name = name;
	this->author = author;
	this->price = price;
	this->qtyInStock = qtyInStock;
}

string Book::getName()
{
	return name;
}

Author Book::getAuthor()
{
	return author;
}

double Book::getPrice()
{
	return price;
}

void Book::setPrice(double price)
{
	this->price = price;
}

int Book::getQtyInStock()
{
	return qtyInStock;
}

void Book::setQtyInStock(int qtyInStock)
{
	this->qtyInStock = qtyInStock;
}

void Book::print()
{
	cout << "'" << name << "' by " << author.getName() << " (" << author.getGender() << ") at " << author.getEmail() << endl;
}

string Book::getAuthorName()
{
	return author.getName();
}

int main()
{
	// Declare and construct an instance of Author
	Author peter("Peter Jones", "peter@somewhere.com", 'm');
	peter.print();  // Peter Jones (m) at peter@somewhere.com
	cout << endl;
	
	// Declare and construct an instance of Book
	Book book("C++ for Dummies", peter, 19.99);
	book.print(); // 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com
	cout << endl;
	
	peter.setEmail("peter@xyz.com");
	peter.print();   // Peter Jones (m) at peter@xyz.com
	cout << endl;
	
	book.print(); // 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com
	cout << endl;
	
	book.getAuthor().setEmail("peter@abc.com");
	book.print(); // 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com
	cout << endl;
	
	cout << endl << endl;
	system("pause");
	return 0;
}
