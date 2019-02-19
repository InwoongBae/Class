/*
  Chapter: 10
  Program: ch10s-Elecbill.cpp
  Author : Inwoong Bae
  Date   : 3/23/2015

  Purpose: Provide a sample of inputting data from a file

  Problem: -- opne input file that contains data related to electricity bills

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
//==========================================================================
//Main Routine
//--------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void putHead1();
void putHead2();

int main()
{
  ifstream fin;   // input file stream
  string ifname;  // input file name

  int yr;         // year 
  int mon;        // month
  int kwh;        // kilowatt hour
  double cost;    // cost

  putHead1();
  putHead2();

  cout << fixed << showpoint << setprecision(2);

  ifname = "Ch10-ElecBills.txt";
  fin.open(ifname);

  

  while(fin.good())
  {
    fin >> yr;
    fin >> mon;
    fin >> kwh;
    fin >> cost; 

    cout << "  " << setw(4) << yr << "  " << setw(3) << mon << "  "<< setw(5) << kwh << "  " << setw(7) << cost << endl;
  
  }
   
}

void putHead1()
{  
  cout << "  Electricity Bill Program" << endl;
  cout << "  -----------------------------------" << endl << endl;
  cout << "  This program will input data related " << endl;
  cout << "  to electricity bills from a file, then " << endl;
  cout << "  output the same data to the console " << endl << endl;
}

void putHead2()
{
  cout << "  Year  Mon    KWh    $Cost" << endl;
  cout << "  ----  ---  -----  -------" << endl;
  cout << endl;
}