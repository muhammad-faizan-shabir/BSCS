#include <iostream>
#include <vector>
using namespace std;

void calcSubset(vector<char>& A, vector<vector<char> >& res,vector<char>& subset, int index)
{
	res.push_back(subset); // Add the current subset to the result list
	for (int i = index; i < A.size(); i++) // Generate subsets by recursively including and excluding elements
	{
		subset.push_back(A[i]); // Include the current element in the subset
		calcSubset(A, res, subset, i + 1); // Recursively generate subsets with the current element included
		subset.pop_back(); // Exclude the current element from the subset (backtracking)
	}
}

vector<vector<char> > subsets(vector<char>& A)
{
	vector<char> subset;
	vector<vector<char> > res;
	int index = 0;
	calcSubset(A, res, subset, index);
	return res;
}

int main()
{
	vector<char> array = { 'a', 'b', 'c','d'};
	vector<vector<char> > res = subsets(array);
	
	cout << "The original string is: ";
	for(int i=0;i<array.size();i++)
	{
		cout << array[i];
	}
	cout << endl;
	
	cout << "The subsets are:" << endl;
	for (int i = 0; i < res.size(); i++) // Print the generated subsets
	{
		cout << "{";
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j];
			if(j!= (res[i].size()-1))
			{
				cout << ",";
			}
		}
		if(i==0)
		{
			cout << "Empty Set";
		}
		cout << "}";
		cout << endl;
	}
	
	cout << endl;
	system("pause");
	return 0;
}
