// Kit Wong
// Programming Challenge
// 23. Patterns Display
// 7-20-2014

#include<iostream>
using namespace std;

int main()
{
	int r,c;

	for(r=0;r<10;r++)
	{
		for(c=0;c<=r;c++)cout<<"+";
		cout<<endl;
	}

	for(r=0;r<10;r++)
	{
		for(c=10;c>r;c--)cout<<"+";
		cout<<endl;
	}

	cout<<"\n";
	system("pause");
	return 0;
}