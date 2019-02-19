/*
	Chapter: 5
	Program: ch05s-Per
	Author : Inwoong Bae
	Date   : 2/9/2015
	Purpose: Sample program that inputs several types of data
	Program: Input personal information about a student:
		 name, gender, age, and grade point average
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string fname; // Student first name
	string lname; // Student last name
	string name; // Student full name
	
	cout << endl;
	cout << "Personal Information Program" << endl;
	cout << "----------------------------" << endl << endl;
	
	cout << "input"<< endl << endl;	
	
	cout << " first name ? ";
	cin >> fname;
	//getline(cin, name);
	
	cout << " Last  name ? ";
	cin >> lname;
	
	name = fname + " " + lname;
	
	cout << endl;
	cout << "confirmation" << endl << endl;
	
	cout << " first name : " << fname << endl;
	cout << " last  name : " << lname << endl;
	cout << " Full  name : " << name << endl;
	
}