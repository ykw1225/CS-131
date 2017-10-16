// Kit Wong
// Programming Challenge
// 6. Distance
// 7-20-2014

#include<iostream>
using namespace std;

int main()
{
	double s, t;
	cout<<"Enter the speed(miles per hour) of your vehicle: ";
	cin>>s;
	while(s<0)
	{
		cout<<"Invaild number, please enter again: ";
		cin>>s;
	}
	cout<<"Enter the time(in hours) you travled: ";
	cin>>t;
	while(t<1)
	{
		cout<<"Invaild number, please enter again: ";
		cin>>t;
	}
	cout<<"\nHour     Distance Traveled\n________________________\n";
	for(int count=1;count<=t;count++)
	{
		cout<<count<<"     "<<(count*s)<<endl;
	}


	system("pause");
	return 0;
}