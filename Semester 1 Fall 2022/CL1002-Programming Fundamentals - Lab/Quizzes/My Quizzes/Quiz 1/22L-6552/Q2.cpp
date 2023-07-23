#include <iostream> 
using namespace std;
int main()
{
	int date;
	int MonthNumber;
	
	cout<<"Enter the day number of month of your birthday: "<<endl;
	cin>>date;
	
	cout<<"Enter the month number for example 1,2,3: "<<endl;
	cin>>MonthNumber;
	
	while ((MonthNumber<1)||(MonthNumber>12))
	{
		cout<<"Please enter month number between 1 and 12:"<<endl;
		cin>>MonthNumber;
		
		
	}
	
	if((MonthNumber==3)&&(date>=21 && date<=31))
	{
		cout<<"Horoscope is Aries"<<endl;
	}
	
	if((MonthNumber==4)&&(date>=1 && date<=19))
	{
		cout<<"Horoscope is Aries"<<endl;
	}
	
	if((MonthNumber==4)&&(date>=20 && date<=30))
	{
		cout<<"Horoscope is Taurus"<<endl;
	}
	if((MonthNumber==5)&&(date>=1 && date<=20))
	{
		cout<<"Horoscope is Taurus"<<endl;
	}
	if((MonthNumber==5)&&(date>=21 && date<=31))
	{
		cout<<"Horoscope is Gemini"<<endl;		
	}
	if((MonthNumber==6)&&(date>=11 && date<=21))
	{
		cout<<"Horoscope is Gemini"<<endl;
	}
	if((MonthNumber==6)&&(date>=22 && date<=30))
	{
		cout<<"Horoscope is Cancer"<<endl;
	}
	if((MonthNumber==7)&&(date>=1 && date<=22))
	{
		cout<<"Horoscope is Cancer"<<endl;
	}
	if((MonthNumber==7)&&(date>=23 && date<=31))
	{
		cout<<"Horoscope is Leo"<<endl;
	}
	if((MonthNumber==8)&&(date>=1 && date<=22))
	{
		cout<<"Horoscope is Leo"<<endl;
	}
	if((MonthNumber==8)&&(date>=23 && date<=31))
	{
		cout<<"Horoscope is Virgo"<<endl;
	}
	if((MonthNumber==9)&&(date>=1 && date<=22))
	{
		cout<<"Horoscope is Virgo"<<endl;
	}
	if((MonthNumber==9)&&(date>=23 && date<=30))
	{
		cout<<"Horoscope is Libra"<<endl;
	}
	if((MonthNumber==10)&&(date>=1 && date<=22))
	{
		cout<<"Horoscope is Libra"<<endl;
	}
	if((MonthNumber==10)&&(date>=23 && date<=31))
	{
		cout<<"Horoscope is Scorpio"<<endl;
	}
	if((MonthNumber==11)&&(date>=1 && date<=21))
	{
		cout<<"Horoscope is scorpio"<<endl;
	}
	if((MonthNumber==11)&&(date>=22 && date<=30))
	{
		cout<<"Horoscope is Sagittarius"<<endl;
	}
	if((MonthNumber==12)&&(date>=1 && date<=21))
	{
		cout<<"Horoscope is Sagittarius"<<endl;
	}
	if((MonthNumber==12)&&(date>=22 && date<=31))
	{
		cout<<"Horoscope is Capricon"<<endl;
	}
	if((MonthNumber==1)&&(date>=1 && date<=19))
	{
		cout<<"Horoscope is Capricon"<<endl;
	}
	if((MonthNumber==1)&&(date>=20 && date<=31))
	{
		cout<<"Horoscope is Aquarius"<<endl;
	}
	if((MonthNumber==2)&&(date>=1 && date<=18))
	{
		cout<<"Horoscope is Aquarius"<<endl;
	}
	if((MonthNumber==2)&&(date>=19 && date<=28))
	{
		cout<<"Horoscope is Pisces"<<endl;
	}
	if((MonthNumber==3)&&(date>=1 && date<=20))
	{
		cout<<"Horoscope is Pisces "<<endl;
	}
}
