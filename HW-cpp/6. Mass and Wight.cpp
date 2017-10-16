// Kit Wong
// Programming Challenge
// 6. Mass and Wight
// 7-12-2014

#include<iostream>
using namespace std;

int main()
{
	float m, w;

	cout<<"Enter mass (in kilograms): ";
	cin>>m;

	w=9.8*m;

	if (w>1000) cout<<"Too heavy!\n";
	else if (w<10) cout<<"Too light!\n";

	system("pause");
	return 0;
}