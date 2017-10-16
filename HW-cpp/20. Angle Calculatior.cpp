// Kit Wong
// Programming Challenge
// 20. Angle Calculator
// 7-2-2014

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	float radians, s, c, t;

	cout << "Enter an angle (in radians): ";
	cin >> radians;

	s = sin(radians);
	c = cos(radians);
	t = tan(radians);

	cout <<setprecision(4)<<fixed<<showpoint;
	cout << "Sin("<<radians<<") is "<<s<<endl;
	cout << "Cos("<<radians<<") is "<<c<<endl;
	cout << "Tan("<<radians<<") is "<<t<<endl;

	system("pause");
	return 0;
}