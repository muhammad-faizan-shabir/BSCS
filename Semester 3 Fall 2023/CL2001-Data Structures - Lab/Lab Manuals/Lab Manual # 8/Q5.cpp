#include <iostream>
#include<string>
using namespace std;

void permute(string& a, int l, int r) // function takes a string, starting index and ending index
{
    if (l == r) // Base case
    {
        cout << a << endl;
    } 
    else  // general case
    {
        for (int i = l; i <= r; i++) // Permutations made 
        {
            swap(a[l], a[i]); // Swapping done
            permute(a, l + 1, r); // Recursion called 
            swap(a[l], a[i]); // backtrack 
		}
	}
}

//arr[] ---> Input Array
//data[] ---> Temporary array to store current combination
//start & end ---> Starting and Ending indexes in arr[]
//index ---> Current index in data[]
//r ---> Size of a combination to be printed 
void combinations(int arr[], int data[], int start, int end, int index, int r)
{
    if (index == r) // Base Case: Current combination is ready to be printed, print it
    {
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        return;
    }

    // replace index with all possible 
    // elements. The condition "end-i+1 >= r-index"
    // makes sure that including one element 
    // at index will make a combination with 
    // remaining elements at remaining positions 
    for (int i = start; i <= end && end - i + 1 >= r - index; i++) 
    {
        data[index] = arr[i];
        combinations(arr, data, i + 1,end, index + 1, r); // general case
    }
}

void printCombination(int arr[],int data[], int n,int r)
{ 
    combinations(arr, data, 0, n - 1, 0, r);
}

int main()
{
    cout << "The permutations of ABC are:" << endl;
	string str = "ABC";
	int n = str.size(); 
	permute(str, 0, n - 1);

    cout<<endl << "The combinations of 1234 for r=2 are:" << endl;
    int arr[] = { 1, 2, 3, 4 };
    int const r = 2;
    int data[r];
    int N = sizeof(arr) / sizeof(arr[0]);
    printCombination(arr,data, N, r);
    
    cout << endl;
    system("pause");
	return 0;
}
