/*
  Chapter: 11
  program: Ch11s-Home-Bae-Inwoong.cpp
  Author : Inwoong Bae
  Date   : 4/6/2015

  Purpose: Provide sample program that uses and sorts array
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void   putHead();
string getName();
void   procRec(string);

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
  ifstream fin;
  int i;
  int j;
  int price[9];
  double temp;

  fin.open(name);
  
  while(fin.good())  // input record values, store in array
  {
    for(i = 0 ; i < 9 ; i++)
    { 
      fin >> price[i];
    }
    
  }

  for(i = 0 ; i < 9 ; i++) // sort array values
  {
    for(j = i+1 ; j < 9 ; j++)
    {
      if(price[i] > price[j])
      {
        temp = price[i];
        price[i] = price[j];
        price[j] = temp; 
      }
    }
  }
  cout << endl;
  cout << "  Rec list  :  Sorted ascending by price" << endl;
  cout << "  Rec    Price  " << endl;
  cout << endl;
  cout << "  ---  -------  " << endl;

  cout << fixed << showpoint << setprecision(2); 
  
  for(i = 0 ; i < 9 ; i++)  // output array values
  {
    cout << "  " << setw(3) << i << "  " << setw(7) <<  price[i] << endl;
  }

}