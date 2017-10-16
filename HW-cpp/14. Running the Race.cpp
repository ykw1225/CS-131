// Kit Wong
// Programming Challenge
// 14. Running the Race
// 7-12-2014

#include<iostream>
using namespace std;

int main()
{
	char a[20], b[20], c[20];
	float t1, t2, t3;

	cout<<"First runner's name: ";
	cin>>a;
	cout<<"First runner's time: ";
	cin>>t1;
	while (t1<=0)
	{
		cout<<"Wrong input, enter again; ";
		cin>>t1;
	}


	cout<<"Second runner's name: ";
	cin>>b;
	cout<<"Second runner's time: ";
	cin>>t2;
	while (t2<=0)
	{
		cout<<"Wrong input, enter again; ";
		cin>>t2;
	}


	cout<<"Third runner's name: ";
	cin>>c;
	cout<<"Third runner's time: ";
	cin>>t3;
	while (t3<=0)
	{
		cout<<"Wrong input, enter again; ";
		cin>>t3;
	}

	
	if      (t1>t2&&t2>t3) cout<<"First is "<<a<<", second is "<<b<<", third is "<<c<<" .\n";
	else if (t1>t2&&t3>t2) cout<<"First is "<<a<<", second is "<<c<<", third is "<<b<<" .\n";
	else if (t2>t3&&t3>t1) cout<<"First is "<<b<<", second is "<<c<<", third is "<<a<<" .\n";
	else if (t2>t1&&t1>t3) cout<<"First is "<<b<<", second is "<<a<<", third is "<<c<<" .\n";
	else if (t3>t2&&t2>t1) cout<<"First is "<<c<<", second is "<<b<<", third is "<<a<<" .\n";
	else                   cout<<"First is "<<c<<", second is "<<a<<", third is "<<b<<" .\n";

	system("pause");
	return 0;
}