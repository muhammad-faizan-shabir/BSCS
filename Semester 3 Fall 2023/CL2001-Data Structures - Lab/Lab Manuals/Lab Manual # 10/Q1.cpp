#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	node(int d=0) // constructor
	{
		left = nullptr;
		right = nullptr;
		data = d;
	}
};

class BST
{
	node* root;
public:
	BST() // Problem1 Part1 
	{
		root = nullptr;
	}

	bool insert(int v) // Problem1 Part2 
	{
		return insert(v, root);
	}
	bool insert(int v,node*&root) // Problem1 Part2 
	{
		if(root!=nullptr&&root->data==v) // check for duplication
		{
			return false;
		}
		else if(root==nullptr) // check if end is reached
		{
			root = new node(v);
			return true;
		}
		else if(root->data>v) // move to left 
		{
			return insert(v, root->left);
		}
		else // move to right
		{ 
			return insert(v, root->right);
		}
	}

	BST(BST &obj) // Problem1 Part3
	{
		destroy(root); // destroy original tree to avoid memory waste
		copyTree(obj.root,root); // call copy function
	}
	void copyTree(node*externalRoot,node*&root) // Problem1 Part3
	{
		if(externalRoot!=nullptr) // base condition
		{
			root = new node(externalRoot->data); // copy data from current node
			copyTree(externalRoot->left, root->left); // copy data from left subtree
			copyTree(externalRoot->right, root->right); // copy data from right subtree
		}
	}

	void InOrderPrint() // Problem1 Part4
	{
		InOrderPrint(root);
		if(root!=nullptr)
		{
			cout << endl;
		}
	}
	void InOrderPrint(node*root) // Problem1 Part4
	{
		if(root!=nullptr) // base condition
		{
			InOrderPrint(root->left); // traverse left subtree
			cout << root->data << " "; // output current node data
			InOrderPrint(root->right); // traverse right subtree
		}
	}

	void BFS() // Problem1 Part5
	{
		BFS(root);
	} 
	void BFS(node* root) // Problem1 Part5
	{
		node* temp; // temporary pointer
		queue<node*> q; // queue to hold pointers for level order traversal
		if (root != nullptr)
		{
			q.push(root); // push root in the queue
			 
			while (!q.empty()) // keep print elements until loop queue becomes empty
			{
				temp = q.front(); // get node from queue
				q.pop();

				cout << temp->data << " "; // print node data

				if (temp->left != nullptr) // put left child(if any) of current node in queue 
				{
					q.push(temp->left);
				}
				if (temp->right != nullptr) // put right child(if any) of current node in queue 
				{
					q.push(temp->right);
				}
			}
			cout << endl;
		}
	}

	node* search(int key) // Problem1 Part6
	{
		return search(key, root);
	}
	node*search(int key,node*root) // Problem1 Part6
	{ 
		if(root==nullptr) // check if end is reached
		{
			return nullptr;
		}
		else if(root->data==key) // check if key is found
		{
			return root; // return addrees of node with the key
		}
		else if(root->data>key) // traverse left subtree
		{
			return search(key, root->left);
		}
		else // traverse right subtree
		{
			return search(key,root->right);
		}
	}
	
	int countNodes() // Problem1 Part7
	{
		int count = 0;
		countNodes(count,root);
		return count;
	}
	void countNodes(int&count,node*root) // Problem1 Part7
	{
		if(root!=nullptr) // base condition
		{
			countNodes(count, root->left); // count nodes in the left subtree
			count++; // count current node
			countNodes(count, root->right); // count nodes in the right subtree
		}
	}

	int leafCount() // Problem1 Part8
	{
		int count = 0;
		leafCount(count,root);
		return count;
	}
	void leafCount(int &count,node*&root) // Problem1 Part8
	{ 
		if(root!=nullptr) // base condition
		{
			leafCount(count,root->left); // count leaf nodes in the left subtree
			leafCount(count,root->right); // count leaf nodes in the right subtree
			if(root->left==nullptr&&root->right==nullptr) // count current leaf node
			{
				count++; 
			}
		}
	}

	void destroy(node*root) // Problem1 Part9
	{
		if(root!=nullptr) // base condition
		{ 
			destroy(root->left);  // delete left subtree
			destroy(root->right); // delete right subtree
			delete root; // delete current node
		}
	}
	~BST() // Problem1 Part9
	{
		if(root!=nullptr)
		{
			destroy(root);
		}
	 }
};

int main()
{
	cout << "-------------------BST---------------" << endl;
	BST bst1;
	bst1.insert(50);
	bst1.insert(30);
	bst1.insert(70);
	bst1.insert(20);
	bst1.insert(40);
	bst1.insert(60);
	bst1.insert(80);
	bst1.insert(90);
	bst1.insert(79);

	cout << "Inorder traversal of BST1:" << endl;
	bst1.InOrderPrint();
	
	cout << endl << "Level Order traversal of BST1:" << endl;
	bst1.BFS();
	cout << endl;
	
	node *ptr=bst1.search(50);
	if(ptr!=nullptr)
	{
		cout << "50 found" << endl << endl;
	}
	else
	{
		cout << "50 not found" << endl << endl;
	}
	
	ptr = bst1.search(65);
	if (ptr != nullptr)
	{
		cout << "65 found" << endl << endl;
	}
	else
	{
		cout << "65 not found" << endl << endl;
	}

	cout << "Count of nodes in BST1 is: " << bst1.countNodes() << endl << endl;
	
	cout << "Count of leaf nodes in BST1 is: " << bst1.leafCount() << endl << endl;

	BST bst2(bst1);
	cout << "Inorder traversal of BST2 that is a copy of BST1: " << endl;
	bst2.InOrderPrint();
	cout << endl;
	system("pause");
	return 0;
}