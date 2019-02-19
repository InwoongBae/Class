/*
	Chapter: 6
	Program: ch06s-SumAve-Bae-Inwoong
	Author : Inwoong Bae
	Date   : 2/23/2015
	Purpose: Demonstrate validation and looping, until user enters sentinel
	Problem: Determine sum and average of series of positive numbers

		 Prompt user to enter series of positive numbers, accumulate their sum and count their instances until user enters zero, 
		 then output their sum and count, and calculate and output their average(with two digits to right of decimal point)

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
			 add 1      to count
		 
		 -- output sum
		 -- output count

		 -- set output format

		 -- calculate average
		 -- output    average
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//declare variables
	double num;    // Number (input)
	double sum;    // Sum    (accumulate)
	int    count;  // count  (incremented)
	double ave;    // Average(calculated)
	
	sum   = 0; // initialize sum
	count = 0; // initialize count
	ave   = 0; // initialize ave

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
			count++;
		}

	}
	ave =  sum / count;

	cout << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "Sum    : " << sum   << endl;
	cout << "Count  : " << count << endl;
	cout << "Average: " << ave   << endl;  
	
}	