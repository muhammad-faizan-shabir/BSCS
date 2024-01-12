#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Node
{
public:
	int key;
	string title;
	string author;
	Node* left;
	Node* right;
	int height;
	Node(int key=0,string author="",string title="") // constructor
	{
		this->key = key;
		this->title = title;
		this->author = author;
		left = nullptr;
		right = nullptr;
		height = 1;
	}
};

class BST
{
	Node* root;
public:
	BST() // constructor
	{
		root = nullptr;
	}

	void erase(int key) // Problem1
	{
		root = erase(root, key);
	}
	Node* erase(Node* root, int key) // Problem1
	{
		if (root == nullptr) // base case
		{
			return root;
		}

		if (key < root->key) // traverse left subtree
		{
			root->left = erase(root->left, key);
		}
		else if (key > root->key) // traverse right subtree
		{
			root->right = erase(root->right, key);
		}
		else // case when node to be deleted is found
		{
			if (root->left == nullptr || root->right == nullptr)  // case when at most one child
			{
				Node* temp = root->left ? root->left : root->right;

				if (temp == nullptr)
				{
					temp = root;
					root = nullptr;
				}
				else
				{
					*root = *temp;
				}
				delete temp;
			}
			else // case when two children
			{
				Node* temp = findMin(root->right);
				root->key = temp->key;
				root->right = erase(root->right, temp->key);
			}
		}

		if (root == nullptr) // case when end is reached
		{
			return root;
		}

		root->height = 1 + max(height(root->left), height(root->right)); // Update height of the current node

		int balance = balanceFactor(root); // Get the balance factor to check whether this node became unbalanced

		if (balance > 1 && balanceFactor(root->left) >= 0) // Left Left case
		{
			return rotateRight(root); // rotate right
		}

		if (balance > 1 && balanceFactor(root->left) < 0) // Left Right case
		{
			root->left = rotateLeft(root->left); // rotate left 
			return rotateRight(root);  // rotate right
		}

		if (balance < -1 && balanceFactor(root->right) <= 0) // Right Right case
		{
			return rotateLeft(root); // rotate right
		}

		if (balance < -1 && balanceFactor(root->right) > 0) // Right Left case
		{
			root->right = rotateRight(root->right); // rotate right
			return rotateLeft(root); // rotate left
		}

		return root; // return updated root
	}

	int heightOfTree() // Problem2
	{ 
		return height(root);
	}
	int height(Node* n) // Problem2
	{
		if (n == nullptr)
		{
			return 0;
		}
		return n->height;
	}
	
	int findDepth(int key) // Problem3
	{
		int depth = 0;
		findDepth(root, key, depth);
		return depth;
	}
	void findDepth(Node*&root, int key, int &depth) // Problem3
	{
		if (root == nullptr) 
		{
			return;
		}


		if (root->key == key) 
		{
			return;
		}
		else if (key < root->key) 
		{
			depth++;
			return findDepth(root->left, key, depth);
		}
		else 
		{
			depth++;
			return findDepth(root->right, key, depth);
		}
	}

	bool isBalanced(BST & tree)  // Problem4
	{
		bool flag = true;
		isBalanced(tree.root, flag);
		return flag;
	}
	void isBalanced(Node*root, bool &flag)  //Problem4
	{
		if (root != nullptr)
		{
			if ((balanceFactor(root)>1) || (balanceFactor(root)<-1)) 
			{
				flag = false;
			}
			else
			{
				isBalanced(root->left, flag); 
				isBalanced(root->right, flag); 
			}
		}
	}

