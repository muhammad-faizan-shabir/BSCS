#include<iostream>
using namespace std;

class HashTable1; // class with linear probing
class HashTable2;  // class with quadratic probing

class HashItem 
{ 
	friend class HashTable1;
	friend class HashTable2;
private:
	int key; // key will be used to calculate hash
	string value;  // value against key
	int status; // 0 means empty, 1 means deleted, 2 means occupied
public:
	HashItem(int key=0,string value="",int status=0) // constructor
	{
		this->key = key;
		this->value = value;
		this->status = status;
	}
};

class HashTable1 // class with linear probing
{
private:
	HashItem* hashArray; // array to store objects of HashItem class
	int capacity; // max available space in array
	int currentElements; // current elements in the array
public:
	HashTable1() // Question1
	{
		capacity = 10; // default capacity is 10
		hashArray = new HashItem[capacity]; // make array of objects of HashItem class
		currentElements = 0; // currently no element in the array
	}

	HashTable1(int const capacity) // Question1
	{
		this->capacity = capacity; // capacity set by user input
		hashArray = new HashItem[capacity]; // make array of objects of HashItem class
		currentElements = 0; // currently no element in the array
	}

	int getNextCandidateIndex(int key,int i) // Question2
	{
		return (((key % capacity) + i) % capacity); // add i to the hash value and also check for wrap around
	}

	void doubleCapacity() // Question2
	{
		int oldCapacity = capacity; // save old capacity
		capacity = capacity * 2; // double current capacity
		HashItem* tempPtr = hashArray; // save old array
		hashArray=new HashItem[capacity]; // make new array with double capacity
		currentElements = 0; // reset currentElements for the double sized array

		for(int i=0;i<oldCapacity;i++) // traverse the old array
		{
			if(tempPtr[i].status==2) // check for occupied slots
			{ 
				insert(tempPtr[i].key, tempPtr[i].value); // move occupied slots to the new array
			}
		}

		delete[] tempPtr; // delete old array
	}

	void insert(int const key, string const value) // Question3
	{
		int index = key % capacity; // calculate hash/index

		if (hashArray[index].status != 2) // check if current index is occupied or not
		{
			hashArray[index].key = key; // add key
			hashArray[index].value = value; // add value
			hashArray[index].status = 2; // update status
			currentElements++; // update number of elements
		}
		else // case when there is a collision
		{
			int i = 1; // start with 1

			while (hashArray[index].status == 2) // keep looking for an unoccupied slot
			{
				index = getNextCandidateIndex(key, i); // get next index
				i++; // increment i
			} 

			hashArray[index].key = key; // add key
			hashArray[index].value = value; // add value
			hashArray[index].status = 2; // update status
			currentElements++; // update number of elements
		}

		if(currentElements>=0.75*capacity) // check load factor to determine whether doubling the size is required or not
		{
			doubleCapacity();
		}
	}

	bool deleteKey(int const key) // Question4
	{
		int index = key % capacity;  // calculate hash/index

		if (hashArray[index].key == key&&hashArray[index].status==2) // make sure key is found and is occupied
		{
			hashArray[index].status = 1; //  update status
			currentElements--; // decrease number of elements
			return true; 
		}
		else // case when the key might be at some next index due to collison
		{
			int i = 1; // start with 1

			while (hashArray[index].status != 0 && hashArray[index].key != key) // keep looking for the key until it is found or an empty slot is reached
			{
				index = getNextCandidateIndex(key, i); // get next index
				i++; // increment i
			}

			if (hashArray[index].key == key&&hashArray[index].status == 2) // make sure key is found and is occupied
			{
				hashArray[index].status = 1; //  update status
				currentElements--; // decrease number of elements
				return true;
			}
			else // case when key to be deleted is not found
			{
				return false;
			}
		}
	}

	string get(int const key) // Question4
	{
		int index = key % capacity; // calculate hash/index

		if (hashArray[index].status == 2 && hashArray[index].key == key) // make sure key is found and is occupied
		{
			return hashArray[index].value; // return value against key
		}
		else // case when the key might be at some next index due to collison
		{
			int i = 1; // start with 1

			while (hashArray[index].status != 0 && hashArray[index].key != key)  // keep looking for the key until it is found or an empty slot is reached
			{
				index = getNextCandidateIndex(key, i); // get next index
				i++; // increment i
			}

			if ((hashArray[index].status == 2 && hashArray[index].key == key)) // make sure key is found and is occupied
			{
				return hashArray[index].value; // return value against key
			}
			else // case when key to be searched is not found
			{
				return "NOT FOUND"; // return not found string
			}
		}
	}

	~HashTable1() // Question1
	{
		delete[] hashArray; // delete array of objects of HashItem class
	}
};

