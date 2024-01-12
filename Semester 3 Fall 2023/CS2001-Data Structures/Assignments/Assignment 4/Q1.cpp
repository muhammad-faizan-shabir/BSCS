#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
using namespace std;

template <class K,class V> // template class
class node
{
public:
	K key;
	V value;
	node* left;
	node* right;
	node(K key,V value,node*l=nullptr,node*r=nullptr) // constructor
	{
		this->key = key; // key
		this->value = value; // value
		left = l; // left ptr
		right = r; // right ptr
	}
};

template<class K,class V> // template class
class SpecialBST
{
	node<K,V>* root; // root
	node<K, V>** doublePtr; // pointer to a pointer
public:
	SpecialBST() // constructor
	{
		root = nullptr;
		doublePtr = nullptr;
	}
	
	void moveToRoot(stack<node<K,V>**> &stackOfNodes,stack<bool> &stackOfDirection) // function to move a node to the root of the tree
	{
		bool direction; // variable to hold direction left/ right i.e. 0/1
		
		while(!stackOfNodes.empty()) // keep getting addresses of nodes and directions until the stack becomes empty
		{
			doublePtr = stackOfNodes.top(); // get address of a node from the stack
			stackOfNodes.pop();
			
			direction = stackOfDirection.top(); // get the direction for the node i.e left/right
			stackOfDirection.pop();

			if(direction == 0) // if direction is left i.e. 0 then we rotate a node with its left child
			{
				rotateLeftChild(*doublePtr);
			}
			else // if direction is right i.e. 1 then we rotate a node with its right child
			{
				rotateRightChild(*doublePtr);
			}
		}
	}

	void rotateLeftChild(node<K,V> *&pivot) // function to rotate a node with its left child
	{
		node<K, V>* leftChild = pivot->left; // temporarily hold the left child of the pivot
		pivot->left = leftChild->right; // left pointer of pivot will now point to the right child of its left child
		leftChild->right = pivot; // right pointer of the pivot's left child will now point to the pivot 
		pivot = leftChild; // pointer pointing to the pivot will now point to the left child of the pivot so that left child now becomes the pivot and moves one level up
	}

	void rotateRightChild(node<K,V> *&pivot) // function to rotate a node with its right child
	{
		node<K, V>* rightChild = pivot->right; // temporarily hold the right child of the pivot
		pivot->right = rightChild->left; // right pointer of pivot will now point to the left child of its right child
		rightChild->left = pivot; // left pointer of the pivots's right child will now point to the pivot 
		pivot = rightChild; // pointer pointing to the pivot will now point to the right child of the pivot so that right child now becomes the pivot and moves one level up
	}
	
	bool insert(K key,V value) // work horse function for insertion of data
	{
		stack<node<K, V>**> stackOfNodes; // make a stack to hold addresses of nodes that are visited
		stack<bool> stackOfDirection; // make a stack to hold the directions in which we move
		bool flag= insert(root, key, value,stackOfNodes,stackOfDirection); // call insert function 
		moveToRoot(stackOfNodes, stackOfDirection); // call moveToRoot function to move the last accessed node to top
		return flag;
	}

	bool insert(node<K,V>*&root,K key,V value,stack<node<K,V>**>& stackOfNodes,stack<bool> &stackOfDirection) // function to insert data
	{
		if(root==nullptr) // add a node if nullptr is reached
		{
			root = new node<K, V>(key, value);
			return true;
		}
		else if(root->key==key) // check for duplication of keys
		{
			return false;
		}
		else if(root->key>key) // traverse left if key is less than current node's key
		{
			doublePtr = &root; 
			stackOfNodes.push(doublePtr); // save address of current node
			stackOfDirection.push(0); // save direction in which we move from current node
			return insert(root->left, key, value, stackOfNodes, stackOfDirection);
		}
		else
		{
			doublePtr = &root;
			stackOfNodes.push(doublePtr); // save address of current node
			stackOfDirection.push(1); // save direction in which we move from current node
			return insert(root->right, key, value, stackOfNodes, stackOfDirection);
		}
	}

	V* search(K key) // workhorse function to search for data
	{
		stack<node<K, V>**> stackOfNodes; // make a stack to hold addresses of nodes that are visited
		stack<bool> stackOfDirection; // make a stack to hold the directions in which we move
		V* ptr=search(root, key,stackOfNodes,stackOfDirection); // call search function
		if(ptr==nullptr&&(!stackOfNodes.empty())) // we need to remove one pair of adrress and direction from the stack in case the data was not found
		{
			stackOfNodes.pop();
			stackOfDirection.pop();
		}
		moveToRoot(stackOfNodes, stackOfDirection); // call moveToRoot function to move the last accessed node to top
		return ptr;
	}

