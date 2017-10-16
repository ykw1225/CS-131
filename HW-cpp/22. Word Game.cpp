// Kit Wong
// Programming Challenge
// 22. Word Game
// 7-2-2014

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string name, age, city, college, profession, animal, pet;

	cout << "What is your name? "<< endl;
	getline(cin,name);
	cout << "How old are you? " << endl;
	getline(cin,age);
	cout << "What city do you live? " << endl;
	getline(cin,city);
	cout << "Which college did you go? " << endl;
	getline(cin,college);
	cout << "What is your prefession? " << endl;
	getline(cin,profession);
	cout << "Chose one animal. " << endl;
	getline(cin,animal);
	cout << "If you have a pet, what name is going to be? " << endl;
	getline(cin,pet);
	cout << "\n\n\n";
	cout << "There once was a person named "<<name<<" who lived in "<<city
		<<". At the age of\n"<<age<<", "<<name<<" went to college at "<<college
		<<". "<<name<<" graduated and went to work\nas a "<<profession<<". Then, "
		<<name<<" adopted a(n) "<<animal<<" named "<<pet<<". They both lived \nhappily ever after!"
		<<endl;

	system("pause");
	return 0;
}