#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	node(int key = 0)
	{
		data = key;
		left = nullptr;
		right = nullptr;
	}
};

class BinaryTree
{
	node* root;
public:
	BinaryTree()
	{
		root = nullptr;
	}

	void insert(int key) // Problem 1
	{
		insert(key, root);
	}
	
	bool insert(int key, node*& root) // Problem 1
	{
		if (root == nullptr)
		{
			root = new node(key);
			return true;
		}

		queue<node*> q;
		q.push(root);
		node* temp;
		
		while (!q.empty())
		{
			temp = q.front();
			q.pop();

			if (temp->left != nullptr)
			{
				q.push(temp->left);
			}
			else
			{
				temp->left = new node(key);
				return true;
			}

			if (temp->right != nullptr)
			{
				q.push(temp->right);
			}
			else 
			{
				temp->right = new node(key);
				return true;
			}
		}
	}
	
	bool search(int key)  // Problem 1
	{
		bool flag = false;
		search(key, root, flag);
		return flag;
	}
	
	void search(int key, node* root, bool& flag)  // Problem 1
	{
		if (root != nullptr && flag == false)
		{
			if (root->data == key)
			{
				flag = true;
			}
			search(key, root->left, flag);
			search(key, root->right, flag);
		}
	}

	void InOrderTraversal() // Problem 2
	{
		InOrderTraversal(root);
		cout << endl;
	}
	
	void InOrderTraversal(node* root) // Problem 2
	{
		if (root != nullptr)
		{
			InOrderTraversal(root->left);
			cout << root->data << " ";
			InOrderTraversal(root->right);
		}
	}

	void deleteNode(int key) // Problem 3
	{
		bool flag = false;
		findNode(key, root, flag);
	}
	
	void findNode(int key, node*& root, bool& flag) // Problem 3
	{
		if (flag == false && root != nullptr)
		{
			if (root->data == key)
			{
				deleteNode(root);
				flag = true;
			}
			findNode(key, root->left, flag);
			findNode(key, root->right, flag);
		}
	}
	
	void deleteNode(node*& root) // Problem 3
	{
		int key;
		node* temp = root;
		
		if (root->left == nullptr)
		{
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr)
		{
			root = root->left;
			delete temp;
		}
		else
		{
			getSuccessor(root->left, key);
			root->data = key;
			bool flag = false;
			findNode(key, root->left, flag);
		}
	}
	
	void getSuccessor(node* root, int& key) // Problem 3
	{
		while (root->right != nullptr)
		{
			root = root->right;
		}
		key = root->data;
	}

	void Destructor(node* root)
	{
		if (root != nullptr)
		{
			Destructor(root->left);
			Destructor(root->right);
			delete root;
		}
	}
	
	~BinaryTree()
	{
		Destructor(root);
		root = nullptr;
	}
};

class BinarySearchTree
{
	node* root;
public:
	BinarySearchTree()
	{
		root = nullptr;
	}

	void RecursiveInsertion(int key) // Problem 4
	{
		RecursiveInsertion(key, root);
	}
	
	void RecursiveInsertion(int key, node*& root) // Problem 4
	{
		if (root == nullptr)
		{
			root = new node(key);
		}
		else if (root->data > key)
		{
			RecursiveInsertion(key, root->left);
		}
		else
		{
			RecursiveInsertion(key, root->right);
		}
	}

	void deleteRecursive(int key) // Problem 4
	{
		deleteRecursive(key, root);
	}
	
	void deleteRecursive(int key, node*& root) // Problem 4
	{
		if (root != nullptr)
		{
			if (root->data > key)
			{
				deleteRecursive(key, root->left);
			}
			else if (root->data < key)
			{
				deleteRecursive(key, root->right);
			}
			else
			{
				deleteNode(root);
			}
		}
	}

	void deleteNode(node*& root) // Problem 4
	{
		int key = 0;
		node* temp = root;
		
		if (root->left == nullptr)
		{
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr)
		{
			root = root->left;
			delete temp;
		}
		else
		{
			getSuccessor(root->left, key);
			root->data = key;
			deleteRecursive(key, root->left);
		}
	}
	
	void getSuccessor(node* root, int& key) // Problem 4
	{
		while (root->right != nullptr)
		{
			root = root->right;
		}
		key = root->data;
	}

	void rangeSearch(int low, int high) // Problem 5
	{
		rangeSearch(low, high, root);
		cout << endl;
	}
	
	void rangeSearch(int low, int high, node* root) // Problem 5
	{
		if (root != nullptr)
		{
			if (root->data >= low and root->data <= high)
			{
				cout << root->data << " ";
			}
			rangeSearch(low, high, root->left);
			rangeSearch(low, high, root->right);
		}
	}

