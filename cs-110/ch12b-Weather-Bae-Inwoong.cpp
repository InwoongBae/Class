/*
Chapter: 12
Program: Ch12a-Weather-Bae-Inwoong.cpp
Author : Inwoong Bae
Date   : 04/13/2015

Problem: Similar to the assignment ch12a

         -- create 'struct weatheryear" with same layout as "struct Weather" except remove "mon" 
            field(since this new structure will hold weather data summarized by year)

         -- declare prototype and header for function "sumYear", to summarize weather records by year 
            with integer "count" (of years) to return, and with parameters   
            -- integer "count" (passed by value)
            -- weatherYear "y" (passed by reference)
            -- weather "w"     (passed by reference)

         -- declare prototype and header for function "putYear", to output weather records by year with no return value, but with parameters
            -- integer "count" (passed by value)
            -- weatheryear "y" (passed by reference)

         -- in "main"
            -- declare array "y" based on "WeatherYear"
            -- call "sumRec" and pass "count", "w" and "y"

         -- in "sumYear"
            -- declare, initialize and accumulate total rain and total temperature per year
            -- calculate average temperature per year
            -- return count of years

         -- in "putYear"
            -- output years, total rain and average temperature
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

struct WeatherYear
{
  string loc;
  string year;
  double rain;
  double temp; 
};

void    putHead();
string  getName();
int     getCount();
void    getRec (string, int, Weather*);
void    putRec (int, Weather*);
int     sumYear(int, Weather*, WeatherYear*);
void    putYear(int, WeatherYear*);


int main()
{
  string  name;      // name  of input file
  int     count;     // count of input records
  Weather* w;        // array of weather data
  WeatherYear* y;    // array of WeatherYear data

  putHead();

  name = getName();

  count = getCount();

  w = new Weather[count];

  getRec(name, count, w);

  putRec(count, w);

  y = new WeatherYear[count];

  count = sumYear (count, w, y);

  putYear(count, y);
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

void  getRec(string name, int count, Weather* w)
{
  ifstream fin;
  fin.open(name);
  int i;

  while(fin.good())
  {
    for(i = 0; i < count; i++)
    {
      fin >> w[i].loc;
      fin >> w[i].year;
      fin >> w[i].month;
      fin >> w[i].rain;
      fin >> w[i].temp;
    }
  }
}

int sumYear (int count, Weather* w, WeatherYear* y)
{
  int i;
  int j;
  
  double totRain;
  double totTemp;
 
  string oldYear;

  int countYear;

  totRain = 0.0;
  totTemp = 0.0;

  j = 0; // Initialize index for weatheryear

  oldYear = w[0].year; // Initialize prior year  

  for(i = 0; i < count; i++)
  {
    if (w[i].year == oldYear)
    {
      totRain = totRain + w[i].rain;
      totTemp = totTemp + w[i].temp;
    }
    else
    {
      y[j].year = oldYear;
      y[j].rain = totRain;
      y[j].temp = totTemp / 12;

      oldYear = w[i].year;
      totRain = w[i].rain;
      totTemp = w[i].temp;

      j++;
    }
  }
  y[j].year = oldYear;
  y[j].rain = totRain;
  y[j].temp = totTemp / 12;

  countYear = count / 12;

  return countYear;
}

void putRec(int count, Weather* w)
{
  cout << endl;
  cout << "  Detail by month" << endl;
  cout << "  ----------------------------" << endl;
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

void putYear(int count, WeatherYear* y)
{
  cout << endl;
  cout << "  Summary by Year" << endl;
  cout << "  ----------------------------" << endl;
  cout << "                    Tot    Avg" << endl;
  cout << "       Year        Rain   Temp" << endl;
  cout << "       ----        ----   ----" << endl;

  for (int i = 0; i < count ; i++)
  {
    cout << "       " << y[i].year << "       " << fixed << showpoint << setprecision(2) << setw(5) << y[i].rain << "  "; 
    cout << setw(5) << fixed << showpoint << setprecision(1) << y[i].temp << endl;
  }

}