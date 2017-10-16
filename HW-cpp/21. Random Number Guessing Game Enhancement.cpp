// Kit Wong
// Programming Challenge
// 21. Random Number Guessing Game Enhancement
// 7-20-2014

#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int main()
{
	int x, guess, count;
	unsigned int a = time(0);
	srand(a);
	x = rand()%101;

	cout<<"Welcome to LUCKY GUESS!\n";
	cout<<"Enter the number you guess (0-100): ";
	cin>>guess;
	for (count=0;guess!=x;count++)
	{
		if (guess < x)
		{
			cout<<"\nTry BIGGER!!!\n";
			cin>>guess;
		}
		else
		{
			cout<<"\nTry SMALLER!!!\n";
			cin>>guess;
		}
	}
	cout<<"\nYou are so LUCKY!!!\nYou spend "<<count<<" times on GUESSING!!!\n";
	cout<<"\n";
	system("pause");
	return 0;
}