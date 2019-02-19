/* 

  Chapter : 9
  Program : ch09a-ShortIntMax-Bae-Inwoong.cpp
  Author  : Inwoong Bae
  Date    : 3/16/2015
  Purpuse : Provide exercise in limiting short integer values (that are input or accumulated) to maximums

  Problem : -- declare signed short int num variable
            -- declare signed short int sum accumulator

            -- output program heading (title and instructions) with function

            -- initialize sum accumulator

            -- prompt, then input, signed short int num

            -- loop continuously
               {
                 if (num is positive)
                   add num to sum
                 
                 else if (num is zero)
                 {
                   output goodbye message
                   exit loop
                 }
                 else
                 {
                   output audible alert (not beep)
                   output error message
                   exit loop
                 }

                 if (sum is positive or zero)
                 {
                   prompt for input
                   input subsequent short int num value
                 }
                 else
                 {
                   output audible alert (not beep)
                   output overflow error message
                   exit loop
                 }
               }
            -- output sum

*/

#include <iostream>

using namespace std;

void putHead();

int main()
{
  short int num;
  short int sum;

  putHead();

  sum = 0;

  cout << "  Num? ";
  cin >> num;   
  
  while(true)
  {
    if (num > 0)
      sum =  sum + num;
    else if (num == 0)
    {
      cout << "  goodbye  ";
      break;
    }
    else
    {
      cout << '\a';
      cout << endl;
      cout << "  Overflow error ";
      break;
    }

    if (sum >= 0)
    {
      cout << "  Num? ";
      cin >> num;
    }   
    else
    {
      cout << '\a';
      cout << endl;
      cout << "  Sum has overflowed ";
      break;
    }    
  }
  cout << endl;
  cout << "  Sum = " << sum; 
}

void putHead()
{
  cout << "  Short Int Maximum Program " << endl;
  cout << "  ------------------------------------ " << endl << endl;
  cout << "  When prompted, enter positive number " << endl;
  cout << "  up to maximum of 32767               " << endl << endl;
  cout << "  Program will add it to previously    " << endl;
  cout << "  entered numbers                      " << endl << endl;
  cout << "  Program will stop either when you    " << endl;
  cout << "  enter zero, or when sum overflows    " << endl << endl;  

}