	template<class T>
	BST(T *sortedData, int n)  // Problem5
	{
		for (int i = 0; i < n; i++)
		{
			bst(sortedData[i], root);
		}
	}
	bool bst(int key, Node*& root)  // Problem5
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}

		queue<Node*> q;
		q.push(root);
		Node* temp;

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
				temp->left = new Node(key);
				return true;
			}

			if (temp->right != nullptr)
			{
				q.push(temp->right);
			}
			else
			{
				temp->right = new Node(key);
				return true;
			}
		}
	}

	void insert(int key,string author,string title)   // function to insert data
	{
		root = insert(root, key,author,title);
	}
	Node* insert(Node* node, int key,string author,string title)  // function to insert data
	{
		if (node == nullptr) 
		{
			return new Node(key,author,title);
		}
		if (key < node->key) 
		{
			node->left = insert(node->left, key,author,title);
		}
		else if (key > node->key) 
		{
			node->right = insert(node->right, key,author,title);
		}
		else 
		{
			return node;
		}

		node->height = 1 + max(height(node->left), height(node->right)); 

		int balance = balanceFactor(node); 

		if (balance > 1 && key < node->left->key)  
		{
			return rotateRight(node); 
		}

		if (balance < -1 && key > node->right->key) 
		{
			return rotateLeft(node); 
		}

		if (balance > 1 && key > node->left->key)  
		{
			node->left = rotateLeft(node->left); 
			return rotateRight(node); 
		}

		if (balance < -1 && key < node->right->key) 
		{
			node->right = rotateRight(node->right); 
			return rotateLeft(node); 
		}

		return node; // return updated root
	}
	
	int balanceFactor(Node* n) // function that calculates the balance factor of a node
	{
		if (n == nullptr)
		{
			return 0;
		}
		return height(n->left) - height(n->right);
	}

	Node* rotateRight(Node* y) 
	{
		Node* x = y->left; // hold left child of the node to be rotated
		Node* T2 = x->right; // hold the right child of the left child of the node to be rotated

		x->right = y; // right pointer of right child of the node points to the node itself
		y->left = T2; // left pointer of node points to the right child of its left child

		y->height = max(height(y->left), height(y->right)) + 1; // update heights
		x->height = max(height(x->left), height(x->right)) + 1; // update heights

		return x; // left child is now root
	}

	Node* rotateLeft(Node* x) 
	{
		Node* y = x->right; // hold right child of the node to be rotated
		Node* T2 = y->left; // hold the left child of the right child of the node to be rotated

		y->left = x; // left pointer of left child of the node points to the node itself
		x->right = T2; // right pointer of node points to the left child of its right child

		x->height = max(height(x->left), height(x->right)) + 1; // update heights
		y->height = max(height(y->left), height(y->right)) + 1; // update heights

		return y; // right child is now root
	}

	bool search(int key)   // function for searching
	{
		return search(root, key);
	}
	bool search(Node* root, int key) // function for searching
	{
		if (root == nullptr) // case when key not found
		{
			return false;
		}


		if (root->key == key) // case when key found
		{
			return true;
		}
		else if (key < root->key) // traverse left subtree
		{
			return search(root->left, key);
		}
		else // traverse right subtree
		{
			return search(root->right, key);
		}
	}

	int findMin() 
	{
		Node* minNode = findMin(root);
		return (minNode != nullptr) ? minNode->key : -1;
	}
	Node* findMin(Node* node) 
	{
		while (node->left != nullptr) // keep moving left until you reach last node
			node = node->left;
		return node;
	}

	void printInorder() // function for printing
	{
		inorderTraversal(root);
		cout << endl;
	}
	void inorderTraversal(Node* root) // function for printing
	{
		if (root != nullptr) // base case
		{
			inorderTraversal(root->left); // print left subtree 
			cout<<"(" << root->key << " "<<root->author<<" "<<root->title<<") "; // print current node
			inorderTraversal(root->right); // print right subtree
		}
	}
};

int main()
{
	cout << "--------------BST-------------" << endl;
	BST tree;

	tree.insert(50,"Ali","DataBases");
	tree.insert(40,"Bilal","ShortStories");
	tree.insert(75,"Ahmed","LongStories");
	tree.insert(25,"Hashmi","COAL");
	tree.insert(65,"Faizan","DSA");
	tree.insert(80,"Umer","OOP");

	cout << "Inorder Traversal: (Format: ISBN Author Title)" << endl;
	tree.printInorder();
	cout << endl;

	cout << "The height of the above tree is: " << tree.heightOfTree() << endl << endl;

	cout << "The depth of the ISBN 65 in the above list is: " << tree.findDepth(65) << endl << endl;

	cout << "The above printed tree is balanced or not? " << tree.isBalanced(tree) << endl << endl;
	int sortedArray[10] = { 4, 6, 8, 11, 15, 18, 23, 34, 44, 50 };
	
	cout << "Passing a sorted array to constructor of Perfect BST" << endl;
	BST tree2(sortedArray, 10);
	cout << "Inorder traversal for perfect tree: " << endl;
	tree2.printInorder();
	cout << endl;
	cout << endl;
	system("pause");
	return 0;
}