class HashTable2 // Question5
{
private:
	HashItem* hashArray;
	int capacity;
	int currentElements;
public:
	HashTable2()
	{
		capacity = 10;
		hashArray = new HashItem[capacity];
		currentElements = 0;
	}

	HashTable2(int const capacity)
	{
		this->capacity = capacity;
		hashArray = new HashItem[capacity];
		currentElements = 0;
	}

	int getNextCandidateIndex(int key, int i)
	{
		return (((key % capacity) + (i*i)) % capacity);
	}

	void doubleCapacity()
	{
		int oldCapacity = capacity;
		capacity = capacity * 2;
		HashItem* tempPtr = hashArray;
		hashArray = new HashItem[capacity];
		currentElements = 0;

		for (int i = 0; i < oldCapacity; i++)
		{
			if (tempPtr[i].status == 2)
			{
				insert(tempPtr[i].key, tempPtr[i].value);
			}
		}

		delete[] tempPtr;
	}

	void insert(int const key, string const value)
	{
		int index = key % capacity;

		if (hashArray[index].status != 2)
		{
			hashArray[index].key = key;
			hashArray[index].value = value;
			hashArray[index].status = 2;
			currentElements++;
		}
		else
		{
			int i = 1;

			while (hashArray[index].status == 2)
			{
				index = getNextCandidateIndex(key, i);
				i++;
			}

			hashArray[index].key = key;
			hashArray[index].value = value;
			hashArray[index].status = 2;
			currentElements++;
		}

		if (currentElements >= 0.75 * capacity)
		{
			doubleCapacity();
		}
	}

	bool deleteKey(int const key)
	{
		int index = key % capacity;

		if (hashArray[index].key == key && hashArray[index].status == 2)
		{
			hashArray[index].status = 1;
			currentElements--;
			return true;
		}
		else
		{
			int i = 1;

			while (hashArray[index].status != 0 && hashArray[index].key != key)
			{
				index = getNextCandidateIndex(key, i);
				i++;
			}

			if (hashArray[index].key == key && hashArray[index].status == 2)
			{
				hashArray[index].status = 1;
				currentElements--;
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	string get(int const key)
	{
		int index = key % capacity;

		if (hashArray[index].status == 2 && hashArray[index].key == key)
		{
			return hashArray[index].value;
		}
		else
		{
			int i = 1;

			while (hashArray[index].status != 0 && hashArray[index].key != key)
			{
				index = getNextCandidateIndex(key, i);
				i++;
			}

			if ((hashArray[index].status == 2 && hashArray[index].key == key))
			{
				return hashArray[index].value;
			}
			else
			{
				return "NOT FOUND";
			}
		}
	}

	~HashTable2()
	{
		delete [] hashArray;
	}
};

int main()
{
	cout << "--------------HashTable using Linear Probing-------------" << endl;
	HashTable1 hashtable(5); // Create a hash map with capacity 5 (for simplicity, using string as the value type)
    
	hashtable.insert(101, "Alice");  // Insert key-value pairs into the hash map
	hashtable.insert(201, "Bob");
	hashtable.insert(301, "Charlie");
	hashtable.insert(401, "David");
	hashtable.insert(501, "Eva");
	
	string name = hashtable.get(201); // Test get function
	cout << "Value at key 201: " << name << endl;
	
		bool deleted = hashtable.deleteKey(301); // Test deleteKey function
	if (deleted) 
	{
		cout << "Key 301 deleted successfully." << endl;
	}
	else 
	{
		cout << "Key 301 not found!" << endl;
	}
	
	name = hashtable.get(301); // Test get after deletion
	cout << "Value at key 301: " << name << endl; // Should not be found after deletion
	
	cout<<endl << "--------------HashTable using Quadratic Probing-------------" << endl;
	HashTable2 hashtable2(6); // Create a hash map with capacity 5 (for simplicity, using string as the value type)

	hashtable2.insert(101, "Alice"); // Insert key-value pairs into the hash map
	hashtable2.insert(201, "Bob");
	hashtable2.insert(301, "Charlie");
	hashtable2.insert(401, "David");
	hashtable2.insert(501, "Eva");
	
	name = hashtable2.get(201); // Test get function
	cout << "Value at key 201: " << name << endl;

	deleted = hashtable2.deleteKey(301); // Test deleteKey function
	if (deleted) 
	{
		cout << "Key 301 deleted successfully." << endl;
	}
	else 
	{
		cout << "Key 301 not found!" << endl;
	}
	
	name = hashtable2.get(301); // Test get after deletion
	cout << "Value at key 301: " << name << endl; // Should not be found after deletion

	cout << endl;
	system("pause");
	return 0;
}