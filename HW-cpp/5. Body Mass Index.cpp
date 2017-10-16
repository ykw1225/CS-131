// Kit Wong
// Programming Challenge
// 5. Body Mass Index
// 7-12-2014

#include<iostream>
using namespace std;

int main()
{
	float w, h, BMI;

	cout<<"Enter weight (in pounds): ";
	cin>>w;
	cout<<"Enter height (in inches): ";
	cin>>h;

	BMI=w*703/(pow(h,2));

	BMI>18.5 ? cout<<"Underweight!": BMI>25 ? cout<<"Overweight!":cout<<"Optimal weight!";

	system("pause");
	return 0;
}