#include <iostream>
using namespace std;
void calculateMode(int array[], int size)
{

    int counter = 1;
    int max = 0;
    int mode = array[0];
    for (int pass = 0; pass < size - 1; pass++)
    {
        if (array[pass] == array[pass + 1])
        {
            counter++;
            if (counter > max)
            {
                max = counter;
                mode = array[pass];
            }
        }
        else
            counter = 1; // reset counter.
    }
    cout << "The mode is: " << mode << endl;
}

int main()
{
    int array[100];
    int size;

    cout << "Enter size of array: ";
    cin >> size;

    cout << "Enter " << size << " numbers: " << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    calculateMode(array, size);
}