// Kit Wong
// Programming Challenge
// 13. Property Tax
// 7-2-2014

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double actual, assessment, tax;

	cout << "Enter the actual value of your property (dollars): $ ";
	cin >> actual;

	assessment = actual*0.6;
	tax = assessment*0.64/100;

	cout << setprecision(2) << fixed << showpoint;
	cout << "The assessment value of your property is   $ " << assessment << endl;
	cout << "The tax you should pay for your property is   $ " << tax << endl;

	system("pause");
	return 0;
}