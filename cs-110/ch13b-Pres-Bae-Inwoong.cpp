/*
  Chapter: 13
  Program: Ch13b-Pres-Bae-Inwoong.cpp
  Author : Inwoong Bae
  Date   : 4/20/2015
  Purpose: Similar to ch13a, but also review data validation, array processing, function creation and usage, and data sorting

  Problem: Similar to ch13a assignment, but also:
           -- modifiy end of structure "Pres" to include field "begAge" for beginning age
           -- in existing function "getName" use loop to validate input file name, until either name is valid, or user cancels with ctrl-c
              if file with entered name is invalid, sound audible alert, display error message, and ask user to try again

           -- in function "getPres" (not in "putPres"),  call function "calcAge", then store value "begAge" in array (do not output it yet)

           -- create new level-one (called from main) function "sortPres" that will not return and value, but that will accept "count" and "p" as 
              parameters, and that will sort array data by "begAge" in descending order (oldest to youngest)

              declare prototype and function header for "sortPres" in "main", call "sortPres" before call to "putpres" in "sortPres", use only one "if"
              statement that compares one "begAge" in array with another; when approriate to move "begAge" in array, also move all other fields in same element

           -- create new level-one function "putFoot" (to output footer) that returns no value, that accepts "count" and "p" as parameters, and that at end of
              processing, identifies
              -- oldest president to enter white House
              -- youngest president 
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

  int    begAge;  //beginning age   in office
};
  
const int SIZE = 50; //Maximum array size

void   putHead();
string getName();
int    getPres(string, Pres*);
void   sortPres(int  , Pres*);
void   putPres(int   , Pres*);
void   putFoot(int   , Pres*);
int    calcAge(int   , Pres*);

int main()
{
  string ifName;    //name of input file
  int    count;     //count of records
  Pres   p[SIZE];   //List of presidents as array

  putHead();

  ifName = getName();

  count = getPres(ifName, p);

  sortPres(count , p);

  putPres(count , p);

  putFoot(count , p);
}

void putHead()
{
  cout << "\n  President Program  \n";
  cout.fill('-');
  cout << "  " << setw(55) << "-" << "\n\n";
}

string getName()
{
  ifstream fin;   //File object
  string ifName;
  while(true)
  {
    cout << "  Input File Name ";
    cin >> ifName;
    fin.open(ifName);
    if(fin.good())
    {
      fin.close();    
      break;
    }
    else
    {
      cout << '\a';
      cout << "  Error, try again";
      cout << endl;
    }
  }
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

    p[i].begAge = calcAge(i , p);

    fin.ignore(1000, 10);

    i++;
  }

  fin.close();

  count = i;

  return count;

}

void sortPres(int count, Pres* p)
{
  int i;
  int j;
  int tempInt;
  string tempStr;

  for (i = 0; i < count; i++)
  {
    for (j = i + 1; j < count; j++)
    {
      if(p[i].begAge < p[j].begAge)
      {
        tempInt = p[i].ord;

        p[i].ord = p[j].ord;

        p[j].ord = tempInt;

        tempStr = p[i].lname;

        p[i].lname = p[j].lname;

        p[j].lname = tempStr;

        tempStr = p[i].fname;

        p[i].fname = p[j].fname;

        p[j].fname = tempStr;

        tempStr = p[i].mname;

        p[i].mname = p[j].mname;

        p[j].mname = tempStr;

        tempStr = p[i].birStID;

        p[i].birStID = p[j].birStID;

        p[j].birStID = tempStr;

        tempInt = p[i].birYr;

        p[i].birYr = p[j].birYr;

        p[j].birYr = tempInt;
      
        tempInt = p[i].birMo;

        p[i].birMo = p[j].birMo;

        p[j].birMo = tempInt;

        tempInt = p[i].begYr;

        p[i].begYr = p[j].begYr;

        p[j].begYr = tempInt;

        tempInt = p[i].begMo;

        p[i].begMo = p[j].begMo;

        p[j].begMo = tempInt;

        tempInt = p[i].begAge;

        p[i].begAge = p[j].begAge;

        p[j].begAge = tempInt;
      }
    } 
  }
}

void putPres(int count, Pres* p)
{
  int i;
  int begAge;

  cout << "                                     Born         Began  " << endl;
  cout << "                                     -----------  -------" << endl;
  cout << "  Ord  Last Name   First Name  Mid   St  year Mo  year Mo Age" << endl;
  cout << "  ---  ----------  ----------  ----  --  ---- --  ---- -- ---" << endl;
  
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
    cout << " " << setw(2) << p[i].birMo << "  " << setw(4) << p[i].begYr << " " << setw(2) << p[i].begMo;
    calcAge(i , p);
    cout.fill(' ');
    cout << " " << setw(3) << p[i].begAge << endl;;  
  }
}

void putFoot(int count, Pres* p)
{
  cout << "  Oldest   president at " << p[0].begAge << " is " << p[0].lname << "    ,  " << p[0].fname <<endl;
  cout << "  Youngest president at " << p[count-1].begAge << " is " << p[count-1].lname << " ,  " << p[count-1].fname << endl;
}

//=========
//level 2
//---------

int calcAge(int i, Pres* p)
{
  if(p[i].birMo < p[i].begMo || p[i].birMo == p[i].begMo)
  p[i].begAge = p[i].begYr - p[i].birYr;
  else
  p[i].begAge = p[i].begYr - p[i].birYr - 1;

  return p[i].begAge;
}
