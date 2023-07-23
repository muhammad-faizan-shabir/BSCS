#include <iostream>
using namespace std;

int
main()
{
    int A;
    int B;
    int C;
    
    cout << "Enter first integer angle" << endl;
    cin >> A;
    
    cout << "Enter second integer angle" << endl;
    cin >> B;
    
    cout << "Enter third integer angle" << endl;
    cin >> C;
    
    if ((A == 0) || (B == 0) || (C == 0))
    {
        cout << "ERROR! ANY OF THE ANGLES SHOULD NOT BE ZERO" << endl;
    }
    else if (A + B + C == 180)
    {
        cout << "VALID TRIANGLE" << endl;
    }
    else
    {
        cout << "INVALID TRIANGLE" << endl;
    }
   
}
