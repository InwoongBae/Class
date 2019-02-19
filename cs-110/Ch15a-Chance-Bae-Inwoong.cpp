/*
  Chapter: 15
  Name   : Ch15a-Chance-Bae-Inwoong.cpp
  Author : Inwoong Bae
  Date   : 5/4/2015
  Purpose: Make a factorial function using recursion and output chance to see a head of coin
*/

#include <iostream>
#include <cmath>

using namespace std;

int fact(int);

int main()
{
  int n;

  int h;

  double chance;

  cout << "  Number of coin tosses? ";
  cin >> n;
  cout << "  Number of heads? ";
  cin >> h;

  if(h>0 && n>0 && n >= h)
  {
    chance = fact(n) / (fact(h) * fact(n-h) * pow(2 , n));
  }
  cout << "  chance of coin = " << chance;
}

int fact(int n)
{
  int result;
  if (n < 2)
    result = 1;
  else
    result = n * fact(n-1);
  return result;
}