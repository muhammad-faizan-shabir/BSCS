#include <iostream>
using namespace std;

class Node 
{
public:
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) // constructor
    {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    } 
};

class AVLTree 
{
    Node* root;
public:
    AVLTree() // constructor
    {
        root = nullptr;
    }

    void insert(int key)  // Problem2 Part1
    {
        root = insert(root, key);
    }
    Node* insert(Node* node, int key) // Problem2 Part1
    {
        if (node == nullptr) // base case
        {
            return new Node(key);
        }
        if (key < node->key) // traverse left subtree
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key) // traverse right subtree
        {
            node->right = insert(node->right, key);
        }
        else // return if duplicate key is found
        {
            return node;
        }
        
        node->height = 1 + max(height(node->left), height(node->right)); // Update height of the current node

        int balance = balanceFactor(node); // Get the balance factor to check whether this node became unbalanced

        if (balance > 1 && key < node->left->key)  // Left Left Case
        {
            return rotateRight(node); // rotate right
        }
        
        if (balance < -1 && key > node->right->key) // Right Right Case
        {
            return rotateLeft(node); // rotate left
        }
        
        if (balance > 1 && key > node->left->key)  // Left Right Case
        {
            node->left = rotateLeft(node->left); // rotate left
            return rotateRight(node); // rotate right
        }
        
        if (balance < -1 && key < node->right->key) // Right Left Case
        {
            node->right = rotateRight(node->right); // rotate right
            return rotateLeft(node); // rotate left
        }