	V*search(node<K,V>*&root,K key,stack<node<K,V>**>& stackOfNodes,stack<bool> &stackOfDirection) // function to search for data
	{
		if(root!=nullptr) // make sure that a pointer is not null
		{
			if(root->key==key) // case when data to be searched is found
			{ 
				return &(root->value);
			}
			else if(root->key>key) // case when data to be searched is less than current nodes's data
			{
				doublePtr = &root;
				stackOfNodes.push(doublePtr); // save address of current node
				stackOfDirection.push(0); // save direction in which we move from current node
				return search(root->left, key, stackOfNodes, stackOfDirection);
			}
			else
			{
				doublePtr = &root;
				stackOfNodes.push(doublePtr); // save address of current node
				stackOfDirection.push(1); // save direction in which we move from current node
				return search(root->right, key, stackOfNodes, stackOfDirection);
			}
		}
		else // case when data to be searched is not found
		{
			return nullptr;
		}
	}
	
	bool Delete(K key) // workhorse function to delete a node
	{ 
		stack<node<K, V>**> stackOfNodes; // make a stack to hold addresses of nodes that are visited
		stack<bool> stackOfDirection; // make a stack to hold the directions in which we move
		bool flag = Delete(root, key,stackOfNodes,stackOfDirection); // call delete function
		if(!stackOfNodes.empty()) // we need to remove one pair of adrress and direction from the stack
		{ 
			stackOfNodes.pop();
			stackOfDirection.pop();
		}
		moveToRoot(stackOfNodes, stackOfDirection); // call moveToRoot function to move the last accessed node to top
		return flag;
	}

	bool Delete(node<K,V>*&root, K key,stack<node<K,V>**> & stackOfNodes,stack<bool> & stackOfDirection) // function to find a node to be deleted
	{
		if(root!=nullptr) // // make sure that a pointer is not null
		{
			if(root->key>key) // case when data to be deleted is less than current node's data
			{
				doublePtr = &root;
				stackOfNodes.push(doublePtr); // save address of current node
				stackOfDirection.push(0); // save direction in which we move from current node
				return Delete(root->left, key, stackOfNodes, stackOfDirection);
			}
			else if(root->key<key) // case when data to be deleted is greater than current node's data
			{
				doublePtr = &root;
				stackOfNodes.push(doublePtr); // save address of current node
				stackOfDirection.push(1); // save direction in which we move from current node
				return Delete(root->right, key, stackOfNodes, stackOfDirection);
			}
			else // case when data to be deleted is found
			{
				deleteNode(root);
				return true;
			}
		}
		else // case when data to be deleted  is not found
		{
			return false;
		}
	}

	void deleteNode(node<K,V>*&root) // function to delete a node 
	{
		K key; // temporary variable to hold key
		V value; // temporary variable to hold value
		node<K, V>* temp = root; // temporary pointer to hold current node's address

		if(root->left==nullptr) // case when 0 children or only right child
		{
			root = root->right;
			delete temp;
		}
		else if(root->right==nullptr) // case when 0 children or only left child
		{
			root = root->left;
			delete temp;
		}
		else // case when two children 
		{
			getSuccessor(root->left, key, value); // get largest key from left subtree 
			root->value = value; // overwrite current node's data with the largest node from left subtree 
			root->key = key; // overwrite current node's data with the largest node from left subtree
			
			stack<node<K, V>**> stackOfNodes; // make a stack to hold addresses of nodes that are visited
			stack<bool> stackOfDirection; // make a stack to hold the directions in which we move
			Delete(root->left, key, stackOfNodes, stackOfDirection); // delete the largest node from left subtree 
			if (!stackOfNodes.empty()) // we need to remove one pair of adrress and direction from the stack
			{
				stackOfNodes.pop();
				stackOfDirection.pop();
			}
			moveToRoot(stackOfNodes, stackOfDirection); // call moveToRoot function to move the last accessed node to top
		}
	}

	void getSuccessor(node<K,V>*root,K &key,V &value) // function t get largest node's data from left subtree
	{
		while(root->right!=nullptr) // move till the right most leaf node
		{
			root = root->right;
		}
		key = root->key;
		value = root->value;
	}

