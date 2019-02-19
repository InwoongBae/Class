/*
	Chapter: 6
	Program: ch06s-Sum
	Author : Inwoong Bae
	Date   : 2/23/2015
	Purpose: Demonstrate validation and looping, until user enters sentinel
	Problem: Determine sum of series of positive numbers

		 Prompt user to enter series of positive numbers, accumulate their sum until user enters zero, then output sum
		 -- Include preprocessor directives 

		 -- declare variables
		 
		 -- initialize accumulator to zero
		 
		 -- output title
		
		 -- output instruction to enter positive
		    numbers (or 0 to quit)

		 -- loop
			-- prompt user to enter number
			
			-- if number is negative
			 output "invalid"

			-- else if number is zero
			 exit loop
			
			-- else 
			 add number to sum
		 
		 -- output sum
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//declare variables
	double num; // Number (input)
	double sum; // Sum    (accumulate)
	double div; // Division
	double ave; // Average
	
	sum = 0; // initialize sum
	div = 0; // initialize div

	cout << "Sum and Average Program" << endl;
	cout << "-----------------------" << endl << endl;
	cout << "Enter positive numbers " << endl;
	cout << "(to quit , enter 0)" << endl << endl;
	
	while(true)
	{
		cout << "Number ? ";
		cin >> num; 
		if(num < 0)
		{
			cout << "invalid" << endl;
			
		}
		else if(num == 0)
		break;
		else
		{
			sum =  sum + num;
			div++;
		}

	}
	ave =  sum / div;
	cout << endl;
	cout << "Sum    : " << sum << endl;
	cout << "Average: " << ave << endl;  
	
}	