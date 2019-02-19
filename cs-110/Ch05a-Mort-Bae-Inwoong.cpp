/*
	Chapter: 5
	Program: ch05a-Mort-Bae-Inwoong
	Author : Inwoong Bae
	Date   : 2/9/2015
	Purpose: Provide an exercise involving console input
		 (as well as calculation, and console output)
	Program: -- Determine monthly mortgage payment based on 
		 several input values:
		   -- Principle loan amount   (dollars)
		   -- Term of loan            (years)
		   -- Rate of annual interest (persentage)
		 -- Confirm input values
		 -- Calculate rate of monthly interest (decimal)
		 -- Calculate and output payment
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double p; // Principle loan amount    (input - dollars)
	double y; // Term of loan             (input - years)
	double a; // Rate of annual interest  (input - percentage)
	
	double n; // Term of loan             (calculated - month)
	double r; // Rate of monthly interest (calculated - decimal)
	double m; // Monthly payment amount   (calculated - dollars) 
	
	cout << endl;
	cout << "mortgage Program" << endl;
	cout << "----------------" << endl;
	
	cout << "input"            << endl;

	cout << "  principle? ";
	cin >> p; 
	cout << "  Year     ? ";
	cin >> y;
	cout << "  interest ? ";
	cin >> a;
	
	n = 12 * y;
	r = a / 1200;
	
	m = (p * pow(1+r , n) * r ) / (pow(1+r , n) - 1);

	cout << endl << endl;

	cout.setf( ios:: fixed | ios:: showpoint);
	

	cout << "Confirmation"<< endl;
	cout << "  Principle: $" << setw(9) << setprecision(0) << p << endl;
	cout << "  years    :  " << setw(9) << setprecision(0) << y << endl;
	cout << "  Interest :  " << setw(11) << setprecision(2) << a << "%" << endl;
	cout << endl;
	cout << "Result" << endl;
	cout << "  Payment  : $" << setw(11) << setprecision(2) << m << endl;
	
}