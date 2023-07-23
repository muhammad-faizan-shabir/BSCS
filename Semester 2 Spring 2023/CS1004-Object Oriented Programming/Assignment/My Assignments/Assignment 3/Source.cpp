#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class bigint
{
private:
	int v[5];
public:
	bigint() // default constructor
	{
		v[0] = 0;
		v[1] = 0;
		v[2] = 0;
		v[3] = 0;
		v[4] = 0;
	}

	bigint(int x0)
	{
		v[0] = x0;
		v[1] = 0;
		v[2] = 0;
		v[3] = 0;
		v[4] = 0;
	}

	bigint(int x0, int x1)
	{
		v[0] = x0;
		v[1] = x1;
		v[2] = 0;
		v[3] = 0;
		v[4] = 0;
	}

	bigint(int x0, int x1, int x2)
	{
		v[0] = x0;
		v[1] = x1;
		v[2] = x2;
		v[3] = 0;
		v[4] = 0;
	}

	bigint(int x0, int x1, int x2, int x3)
	{
		v[0] = x0;
		v[1] = x1;
		v[2] = x2;
		v[3] = x3;
		v[4] = 0;
	}

	bigint(int x0, int x1, int x2, int x3, int x4)
	{
		v[0] = x0;
		v[1] = x1;
		v[2] = x2;
		v[3] = x3;
		v[4] = x4;
	}

	bigint(const bigint &obj) // copy constructor
	{
		v[0] = obj.v[0];
		v[1] = obj.v[1];
		v[2] = obj.v[2];
		v[3] = obj.v[3];
		v[4] = obj.v[4];
	}

	int power(int i) // function to be used by overloaded >> operator 
	{
		int num = 1;
		for (int x = 0; x < i; x++)
		{
			num = num * 10;
		}
		return num;
	}

	friend istream &operator>>(istream &strm, bigint &obj) // overloaded >> operator 
	{
		string num; // string used to input the number
		getline(strm, num);

		int length = 0; // to count the number of digits in the number
		for (int i = 0; num[i] != '\0'; i++)
		{
			length++;
		}
		
		int index = length - 1; // index for the string
		
		for (int i = 0; (i < 9) && (index >= 0);) // storing 9 digits at 0th index of array
		{
			obj.v[0] = (obj.v[0]) + ((num[index] - 48)*(obj.power(i))); // converting number from char to int and attaching it to the start of the number at that index
			index--; // moving to previous index of the string
			i++;
		}

		for (int i = 0; (i < 9) && (index >= 0);) // storing 9 digits at 1st index of array
		{
			obj.v[1] = (obj.v[1]) + ((num[index] - 48)*(obj.power(i))); // converting number from char to int and attaching it to the start of the number at that index
			index--; // moving to previous index of the string
			i++;
		}

		for (int i = 0; (i < 9) && (index >= 0);) // storing 9 digits at 2nd index of array
		{
			obj.v[2] = (obj.v[2]) + ((num[index] - 48)*(obj.power(i))); // converting number from char to int and attaching it to the start of the number at that index
			index--; // moving to previous index of the string
			i++;
		}

		for (int i = 0; (i < 9) && (index >= 0);) // storing 9 digits at 3rd index of array
		{ 
			obj.v[3] = (obj.v[3]) + ((num[index] - 48)*(obj.power(i))); // converting number from char to int and attaching it to the start of the number at that index
			index--; // moving to previous index of the string
			i++;
		}

		for (int i = 0; (i < 9) && (index >= 0);) // storing 9 digits at 4th index of array
		{
			obj.v[4] = (obj.v[4]) + ((num[index] - 48)*(obj.power(i))); // converting number from char to int and attaching it to the start of the number at that index
			index--; // moving to previous index of the string
			i++;
		}
		
		return strm;
	}
	
	friend ostream &operator<<(ostream &strm, bigint &obj)  // overloaded << operator 
	{
		if ((obj.v[4] == 0) && (obj.v[3] == 0) && (obj.v[2] == 0) && (obj.v[1] == 0))
		{
			strm << obj.v[0];
		}
		else if ((obj.v[4] == 0) && (obj.v[3] == 0) && (obj.v[2] == 0))
		{
			strm << obj.v[1];
			cout << setfill('0') << setw(9) << obj.v[0];
		}
		else if ((obj.v[4] == 0) && (obj.v[3] == 0))
		{
			cout << obj.v[2];
			cout << setfill('0') << setw(9) << obj.v[1];
			cout << setfill('0') << setw(9) << obj.v[0];
		}
		else if ((obj.v[4] == 0))
		{
			cout << obj.v[3];
			cout << setfill('0') << setw(9) << obj.v[2];
			cout << setfill('0') << setw(9) << obj.v[1];
			cout << setfill('0') << setw(9) << obj.v[0];
		}
		else
		{
			cout << obj.v[4];
			cout << setfill('0') << setw(9) << obj.v[3];
			cout << setfill('0') << setw(9) << obj.v[2];
			cout << setfill('0') << setw(9) << obj.v[1];
			cout << setfill('0') << setw(9) << obj.v[0] ;
		}
		
		return strm;
	}

	bool operator<(const bigint &obj) // overloaded < operator
	{
		if (v[4] < obj.v[4])
		{
			return true;
		}
		else
		{
			if (v[4] > obj.v[4])
			{
				return false;
			}
			else
			{
				if (v[3] < obj.v[3])
				{
					return true;
				}
				else
				{
					if (v[3] > obj.v[3])
					{
						return false;
					}
					else
					{
						if (v[2] < obj.v[2])
						{
							return true;
						}
						else
						{
							if (v[2] > obj.v[2])
							{
								return false;
							}
							else
							{
								if (v[1] < obj.v[1])
								{
									return true;
								}
								else
								{
									if (v[1] > obj.v[1])
									{
										return false;
									}
									else
									{
										if (v[0] < obj.v[0])
										{
											return true;
										}
										else
										{
											return false;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	bool operator>(const bigint &obj) // overloaded > operator
	{
		if (v[4] > obj.v[4])
		{
			return true;
		}
		else
		{
			if (v[4] < obj.v[4])
			{
				return false;
			}
			else
			{
				if (v[3] > obj.v[3])
				{
					return true;
				}
				else
				{
					if (v[3] < obj.v[3])
					{
						return false;
					}
					else
					{
						if (v[2] > obj.v[2])
						{
							return true;
						}
						else
						{
							if (v[2] < obj.v[2])
							{
								return false;
							}
							else
							{
								if (v[1] > obj.v[1])
								{
									return true;
								}
								else
								{
									if (v[1] < obj.v[1])
									{
										return false;
									}
									else
									{
										if (v[0] > obj.v[0])
										{
											return true;
										}
										else
										{
											return false;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	bool operator<=(const bigint &obj) // overloaded <= operator
	{
		if (this->operator>(obj))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator>=(const bigint&obj) // overloaded >= operator
	{
		if (this->operator<(obj))
		{
			return false;
		}
		else
		{
			return  true;
		}
	}

	bool operator==(const bigint &obj) // overloaded == operator
	{
		if ((this->operator<(obj) == false) && (this->operator>(obj) == false))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const bigint&obj) // overloaded != operator
	{
		if (this->operator==(obj))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bigint operator+(const bigint &obj) // overloaded + operator for objects with objects
	{
		bigint temp;
		int tempsum = 0;

		tempsum = v[0] + obj.v[0] + temp.v[0]; // calculate sum for current index
		if (tempsum > (999999999)) // if 9 digits are exceeded
		{
			temp.v[1] = tempsum / 1000000000; // move the 10th digit to next index of temp object
			temp.v[0] = tempsum % 1000000000; // put the remaining 9 digits at the current index of temp object
		}
		else
		{
			temp.v[0] = tempsum;
		}

		tempsum = v[1] + obj.v[1] + temp.v[1]; // calculate sum for current index
		if (tempsum > (999999999)) // if 9 digits are exceeded
		{
			temp.v[2] = tempsum / 1000000000; // move the 10th digit to next index of temp object
			temp.v[1] = tempsum % 1000000000; // put the remaining 9 digits at the current index of temp object
		}
		else
		{
			temp.v[1] = tempsum;
		}

		tempsum = v[2] + obj.v[2] + temp.v[2]; // calculate sum for current index
		if (tempsum >(999999999)) // if 9 digits are exceeded
		{
			temp.v[3] = tempsum / 1000000000; // move the 10th digit to next index of temp object
			temp.v[2] = tempsum % 1000000000; // put the remaining 9 digits at the current index of temp object
		}
		else
		{
			temp.v[2] = tempsum;
		}

		tempsum = v[3] + obj.v[3] + temp.v[3]; // calculate sum for current index
		if (tempsum >(999999999)) // if 9 digits are exceeded
		{
			temp.v[4] = tempsum / 1000000000; // move the 10th digit to next index of temp object
			temp.v[3] = tempsum % 1000000000; // put the remaining 9 digits at the current index of temp object
		}
		else
		{
			temp.v[3] = tempsum;
		}

		tempsum = v[4] + obj.v[4] + temp.v[4]; // calculate sum for current index
		temp.v[4] = tempsum;
		
		return temp;
	}

	bigint operator+(int num) // overloaded + operator for addition of objects with numbers
	{
		bigint temp(num);

		return this->operator+(temp);
	}
	
	bigint operator-(const bigint &obj) // overloaded - operator for subtraction of objects from objects
	{
		if (this->operator>(obj)) // to ensure that larger number is subtracted from smaller
		{
			bigint temp;
			temp.v[0] = v[0];
			temp.v[1] = v[1];
			temp.v[2] = v[2];
			temp.v[3] = v[3];
			temp.v[4] = v[4];

			// subtraction procedure for 0th index
			if (temp.v[0] >= obj.v[0])
			{
				temp.v[0] = temp.v[0] - obj.v[0];
			}
			else
			{
				if (temp.v[1] > 0)
				{
					temp.v[1] = temp.v[1] - 1;
					temp.v[0] = 1000000000 + temp.v[0];
					temp.v[0] = temp.v[0] - obj.v[0];
				}
				else if (temp.v[2] > 0)
				{
					temp.v[2] = temp.v[2] - 1;
					temp.v[1] = 1000000000 + temp.v[1];
					temp.v[1] = temp.v[1] - 1;
					temp.v[0] = 1000000000 + temp.v[0];
					temp.v[0] = temp.v[0] - obj.v[0];
				}
				else if (temp.v[3] > 0)
				{
					temp.v[3] = temp.v[3] - 1;
					temp.v[2] = 1000000000 + temp.v[2];
					temp.v[2] = temp.v[2] - 1;
					temp.v[1] = 1000000000 + temp.v[1];
					temp.v[1] = temp.v[1] - 1;
					temp.v[0] = 1000000000 + temp.v[0];
					temp.v[0] = temp.v[0] - obj.v[0];
				}
				else
				{
					temp.v[4] = temp.v[4] - 1;
					temp.v[3] = 1000000000 + temp.v[3];
					temp.v[3] = temp.v[3] - 1;
					temp.v[2] = 1000000000 + temp.v[2];
					temp.v[2] = temp.v[2] - 1;
					temp.v[1] = 1000000000 + temp.v[1];
					temp.v[1] = temp.v[1] - 1;
					temp.v[0] = 1000000000 + temp.v[0];
					temp.v[0] = temp.v[0] - obj.v[0];
				}
			}

			// subtraction procedure for 1st index
			if (temp.v[1] >= obj.v[1])
			{
				temp.v[1] = temp.v[1] - obj.v[1];
			}
			else
			{
				if (temp.v[2] > 0)
				{
					temp.v[2] = temp.v[2] - 1;
					temp.v[1] = 1000000000 + temp.v[1];
					temp.v[1] = temp.v[1] - obj.v[1];
				}
				else if (temp.v[3] > 0)
				{
					temp.v[3] = temp.v[3] - 1;
					temp.v[2] = 1000000000 + temp.v[2];
					temp.v[2] = temp.v[2] - 1;
					temp.v[1] = 1000000000 + temp.v[1];
					temp.v[1] = temp.v[1] - obj.v[1];
				}
				else
				{
					temp.v[4] = temp.v[4] - 1;
					temp.v[3] = 1000000000 + temp.v[3];
					temp.v[3] = temp.v[3] - 1;
					temp.v[2] = 1000000000 + temp.v[2];
					temp.v[2] = temp.v[2] - 1;
					temp.v[1] = 1000000000 + temp.v[1];
					temp.v[1] = temp.v[1] - obj.v[1];
				}
			}

			// subtraction procedure for 2nd index
			if (temp.v[2] >= obj.v[2])
			{
				temp.v[2] = temp.v[2] - obj.v[2];
			}
			else
			{
				if (temp.v[3] > 0)
				{
					temp.v[3] = temp.v[3] - 1;
					temp.v[2] = 1000000000 + temp.v[2];
					temp.v[2] = temp.v[2] - obj.v[2];
				}
				else
				{
					temp.v[4] = temp.v[4] - 1;
					temp.v[3] = 1000000000 + temp.v[3];
					temp.v[3] = temp.v[3] - 1;
					temp.v[2] = 1000000000 + temp.v[2];
					temp.v[2] = temp.v[2] - obj.v[2];
				}
			}

			// subtraction procedure for 3rd index
			if (temp.v[3] >= obj.v[3])
			{
				temp.v[3] = temp.v[3] - obj.v[3];
			}
			else
			{
				temp.v[4] = temp.v[4] - 1;
				temp.v[3] = 1000000000 + temp.v[3];
				temp.v[3] = temp.v[3] - obj.v[3];
			}

			// subtraction procedure for 4th index
			temp.v[4] = temp.v[4] - obj.v[4];
			
			return temp;
		}
		else // to ensure that larger number is subtracted from smaller
		{
			bigint temp;
			temp.v[0] = obj.v[0];
			temp.v[1] = obj.v[1];
			temp.v[2] = obj.v[2];
			temp.v[3] = obj.v[3];
			temp.v[4] = obj.v[4];

			// subtraction procedure for 0th index
			if (temp.v[0] >= v[0])
			{
				temp.v[0] = temp.v[0] - v[0];
			}
			else
			{
				if (temp.v[1] > 0)
				{
					temp.v[1] = temp.v[1] - 1;
					temp.v[0] = 1000000000 + temp.v[0];
					temp.v[0] = temp.v[0] - v[0];
				}
				else if (temp.v[2] > 0)
				{
					temp.v[2] = temp.v[2] - 1;
					temp.v[1] = 1000000000 + temp.v[1];
					temp.v[1] = temp.v[1] - 1;
					temp.v[0] = 1000000000 + temp.v[0];
					temp.v[0] = temp.v[0] - v[0];
				}
				else if (temp.v[3] > 0)
				{
					temp.v[3] = temp.v[3] - 1;
					temp.v[2] = 1000000000 + temp.v[2];
					temp.v[2] = temp.v[2] - 1;
					temp.v[1] = 1000000000 + temp.v[1];
					temp.v[1] = temp.v[1] - 1;
					temp.v[0] = 1000000000 + temp.v[0];
					temp.v[0] = temp.v[0] - v[0];
				}
				else
				{
					temp.v[4] = temp.v[4] - 1;
					temp.v[3] = 1000000000 + temp.v[3];
					temp.v[3] = temp.v[3] - 1;
					temp.v[2] = 1000000000 + temp.v[2];
					temp.v[2] = temp.v[2] - 1;
					temp.v[1] = 1000000000 + temp.v[1];
					temp.v[1] = temp.v[1] - 1;
					temp.v[0] = 1000000000 + temp.v[0];
					temp.v[0] = temp.v[0] - v[0];
				}
			}

			// subtraction procedure for 1st index
			if (temp.v[1] >= v[1])
			{
				temp.v[1] = temp.v[1] - v[1];
			}
			else
			{
				if (temp.v[2] > 0)
				{
					temp.v[2] = temp.v[2] - 1;
					temp.v[1] = 1000000000 + temp.v[1];
					temp.v[1] = temp.v[1] - v[1];
				}
				else if (temp.v[3] > 0)
				{
					temp.v[3] = temp.v[3] - 1;
					temp.v[2] = 1000000000 + temp.v[2];
					temp.v[2] = temp.v[2] - 1;
					temp.v[1] = 1000000000 + temp.v[1];
					temp.v[1] = temp.v[1] - v[1];
				}
				else
				{
					temp.v[4] = temp.v[4] - 1;
					temp.v[3] = 1000000000 + temp.v[3];
					temp.v[3] = temp.v[3] - 1;
					temp.v[2] = 1000000000 + temp.v[2];
					temp.v[2] = temp.v[2] - 1;
					temp.v[1] = 1000000000 + temp.v[1];
					temp.v[1] = temp.v[1] - v[1];
				}
			}

			// subtraction procedure for 2nd index
			if (temp.v[2] >= v[2])
			{
				temp.v[2] = temp.v[2] - v[2];
			}
			else
			{
				if (temp.v[3] > 0)
				{
					temp.v[3] = temp.v[3] - 1;
					temp.v[2] = 1000000000 + temp.v[2];
					temp.v[2] = temp.v[2] - v[2];
				}
				else
				{
					temp.v[4] = temp.v[4] - 1;
					temp.v[3] = 1000000000 + temp.v[3];
					temp.v[3] = temp.v[3] - 1;
					temp.v[2] = 1000000000 + temp.v[2];
					temp.v[2] = temp.v[2] - v[2];
				}
			}

			// subtraction procedure for 3rd index
			if (temp.v[3] >= v[3])
			{
				temp.v[3] = temp.v[3] - v[3];
			}
			else
			{
				temp.v[4] = temp.v[4] - 1;
				temp.v[3] = 1000000000 + temp.v[3];
				temp.v[3] = temp.v[3] - v[3];
			}

			// subtraction procedure for 4th index
			temp.v[4] = temp.v[4] - v[4];
			
			return temp;
		}
	}

	bigint operator-(int num) // overloaded - operator for subtraction of numbers from objects
	{
		bigint temp(num);

		return this->operator-(temp);
	}
};

int main()
{
	bigint x;
	bigint y;

	if (x == y) cout << x << " is equal to " << y << "." << endl;
	if (x != y) cout << x << " is not equal to " << y << "." << endl;
	if (x > y) cout << x << " is larger than " << y << "." << endl;
	if (x >= y) cout << x << " is larger than or equal to " << y << "." << endl;
	if (x < y) cout << x << " is smaller than " << y << "." << endl;
	if (x <= y) cout << x << " is smaller than or equal to " << y << "." << endl;

	bigint x1(123456789);
	bigint y1(111111111);

	if (x1 == y1) cout << x1 << " is equal to " << y1 << "." << endl;
	if (x1 != y1) cout << x1 << " is not equal to " << y1 << "." << endl;
	if (x1 > y1) cout << x1 << " is larger than " << y1 << "." << endl;
	if (x1 >= y1) cout << x1 << " is larger than or equal to " << y1 << "." << endl;
	if (x1 < y1) cout << x1 << " is smaller than " << y1 << "." << endl;
	if (x1 <= y1) cout << x1 << " is smaller than or equal to " << y1 << "." << endl;

	bigint x2(123456789, 111, 111, 111, 111);
	bigint y2(111111111, 111, 111, 111, 111);

	if (x2 == y2) cout << x2 << " is equal to " << y2 << "." << endl;
	if (x2 != y2) cout << x2 << " is not equal to " << y2 << "." << endl;
	if (x2 > y2) cout << x2 << " is larger than " << y2 << "." << endl;
	if (x2 >= y2) cout << x2 << " is larger than or equal to " << y2 << "." << endl;
	if (x2 < y2) cout << x2 << " is smaller than " << y2 << "." << endl;
	if (x2 <= y2) cout << x2 << " is smaller than or equal to " << y2 << "." << endl;

	bigint x3(123456789, 12, 12);
	bigint y3(111111111, 13, 12);

	if (x3 == y3) cout << x3 << " is equal to " << y3 << "." << endl;
	if (x3 != y3) cout << x3 << " is not equal to " << y3 << "." << endl;
	if (x3 > y3) cout << x3 << " is larger than " << y3 << "." << endl;
	if (x3 >= y3) cout << x3 << " is larger than or equal to " << y3 << "." << endl;
	if (x3 < y3) cout << x3 << " is smaller than " << y3 << "." << endl;
	if (x3 <= y3) cout << x3 << " is smaller than or equal to " << y3 << "." << endl;

	bigint x4(999999999, 999999999, 999999999, 20);

	cout << x4 << "+1 = " << x4 + 1 << endl;

	bigint y4(000000000, 000000000, 000000000, 000000000, 0000000001);

	cout << y4 << "-1 = " << y4-1 << endl;

	cout << x1 + x2 + x3 + x4 - y3 + 1 << endl;

	for (int i = 0; i<3; i++) 
	{
		bigint x5, y5;
		cout << "Enter x: ";
		cin >> x5;
		cout << "Enter y: ";
		cin >> y5;
		
		cout << "x = " << x5 << endl;
		cout << "y = " << y5 << endl;

		cout << "x+y=" << x5 + y5 << endl;
		cout << "x-y=" << x5 - y5 << endl;
	}

	cout << endl;
	system("pause");
}