	vector<V>* getValuesLevelWise() // function that return a pointer to vector of Values
	{
		if(root!=nullptr) // make sure tree is not empty
		{
			node<K, V>* temp; // temporary pointer
			queue<node<K, V>*> q; // a queue for the purpose of level order traversal
			vector<V>* vectorPtr = new vector<V>; // a vector hold data level by level
			q.push(root); // push root into the queue

			while(!q.empty()) // keep getting nodes from the queue until it gets empty
			{
				temp = q.front(); // get a node from queue
				q.pop();
				vectorPtr->push_back(temp->value); // put that node in the vector
				 
				if(temp->left!=nullptr) // push left child of node in queue if any
				{
					q.push(temp->left);
				}
				if(temp->right!=nullptr) // push right child of node in queue if any
				{
					q.push(temp->right);
				}
			}
			return vectorPtr;
		} 
		else // case when tree is empty
		{
			return nullptr;
		}
	}

	vector<V>*getValuesInOrder() // workhorse function for returning a pointer to vector of values
	{
		if(root!=nullptr) // make sure tree is not empty
		{
			vector<V>* vectorPtr = new vector<V>; // make a vector of value
			getValuesInOrder(root, vectorPtr); // call the getValuesInOrder function
			return vectorPtr; 
		}
		else // case when tree is empty
		{
			return nullptr;
		}
	}

	void getValuesInOrder(node<K,V>*root,vector<V> *&vectorPtr) // function for returning a pointer to vector of values
	{
		if(root!=nullptr) // base case
		{ 
			getValuesInOrder(root->left, vectorPtr); // get all values from left subtree
			vectorPtr->push_back(root->value); // put current value in the vector
			getValuesInOrder(root->right, vectorPtr); // get all values from right subtree
		}
	}

	void Destructor(node<K,V>*root) // helper function for the destructor
	{
		if(root!=nullptr) // base case
		{
			Destructor(root->left); // delete left subtree
			Destructor(root->right); // delete right subtree
			delete root; // delete current node
		}
	}

	~SpecialBST() // destructor
	{
		if(root!=nullptr) // make sure tree is not already empty
		{
			Destructor(root);
		}
	}
};

class StudentData // class to hold student attributes
{
public:
	int rollNumber;
	string firstName;
	string lastName;
	int batch;
	string department;
	float cgpa;
	StudentData(int rollNumber=-1,string firstName="",string lastName="", int batch=-1,string department="",float cgpa=-1) // constructor
	{
		this->rollNumber = rollNumber;
		this->firstName = firstName;
		this->lastName = lastName;
		this->batch = batch;
		this->department = department;
		this->cgpa = cgpa;
	}
};

class StudentList // StudentList class that internally uses the SpecialBST class
{
	SpecialBST<int, StudentData> tree; // an object of SpecialBST class
	int totalStudents; // count of total students
public:
	StudentList() // constructor
	{
		totalStudents = 0;
	}
	
	bool insertNewStudent(int rollNumber,string firstName,string lastName,int batch,string department,float cgpa) // function to insert a new student
	{
		StudentData value(rollNumber,firstName, lastName, batch, department, cgpa); // make an object of StudentData class to hold all attributes
		
		bool flag= tree.insert(rollNumber, value); // call insert function of SpecialBST with key(rollNumber) and value(StudentData object) as parameters
		if(flag==true) // check if insertion is successful
		{
			totalStudents++; // increment number of students
		} 
		return flag; 
	}

	bool deleteStudent(int rollNumber) // function to remove a student
	{
		bool flag = tree.Delete(rollNumber); // call delete function of SpecialBST
		if(flag==true) // check if deletion is successful
		{
			totalStudents--; // decrement number of students
		}
		return flag;
	}

	void printAllStudents() // function that prints all students inOrder
	{
		vector<StudentData>* ptr = tree.getValuesInOrder(); // get the vector of students
		
		cout << "Total Students(inOrder): " << totalStudents << endl; 
		if(ptr!=nullptr) // make sure the vector is not empty
		{ 
			vector<StudentData>::iterator it; // iterator
			for (it = ptr->begin(); it != ptr->end(); ++it) // print from start to end
			{
				cout << it->rollNumber << " " << it->firstName << " " << it->lastName << " " << it->batch << " " << it->department << " " << it->cgpa;
				cout << endl;
			}
			cout << endl;
			delete ptr; // delete vector to free memory
		}
		else // case when vector is empty
		{
			cout << "There is no data to print!" << endl;
		}
	}

