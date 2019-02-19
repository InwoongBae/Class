/*
  Chapter: 8
  program: ch08a-Avg-Bae-Inwoong
  Author : Inwoong Bae
  Date   : 3/9/2015
  Purpose: Provide exercise that inputs and validates numeric data, and calculates and outputs average, with help of functions

  Program: -- declare preprocessor directives

           -- define void function to output header

              -- output program title

              -- output data entry instructions

           -- define interger function to input number

              -- declare interger number

              -- prompt user to enter number

              -- input number 

              -- return number to main routine

           -- define void function to calculate and output average

              -- declare function to accept integer parameters for sum and count

              -- declare double variable for average

              -- calculate average

              -- output average with 2 digits to right of decimal point

           -- define integer main routine 

              -- declare variables (see below)

              -- call function to output header

              -- initialize accumulator and counter

              -- call function to get initial input number

              -- loop while true

              .  -- if input number below -1000 or above 999,

              .       sound alert

              .       output message

              .     else if input number equals -999

              .       exit loop

              .     else

              .       accumulate sum

              .       increment  count

              .  -- call function to get subsequent input number

              -- call function to calculate and output average, passing in parameters for count and sum
*/

#include <iostream>
#include <iomanip>

using namespace std;

#include <windows.h>

void putHead()
{
  cout << endl;
  cout << "  Average Program " << endl;
  cout << "  ----------------------   " << endl << endl;

  cout << "  Enter integers " << endl;
  cout << "  between 999 and -998 " << endl << endl;
  cout << "  To quit,  enter -999 " << endl;
}

int getNum()
{
  int num;
  cout <<  "  Num ? ";
  cin  >> num;

  return num;
}

void calcAvg(int c , int s)
{
  double avg = 0;

  avg = s * 1.0 / c * 1.0;
  
  cout << endl;

  cout << fixed << showpoint << setprecision(2);  

  cout << "  Avg: " << avg << endl << endl;
}


int main()
{
  int     n;   //number  (input)
  int     c;   //count   (incremented)
  int     s;   //sum     (accumulated)
  double  a;   //Average (calculated)

  s = 0;
  c = 0;

  putHead();
  
  n =  getNum();
  
  while(true)
  {    
    if( n <= -1000 || n > 999 )
    {
      cout << '\a';
      cout << "  Invalid; try again" << endl << endl;
      //n = getNum();  
    }
    else if (n == -999)
      break;
    else
    {
      s = s + n;
      c++;      
    }
    n = getNum();
  }
  //cout << "\n  Sum = " << s << ", Count = " << c << "\n\n";

  calcAvg(c, s);
}
