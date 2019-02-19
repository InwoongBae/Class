/*
  Chapter: 14
  Program: Ch14s-state
  Author : Inwoong Bae
  Date   : 04/27/2015

  Purpose: Provide sample program that uses linked list

  Problem: -- declare / define 
              -- pre-processor directives
              -- structure for state admission data
              -- function prototypes

           -- define / code main routine and level-1 functions
              -- putHead: to console, output header(program title)
              -- getAdmName: from console, input name of file that contains data about 
                             American states, including dates (monts and years) when states were admitted to union
                             -- if file name is invalid, inform user and prompt user to try again
                             -- else return file name to main routine
              -- getAdmData:
                 -- from parameters, accept name of file, and accept by reference start admission record
                 -- from file, input state admission data, store data into linked list, update next and start pointers
                 -- return start pointer

              -- putAdmData:
                 -- from parameter, accept by reference state admission record
                 -- to console, output column headings, and output state admisstion data from linked list
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
  cout << endl;
  cout << "           A  d  m" << endl;
  cout << "           -------" << endl;
  cout << "  Ord  St  Year Mo" << endl;
  cout << "  ---  --  ---- --" << endl;
  for (a = start; a ; a = a->next)
  {
    cout.fill('0');
    cout << "   " << setw(2) << a->ord << "  " << a->stID << "  "  << a->admYr << " ";
    cout << setw(2) << a->admMo;
    cout << endl;
  } 
    
}
