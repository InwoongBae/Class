/*
	Chapter: 6
	Program: ch06a-Score-Bae-Inwoong
	Author : Inwoong Bae
	Date   : 2/18/2015
	Purpose: Learn to use conditional (if) statements
	Problem: Based on score, assign and output values for grade and status

		 -- input score

		 -- assign values to

		    -- grade

			 if score greater than 100 or less than 0
			    grade equals  ?

			 if score between 100 and 90
			    grade equals  A

			 if score between 90  and 80
			    grade equals  B

			 if score between 80  and 70
			    grade equals  C

			 if score between 70  and 60
			    grade equals  D
			 
			 if score between 60  and  0
			    grade equals  F
			 
			 if grade equals A, B, C or D
			    grade equals Pass

			 if grade equals F
			    grade equals Fail

			 if grade equals ?
			    grade equals invalid

		 -- output values for 
		      -- grade
*/

#include <iostream>
#include <string>

using namespace std;



int main()
{
	cout << "Score, Grade and Status Program" << endl;
	cout << "-------------------------------" << endl << endl;

	int    score;  //Student score
	char   grade;  //Student grade
	string status; //Student name

	cout << "Score  ? " ;
	cin >> score;
	cin.ignore(1000, 10);

	//Assign grade

	if (score > 100 || score < 0)
		grade = '?';

	else if (score >= 90)
		grade = 'A';

	else if (score >= 80)
		grade = 'B';

	else if (score >= 70)
		grade = 'C';
	
	else if (score >= 60)
		grade = 'D';

	else 
		grade = 'F';

	if      (grade == '?')		       status = "invalid";
	
	else if (grade >= 'A' && grade <= 'D') status = "Pass";
	
	else                                   status = "Fail";

	cout << "Grade  : " << grade  << endl;
	cout << "Status : " << status << endl;
		
}	