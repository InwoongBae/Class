/*
	Chapter: 5
	Program: ch05b-Dist-Bae-Inwoong
	Author : Inwoong Bae
	Date   : 2/11/2015
	Purpose: Learn to use lower case and square root functions while
		 -- inputting and confirming data
		 -- calculating and outputting a result
	Problem: How far from land can a sailor see a lighthouse (based on its height)?
		 Assume that the lighthouse's distance of visibility equals the square root of 0.8 times of the lighthouse's height.

*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
using namespace std;

int main()
{
	char u;   //Unit of measure
	double h; //Height of lighthouse
	double d; //Distance from lighthouse

	cout << endl;
	cout << "Distance Program" << endl;
	cout << "----------------" << endl << endl;

	cout << "input" << endl;
	cout << "  Unit of measure [f/m] ? ";
	cin >> u;
	cout << "  Height of lighthouse  ? ";
	cin >> h;
	cout << endl << endl;
	
	u = tolower(u);
	cout.setf( ios:: fixed | ios:: showpoint);

	 
	cout << "confirmation" << endl;
	cout << "Unit of measure         : " << u << endl;
	cout << "Height of lighthouse    : " << setprecision(2) << h << endl;
	cout << endl;
	
	d = sqrt( 0.8 * h);
	
	cout << "result" << endl;
	cout << "  Distance of visibility: " << setw(6) << setprecision(2) << d << " miles" << endl;
	
	
	
			
	
}