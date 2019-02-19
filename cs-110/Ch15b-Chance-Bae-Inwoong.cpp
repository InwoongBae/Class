/*
  Chapter: 15
  Program: Ch15b-Chance-Bae-Inwoong.cpp
  Author : Inwoong Bae
  Date   : 5/6/2015
  Purpose: Provide exercise in using recursive logic to solve probability (chance) problem
  Problem: same as program assignment Ch15a, plus:
           -- organize grogram into functions with prototypes
           -- output heading (prrgram title)
           -- validate that number of flips >= 0 and if invalid, notify user with audible and visible alerts
           -- validate that number of heads >= 0 and <= flips, and if invalid, notify user with audible and visible alerts
           -- code only one function (not two) to calculate factorial, and re-use that function
           -- output answer in form of percent with 1 digit to right of decimal point
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void putHead();
int getFlips();
int getHeads(int);
void putChance(int, int);
double calcFact(int);

int main()
{
  int n;

  int h;
  
  putHead();

  n = getFlips();

  h = getHeads(n);

  putChance(n, h);
}

void putHead()
{
  cout << "  Chance Program " << endl;
  cout << "  ---------------------------------------- " << endl << endl;
}

int getFlips()
{
  int n;

  while(true)
  {
    cout << "  Number of coin tosses? ";
    cin >> n;
    if(n < 0)
    {
      cout << '\a';
      cout << "  invalid, Please try again " << endl;
    }
    else
      break;
  }
  return n;
}

int getHeads(int n)
{
  int h;

  while(true)
  {
    cout << "  Number of heads? ";
    cin >> h;
    if(h < 0 || h > n)
    {
      cout << '\a';
      cout << "  invalid, Please try again " << endl;
    }
    else
      break;
  }
  return h;
}

void putChance(int n, int h)
{
  double chance;

  chance = calcFact(n) / (calcFact(h) * calcFact(n-h) * pow(2 , n)) * 100;

  cout << fixed << showpoint << setprecision(1);

  cout << "  Probablity of seeing Heads is " << setw(2) << chance << " %" << endl; 

}

double calcFact(int n)
{
  double result;
  if (n < 2)
    result = 1;
  else
    result = (double)n * calcFact(n-1);
  return result;
}