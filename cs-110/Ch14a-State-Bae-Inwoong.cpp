/*
  Chapter: 14
  Program: Ch14a-State-Bae-Inwoong.cpp
  Author : Inwoong Bae
  Date   : 04/27/2015

  Purpose: Similar to related sample program

  Problem: Plus calculate and output age of each state (years since its admission to union)
           -- include <ctime> library

           -- declare prototype for calcAge function

           -- modify level-1 functions
           
              -- putAdmData:
                 -- output column heading for age
                 -- call calcAge (pass current state admission record to it, and return state age from it)
                 -- include state age in console output
           -- define level-2 function
              -- calcAge:
                 -- accept parameter by reference state admission record
                 -- determine current year and month
                 -- calculate difference of years between current year and state and state admission year (if current month 
                    less than admission month, decrement age by 1)
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


using namespace std;

struct Adm
{
  int    ord;
  
  string stID;

  int    admYr; 
  int    admMo; 

  Adm*   next;  //pointer to next node
};

void putHead();
string getAdmName();
Adm*   getAdmData(string, Adm*);
void   putAdmData(Adm*);
int    calcAge(Adm*);


int main()
{
  string admName;
  Adm*   start = 0;

  putHead();

  admName = getAdmName();
  start   = getAdmData(admName, start);

  putAdmData(start);

}

void putHead()
{
  cout << "  State Program" << endl;
  cout << "  ---------------------------" << endl;
}

string getAdmName()
{
  string admName;
  ifstream fin;   
  while(true)
  {
    cout << "  Adm file name?"; 
    cin >> admName;
    fin.open(admName);
    if(fin.good())
      break;
    else
      cout << "  Error, try again" << endl;    
  }
  fin.close();
  return admName;
}

Adm* getAdmData (string admName, Adm* start)
{
  ifstream fin;
  fin.open (admName);
  while(fin.good())
  {
    Adm* a = new Adm; // create node

    fin >> a->ord;
    fin >> a->stID; 
    fin >> a->admYr;
    fin >> a->admMo;
    
    a->next = start;  
    start = a;
  }
  fin.close();

  return start;
}

void putAdmData (Adm* start)
{
  Adm* a;
  int age;
  cout << endl;
  cout << "           A  d  m" << endl;
  cout << "           -------" << endl;
  cout << "  Ord  St  Year Mo  Age" << endl;
  cout << "  ---  --  ---- --  ---" << endl;
  for (a = start; a ; a = a->next)
  {
    cout.fill('0');
    cout << "   " << setw(2) << a->ord << "  " << a->stID << "  "  << a->admYr << " ";
    cout << setw(2) << a->admMo;
    age = calcAge(a);
    cout << right;
    cout.fill(' ');
    cout << "  " << setw(3) <<  age;    
    cout << endl;
  } 
    
}

int calcAge (Adm* a)
{
  time_t sec  = time(0);
  tm*    cur  = localtime(&sec);

  int curYr   = cur->tm_year + 1900;
  int curMo   = cur->tm_mon;

  int admYr   = a->admYr;
  int admMo   = a->admMo;

  int age;

  if(curMo < admMo)
  age = curYr - admYr - 1;
  else
  age = curYr - admYr;

  return age;

}