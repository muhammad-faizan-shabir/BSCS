#include<iostream>
#include<string>
using namespace std;

class node
{
public:
	int earning;
	string name;
	int age;
	string role;
	node*left;
	node*right;
	node(int e = 0, string n = "", int a = 0, string r = "", node*l = nullptr, node* ri = nullptr)
	{
		earning = e;
		name = n;
		age = a;
		role = r;
		left = l;
		right = ri;
	}
};


class BST
{
public:
	node*root;
	int size;
	BST()
	{
		root = nullptr;
		size = 0;
	}
	void insert(node d)
	{
		insert(root, d);
		size++;
	}

	void insert(node*&root, node d)
	{
		if (root == nullptr)
		{
			root = new node(d);
			
		}
		else if (root->earning > d.earning)
		{
			insert(root->left, d);
		}
		else
		{
			insert(root->right, d);
		}
	}

	void deleteRecursive(int d)
	{
		deleteRecursive(root, d);
	}

	void deleteRecursive(node* &root, int d)
	{
		if (root != nullptr)
		{
			if (root->earning == d)
			{
				deleteNode(root);
				size--;
			}
			else if (root->earning > d)
			{
				deleteRecursive(root->left, d);
			}
			else
			{
				deleteRecursive(root->right, d);
			}
		}
	}

	void deleteNode(node*&root)
	{
		node*temp = root;
		node data = 0;
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
			getSuccessor(root->left, data);
			root->earning = data.earning;
			root->name = data.name;
			root->age = data.age;
			root->role = data.role;
			deleteRecursive(root->left, data.earning);
		}
	}

	void getSuccessor(node*root, node &d)
	{
		while (root->right != nullptr)
		{
			root = root->right;
		}
		d.earning = root->earning;
		d.name = root->name;
		d.age = root->age;
		d.role = root->role;
	}

	void inOrder()
	{
		inOrder(root);
	}

	void inOrder(node*root)
	{
		if (root != nullptr)
		{
			inOrder(root->left);
			cout << "(" << root->name << ", " << root->earning << ", " << root->age << ", " << root->role << ") ";
			inOrder(root->right);
		}
	}

	void destroy(node*root)
	{
		if (root != nullptr)
		{
			destroy(root->left);
			destroy(root->right);
			delete root;
		}
	}
	
	void boundaryTraversal()
	{
		void boundaryTraversal(node*root);
	}

	void boundaryTraversal(node*root)
	{

	}

	~BST()
	{
		destroy(root);
	}

};


int main()
{
	BST b1;
	cout << "Tree after inserting some elements: " << endl;
	node obj1(1200, "Ali", 50, "Father");
	node obj2(1000, "Bilal", 13, "son");
	node obj3(1500, "Sara", 50, "mother");
	b1.insert(obj1);
	b1.insert(obj2);
	b1.insert(obj3);
	b1.inOrder();
	cout << endl;
	cout << "--------------------------------------" << endl;
	cout << "Tree after removing/burning memeber with earning 1000" << endl;
	b1.deleteRecursive(1000);
	b1.inOrder();
	cout << endl;
	system("pause");
}