/*
	Chapter: 7
	Program: ch07s-Roll
	Author : Inwoong Bae
	Date   : 2/25/2015

	Purpose: Provide a sample exercise that uses random number generator and count-controlled looping

	Problem: Simulate roll of die for number of times that user indicates, then accumulate and output total value of roll outcomes

		 -- specify preprocessor directives
		 
		 -- declare variables (see below)

		 -- output title and instructions

		 -- prompt user to input number of times to roll one die, and input that value

		 -- seed random number generator
		
		 -- initialize variables that are accumulators and counters

		 -- loop while index less than or equal to number of rolls that user specified

			-- generate random roll (per author's online supplement on game programming.)

			-- output roll outcome
		
			-- accumulate roll outcome (as part of total)

			-- increment loop index

		 -- output total (of roll outcomes)
	
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{
	
	int n; //Number of rolls   (input)
	int i; //index             (counter)  
	int r; //Roll outcome      (generated)
 	int t; //Total of outcomes (accumulated)

	i = 1; //initialize intex
	t = 0; //initialize accumulator

	srand(time(0));

		
	cout << "Roll Program" << endl;
	cout << "----------------------------------" << endl;
	cout << "Input number of times" << endl;
	cout << "program should roll die" << endl;
	cout << endl;
	cout << "Program will then display" << endl;
	cout << "outcomes as numbers" << endl;
	cout << endl;
	cout << "Program will also accumulate" << endl;
	cout << "and display total of outcomes" << endl;
	cout << endl;
	cout << "Number of rolls ? ";
	cin >> n;

	while(n >= i)
	{
		r = 1 + (rand() % 6); // roll die

		cout << "Roll " << i << " is " << r << endl;

		t = t + r; // accumulate total		
		
		i++;       // increment index
		
		r = 0;     // initialize roll outcome

	}

	cout << endl;
	cout << "Total  is " << t << endl;
		
	
}	