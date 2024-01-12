#include<iostream>
#include<string>
using namespace std;

template<class T> // template class
class stack
{
	struct node
	{
		T data;
		node* next;
		node()
		{
			next = nullptr;
		}
	};
	
	node* topOfStackPointer;
	int size;
public:
	stack() // constructor
	{
		topOfStackPointer = nullptr;
		size = 0;
	}
	
	int Size() // function that returns size of stack
	{
		return size;
	}
	 
	bool isEmpty() // function that tells whether stack is empty or not
	{
		return size == 0;
	}

	bool top(T& data) // function to peek the element at the top of stack
	{
		if (!isEmpty())
		{
			data = topOfStackPointer->data;
			return true;
		}
		else
		{
			return false;
		}
	}

	void pop() // function to remove element from top of stack
	{
		if (size != 0)
		{
			node* temp = topOfStackPointer;
			topOfStackPointer = topOfStackPointer->next;
			delete temp;
			size--;
		}
		else
		{
			cout << "Cannot pop, Stack already empty" << endl;
		}
	}

	void push(T const& data) // function to add element at top of stack
	{
		node* temp = new node;
		temp->data = data;
		temp->next = topOfStackPointer;
		topOfStackPointer = temp;
		size++;
	}

	void print() // function to print the stack
	{
		node* current = topOfStackPointer;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	
	~stack() // destructor
	{
		if (size != 0)
		{
			for (int i = 0; i < size; i++)
			{
				pop();
			}
		}
	}
};

bool matchParentheses(string expression) // function to balance/match brackets
{
	stack<char> stack; // make a stack
	int size = 0;
	size = expression.length(); // get length of the expression
	char character;
	
	for (int i = 0; i < size; i++) // iterate over each character of the expression
	{
		// case when the current character is not a bracket 
		if ((expression[i] != '(') && (expression[i] != ')') && (expression[i] != '[') && (expression[i] != ']') && (expression[i] != '{') && (expression[i] != '}'))
		{
			continue;
		}
		else if ((expression[i] == '(') || (expression[i] == '[') || (expression[i] == '{')) // case when current character is an opening bracket
		{
			if (expression[i] == '(')
			{
				stack.push(')'); // push corresponding closing bracket on stack
			}
			else if (expression[i] == '[')
			{
				stack.push(']'); // push corresponding closing bracket on stack
			}
			else
			{
				stack.push('}'); // push corresponding closing bracket on stack
			}
		}
		else // case when the current character is a closing bracket
		{
			stack.top(character); // peek to of stack

			if (stack.isEmpty() || expression[i] != character) // if stack is empty or if the brackets do not match then brackets are not balanced
			{
				return false;
			}
			
			stack.pop(); // pop element
		}
	}
	
	return stack.isEmpty(); // if stack is empty by the end then true is returned otherwise false is returned
}

int getPriority(char operation) // helper function for infixToPrefix conversion
{
	if (operation == '-' || operation == '+') // low priority of + and -
		return 1;
	else if (operation == '*' || operation == '/') // high priority of * and /
		return 2;
	else
		return 0;
}

void infixToPrefix(string& expression) // function to convert an Infix expression into Prefix
{
	string tempExpression = ""; // make a temporary string
	int size = expression.length(); // get size of expression
	char character;
	stack<char> stack; // make a stack

	for (int i = 0; i < size; i++) // push each character of the expression to stack 
	{
		stack.push(expression[i]);
	}

	expression = ""; // make the expression empty

	for (int i = 0; i < size; i++) // pop each character of the expression from stack back so that its now in reverse
	{
		stack.top(character);
		stack.pop();
		if (character == ')')
		{
			character = '(';
		}
		else if (character == '(')
		{
			character = ')';
		}
		expression.append(string(1, character));
	}

	for (int i = 0; i < size; i++) // iterate each character of reversed expresseion
	{
		// case when the current character is not a bracket and not an operator
		if ((expression[i] != '(') && (expression[i] != ')') && (expression[i] != '+') && (expression[i] != '-') && (expression[i] != '*') && (expression[i] != '/'))
		{
			tempExpression.append(string(1, expression[i])); // move current character to temporary string
		}
		else if (expression[i] == '(') // case when current character is an opening bracket
		{ 
			stack.push(expression[i]); // push opening bracket on stack
		}
		else if (expression[i] == ')') // case when current character is a closing bracket
		{
			stack.top(character);
			while (character != '(') // pop everything from stack until opening bracket
			{
				tempExpression.append(string(1, character));
				stack.pop();
				stack.top(character);
			}
			stack.pop();
		}
		else // case when current character is an operator
		{
			if (stack.isEmpty()) // if stack is empty then simply push the operator onto the stack
			{
				stack.push(expression[i]);
			}
			else // if stack is not empty then check if top of stack contains an operator that is equal to or higher in precedence than the current operator
			{
				stack.top(character);
				while ((getPriority(character) >= getPriority(expression[i])) && !stack.isEmpty()) // keep popping operators until an operator with less precedence is encountered
				{
					tempExpression.append(string(1, character));
					stack.pop();
					stack.top(character);
				}
				stack.push(expression[i]);
			}
		}
	}

	while (!stack.isEmpty()) // by the end pop the complete stack to get all the remaining operators
	{
		stack.top(character);
		tempExpression.append(string(1, character));
		stack.pop();
	}

	size = tempExpression.length(); // recalculate the length of the obtained expression since now it longer has brackets
	expression = "";

	for (int i = 0; i < size; i++) // push each element of obtained expression onto the stack
	{
		stack.push(tempExpression[i]);
	}
	for (int i = 0; i < size; i++) // pop each element back into the expression so that the expression is now in reverse
	{
		stack.top(character);
		stack.pop();
		expression.append(string(1, character));
	}
}

bool isPalindrome(string s) // function to check palindrome
{
	int length = s.length(); // get length of the strng
	stack<char> stack; // make a stack
	
	int i, mid = length / 2; // calculate mid of string 

	for (i = 0; i < mid; i++) // push half of the elements of the string onto the stack
	{
		stack.push(s[i]);
	}

	if (length % 2 != 0) // skip middle element if odd number of elements in the string
	{
		i++;
	}

	char character;

	while (s[i] != '\0') // move till end of remaing string
	{
		stack.top(character); // get an element from stack
		stack.pop();

		if (character != s[i]) // if elements do not match then the string is not a palindrome
			return false;
		i++;
	}

	return true; 
}

int main()
{
	cout << "-------------------TASK 1-------------------" << endl;
	stack<int> list1;
	cout << "After Pushing 1,2,3,4,5:" << endl;
	list1.push(1);
	list1.push(2);
	list1.push(3);
	list1.push(4);
	list1.push(5);
	list1.print();
	cout << "Size of stack after pushing is: " << list1.Size() << endl << endl;
	
	cout << "After Popping two elements from stack:" << endl;
	list1.pop();
	list1.pop();
	list1.print();
	cout << "Size of stack after popping is: " << list1.Size() << endl << endl;
	
	cout << "-------------------TASK 2-------------------" << endl;
	stack<int> list2;
	cout << "Input stack:" << endl;
	list2.push(1);
	list2.push(2);
	list2.push(3);
	list2.push(4);
	list2.push(5);
	list2.print();
	cout << "Output stack after deleting last inserted element of stack:" << endl;
	list2.pop();
	list2.print();
	cout << endl;
	
	stack<int> list3;
	cout << "Input stack:" << endl;
	list3.push(1);
	list3.push(2);
	list3.push(3);
	list3.push(4);
	list3.push(5);
	list3.push(6);
	list3.print();
	cout << "Output stack after deleting last inserted element of stack:" << endl;
	list3.pop();
	list3.print();
	cout << endl;
	
	cout << "-------------------TASK 3-------------------" << endl;
	string expression = "([A+B]+C)+{T}";
	bool match= matchParentheses(expression);
	if(match==true)
	{
		cout << expression << " is balanced" << endl;
	}
	else
	{
		cout << expression << " is not balanced" << endl;
	}
	cout << endl;
	
	expression = "(A+B))";
	match = matchParentheses(expression);
	if (match == true)
	{
		cout << expression << " is balanced" << endl;
	}
	else
	{
		cout << expression << " is not balanced" << endl;
	}
	cout << endl;

	cout << "-------------------TASK 4-------------------" << endl;
	expression = "A*B+C/D";
	cout << "Expression before conversion to prefix is: " << expression << endl;
	infixToPrefix(expression);
	cout << "Expression after conversion to prefix is: " << expression << endl << endl;
	
	expression = "(A-B/C)*(A/K-L)";
	cout << "Expression before conversion to prefix is: " << expression << endl;
	infixToPrefix(expression);
	cout << "Expression after conversion to prefix is: " << expression << endl << endl;
	
	cout << "-------------------TASK 5-------------------" << endl;
	string p = "sasas";
	bool palindrome = isPalindrome(p);
	if(palindrome==true)
	{
		cout << p << " is a palindrome" << endl;
	}
	else
	{
		cout << p << " is not a palindrome" << endl;
	}
	cout << endl;
	
	p = "deer";
	palindrome = isPalindrome(p);
	if (palindrome == true)
	{
		cout << p << " is a palindrome" << endl;
	}
	else
	{
		cout << p << " is not a palindrome" << endl;
	}
	
	cout << endl;
	system("pause");
	return 0;
}