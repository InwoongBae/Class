/*
  Chapter: 11 
  Program: Ch11b-Home-Bae-Inwoong.cpp 
  Author : Inwoong Bae
  Date   : 4/9/2015

  Purpose: Provide assignment similar to first program          
           related to same chapter, but with additional
           requirements below
  Problem:

  -- subdivide level-1 one function that processes records 
      -  procRec() - into several level-2 functions:
  
      -- output records      - putRec (...)
      -- sort   records      - sortRec(...)
      -- output averages     - putAvg (...)
      -- output median (new) - putMed (...)

  -- related notes

      -- move some variable declarations and logic 
         from "procRec" to lower-level functions


      -- from "procRec", pass (by value) integer 
         variable "count" to all other 
         lower-level functions

      -- from "procRec" function, pass (by 
         reference) arrays for area and price, 
         or just price, or totals, where needed


      -- here are additional prototypes that your 
         program will need (besides those already
         in program Ch11a on which Ch11b is based):


  void putRec (int, double*, double*);
  void sortRec(int, double*, double*);
  void putAvg (int, double,  double);
  void putMed (int, double*);

    -- below are related level-2 function headers
       (the extra spacing between parameters is not 
       required, but is used to align similar items 
       for ease of reading here):


  void putRec (int count, double*   area, double*   price)
  void sortRec(int count, double*   area, double*   price)
  void putAvg (int count, double totArea, double totPrice)
  void putMed (int count,                 double*   price)


    -- download and process 2 sets of input files
        -- Ch11b-Home-Odd.txt
        -- Ch11b-Home-Even.txt
*/


#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void   putHead();
string getName();
void   procRec(string);
void   putRec(int* , int*, int);
void   sortRec(int*, int*, int);
void   putAvg(int, int, int);
void   putMed (int, int*);



int main()
{
  string name;       // File name
  
  putHead();         // output header

  name = getName();  // input file name

  procRec(name);     // process records
}

void putHead()
{
  cout << endl;
  cout << "  Home Market Program" << endl;
  cout << "  -------------------------------------" << endl;
}

string getName()
{
  string name; 
  cout << "  File name? ";
  cin >> name;
  return name;
} 

void procRec(string name)
{

  const int SIZE = 15;

  ifstream fin;
  int i;
  int price[SIZE];
  int area[SIZE];
  int totArea = 0;
  int totPrice = 0;

  fin.open(name);
  
  i = 0;

  while(fin.good())  // input record values, store in array
  {
      fin >> area[i];
      fin >> price[i];
      totArea = totArea + area[i];
      totPrice = totPrice + price[i];

      i++;
  }

  cout << endl;
  cout << "  Rec list  :  Unsorted ascending by price" << endl;
  cout << "  Rec        Area    Price  " << endl;
  cout << endl;
  cout << "  ---       -----  -------  " << endl;

  int count;

  count = i;

  putRec(area, price, count);

  sortRec(price, area, count);

  cout << endl;
  cout << "  Rec list  :  Sorted ascending by price" << endl;
  cout << "  Rec        Area    Price  " << endl;
  cout << endl;
  cout << "  ---       -----  -------  " << endl;

  putRec(area, price, count);

  putAvg(totArea, totPrice, count);

  putMed(count, price);

}

void putRec(int* area, int* price, int count)
{
    for(int i = 0 ; i < count ; i++)  // output array values
  {
    cout << "  " << setw(3) << i << "       " << setw(5) << area[i] << "  "<< setw(7) << price[i] << endl;
  } 
}
void sortRec(int* price, int* area, int count)
{
  double temp;

    for(int i = 0 ; i < count ; i++) // sort array values
  {
    for(int j = i+1 ; j < count ; j++)
    {
      if(price[i] > price[j])
      {
        temp = price[i];
        price[i] = price[j];
        price[j] = temp; 

        temp = area[i];
        area[i] = area[j];
        area[j] = temp; 
      }
    }
  }
}
void putAvg(int totArea, int totPrice, int count)
{
  int avgAreaPrice = totPrice / totArea;
  int avgHomePrice = totPrice / count;

  cout << "  ---       -----  -------  " << endl << endl;
  cout << "  " << setw(3) << count << "       " << setw(5) << totArea << "  " << setw(7) << totPrice << endl;
  cout << endl; 
  cout << "  Avg Area Price:   " << setw(6) << avgAreaPrice << endl;
  cout << "  Avg Home Price:   " << setw(6) << avgHomePrice << endl;
} 
void putMed (int count, int*   price)
{
  if(count % 2 == 1)
  cout << "  " << "Med Home Price: " << " " << setw(7) << price[count/2];
  else
  cout << "  " << "Med Home Price: " << " " << setw(7) << ((price[count/2-1]+price[count/2])/2);
}