	void levelOrderPrint() // function that prints all students by level order
	{
		vector<StudentData>* ptr = tree.getValuesLevelWise(); // get the vector of students
		
		cout << "Total Students(LevelOrder): " << totalStudents << endl; 
		if (ptr != nullptr) // make sure the vector is not empty
		{
			vector<StudentData>::iterator it; // iterator
			for (it = ptr->begin(); it != ptr->end(); ++it) // print from start to end
			{
				cout << it->rollNumber << " " << it->firstName << " " << it->lastName << " " << it->batch << " " << it->department << " " << it->cgpa;
				cout << endl;
			}
			cout << endl;
			delete ptr; // delete vector to free memory
		}
		else // case when vector is empty
		{
			cout << "There is no data to print!" << endl;
		}
	}

	bool updateStudent(int oldRollNumber, int newRollNumber, string newFirstName, string newLastName, int newBatch, string newDepartment, float newCgpa) // function update data of a student
	{
		if(oldRollNumber==newRollNumber) // case when old and new roll numbers are same
		{
			StudentData* ptr = tree.search(oldRollNumber); // get pointer to the StudentData object stored in the node
			if(ptr!=nullptr) // make sure that the student exists in the list
			{
				ptr->firstName = newFirstName;
				ptr->lastName = newLastName;
				ptr->batch = newBatch;
				ptr->department = newDepartment;
				ptr->cgpa = newCgpa;
				return true;
			}
			else // case when the student with the given roll number does not exist
			{
				return false;
			}
		}
		else // case when old and new roll numbers are different
		{
			StudentData* ptr = tree.search(oldRollNumber); // get pointer to the StudentData object stored in the node
			if(ptr==nullptr) // case when the student with the given roll number does not exist
			{
				return false;
			}
			else // case when the student exists in the list
			{
				ptr = tree.search(newRollNumber); // find a student that may have the new roll number
				if(ptr!=nullptr) // case when the new roll number is already in the list
				{
					return false;
				}
				else // case when the new roll number is not anywhere in the list
				{
					deleteStudent(oldRollNumber); // delete old node of the student
					insertNewStudent(newRollNumber,newFirstName,newLastName,newBatch,newDepartment,newCgpa); // insert new data for the student
					return true;
				}
			}
		}
	}

	void Search(int rollNumber) // function that searches for a student and prints its details
	{
		StudentData*ptr= tree.search(rollNumber); // find a student against the given roll number
		if(ptr!=nullptr) // make sure that the student exists in the list
		{ 
			cout << "Roll Number: " << ptr->rollNumber << endl;
			cout << "First Name: " << ptr->firstName << endl;
			cout << "Last Name: " << ptr->lastName << endl;
			cout << "Batch: " << ptr->batch << endl;
			cout << "Department: " << ptr->department << endl;
			cout << "CGPA: " << ptr->cgpa << endl;
		}
		else  // case when the student with the given roll number does not exist
		{
			cout << "Error! Student Not Found!" << endl;
		}
	}
};

void getValidInput(int &rollNumber, string &firstName, string &lastName, int &batch, string &department, float &cgpa) // helper function to validate the inputs given by user
{
	cout << "Enter roll number: ";
	cin >> rollNumber;
	while (rollNumber <= 0) // keep asking for roll number until a positive value is entered
	{
		cout << "Enter a valid roll number: ";
		cin >> rollNumber;
	}
	
	cout << "Enter first name: ";
	cin >> firstName; // get first name
	cout << "Enter last name: ";
	cin >> lastName; // get last name

	cout << "Enter batch: ";
	cin >> batch;
	while (batch <= 0) // keep asking for batch until a positive value is added
	{
		cout << "Enter a valid batch: ";
		cin >> batch;
	}
	
	cout << "Enter department: ";
	cin >> department;
	
	cout << "Enter CGPA: ";
	cin >> cgpa;
	while (cgpa < 0 || cgpa>4) // keep asking for cgpa until the value is between 0 and 4
	{
		cout << "Enter valid CGPA: ";
		cin >> cgpa;
	}
}

