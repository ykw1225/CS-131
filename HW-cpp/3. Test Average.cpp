// Kit Wong
// Programming Challenge
// 3. Test Average
// 7-2-2014

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	float first, second, third, fourth, fifth, sum, average;

	cout << "Enter the first test scores: ";
	cin >> first;
	cout << "Enter the second test scores: ";
	cin >> second;
	cout << "Enter the third test scores: ";
	cin >> third;
	cout << "Enter the fourth test scores: ";
	cin >> fourth;
	cout << "Enter the fifth test scores: ";
	cin >> fifth;

	sum = first+second+third+fourth+fifth;
	average = sum/5;

	cout << setprecision(1) << fixed << showpoint;
	cout << "Average test scores: " << average << endl;

	system("pause");
	return 0;
}