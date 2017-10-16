// Kit Wong
// Programming Challenge
// 1. Miles per Gallon
// 7-2-2014

#include<iostream>
using namespace std;

int main()
{
	float gallons, miles, mpg;

	cout << "How many gallons of gas your car can hold: ";
	cin >> gallons;
	cout << "How many miles your car can be driven on a full tank: ";
	cin >> miles;

	mpg = miles/gallons;

	cout << "Your car can be driven " << mpg << " miles per gallon." << endl;
	
	system("pause");
	return 0;
}