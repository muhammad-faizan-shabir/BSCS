#include<iostream>
#include<vector>
#include<string>
using namespace std;

class node
{
public:
	int data;
	node*left;
	node*right;
	node(int d=0)
	{
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

class BST
{
public:
	node*root;
	int size;
	BST()
	{
		size = 0;
		root = nullptr;
	}

	void insert(int d)
	{
		insert(root, d);
		size++;
	}

	void insert(node*&root, int d)
	{
		if (root == nullptr)
		{
			root = new node;
			root->data = d;
		}
		else if (root->data > d)
		{
			insert(root->left, d);
		}
		else
		{
			insert(root->right, d);
		}
	}
	
	

	void preOrder()
	{
		preOrder(root);
	}


	void preOrder(node*root)
	{
		if (root != nullptr)
		{
			cout << root->data << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}

	void preOrderSpecial(node*root,int *arr,int &i)
	{
		if (root != nullptr)
		{
			arr[i] = root->data;
			i++;
			preOrderSpecial(root->left,arr,i);
			preOrderSpecial(root->right,arr,i);
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
			if (root->data == d)
			{
				deleteNode(root);
				size--;
			}
			else if (root->data > d)
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
		int data = 0;
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
			root->data = data;
			deleteRecursive(root->left, data);
		}
	}

	void getSuccessor(node*root, int &d)
	{
		while (root->right != nullptr)
		{
			root = root->right;
		}
		d = root->data;
	}
	void destroy(node*&root)
	{
		if (root != nullptr)
		{
			destroy(root->left);
			destroy(root->right);
			delete root;
		}
	}
	~BST()
	{
		destroy(root);
	}

};

void trim(BST*tree, int low, int high)
{
	int size = tree->size;
	int *arr = new int[size];
	int index = 0;
	tree->preOrderSpecial(tree->root, arr, index);
	
	for (int i = 0; i < size; i++)
	{
		if ((arr[i]<low) || (arr[i]>high))
		{
			tree->deleteRecursive(arr[i]);
		}
	}
	delete[]arr;

}



int main()
{
	cout << "Test Case 1:" << endl;
	cout << "Tree before trimming: " << endl;
	BST b1;
	b1.insert(3);
	b1.insert(0);
	b1.insert(2);
	b1.insert(1);
	b1.insert(4);
	b1.preOrder();
	cout << endl;
	trim(&b1, 1, 3);
	cout << "Tree after trimming with low=1 and high =3" << endl;
	b1.preOrder();
	cout << endl;
	cout <<"------------------------------------"<< endl;
	cout << "Test Case 2" << endl;
	cout << "Tree before trimming: " << endl;
	BST b2;
	b2.insert(5);
	b2.insert(8);
	b2.insert(3);
	b2.insert(4);
	b2.insert(1);
	b2.preOrder();
	cout << endl;
	trim(&b2, 3, 5);
	cout << "Tree after trimming with low=3 and high =5" << endl;
	b2.preOrder();
	cout << endl;
	cout << endl;
	system("pause");
}