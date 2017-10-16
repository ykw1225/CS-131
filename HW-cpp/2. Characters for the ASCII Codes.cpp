// Kit Wong
// Programming Challenge
// 2. Characters for the ASCII Codes
// 7-20-2014

#include<iostream>
using namespace std;

int main()
{
	char b=0;
	for (int count=0,col=0;count<127;count++,b++,col++)
	{
		cout<<b;
		for (;col>16;col=0) cout<<endl;
	}

	system("pause");
	return 0;
}