	int SecondLargestElement() // Problem 6
	{
		if (root != nullptr)
		{
			if (root->left == nullptr && root->right == nullptr)
			{
				return -1;
			}
			
			int largest = root->data;
			int secondLargest = root->data;
			SecondLargestElement(largest, secondLargest, root);
			return secondLargest;
		}
		else
		{
			return -1;
		}
	}
	
	void SecondLargestElement(int& largest, int& secondLargest, node* root) // Problem 6
	{
		if (root != nullptr)
		{
			if (root->data > largest)
			{
				secondLargest = largest;
				largest = root->data;
			}
			else if (root->data > secondLargest || largest == secondLargest)
			{
				secondLargest = root->data;
			}
			SecondLargestElement(largest, secondLargest, root->left);
			SecondLargestElement(largest, secondLargest, root->right);
		}
	}
	 
	void BFS() // Problem 7
	{
		BFS(root);
	}
	
	void BFS(node* root) // Problem 7
	{
		node* temp;
		queue<node*> q;
		
		if (root != nullptr)
		{
			q.push(root);

			while (!q.empty())
			{
				temp = q.front();
				q.pop();

				cout << temp->data << " ";

				if (temp->left != nullptr)
				{
					q.push(temp->left);
				}
				if (temp->right != nullptr)
				{
					q.push(temp->right);
				}
			}
			cout << endl;
		}
	}
	 
	void ZigZagTraversal() // Problem 9
	{
		ZigZagTraversal(root);
		cout << endl;
	}
	
	void ZigZagTraversal(node* root)  // Problem 9
	{
		if (!root)
		{
			return;
		}
		
		stack<node*> currentLevel;
		stack<node*> nextLevel;
		bool leftToRight = true;
		currentLevel.push(root);

		while (!currentLevel.empty()) 
		{
			node* currentNode = currentLevel.top();
			currentLevel.pop();

			cout << currentNode->data<< " ";

			if (leftToRight) 
			{
				if (currentNode->left) nextLevel.push(currentNode->left);
				if (currentNode->right) nextLevel.push(currentNode->right);
			}
			else 
			{
				if (currentNode->right) nextLevel.push(currentNode->right);
				if (currentNode->left) nextLevel.push(currentNode->left);
			}

			if (currentLevel.empty()) 
			{
				leftToRight = !leftToRight;
				swap(currentLevel, nextLevel);
			}
		}
	}
	
	void Destructor(node* root)
	{
		if (root != nullptr)
		{
			Destructor(root->left);
			Destructor(root->right);
			delete root;
		}
	}

	~BinarySearchTree()
	{
		Destructor(root);
		root = nullptr;
	}
};

int main()
{
	cout << "Binary tree" << endl;
	BinaryTree tree1;
	for (int i = 0; i < 10; i++)
	{
		tree1.insert(i + 1);
	}
	
	cout << "Inorder traversal:" << endl;
	tree1.InOrderTraversal();

	cout << "10 found ? ";
	cout << tree1.search(10) << endl;
	cout << "20 found ? ";
	cout << tree1.search(100) << endl;

    tree1.deleteNode(2);
	tree1.deleteNode(8);
	cout << "After deleting 2 and 8:" << endl;
	tree1.InOrderTraversal();
	cout << endl;

	cout << "BST 1" << endl;
	BinarySearchTree tree2;
	
	tree2.RecursiveInsertion(23);
	tree2.RecursiveInsertion(18);
	tree2.RecursiveInsertion(10);
	tree2.RecursiveInsertion(30);
	tree2.RecursiveInsertion(20);
	tree2.RecursiveInsertion(27);
	tree2.RecursiveInsertion(32);
	tree2.RecursiveInsertion(50);
	tree2.RecursiveInsertion(6);
	tree2.RecursiveInsertion(15);
	cout << "Level order traversal Before deletion of 23 and 18" << endl;
	tree2.BFS();
	
	tree2.deleteRecursive(23);
	tree2.deleteRecursive(18);
	cout << "Level order traversal After deletion of 23 and 18" << endl;
	tree2.BFS();

	cout << "The numbers in range 4 to 9 are:";
	tree2.rangeSearch(4, 9);
	
	cout << "The second largest element is: ";
	cout << tree2.SecondLargestElement();
	cout << endl << endl;
	
	cout << "BST 2" << endl;
	BinarySearchTree tree3;
	tree3.RecursiveInsertion(23);
	tree3.RecursiveInsertion(18);
	tree3.RecursiveInsertion(10);
	tree3.RecursiveInsertion(30);
	tree3.RecursiveInsertion(20);
	tree3.RecursiveInsertion(27);
	tree3.RecursiveInsertion(32);
	tree3.RecursiveInsertion(50);
	tree3.RecursiveInsertion(6);
	tree3.RecursiveInsertion(15);
	
	cout << "Zig zag traversal" << endl;
	tree3.ZigZagTraversal();
	cout << endl;
	system("pause");
}