int main()
{
	StudentList studentList; // make an object of StudentList class
	char input = ' '; // input variable to hold menu options
	int rollNumber; // variable to input roll number
	string firstName; // variable to input first name
	string lastName; // variable to input last name
	int batch; // variable to input batch 
	string department; // variable to input department
	float cgpa; // variable to input cgpa
	bool flag = false; // helper flag variable
	
	cout << "Press I to insert a new student." << endl; // print the menu
	cout << "Press D to delete a student." << endl;
	cout << "Press S to search a student by roll number." << endl;
	cout << "Press U to update the data of a student." << endl;
	cout << "Press P to print all students sorted by roll number." << endl;
	cout<<  "Press L to print all students in level order." << endl;
	cout << "Press E to exit." << endl;
	cin >> input; // get input
	
	while(input!='E'&&input!='e') // keep on going until E is pressed
	{
		if((input=='i')||(input=='I')) // case when I is pressed
		{
			cout << "Please enter the data of new student in the order: Roll Number, First Name, Last Name, Batch, Department, CGPA" << endl;
			getValidInput(rollNumber, firstName, lastName, batch, department, cgpa); // call getValidInput to get valid inputs
			flag = studentList.insertNewStudent(rollNumber, firstName, lastName, batch, department, cgpa); // call insert function
			if(flag==true) // check if the student is inserted successfully
			{
				cout << "New Student Inserted Successfully!" << endl;
			}
			else // case when student not inserted
			{
				cout << "Error! Student Not Inserted due to Duplicate roll number!" << endl;
			}
		}
		else if((input == 'D') ||(input == 'd')) // case when D is pressed
		{
			cout << "Please enter the roll number of the student that you want to delete: ";
			cin >> rollNumber; 
			while(rollNumber<=0) // keep asking for roll number until a positive value is entered
			{
				cout << "Enter a valid rollNumber to delete: ";
				cin >> rollNumber;
			}
			
			flag = studentList.deleteStudent(rollNumber); // call delete function to delete data against provided roll number
			if(flag==true) // case when deletion is successful
			{
				cout << "Student Deleted Successfully!" << endl;
			}
			else // case when deletion is not successful
			{
				cout << "Error! Student Not Found, So Not Deleted!" << endl;
			}
		}
		else if((input == 'S') ||(input == 's')) // case when S is pressed
		{
			cout << "Please enter the roll number of the student that you want to search: ";
			cin >> rollNumber;
			while(rollNumber<=0) // keep asking for roll number until a positive value is entered
			{
				cout << "Enter a valid rollNumber to search: ";
				cin >> rollNumber;
			}
			studentList.Search(rollNumber); // search for the given roll number
		}
		else if ((input == 'U') || (input == 'u')) // case when U is pressed
		{
			int oldRollNumber;
			cout << "Please enter the roll number of the student whose data you want to update: ";
			cin >> oldRollNumber;
			while(oldRollNumber <=0) // keep asking for roll number until a positive value is entered
			{
				cout << "Enter a valid rollNumber to update: ";
				cin >> oldRollNumber;
			}
			
			cout << "Please enter new data of student in this order: Roll Number, First Name, Last Name, Batch, Department, CGPA" << endl;
			getValidInput(rollNumber, firstName, lastName, batch, department, cgpa);  // call getValidInput to get valid inputs
			flag=studentList.updateStudent(oldRollNumber, rollNumber, firstName, lastName, batch, department, cgpa); // call update function
			if(flag==true) // case when updation is successful
			{
				cout << "Student Data Updated Successfully!" << endl;
			}
			else // case when updation is not successful
			{
				cout << "Error! Either New roll number is Duplicate or the Student Does Not Exist!" << endl;
			}
		}
		else if ((input == 'P') || (input == 'p')) // case when P is pressed
		{
			studentList.printAllStudents(); // call print function
		}
		else if ((input == 'L') || (input == 'l')) // case when L is pressed
		{ 
			studentList.levelOrderPrint(); // call print function
		}
		else // case when some other key is pressed
		{
			cout << "Error! Choose a Valid Option from the Menu!" << endl; 
		}
		
		cout << endl;
		cout << "Press I to insert a new student." << endl;  // print the menu
		cout << "Press D to delete a student." << endl;
		cout << "Press S to search a student by roll number." << endl;
		cout << "Press U to update the data of a student." << endl;
		cout << "Press P to print all students sorted by roll number." << endl;
		cout << "Press L to print all students in level order." << endl;
		cout << "Press E to exit." << endl;
		cin >> input; // get input
	}
	cout << endl;
	system("pause");
	return 0;
}
