//Programmer: Dhanush Patel
//Programmer ID: 1553428

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <cstdlib>
#include <ctime>
#include "StdAfx.h"
#include "Rider.h"
#include "Building.h"
#include "Floor.h"
#include "Panel.h"

int main()
{
  srand(time(0)); rand();
 
  cout << "Programmer: Dhanush Patel\n";
  cout << "Programmer's ID: 1553428\n";
  cout << "File: " << __FILE__ << "\n\n";

  for (int i = 0;; i++)
  { 
    cout << "-----------------------------------------------\n";
    cout << "-- Time " << i << " ---------------------------\n";
    for (int elevator = 0; elevator < Building::ELEVATORS; elevator++)
       cout << Building::elevators[elevator] << endl;

    for (int floor = 0; floor < Building::FLOORS; floor++)
       cout << Building::floors[floor] << endl;
     
    double myArrivalRate = 1.0;
    Building::action(i < 300 ? myArrivalRate : 0);
 
    cin.get();
  }
}