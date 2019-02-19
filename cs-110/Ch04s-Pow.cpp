/*
	Chapter: 4
	Program: ch04s-Pow-Bae-Inwoong
	Author : Inwoong Bae
	Date   : 2/4/2015
	Purpose: Demonstrate use of Pow math function in geometric formulas
	Program: Calculate
		 -- area of circle
		 -- volume of sphere (4/3 pi * r * r * r)
		 for radius of 1 and 2 centimeters
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{

	
	double p = 3.1415926; // pi
	double r;             // radius of circle or sphere
	double a;	      // area   of circle
	double v; 	      // volume of sphere
	
	
	r = 1.00;
	a = p * pow(r , 2.00);
	v = 4.00 / 3.00 * p * pow(r , 3.00);

	cout.setf( ios:: fixed | ios:: showpoint);
	cout << setprecision(2);

	cout << "Area of Circle and Volume of Sphere" << endl;
	cout << "-----------------------------------" << endl << endl;
	cout << "Radius:  " << setw(5) << r << " cm." << endl;
	cout << "Area  :  " << setw(5) << a << " cm.2"<< endl;
	cout << "Volume:  " << setw(5) << v << " cm.3"<< endl << endl;
	
	r = 2.00;
	a = p * pow(r , 2.00);
	v = 4.00 / 3.00 * p * pow(r , 3.00);	

	cout << "Radius:  " << setw(5) << r << " cm." << endl;
	cout << "Area  :  " << a << " cm.2"<< endl;
	cout << "Volume:  " << v << " cm.3"<< endl << endl;
	
}