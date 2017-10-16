// Kit Wong
// Programming Challenge
// 10. Celsius to Fahrenheit
// 7-2-2014

#include<iostream>
using namespace std;

int main()
{
	float c, f;

	cout << "Enter the temperature (celsius): ";
	cin >> c;

	f = 1.8*c+32;

	cout << "The temperature " << c << " degree celsius is " << f << " degree fahrenheit."
			<< endl;

	system("pause");
	return 0;
}