/*
  Chapter: 11
  program: Ch11a-Home-Bae-Inwoong.cpp
  Author : Inwoong Bae
  Date   : 4/8/2015

  Purpose: To provide assignment similar to related sample program, but with additional requirements below
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void   putHead();
string getName();
void   procRec(string);

void   putRec(int*);

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
  int j;
  int price[SIZE];
  int area[SIZE];
  int totArea = 0;
  int totPrice = 0;
  int avgAreaPrice;
  int avgHomePrice;
  double temp;

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

  int count;

  count = i;

  for(i = 0 ; i < count ; i++) // sort array values
  {
    for(j = i+1 ; j < count ; j++)
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

  cout << endl;
  cout << "  Rec list  :  Sorted ascending by price" << endl;
  cout << "  Rec        Area    Price  " << endl;
  cout << endl;
  cout << "  ---       -----  -------  " << endl;

  cout << fixed << showpoint << setprecision(2); 
  
  for(i = 0 ; i < 9 ; i++)  // output array values
  {
    cout << "  " << setw(3) << i << "       " << setw(5) << area[i] << "  "<< setw(7) << price[i] << endl;
  }
  cout << "  ---       -----  -------  " << endl << endl;
  cout << "  " << setw(3) << i << "       " << setw(5) << totArea << "  " << setw(7) << totPrice << endl;

  avgAreaPrice = totPrice / totArea;
  avgHomePrice = totPrice / count;

  cout << endl; 
  cout << "  Avg Area Price:   " << setw(6) << avgAreaPrice << endl;
  cout << "  Avg Home Price:   " << setw(6) << avgHomePrice << endl;

}

void putRec(price[])
{
  

}