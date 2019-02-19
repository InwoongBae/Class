/*
  Chapter:  7
  Program:  ch07c-MonthInt-Bae-Inwoong
  Author :  Inwoong Bae
  Date   :  3/4/2015

  Purpose:  Provide project that involves console input,
            data validation, switch-case construct, nested loops,
            math function, arithmetic operations, and console output


  Tutor  :  Sat., Mar. 7,  9:00 a.m. - 11:59 a.m.
  Due    :  Sat., mar. 7,  . . . . . . 11:59 a.m.
  Value  :  20 points

  Problem:  Based on starting balance that user inputs, for each month of year, identify name of month, and calculate balance at end of month based on
            compound interest at three annual rates of interest: 2%, 4% and 6%, then output month name, and three ending balances

            -- research formula for monthly compound interest

            -- declare preprocessor directives
            
            -- declare variables as below

            -- output title and instructions

               -- identify program as Monthly Compound Interest Program
              
               -- Instruct user, when prompted, to enter starting amount as positive number (with no dollar signs or commas)

            -- loop "while" true

               -- prompt user to input starting amount, then input it

               -- if input greater than zero
                
                  -- exit loop

               -- else
                  
                  -- sound alert
  
                  -- output error message

               -- output column headings

               -- in outer "for" loop for month, use "switch-case" construct to output 3-character abbreviation for month name

                  -- in inner "for" loop, based on annual interest rate that is compounded monthly, calculate and output month's ending balance for

                     each of three rates

               -- required elements, besides correct syntax and logic, include

                  -- good source formatting such as consistent indentation and appropriate line spacing

                  -- good output formatting such as fixed-point output of real numbers that align well and that shows dollars and cents, and appropriate

                     line spacing

*/

//Declare preprocessor directives
#include <iostream>
#include <iomanip>

using namespace std;

#include <cmath>
#include <string>
#include <windows.h>

int main()
{
//Declare variables

  double p; //principal at beginning of period
  double r; //Rate      of annual interest (as decimal)
  double a; //Amount    at end       of period
  int    m; //Month index
  string s; //Month name (abbreviated)

//Output title and instructions 

  cout << "Monthly Compound Interest Program" << endl;
  cout << "-------------------------------------" << endl << endl;
  cout << "When prompted, enter starting amount " << endl;
  cout << "(as positive number, with no dollar" << endl;
  cout << "sign or commas)" << endl << endl;

//Get input and validate

  while(true)
  {
    cout << "Starting amount? ";
    cin >> p;
    
    if(p>0)
    break;
    
    else
    {
        cout << '\a';
        cout << "Must be positive number; try again" << endl << endl;
    }
  }
  
//Output column headings

  cout << endl;
  cout << "          E n d i n g   B a l a n c e" << endl;
  cout << "         ----------------------------" << endl;
  cout << "  Mon.         2%        4%        6%" << endl;
  cout << "  ----   --------  --------  --------" << endl;
  cout << endl;
 
//Output month names

  cout << fixed << showpoint << setprecision(2);

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
       cout << "  " << s << "     ";
    
  //Calculate and output amounts with compound interest

    for(r = 0.02; r <= 0.06; r = r+0.02)
    {
      a = p * pow(1 + r/12 , m); 
      
      cout << setw(6) << a << "    "; 
    }
    cout << endl;
  }   
}