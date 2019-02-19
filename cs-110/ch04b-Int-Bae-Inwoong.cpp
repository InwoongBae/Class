/*
	Chapter: 4
	Program: ch04b-INt-Bae-Inwoong
	Author : Inwoong Bae
	Date   : 2/4/2015
	Purpose: Demonstrate use of Pow math function 
		 while calculating compound interest
	Program: Calculate future value of monthly savings
		 of $100 in 30 years
		 at annual interest rates of
		 -- 4%
		 -- 8%
		 
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double s; // sum of deposits and compound interest after y years
	double y; // years
	double d; // monthly deposit amount (dollars)
	double r; // annual interest rate (percentage as decimal)
	double t; // total time period (months)
	double p; // monthly interest rate (percentage as decimal)

	cout << fixed << showpoint;

	y = 30.0;
	t = y * 12.0;
	d = 100.0;

	r = 0.04;
	p = r / 12.0;	

	s = d * ((pow(1+p,t)-1)/p);	
	cout << endl;
	cout << "Future Value of Monthly Deposits and Compound Interest" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << endl;
	cout << "Years            : " << setprecision(0)<< setw(9) << y << endl;
	cout << "Months           : " << setprecision(0)<< setw(9) << t << endl;
	cout << endl;
	cout << "Annual   Interest: " << setprecision(4)<< setw(13)<< r  <<endl;
	cout << "Monthly  Interest: " << setprecision(6)<< setw(15)<< p  <<endl;
	cout << "Monthly  deposit : " << "$ " << setprecision(2)<< setw(9) << d << endl;
	cout << "Future   Value   : " << "$ " << setprecision(2)<< setw(9) << s << endl;

	r = 0.08;
	p = r / 12.0;		
	s = d * ((pow(1+p,t)-1)/p);

	cout << endl;
	cout << "Annual   Interest: " << setprecision(4)<< setw(13)<< r <<  endl;
	cout << "Monthly  Interest: " << setprecision(6)<< setw(15)<< p <<  endl;
	cout << "Monthly  deposit : " << "$ " << setprecision(2)<< setw(9) << d << endl;
	cout << "Future   Value   : " << "$ " << setprecision(2)<< setw(9) << s << endl;
	
}