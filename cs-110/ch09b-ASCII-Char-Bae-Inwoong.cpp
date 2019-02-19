/*
  Chapter: 9
  Program: Ch09b-ASCII-Char-Bae-Inwoong.cpp
  Author : Inwoong Bae
  Date   : Mar. 20, 2015

  Purpose: Provide sample program that uses functions, 
           and data validation with boolean variable, 
           to produce ASCII table 

  Problem:  -- prompts the user to enter beginning and ending character (not integer) values
              -- validates those character values so that the:
              -- beginning value is greater than character zero ('0')
              -- beginning value is less than or equal to the ending value
              -- ending value is less than or equal to the lower-case character 'z'
*/

#include <bitset>
#include <iomanip>
#include <iostream>
using namespace std;

//=========================================================
//Prototypes
//---------------------------------------------------------

void putHead1();            //Output program header
void putHead2();            //Output column headers

char  getBeg();             //Input beginning value
char  getEnd();             //Input ending    value
 
bool valBegEnd(char, char);   //Validate beg. and end. values

void putASCII(char, char);  //Output ASCII table 

//=========================================================
//Main Routine
//---------------------------------------------------------

int main()
{
  char  b;  //Beginning value
  char  e;  //Ending    value

  bool v;  //Valid     indicator

  v = false;

  putHead1();

  while(v == false)
  {
    b = getBeg();
    e = getEnd();

    v = valBegEnd(b, e);  
  }

  putHead2();

  putASCII(b, e);
}

//=========================================================
//Level 1 Functions
//---------------------------------------------------------

void putHead1()
{
  cout <<   "\n  ASCII Program                           ";
  cout <<   "\n  ----------------------------------------";

  cout << "\n\n  This program outputs part or all of an  ";
  cout <<   "\n  Amerian Standard Code for Information   ";
  cout <<   "\n  Interchange table                       ";

  cout << "\n\n  The program asks you to enter beginning ";
  cout <<   "\n  and ending character values between";
  cout <<   "\n  0 and 'z' (where beginning is less than ";
  cout <<   "\n  or equal to ending)                   \n";
}

void putHead2()
{
  cout <<   "\n  Dec  Bin       Hex  Char                ";
  cout <<   "\n  ---  --------  ---  ----              \n";
}

char getBeg()
{
  char b;  //Beginning value

  cout << "\n  Beg? ";
  cin  >>      b;

  return b;
}

char getEnd()
{
  char e;  //Ending value

  cout << "  End? ";
  cin  >>    e;

  return e;
}

bool valBegEnd(char b, char e)
{
  bool v;  //Valid indicator

  if (b >= '0' && b <= e && e <= 'z')
  {
    cout << "\n  Thanks; here's your ASCII table \n";
    v = true;
  }
  else
  {
    cout << "\a" << "\n  Invald values(s); try again \n";
    v = false;
  }

  return v;
}

void putASCII(char b, char e)
{
  int i; // loop index
  
  for (char(i) = b; char(i) <= e; char(i)++)

  {

    cout << "\n  " << setw(3) << dec << int(char(i));

    cout <<   "  " << setw(8) << bitset<8>(int(char(i)));

    cout <<   "  " << setw(3) << hex << uppercase << int(char(i));

    cout <<   "  " << setw(2) << char(i);

  }

  cout << "\n\n Done \n";

}

