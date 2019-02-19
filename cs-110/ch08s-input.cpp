/*
  Chapter: 8
  program: ch08s-Input
  Author : Inwoong Bae
  Date   : 3/9/2015
  Purpose: Provide sample of program that inputs data with help of user-defined functions
*/

#include <iostream>
using namespace std;

void putHead()
{
  cout << "\nSample Input-with-Functions Program \n";
  cout <<   "----------------------------------- \n\n";

  cout << "Enter integer                         \n";
  cout << "To quit, enter -999                   \n\n";
}

int getNum()
{
  int n;         //number (input)

  cout << "num ? ";
  cin  >> n;

  cout << "Num : " << n << endl << endl;

  return n;
} 

int main()
{
  int n;         //Number (integer)

  putHead();     //call function to output headers 

  n = getNum();  //call function to input number

  while (true)
  {
    if (n == -999)
      break;

    else
      n = getNum();
  }

}