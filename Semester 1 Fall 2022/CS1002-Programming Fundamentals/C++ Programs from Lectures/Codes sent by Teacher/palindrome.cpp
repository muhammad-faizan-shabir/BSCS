//Program to check palindrome number
#include <iostream>
using namespace std;

int main()
{
    int n, num, rev = 0;

    /* Input a number from user */
   cout<<"Enter any number to check palindrome: ";
   cin>> n;

   
    num = n; 

    
    while(n != 0)
    {
        rev = (rev * 10) + (n % 10);
        n  /= 10;
    }

    /* Check if reverse is equal to 'num' or not */
    if(rev == num)
    {
        cout<<" is palindrome."<< num;
    }
    else
    {
        cout<<" is not palindrome."<< num;
    }

    return 0;
}