/*
  Chapter: 16
  Program: Pr16a-Chance-Bae-Inwoong.cpp
  Author : Inwoong Bae
  Date   : 5/11/2015

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

struct Reality
{
  int closeYr;
  int closeMo;
  int closeDy;
  string propCode;
  int buildYr;
  int area;
  int price;
};

const int SIZE = 100;

void putHead();
string getName();
int getMo();
int getData(int, string, Reality*);
void sortData(int, Reality*);
void putData(int, int, Reality*);
void putAvg(int, int, Reality*);

int main()
{
  string fileName;
  int closeMo;
  Reality arr[SIZE];
  int count;
  char more;

  fileName = getName();
  closeMo = getMo();
  putHead();
  count = getData(closeMo, fileName, arr);
  sortData(count, arr);
  putData(count, closeMo, arr);
  putAvg(count, closeMo, arr);
  
  while(true)
  { 
    cout << "  More (Y or N) ? " ;
    cin >> more;
    if(toupper(more) == 'Y' )
    {     
      closeMo = getMo();
      putHead();
      count = getData(closeMo, fileName, arr);
      sortData(count, arr);
      putData(count, closeMo, arr);
      putAvg(count, closeMo, arr);
    }
    else if(toupper(more) == 'N')
      break;
    else
    {
      cout << "  Invalid; try again" << endl;
    }
  }
}

void putHead()
{
  cout << endl;
  cout << "  Realty Program" << endl;
  cout << "  ----------------------------------------------   " << endl;
  cout << "   C l o s e   " << endl;
  cout << "  ----------  Prop     Build  " << endl;
  cout << "    Yr Mo Dy  Code        Yr  Age  Area    Price   " << endl;
  cout << "  ---- -- --  --------  ----  ---  ----  -------   " << endl;
}

string getName()
{
  string fileName;
  ifstream fin;
  while(true)
  {
    cout << "  File name  ? "; 
    cin >> fileName;
    fin.open(fileName);
  
    if(fin.good())
    {
      fin.close();
      break;
    }
    else
    {
      cout << '\a';
      cout << "  Invalid; try again" << endl;  
    }
  }
  return fileName;
}

int getMo()
{
  int intMo;
  string strMo;

  while(true)
  {
    cout << "  Close month? ";
    cin >> intMo;
    if(intMo > 0 && intMo < 13)
    {
      switch(intMo)
      {
        case 1 : strMo = "Jan"; break;
        case 2 : strMo = "Feb"; break;
        case 3 : strMo = "Mar"; break;
        case 4 : strMo = "Apl"; break;
        case 5 : strMo = "May"; break;
        case 6 : strMo = "Jun"; break;
        case 7 : strMo = "Jul"; break;
        case 8 : strMo = "Aug"; break;
        case 9 : strMo = "Sep"; break;
        case 10 : strMo = "Oct"; break;
        case 11 : strMo = "Nov"; break;
        case 12 : strMo = "Dec"; break;
        default : strMo = "???"; break;
      }
      break;
    }
    else
    { 
      cout << '\a';
      cout << "  Invalid; try again" << endl;
    }
  }
  cout << "  Close month: " << strMo;

  return intMo;
}

int getData(int closeMo ,string fileName, Reality* arr)
{
  ifstream fin;
  int i;

  fin.open(fileName);

  i = 0;

  fin.ignore (1000, 10); // Discard first record

  while(fin.good())
  {
    fin >> arr[i].closeYr;
    fin >> arr[i].closeMo;
    if(arr[i].closeMo == closeMo)
    {
      fin >> arr[i].closeDy;
      fin >> arr[i].propCode;
      fin >> arr[i].buildYr;
      fin >> arr[i].area;
      fin >> arr[i].price;
      i++;
    }
    else
      fin.ignore (1000, 10); // ignore the other data


  }
  
  fin.close();

  return i;
}

void sortData(int count, Reality* arr)
{
  int i;
  int j;
  Reality temp;

  for(i = 0;i < count; i++)
  {
    for(j = i+1; j < count; j++)
    {
      if(arr[i].price > arr[j].price)
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void putData(int count, int closeMo, Reality* arr)
{
  for(int i = 0; i < count; i++)
  {
    if(arr[i].closeMo == closeMo)
    {
      cout.fill(' ');
      cout << right;
      cout << "  " << setw(4) << arr[i].closeYr << " " << setw(2) << arr[i].closeMo << " " << setw(2) << arr[i].closeDy << "  " << arr[i].propCode << "  " << arr[i].buildYr << "  ";
      cout << setw(3) << arr[i].closeYr - arr[i].buildYr << "  " << setw(4) << arr[i].area << "  " <<  setw(7) <<  arr[i].price << endl; 
    } 
  } 
}

void putAvg(int count, int closeMo, Reality* arr)
{
  int sumAge = 0;
  int sumPrice = 0;
  int sumArea = 0;
  double avgArea;
  double avgAge;
  double avgPrice;

  for(int i = 0; i < count; i++)
  {
    if(arr[i].closeMo == closeMo)
    {
      sumAge = sumAge + arr[i].closeYr - arr[i].buildYr;
      sumArea = sumArea + arr[i].area;
      sumPrice = sumPrice + arr[i].price; 
    }
  }

  avgAge = sumAge/count;
  avgArea = sumArea/count;
  avgPrice = sumPrice/count;

  
  cout << "  Average:                     " << avgAge << "  " <<avgArea << "   " << avgPrice << endl;                     
}

