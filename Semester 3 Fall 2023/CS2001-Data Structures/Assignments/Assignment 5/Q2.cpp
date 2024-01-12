#include<iostream>
#include<fstream>
#include<string>
#include<assert.h>
using namespace std;

template<class v> // template class
struct HashItem
{
	int key;
	v value;
	short status; // 0 means empty, 1 means deleted, 2 means occupied
	HashItem() // constructor
	{
		key = 0;
		status = 0;
	}
};

template<class v> // template class
class HashMap 
{
private:
	HashItem<v> * hashArray;
	int capacity;
	int currentElements;
public:
	HashMap() // default constructor
	{
		currentElements = 0;
		capacity = 10; // default capacity is 10
		hashArray = new HashItem<v>[capacity];
	}

	HashMap(int const capacity) // parametrized constructor
	{
		currentElements = 0;
		this->capacity = capacity;
		hashArray = new HashItem<v>[capacity];
	}
	 
	int getCapacity() // getter for capacity
	{
		return capacity;
	}

	void insert(int const key, v const value) // function to insert elements in the HashMap
	{
		int index = key % capacity; // calculate hash/index
		v* ptr = get(key); // try to find the key in the map
		if(ptr!=nullptr) // check if key already exists in the map
		{
			(*ptr) = value; // update the key's value
		}
		else if (hashArray[index].status != 2) // check if current index is occupied or not
		{
			hashArray[index].key = key; // add key
			hashArray[index].value = value; // add value
			hashArray[index].status = 2; // update status
			currentElements++; // update number of elements
		}
		else // case when there is a collision
		{
			int i = 1; // start with 1

			while (hashArray[index].status == 2) // keep looking for an unoccupied/deleted slot
			{
				index = getNextCandidateIndex(key, i); // get next index
				i++; // increment i
			}

			hashArray[index].key = key; // add key
			hashArray[index].value = value; // add value
			hashArray[index].status = 2; // update status
			currentElements++; // update number of elements
		}

		if (currentElements >= 0.75 * capacity) // check load factor to determine whether doubling the size is required or not
		{
			doubleCapacity();
		}
	}

	void doubleCapacity() // function to double the capacity of the hashmap and rehash all the elements 
	{
		int oldCapacity = capacity; // save old capacity
		capacity = capacity * 2; // double current capacity
		HashItem<v>* tempPtr = hashArray; // save old array
		hashArray = new HashItem<v>[capacity]; // make new array with double capacity
		currentElements = 0; // reset currentElements for the double sized array

		for (int i = 0; i < oldCapacity; i++) // traverse the old array
		{
			if (tempPtr[i].status == 2) // check for occupied slots
			{
				insert(tempPtr[i].key, tempPtr[i].value); // move occupied slots to the new array
			}
		}

		delete[] tempPtr; // delete old array
	}

	virtual int getNextCandidateIndex(int key, int i) // function to get next index using linear probing in case there is a collision
	{
		return (((key % capacity) + i) % capacity); // add i to the hash value and also check for wrap around
	}

	bool deleteKey(int const key) // function to delete a key if it exists
	{
		int index = key % capacity;  // calculate hash/index

		if (hashArray[index].key == key && hashArray[index].status == 2) // make sure key is found and is occupied
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

			if (hashArray[index].key == key && hashArray[index].status == 2) // make sure key is found and is occupied
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

	v* get(int const key) // function to find a key if it exists and then return a pointer to the value against that key
	{
		int index = key % capacity; // calculate hash/index

		if (hashArray[index].status == 2 && hashArray[index].key == key) // make sure key is found and is occupied
		{
			return &(hashArray[index].value); // return value against key
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
				return &(hashArray[index].value); // return value against key
			}
			else // case when key to be searched is not found
			{
				return nullptr; // return nullptr
			}
		}
	}

	~HashMap() // Destructor
	{
		delete[] hashArray;
	}
};

template<class v> // template class
class QHashMap : public HashMap<v>  
{
public:
	int getNextCandidateIndex(int key, int i) // function to get next index using quadratic probing in case there is a collision
	{
		return (((key % (HashMap<v>::getCapacity())) + (i*i)) % (HashMap<v>::getCapacity())); // add i*i to the hash value and also check for wrap around
	}
};

template<class v> // template class
class DHashMap: public HashMap<v>
{
public:
	int getNextCandidateIndex(int key, int i) // function to get next index using double hashing in case there is a collision
	{
		int first_value = key % (HashMap<v>::getCapacity());
		int second_value = (11 - (key % 11));
		int candidate_index = (first_value + (i * second_value)) % (HashMap<v>::getCapacity());
		return candidate_index;
	}
};

void populateHash(string filename,HashMap<string>*hash) // function to read data from a file and insert it in a hashmap passed as parameter
{
	ifstream fin; // make an ifstream object
	fin.open(filename); // open the file
	if(!fin) // case when file is not opened
	{
		cout << "Error! File not opening" << endl;
		return;
	}

	int id; 
	string name;
	 
	while(!fin.eof()) // traverse the entire file
	{ 
		fin >> id; // get id
		fin >> name; // get name
		hash->insert(id, name); // call insert function for the hashmap
	}

	fin.close(); // close the file
}

int main()
{
	HashMap<string>* map; 

	map = new HashMap<string>; 
	populateHash("students.txt", map); 
	cout << *map->get(9) << endl;
	map->deleteKey(9); 
	assert(map->get(9) == nullptr); 
	delete map;

	map = new QHashMap<string>; 
	populateHash("students.txt", map); 
	cout << *map->get(98) << endl;
	map->deleteKey(98); 
	assert(map->get(98) == nullptr); 
	delete map;
	
	map = new DHashMap<string>; 
	populateHash("students.txt", map); 
	cout << *map->get(101) << endl;
	map->deleteKey(101); 
	assert(map->get(101) == nullptr); 
	delete map;

	cout << endl;
	system("pause");
	return 0;
}
