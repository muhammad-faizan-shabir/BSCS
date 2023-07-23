#include <iostream>
using namespace std;

int main()
{
    int code;
    cout << "Enter code";
    cin >> code;
    if ((code > 64) && (code < 91))
    {
        cout << code << " Represents an upper case English alphabet" << endl;
    }
    else
        if ((code > 96) && (code < 123)) { cout << code << " Represents a lower case English alphabet" << endl; }
        else
            if ((code > 47) && (code < 58)) { cout << code << " Represents a digit" << endl; }
            else
                if (code < 128) { cout << code << " Represents a special character" << endl; }
                else { cout << code << " DOES NOT REPRESENT AN ASCII CHARACTER " << endl; }
    cout << "THE END";


}
