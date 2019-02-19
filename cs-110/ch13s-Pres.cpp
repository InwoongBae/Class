/*
  Chapter: 13
  Program: Ch13s-Pres
  Author : Inwoong Bae
  Date   : 4/20/2015
  Purpose: provide sample of program that:
           -- works with list represented as array
           -- edits, justifies and fills console output
           -- reviews topics including arrays, file input, functions, comparisons, and sorting

  Problem: Input file of american president, put contents into list, output list to console with some editing
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct Pres
{
  int    ord;     //Ordinal number of presidency
  string lname;   //Last name
  string fname;   //First name
  string mname;   //Middle name
  string birStID; //birth state Id of president
  int    birYr;   //birth year
  int    birMo;   //birth month

  int    begYr;   //beginning year  in office
  int    begMo;   //beginning month in office
};
  
const int SIZE = 50; //Maximum array size

void   putHead();
string getName();
int    getPres(string, Pres*);
void   putPres(int   , Pres*);

int main()
{
  string ifName;    //name of input file
  int    count;     //count of records
  Pres   p[SIZE];   //List of presidents as array

  putHead();

  ifName = getName();

  count = getPres(ifName, p);

  putPres(count , p);
}

void putHead()
{
  cout << "\n  President Program  \n";
  cout.fill('-');
  cout << "  " << setw(55) << "-" << "\n\n";
}

string getName()
{
  string ifName;
  cout << "  Input File Name ";
  cin >> ifName;
  return ifName;
}  

int getPres(string ifName, Pres* p)
{
  ifstream fin;   //File object
  int      count; //Record count
  int      i;     //List index

  fin.open(ifName);

  i = 0;

  while(fin.good())
  {
    fin >> p[i].ord;
    fin >> p[i].lname;
    fin >> p[i].fname;
    fin >> p[i].mname;
    fin >> p[i].birStID;
    fin >> p[i].birYr;
    fin >> p[i].birMo;
    fin >> p[i].begYr;
    fin >> p[i].begMo;

    fin.ignore(1000, 10);

    i++;
  }

  fin.close();

  count = i;

  return count;

}

void putPres(int count, Pres* p)
{
  int i;
  int begAge;

  cout << "                                     Born         Began  " << endl;
  cout << "                                     -----------  -------" << endl;
  cout << "  Ord  Last Name   First Name  Mid   St  year Mo  year Mo" << endl;
  cout << "  ---  ----------  ----------  ----  --  ---- --  ---- --" << endl;
  
  for(i = 0; i < count; i++)
  {
    cout.fill('0');
    cout << right;
    cout << "  " << setw(3) << p[i].ord;
    cout << left;
    cout.fill(' ');
    cout << "  " << setw(10) << p[i].lname;
    cout << "  " << setw(10) << p[i].fname;

    if (p[i].mname == ".")
      p[i].mname = " "; 
    cout << "  " << setw(04) << p[i].mname << "  " << p[i].birStID;
    cout.fill('0');
    cout << right;
    cout << "  " << setw(4) << p[i].birYr;
    cout << " " << setw(2) << p[i].birMo << "  " << setw(4) << p[i].begYr << " " << setw(2) << p[i].begMo << endl;
  }
}