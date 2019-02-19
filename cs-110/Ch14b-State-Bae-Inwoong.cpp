/*
  Chapter: 14
  Program: Ch14a-State-Bae-Inwoong.cpp
  Author : Inwoong Bae
  Date   : 04/27/2015

  Purpose: Similar to related Ch14a program

  Problem: plus input file name and data regarding state names and capital city
           names with help of substring function, then find and output that data in relation to each state admission
           record that is output (indicate state name and capital are unknown)

           -- before main routine
          
              -- define structure Cap (capital data)

              -- declare prototypes for new functions

              -- declare constant size for array of capital data of American states

           -- in main routine

              -- declare string capName (capital file name)

              -- declare Cap c (capital data array) with size that equals constant size declared earlier

              -- call new getCapName function (input capital file name) and assign result to capName

              -- call new getCapData function (input capital data) and pass as parameters both capName and c

           -- among level-1 functions

              -- create new getCapName function, similar to getAdmName function, and return capName

              -- create new getCapData funciotn, take string capName and Cap* C as parameters, input state names and capital names
                 and store them in array c, with help of substr (substring) function

              -- in existing level-1 putAdmData function, call new level-2 putCapData function(output capital data) and pass as parameters both a and c

           -- among level-2 functions

              -- create new putCapData fucntion, take Adm* a and Cap* c as parameters, and to console, output state name and capital name for current state
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

struct Cap
{
  string stID;
  string stName;
  string stCap; 
};

void putHead();
string getAdmName();
string getCapName();
Adm*   getAdmData(string, Adm*);
void   getCapData(string, Cap*);
void   putAdmData(Adm*, Cap*);
int    calcAge(Adm*);
void   putCapData(Adm*, Cap*);

const int SIZE = 50;


int main()
{
  string admName;
  string capName;
  Adm*   start = 0;
  Cap    c[SIZE];

  putHead();

  admName = getAdmName();
  capName = getCapName();

  start   = getAdmData(admName, start);
  getCapData(capName, c);

  putAdmData(start, c);

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
    cout << "  Adm file name? "; 
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

string getCapName()
{
  string capName;
  ifstream fin;   
  while(true)
  {
    cout << "  Cap file name? "; 
    cin >> capName;
    fin.open(capName);
    if(fin.good())
      break;
    else
      cout << "  Error, try again" << endl;    
  }
  fin.close();
  return capName;
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

void getCapData (string capName, Cap* c)
{
  ifstream fin;
  int i;

  fin.open(capName);

  i = 0;

  while(fin.good())
  {

    /*
    fin >> c[i].stID;
    fin >> c[i].stName;
    fin >> c[i].stCap;
    */

    getline (fin, capName);

    c[i].stID = capName.substr (00, 02);
    c[i].stName = capName.substr (04, 14);
    c[i].stCap = capName.substr (20, 14);

    i++;
  }

  fin.close();
}

void putAdmData (Adm* start, Cap* c)
{
  Adm* a;
  int age;
  cout << endl;
  cout << "           A  d  m" << endl;
  cout << "           -------" << endl;
  cout << "  Ord  St  Year Mo  Age  Name             Capital" << endl;
  cout << "  ---  --  ---- --  ---  ---------------  ---------------" << endl;
  for (a = start; a ; a = a->next)
  {
    cout.fill('0');
    cout << "   " << setw(2) << a->ord << "  " << a->stID << "  "  << setw(4) << a->admYr << " ";
    cout << setw(2) << a->admMo;
    age = calcAge(a);
    cout << right;
    cout.fill(' ');
    cout << " " << setw(4) <<  age;
    putCapData(a , c);    
    cout << endl;
  } 
    
}

//----------------------------------------------
//level-2
//----------------------------------------------


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

void putCapData(Adm* a, Cap* c)
{
  int i;

  string stName;
  string stCap;

  stName = "Unknown       ";
  stCap  = "UnKnown";

  for(i = 0; i < SIZE; i++)
  {
    if(a->stID == c[i].stID)
    {
      stName = c[i].stName; 
      stCap = c[i].stCap;
    }
  }
  cout << "  " << stName << "   " << stCap;
}