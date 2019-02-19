/*
Chapter: 12
Program: Ch12s-Weather.cpp
Author : Inwoong Bae
Date   : 04/13/2015

Purpose: provide sample program with "struct" array passed by reference among functions

Problem: Download and process small file of weather data called "ch12s-weather.txt" (with just 12 months of rainfall totals and mean(average) temperatures)
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
int     getRec (string, Weather*);
void    putRec (int   , Weather*);

const int SIZE = 24;

int main()
{
  string  name;      // name  of input file
  int     count;     // count of input records
  Weather w[SIZE];   // array of weather data

  putHead();

  name = getName();

  count = getRec(name, w);

  putRec(count, w);

}

void putHead()
{
  cout << endl;
  cout << "  Weather Program" << endl;
  cout << "  -------------------------------------" << endl;
  cout << "  This program will display monthly" << endl;
  cout << "  rainfall totals and mean temperatures" << endl;
  cout << endl;
}

string getName()
{
  string name; 
  cout << "  Name of input file? ";
  cin >> name;
  return name;
}

int getRec(string name, Weather* w)
{
  ifstream fin;
  fin.open(name);
  int i = 0;
  int count;

  while(fin.good())
  {
    fin >> w[i].loc;
    fin >> w[i].year;
    fin >> w[i].month;
    fin >> w[i].rain;
    fin >> w[i].temp;
    i++;  
  }
  
  count = i;

  return count;

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