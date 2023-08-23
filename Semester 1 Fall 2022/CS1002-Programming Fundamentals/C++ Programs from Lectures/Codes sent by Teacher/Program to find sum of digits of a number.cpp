//Program to find sum of digits of a numbe

#include <iostream>
using namespace std;

int main()
{
    int num, sum=0;
    cout<<"Enter any number to find sum of its digit: ";
    cin>> num;
    /* Repeat till num becomes 0 */
    for(;num>0;num=num/10)
    {
        sum += num % 10;
    }
    cout<<"Sum of digits = " << sum;

    return 0;
}