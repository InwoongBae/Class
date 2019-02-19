/*
  Chapter: 8
  program: ch08b-MonthInt
  Author : Inwoong Bae
  Date   : 3/11/2015
  Purpose: Provide project that involves console input, data validation, switch-case construct, nested loops, math function, 
           arithmetic operations, and console output, with functions

  Problem: similar to project ch07c, but organized into functions

*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include <cmath>
#include <windows.h>

void   putHead1();
double getPrin();
void   putHead2();
void   putMon(double);
void   putAmt(double, int);

//=================================================================================
//Level 1 function
//---------------------------------------------------------------------------------

void   putHead1()                     //output headings - title and instruction
{
  cout << "Monthly Compound Interest Program" << endl;
  cout << "-------------------------------------" << endl << endl;
  cout << "When prompted, enter starting amount " << endl;
  cout << "(as positive number, with no dollar" << endl;
  cout << "sign or commas)" << endl << endl;

}

double getPrin()                      //get Principle (input, validate and return starting amount)
{
  double p;                           //Principal  (starting amount)

  while(true)
  {
    cout << "Starting amount? ";
    cin >> p;
    
    if(p>0)
        return p;    
    else
    {
        cout << '\a';
        cout << "Must be positive number; try again" << endl << endl;
    }
  }  
}

void   putHead2()                     //Output column headings
{
  cout << endl;
  cout << "          E n d i n g   B a l a n c e" << endl;
  cout << "         ----------------------------" << endl;
  cout << "  Mon.         2%        4%        6%" << endl;
  cout << "  ----   --------  --------  --------" << endl;
  cout << endl;

}

void   putMon(double p)               //Output month names
{
  int    m;                           //Month index
  string s;                           //Month name (abbreviated)

  for(m = 1; m <= 12 ; m++)
  {
    switch(m)
      {
        case  1: s = "Jan."; break;
        case  2: s = "Feb."; break;
        case  3: s = "Mar."; break;
        case  4: s = "Apr."; break;
        case  5: s = "May."; break;
        case  6: s = "Jun."; break;
        case  7: s = "Jul."; break;
        case  8: s = "Aug."; break;
        case  9: s = "Sep."; break;
        case 10: s = "Oct."; break;
        case 11: s = "Nov."; break;
        case 12: s = "Dec."; break;
      }
       cout << "  " << s << "     ";  //Output month name (abbreviated)

    putAmt(p, m);                     //output 3 amounts (at end of 1 month)  
  
    cout << endl;                     //Advance to next line
  }   

}

//=================================================================================
//Level 2 function
//---------------------------------------------------------------------------------

void putAmt(double p, int m)
{
  double r;                           //Rate      of annual interest (as decimal)
  double a;                           //Amount    at end       of period

  cout << fixed << showpoint << setprecision(2);

  for(r = 0.02; r <= 0.06; r = r+0.02)
    {
      a = p * pow(1 + r/12 , m); 
      
      cout << setw(6) << a << "    "; 
    }
}


//=================================================================================
//Main Routine
//---------------------------------------------------------------------------------

int main()
{
  double p;      //principal at beginning of period

  putHead1();    //output headings - title and instruction
  
  p = getPrin(); //get Principle (input, validate and return starting amount)

  putHead2();

  putMon(p);
}