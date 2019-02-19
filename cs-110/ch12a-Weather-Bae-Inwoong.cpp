/*
Chapter: 12
Program: Ch12a-Weather-Bae-Inwoong.cpp
Author : Inwoong Bae
Date   : 04/13/2015

Problem: Similar to the simple program

         -- remove constant size

         -- change "getRec" function from "int" to "void"
            type, and do NOT return "count" from it

         -- after prototype and header for "getRec"
            function, declare prototype and header for
            "getCount" that returns integer "count"

         -- in "main" after "getRec", call "getCount",
            and assign returned value to variable "count"

         -- in "getCount", prompt user to enter count
            of records to process, then input value to
            variable "count", and return that value

         -- in "main", move declaration of weather array
            from before to after count is determined, then
            change "SIZE" of weather array from fixed size
            to dynamic "count"

         -- download and process larger file of weather
            data called "Ch12a-Weather.txt" (with 600
            months of data)

         -- try processing data for different counts of
            months (up thru 600)
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct Weather
{
  string loc;
  string year;
  string month;
  double rain;
  double temp; 
};

void    putHead();
string  getName();
int     getCount();
void    getRec (string, int ,Weather*);
void    putRec (int   , Weather*);


int main()
{
  string  name;      // name  of input file
  int     count;     // count of input records
  Weather* w;        // array of weather data

  putHead();

  name = getName();

  count = getCount();

  w = new Weather[count];

  getRec(name, count, w);

  putRec(count, w);

}

void putHead()
{
  cout << endl;
  cout << "  Weather Program" << endl;
  cout << "  -------------------------------------" << endl;
  cout << "  This program will display monthly" << endl;
  cout << "  rainfall totals and mean temperatures" << endl;
  cout << "  by location" << endl;
  cout << endl;
}

string getName()
{
  string name; 
  cout << "  Name  of input file? ";
  cin >> name;
  return name;
}

int getCount()
{
  int count;
  cout << endl;
  cout << "  Count of records   ? ";
  cin >> count;
  return count;
}

void  getRec(string name,int count, Weather* w)
{
  ifstream fin;
  fin.open(name);
  int i = 0;

  while(fin.good())
  {
    for(i = 0; i < count ; i++)    
    {
      fin >> w[i].loc;
      fin >> w[i].year;
      fin >> w[i].month;
      fin >> w[i].rain;
      fin >> w[i].temp;
    }  
  }
}

void putRec(int count, Weather* w)
{
  cout << endl;
  cout << "  Loc  year  Mon   Rain   Temp" << endl;
  cout << "  ---  ----  ---  -----  -----" << endl;
  cout << endl;

  for (int i = 0; i < count ; i++)
  {
    cout << fixed << showpoint << setprecision(2);
    cout << "  " << w[i].loc << "  " << w[i].year << "  " << w[i].month << "   " << setw(5) << w[i].rain << "  ";
    cout << fixed << showpoint << setprecision(1);
    cout << setw(5) << w[i].temp << endl; 

  }
}