        return node; // return update root
    }

    void deleteNode(int key)  // Problem2 Part2
    {
        root = deleteNode(root, key);
    }
    Node* deleteNode(Node* root, int key) // Problem2 Part2
    {
        if (root == nullptr) // base case
        {
            return root;
        }
            
        if (key < root->key) // traverse left subtree
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->key) // traverse right subtree
        {
            root->right = deleteNode(root->right, key);
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
                root->right = deleteNode(root->right, temp->key);
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

    int height(Node* n) // function that returns height of a node
    {
        if (n == nullptr)
        {
            return 0;
        }
        return n->height;
    }

    int balanceFactor(Node* n) // function that calculates the balance factor of a node
    {
        if (n == nullptr)
        {
            return 0;
        }
        return height(n->left) - height(n->right);
    }

    Node* rotateRight(Node* y) // Problem2 Part3
    {
        Node* x = y->left; // hold left child of the node to be rotated
        Node* T2 = x->right; // hold the right child of the left child of the node to be rotated

        x->right = y; // right pointer of right child of the node points to the node itself
        y->left = T2; // left pointer of node points to the right child of its left child

        y->height = max(height(y->left), height(y->right)) + 1; // update heights
        x->height = max(height(x->left), height(x->right)) + 1; // update heights

        return x; // left child is now root
    }

    Node* rotateLeft(Node* x)  // Problem2 Part3
    {
        Node* y = x->right; // hold right child of the node to be rotated
        Node* T2 = y->left; // hold the left child of the right child of the node to be rotated

        y->left = x; // left pointer of left child of the node points to the node itself
        x->right = T2; // right pointer of node points to the left child of its right child

        x->height = max(height(x->left), height(x->right)) + 1; // update heights
        y->height = max(height(y->left), height(y->right)) + 1; // update heights

        return y; // right child is now root
    }

    bool isAVL(AVLTree & tree) // Problem2 Part4
    {
        bool flag = true;
        isAVL(tree.root,flag);
        return flag;
    }
    void isAVL(Node*root,bool &flag) // Problem2 Part4
    {
        if(root!=nullptr)
        {
            if((balanceFactor(root)>1)||(balanceFactor(root)<-1)) // check balance of each node and check for violation
            {
                flag = false;
            }
            else
            {
                isAVL(root->left,flag); // check left subtree
                isAVL(root->right, flag); // check right subtree
            }
        }
    }

    bool search(int key)  // Problem2 Part5
    {
        return search(root, key);
    }
    bool search(Node* root, int key) // Problem2 Part5
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

    int findMin()  // Problem2 Part6
    {
        Node* minNode = findMin(root);
        return (minNode != nullptr) ? minNode->key : -1;
    }
    Node* findMin(Node* node)  // Problem2 Part6
    {
        while (node->left != nullptr) // keep moving left until you reach last node
            node = node->left;
        return node;
    }

    void printInorder() // Problem2 Part7
    {
        inorderTraversal(root);
        cout << endl;
    }
    void inorderTraversal(Node* root)  // Problem2 Part7
    {
        if (root != nullptr) // base case
        {
            inorderTraversal(root->left); // print left subtree 
            cout << root->key << " "; // print current node
            inorderTraversal(root->right); // print right subtree
        }
    }

    void printPreorder() // Problem2 Part7
    {
        preorderTraversal(root);
        cout << endl;
    }
    void preorderTraversal(Node* root) // Problem2 Part7
    {
        if (root != nullptr) 
        {
            cout << root->key << " "; // print current node
            preorderTraversal(root->left); // print left subtree
            preorderTraversal(root->right); // print right subtree
        }
    }

    void printPostorder()  // Problem2 Part7
    {
        postorderTraversal(root); 
        cout << endl;
    }
    void postorderTraversal(Node* root) // Problem2 Part7
    {
        if (root != nullptr) 
        {
            postorderTraversal(root->left); // print left subtree
            postorderTraversal(root->right); // print right subtree
            cout << root->key << " "; // print current node
        }
    }

    void printAllPaths() // Problem2 Part8
    {
        int path[100]; // Assuming the maximum length of a path is 100
        printAllPathsRecursive(root, path, 0);
    }
    void printAllPathsRecursive(Node* curr, int path[], int pathLength) // Problem2 Part8
    {
        if (curr == nullptr) // base case
            return;

        path[pathLength] = curr->key; // key track of keys/nodes visited
        pathLength++; // keep tracking path length

        if (curr->left == nullptr && curr->right == nullptr) // check whether current node is a leaf node
        {
            printPath(path, pathLength); // print path for current leaf node
        }
        else 
        {
            printAllPathsRecursive(curr->left, path, pathLength); // find all paths in the left subtree
            printAllPathsRecursive(curr->right, path, pathLength); // find all paths in the right subtree
        }
    }
    void printPath(int path[], int pathLength) // Problem2 Part8
    {
        for (int i = 0; i < pathLength; i++) // print keys in the array that represent the path
        {
            cout << path[i];
            if (i < pathLength - 1)
                cout << " -> ";
        }
        cout << endl;
    }
};

int main() 
{
    cout << "--------------AVL Tree-------------" << endl;
    AVLTree avlTree;

    avlTree.insert(50);
    avlTree.insert(40);
    avlTree.insert(75);
    avlTree.insert(25);
    avlTree.insert(65);
    avlTree.insert(80);

    cout << "Inorder Traversal: " << endl;
    avlTree.printInorder();
    cout << endl;

    cout << "Preorder Traversal: " << endl;
    avlTree.printPreorder();
    cout << endl;
    
    cout << "Postorder Traversal: " << endl;
    avlTree.printPostorder();
    cout << endl;
    
    cout << "All Paths from Root to Leaf:" << endl;
    avlTree.printAllPaths();
    cout << endl;
    
    avlTree.deleteNode(40);
    cout << "Inorder traversal after deletion of 40: " << endl;
    avlTree.printInorder();
    cout << endl;

    cout << "Is this tree AVL? " << avlTree.isAVL(avlTree) << endl << endl;
    
    cout << "75 found? " << avlTree.search(75) << endl << endl;
    cout << "100 found? " << avlTree.search(100) << endl << endl;

    cout << "Minimum element is: " << avlTree.findMin() << endl;
    
    cout << endl;
    system("pause");
    return 0;
}
