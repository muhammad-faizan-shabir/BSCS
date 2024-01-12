#include <iostream>
#include<string>
using namespace std;

struct node
{
	string location;
	string routes;
	string stops;
	string schedules;
	string modesOftransportation;
	node* next;

	node(string location="",string routes="",string stops="",string schedules="", string modes="")
	{
		this->location = location;
		this->routes = routes;
		this->stops = stops;
		this->schedules = schedules;
		modesOftransportation = modes;
		next = nullptr;
	}

};

class LinkedList
{
public:
	node* head;

	LinkedList()
	{
		head = nullptr;
	}

	void Insert(node data)
	{
		node* temp = new node(data);
		node* current = head;
		node* previous = nullptr;
		while(current!=nullptr)
		{
			previous = current;
			current = current->next;
		}

		temp->next = current;
		if(head==nullptr)
		{
			head = temp;
		}
		else
		{
			previous->next = temp;
		}
		
	}

	bool Find(string location,node&data)
	{
		if(head!=nullptr)
		{
			node* current = head;

			while(current!=nullptr&&current->location!=location)
			{
				current = current->next;
			}

			if(current==nullptr)
			{
				return false;
			}
			else
			{
				data.location = current->location;
				data.routes = current->routes;
				data.stops = current->stops;
				data.schedules = current->schedules;
				data.modesOftransportation = current->modesOftransportation;
				return true;
			}

		}
		else
		{
			return false;
		}
	}
	void print()
	{
		node* current = head;
		cout << "The Transport Network data is below (Assuming that we are currently in Lahore):" << endl;
		while(current!=nullptr)
		{
			cout << "Location: " << current->location << " Routes: " << current->routes << " Stops: " << current->stops << " Schedule: " << current->schedules << " Mode: " << current->modesOftransportation << endl;
			current = current->next;
		}
		cout << endl;
	}
	bool IsEmpty()
	{
		if(head==nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	~LinkedList()
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
struct node2
{
	string customerName;
	string location;
	node2* next = nullptr;
	node2(string customerName = "", string location = "")
	{
		this->customerName = customerName;
		this->location = location;
		next = nullptr;
	}
};
class Queue
{
public:
	

	node2* front;
	node2* rear;
	int size;

	Queue()
	{
		size = 0;
		front = nullptr;
		rear = nullptr;
	}


	bool IsEmpty()
	{
		if(size==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	void enqueue(node2 data)
	{
		node2* temp = new node2(data);
		temp->next = nullptr;

		if(size==0)
		{
			front = temp;
			rear = temp;
		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
		size++;
	}


	bool dequeue(node2 &data)
	{
		if(size!=0)
		{
			node2* temp = front;
			front = front->next;
			size--;

			if(size==0)
			{
				front = nullptr;
				rear = nullptr;
			}
			data.customerName = temp->customerName;
			data.location = temp->location;
			delete temp;
			return true;
		}
		else
		{
			return false;
		}
	}

	~Queue()
	{
		node2 data;
		while(size!=0)
		{
			dequeue(data);
		}

	}
};




int main() 
{
	LinkedList list1;
	node data1("Faisalabad", "Motorway", "Motorway rest area", "9AM to 11AM", "Bus");
	list1.Insert(data1);
	node data2("Karachi", "By air", "No stop", "1PM to 2PM", "Airplane");
	list1.Insert(data2);
	node data3("Multan", "GT road", "MianChannu", "1PM to 5PM", "Van");
	list1.Insert(data3);
	node data4("Islamabad", "Motorway", "Kallar Kahar", "8AM to 12PM", "Bus");
	list1.Insert(data4);
	list1.print();
	cout << "---------------------------------" << endl;
	Queue passengers;
	cout << "Adding Ali to the Queue of Passengers who wants to go to Karachi" << endl;
	node2 data5("Ali", "Karachi");
	passengers.enqueue(data5);
	cout << "Adding Hamza to the Queue of Passengers who wants to go to Islamabad" << endl;
	node2 data6("Hamza", "Islamabad");
	passengers.enqueue(data6);
	cout << "Adding Faizan to the Queue of Passengers who wants to go to Multan " << endl;
	node2 data7("Faizan", "Multan");
	passengers.enqueue(data7);
	cout << "Adding Ahmed to the Queue of Passengers who wants to got to Faisalabad" << endl;
	node2 data8("Ahmed", "Faisalabad");
	passengers.enqueue(data8);
	cout << "Adding Babar to the Queue of Passengers who wants to got to Quetta " << endl;
	node2 data9("Babar", "Quetta");
	passengers.enqueue(data9);
	cout << "-------------------------";
	cout << endl;

	node networkData;
	node2 passengerdata;
	bool found = true;

	while(!passengers.IsEmpty())
	{
		passengers.dequeue(passengerdata);

		found = list1.Find(passengerdata.location, networkData);
		if(found==true)
		{
			cout << "The route is available for " << passengerdata.customerName << ", the details are below:" << endl;
			cout << "Location: " << networkData.location << " Routes: " << networkData.routes << " Stops: " << networkData.stops << " Schedule: " << networkData.schedules << " Mode: " << networkData.modesOftransportation << endl;
			cout << "-----------------------------------" << endl;
		}
		else
		{
			cout << "There is no route available for " << passengerdata.customerName << " to go to " << passengerdata.location << endl;
		}
	}
	
	cout << endl;
	system("pause");
	return 0;
}
