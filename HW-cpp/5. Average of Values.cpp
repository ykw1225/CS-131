// This is the ch.2 textbook homework
// programming challenges part
// Date: June 26 2014
// 5. Average of Values

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a = 28, b = 32, c = 37, d = 24, e = 33, sum, average;
	sum = a + b + c + d + e;
	average = sum / 5;
	cout << average << endl;

	cout << setw(6) << 1234<<endl;
	system ("pause");
	return 0;
}