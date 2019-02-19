/*
  Chapter: 10
  Program: ch10s-Elecbill.cpp
  Author : Inwoong Bae
  Date   : 3/25/2015

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

  Also   : Similar to sample program, plus:
           -- declare and initialize counters and accumulators

              -- monthly records       (monCount)
              -- kilowatt hours        (kwhSum)
              -- costs                 (costSum)

           -- declare
              
              -- average cost per month(monAvg)
              -- average cost per kilowatt hour (kwhAvg)

           -- declare prototype and header for function(putFoot(...)) with parameters
              -- monSum
              -- kwhSum
              -- costSum
              but that will not return any result to main routine

           -- in putHead1(), add to comments that this program will also calculate and output some sums and averages

           -- in loop

              -- count monthly records
              -- accumulate kilowatt-hour sum
              -- accumulate cost sum
 
           -- after loop, call footer function that will declare necessary variable to calculate and output

              -- month cost average
              -- kilowatt-hour cost average            
*/



//=====================================================================
//Main Routine
//---------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void putHead1();
void putHead2();
void putFoot(int, int, double);


//=====================================================================
//Main Routine
//---------------------------------------------------------------------

int main()
{
  ifstream fin;     //Input file stream
  string   ifname;  //Input file name

  int      yr;      //Year
  int      mon;     //Month
  int      kwh;     //Kilowatt hour
  double   cost;    //Cost

  int monCount = 0;
  int kwhSum = 0;
  double costSum = 0; 
  
  double monAvg;
  double kwhAvg;

  putHead1();

  ifname = "Ch10-ElecBills.txt";

  fin.open(ifname);

  putHead2();

  cout << fixed << showpoint << setprecision(2);

  while(fin.good())
  {
    fin >> yr;
    fin >> mon;
    fin >> kwh;
    fin >> cost;

    cout << "  " << yr;
    cout << "  " << setw(3) << mon;
    monCount++;
    cout << "  " << setw(5) << kwh;
    kwhSum = kwhSum + kwh;
    cout << "  " << setw(7)  << cost;
    cout << endl;
    costSum = costSum + cost;    
  }
  putFoot(monCount, kwhSum, costSum);
}


//=====================================================================
//Level 1 function
//---------------------------------------------------------------------
void putHead1()
{
  cout << endl;
  cout << "  Electricity Bills Program                            " << endl;
  cout << "  -----------------------------------------------------" << endl << endl;
  cout << "  This program will input data related "   << endl;
  cout << "  to electricity bills from a file, then " << endl;
  cout << "  output the same data to the console"     << endl << endl;
  cout << "  This program will also calculate and output some averages " << endl << endl;
}

//=====================================================================
//Level 1 function
//---------------------------------------------------------------------
void putHead2()
{
  cout << "  Year  Mon    KWh    $Cost" << endl;
  cout << "  ----  ---  -----  -------" << endl << endl;
}

//=====================================================================
//Level 1 function
//---------------------------------------------------------------------
void putFoot(int monCount, int kwhSum, double costSum)
{
  double monAvg;
  double kwhAvg;

  monAvg = costSum / monCount;
  kwhAvg = costSum / kwhSum;

  cout << fixed << showpoint << setprecision(2);

  cout << "  Month count             = " << setw(5) << monCount << endl;
  cout << "  KWh   sum               = " << setw(5) << kwhSum   << endl;
  cout << "  Cost  sum               = " << setw(8) << costSum  << endl << endl;
  cout << "  Average cost per month  = " << setw(8) << monAvg   << endl;
  cout << "  Average cost per KWh    = " << setw(8) << kwhAvg   << endl;
}