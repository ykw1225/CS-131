// Kit Wong
// Programming Challenge
// 12. Celsius to Fahrenheit Table
// 7-20-2014

#include<iostream>
using namespace std;

int main()
{
	float c, f;
	
	cout<< "Celsius\tFahrenheit\n"
		<< "-------------------\n";

	for (c=0;c<21;c++)
	{
		f = 1.8*c+32;
		cout<< c << "\t" << f << "\n";
	}

	
	cout<<"\n";
	system("pause");
	return 0;
}