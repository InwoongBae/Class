/*
	Chapter: 4
	Program: ch04a-Trig-Bae-Inwoong
	Author : Inwoong Bae
	Date   : 2/2/2015
	Purpose: Provide C++ Programming sample with:
		 -- trigonometric function
		 -- formatted output
	Program: Suppose we want to estimate height of cliff

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double ang; // angle of shadow (assume known in degrees)
	double len; // Length of shadow (measurable along ground in feet)
	double hei; // Height of cliff (initially unknown)	
	double rad; // radian of angle

	ang = 53.13; // ang = 0.92729 radians
	rad = 0.92729;
	len = 100;
	hei = len * tan(rad);


	cout << "Trigonometry Sample Program" << endl ;
	cout << "---------------------------" << endl ;
	cout << endl ;
	cout << "Use trig. to estimate height of cliff" << endl << endl ;
	
	cout.setf( ios:: fixed | ios:: showpoint);
	cout << setprecision(3);

	cout << "  Angle   of shadow ~   " << setw(7) << rad << " rad." << endl ;
	cout << "  Length  of shadow =   " << len << " ft." << endl ;
	cout << "  Height  of cliff  ~   " << hei << " ft." << endl ;
		
	
}