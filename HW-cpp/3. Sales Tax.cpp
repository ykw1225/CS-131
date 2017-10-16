// This is the ch.2 textbook homework
// programming challenges part
// Date: June 26 2014
// 3. Sales Tax

#include <iostream>
using namespace std;

int main()
{
	int purchase;
	float statetax, countytax;
	double totaltax;
	purchase = 5;
	statetax = 4E-2;
	countytax = 2E-2;
	statetax = purchase*statetax; 
	countytax = purchase*countytax; 
	totaltax = statetax+countytax;
	cout << totaltax << endl;
	system ("pause");
	return 0;
}