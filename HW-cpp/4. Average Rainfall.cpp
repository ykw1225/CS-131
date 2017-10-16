// Kit Wong
// Programming Challenge
// 4. Average Rainfall
// 7-2-2014

#include<iostream>
using namespace std;

int main()
{
	char a[3], b[3], c[3];
	float aa, bb, cc, sum, average;

	cout << "Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "Enter the first month : " ;
	cin >> a;
	cout << "Enter the amount of rain is fell in " << a << " (in inches): ";
	cin >> aa;
	cout << "Enter the second month : ";
	cin >> b;
	cout << "Enter the amount of rain is fell in " << b << " (in inches): ";
	cin >> bb;
	cout << "Enter the third month : ";
	cin >> c;
	cout << "Enter the amount of rain is fell in " << c << " (in inches): ";
	cin >> cc;


	sum = aa+bb+cc;
	average = sum/3;

	cout << "The average rainfall for " << a << ", " << b << ", and " << c << " is "
		<< average << " inches." << endl;

	system("pause");
	return 0;
}