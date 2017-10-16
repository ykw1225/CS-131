// Kit Wong
// Programming Challenge
// 10. Software Sales
// 7-12-2014

#include<iostream>
using namespace std;

int main()
{
	int p=99;
	float q, d, t;

	cout<<"How many package: ";
	cin>>q;
	while (q<=0)
	{
		cout<<"Wrong input, enter again; ";
	}

	q>99 ? d=1-0.5 : q>49 ? d=1-0.4: q>19?d=1-0.3: q>10 ? d=1-0.2 : d=1;

	t=d*q*p;

	cout<<"Total price: "<<t<<endl;

	system("pause");
	return 0;
}