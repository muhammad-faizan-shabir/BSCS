#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
	int data;
	node* left;
	node* right;
	node(int key=0)
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

	void insert(int key)
	{
		insert(key, root);
	}

	bool insert(int key,node*&root)
	{
		if(root==nullptr)
		{
			root = new node(key);
			return true;
		}

		queue<node*> q;
		q.push(root);
		node* temp;
		while(!q.empty())
		{
			temp = q.front();
			q.pop();

			if(temp->left!=nullptr)
			{
				q.push(temp->left);
			}
			else
			{
				temp->left = new node(key);
				return true;
			}

			if (temp->right != nullptr)
				q.push(temp->right);
			else {
				temp->right = new node(key);
				return true;
			}
		}
	}

	void InOrderTraversal()
	{
		InOrderTraversal(root);
		cout << endl;
	}

	void InOrderTraversal(node* root)
	{
		if (root != nullptr)
		{
			InOrderTraversal(root->left);
			cout << root->data << " ";
			InOrderTraversal(root->right);
		}
	}

	void PreOrderTraversal()
	{
		PreOrderTraversal(root);
		cout << endl;
	}

	void PreOrderTraversal(node* root)
	{
		if (root != nullptr)
		{
			cout << root->data << " ";
			PreOrderTraversal(root->left);
			PreOrderTraversal(root->right);
		}
	}

	void PostOrderTraversal()
	{
		PostOrderTraversal(root);
		cout << endl;
	}

	void PostOrderTraversal(node* root)
	{
		if (root != nullptr)
		{
			PostOrderTraversal(root->left);
			PostOrderTraversal(root->right);
			cout << root->data << " ";
		}
	}
	void BFS()
	{
		BFS(root);
	}

	void BFS(node*root)
	{
		node* temp;
		queue<node*> q;
		if(root!=nullptr)
		{
			q.push(root);

			while(!q.empty())
			{
				temp = q.front();
				q.pop();

				cout << temp->data << " ";

				if(temp->left!=nullptr)
				{
					q.push(temp->left);
				}
				if(temp->right!=nullptr)
				{
					q.push(temp->right);
				}
			}
			cout << endl;
		}
	}

	void deleteNode(int key)
	{
		bool flag = false;
		findNode(key, root, flag);
	}

	void findNode(int key, node*& root, bool& flag)
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

	void deleteNode(node*& root)
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

	void getSuccessor(node* root, int& key)
	{
		while (root->right != nullptr)
		{
			root = root->right;
		}
		key = root->data;
	}



	void Destructor(node*root)
	{
		if(root!=nullptr)
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

	void RecursiveInsertion(int key)
	{
		RecursiveInsertion(key,root);
	}

	void RecursiveInsertion(int key,node*&root)
	{
		if(root==nullptr)
		{
			root = new node(key);
		}
		else if(root->data>key)
		{
			RecursiveInsertion(key, root->left);
		}
		else
		{
			RecursiveInsertion(key, root->left);
		}
	}

	void IterativeInsertion(int key)
	{
		node* newNode = new node(key);
		node* parent=root;
		node* child = root;

		while(child!=nullptr)
		{
			parent = child;
			if(parent->data>key)
			{
				child = child->left;
			}
			else
			{
				child = child->right;
			}
		}
		if(parent==nullptr)
		{
			root = newNode;
		}
		else if(parent->data>key)
		{
			parent->left = newNode;
		}
		else
		{
			parent->right = newNode;
		}
	}

	bool IterativeSearch(int key)
	{
		node* current = root;
		bool found = false;
		while(current!=nullptr&&found==false)
		{
			if(current->data==key)
			{
				found = true;
			}
			else if(current->data>key)
			{
				current = current->left;
			}
			else
			{
				current = current->right;
			}
		}
		return found;
	}

	bool RecursiveSearch(int key)
	{
		return RecursiveSearch(key, root);
	}
	
	bool RecursiveSearch(int key,node*root)
	{
		if(root!=nullptr)
		{
			if(root->data>key)
			{
				return RecursiveSearch(key, root->left);
			}
			else if (root->data < key)
			{
				return RecursiveSearch(key, root->right);
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}

	void deleteRecursive(int key)
	{
		deleteRecursive(key, root);
	}

	void deleteRecursive(int key, node*& root)
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

	void deleteNode(node*& root)
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
	 void getSuccessor(node*root,int &key)
	 {
		 while(root->right!=nullptr)
		 {
			 root = root->right;
		 }
		 key = root->data;
	 }

	 void IterativeDelete(int key)
	 {
		 node* parent = root;
		 node* child = root;
		 while(child!=nullptr&&child->data!=key)
		 {
			 parent = child;
			 if(parent->data>key)
			 {
				 child = child->left;
			 }
			 else
			 {
				 child = child->right;
			 }
		 }
		 if(child!=nullptr)
		 {
			 if(child==root)
			 {
				 deleteNode(root);
			 }
			 else if (parent->left==child)
			 {
				 deleteNode(parent->left);
			 }
			 else
			 {
				 deleteNode(parent->right);
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
	BinaryTree tree;
	for(int i=0;i<10;i++)
	{
		tree.insert(i + 1);
	}
	

	tree.BFS();
	tree.InOrderTraversal();
	tree.PostOrderTraversal();
	tree.PreOrderTraversal();
	tree.deleteNode(1);
	tree.BFS();
	tree.InOrderTraversal();
	tree.PostOrderTraversal();
	tree.PreOrderTraversal();
	tree.deleteNode(10);
	tree.BFS();
	tree.InOrderTraversal();
	tree.PostOrderTraversal();
	tree.PreOrderTraversal();
}