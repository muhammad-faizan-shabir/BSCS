#include<iostream> 
using namespace std;

template<class myType> 
class MACFilter 
{ 
	myType* data; 
	int size; 
public: 
	MACFilter(myType* arr, int s, int* ind)
	{ 
		size = s; 
		data = new myType[size]; 
		for (int i = 0; i<size; i++) 
		{ 
			data[ind[i]] = arr[i]; 
		} 
	} 
	int getSize()
	{ 
		return size; 
	} 
	myType getData(int ind)
	{ 
		return data[ind]; 
	} 
}; 

template<class myType1, class myType2> 
void getMACAddr(MACFilter<myType1>& t1, MACFilter<myType2>& t2) 
{ 
	int k = t2.getSize();
	for (int i = 0; i<t1.getSize(); i++) 
	{ 
		cout << t1.getData(--k) << t2.getData(i) << ":";
	} 
} 

int main() 
{
	const int s = 5; 
	int ind[s] = { 3, 0, 1, 4, 2 }; 
	char c1[s] = { 'A', 'B', 'C', 'D', 'E' }; 
	MACFilter<char> obj1(c1, s, ind);
	
	int val[s] = { 9, 6, 8, 5, 7 }; 
	MACFilter<int> obj2(val, s, ind); 
	getMACAddr(obj2, obj1); 
	cout << endl;
	system("pause");
	return 0;
}