/*
  Chapter: 10
  Program: ElecBills
  Author : Inwoong Bae
  Date   : 3/23/2015

  Purpose: Provide a sample of inputting data from a file
  
  Problem: -- open input file that contains data from a file

	   -- to console, output program header

	   -- assign file name to variable

	   -- to console, output column headers

	   -- loop while input file is good (not at end of file)

	      -- from one input record, get these data fields
	 	  -- year
		  -- month
		  -- kilowatt hours
		  -- cost
	      -- to console, output same data fields

   	   -- close input file 
*/

//=============================================================================================
// Main Routine
//---------------------------------------------------------------------------------------------
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void putHead1();
void putHead2();

//=============================================================================================
// Main Routine
//---------------------------------------------------------------------------------------------

int main()
{
  ifstream fin;     //Input file stream
  string   ifname;  //Input file name

  int      yr;      //Year
  int      mon;     //Month
  int      kwh;     //Kilowatt hour
  double   cost;    //Cost
  
  putHead1();

  ifname = "Ch10-ElecBills.txt";

  fin.open(ifname.c_str());

  putHead2();

  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);


  while(fin.good())
  {
    fin >> yr;
    fin >> mon;
    fin >> kwh;
    fin >> cost;

    cout << "  " << yr;
    cout << "  " << setw(3) << mon;
    cout << "  " << setw(5) << kwh;
    cout << "  " << setw(7)  << cost << endl;
  }
  
}

//=============================================================================================
//Level 1 function
//---------------------------------------------------------------------------------------------
void putHead1()
{
  cout << endl;
  cout << "  Electricity Bills Program                            " << endl;
  cout << "  -----------------------------------------------------" << endl << endl;
  cout << "  This program will input data related "   << endl;
  cout << "  to electricity bills from a file, then " << endl;
  cout << "  output the same data to the console"     << endl << endl;
}

//==============================================================================================
//Level 1 function
//----------------------------------------------------------------------------------------------
void putHead2()
{
  cout << "  Year  Mon    KWh    $Cost" << endl;
  cout << "  ----  ---  -----  -------" << endl << endl;
}