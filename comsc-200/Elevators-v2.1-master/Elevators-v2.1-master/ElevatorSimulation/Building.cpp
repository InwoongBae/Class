//Programmer: Dhanush Patel
//Programmer ID: 1553428

#include "Building.h"
#include "Floor.h"
#include "Elevator.h"

#include <iostream>
using namespace std;

#include <cstdlib>
#include <cmath>

Floor Building::floors[] = 
{
  Floor(0, "First Floor", "1"), 
  Floor(100, "Second Floor", "2"),
  Floor(200, "Third Floor", "3"),
  Floor(305, "Fourth Floor", "4"),
  Floor(410, "Fifth Floor", "5")
}; 
const int Building::FLOORS = sizeof(floors) / sizeof(Floor);

Elevator Building::elevators[] =
{
  Elevator(12, 5, 0),
  Elevator(12, 5, 1),
  Elevator(12, 5, 2)
};
const int Building::ELEVATORS = sizeof(elevators) / sizeof(Elevator);

void Building::getDifferentInts(int& a, int& b)
{
  do 
  {
    a = rand() % FLOORS; // range is 0 to (FLOORS-1)
    b = rand() % FLOORS; // range is 0 to (FLOORS-1)    
  } while (a == b); // try again if they are the same
}

int Building::getPoisson(double avg)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-avg); // requires cmath
  for(double randomValue = (rand() % 1000) / 1000.0; // requires cstdlib
    (randomValue -= probOfnArrivals) > 0.0; 
    probOfnArrivals *= avg / ++arrivals);
  return arrivals;
}

void Building::placeNewRiders(double arrivalsPerSecond)
{
  int n = getPoisson(arrivalsPerSecond);
  for (int i = 0; i < n; i++)
  {
    int from, to;
    getDifferentInts(from, to);
    Rider rider(from, to);
    floors[from].addRider(rider);
  }
}

bool Building::openDoorToDisembarkRider(int e)
{
  // if closed and floor button is lit...
  //...and there are riders to disembark, open door
  if (!elevators[e].isOpen())
    for (int f = 0; f < FLOORS; f++)
      if (floors[f] == elevators[e] && 
          elevators[e].panel.isLit(floors[f].label))
        {
          elevators[e].openDoorTo(f);
          return true;
        }
  return false;
}

void Building::action(double arrivalsPerSecond)
{
  placeNewRiders(arrivalsPerSecond);
  
  // one action per elevator
  for (int e = 0; e < ELEVATORS; e++)
  {
    if (openDoorToDisembarkRider(e)) continue; // lab 8
    if (disembarkRider(e)) continue; // lab 9
    if (boardRider(e)) continue; // lab 9
    //if (waitingForMoreRiders(e)) continue; // lab 12
    //if (doneWaitingMove(e)) continue; // lab 12
    //if (moveableMove(e)) continue; // lab 14
    //if (setIdleElevatorInMotion(e)) continue; // lab 15
    //if (sendIdleElevatorToCallingFloor(e)) continue; // lab 15
    //elevators[e].goIdle(); // nothing to do  
  }
}

bool Building::disembarkRider(int e) // lab 9
{
  // if open and rider to disembark, do that
  if (elevators[e].isOpen() && elevators[e].hasRiderForFloor())
  {
    elevators[e].removeRider();
    return true;
  }
  return false;
}

bool Building::boardRider(int e) // lab 9
{
  // if door is open and not full and rider to load, load
  if (elevators[e].isOpen() && !elevators[e].isFull())
  {
    Floor& floor = floors[elevators[e].getFloorIndex()];
    if (elevators[e].goingUp() && floor.hasUpRider())
    {
      Rider rider = floor.removeUpRider();
      elevators[e].board(rider);
      return true;
    }
    else if (elevators[e].goingDown() && floor.hasDownRider())
    {
      Rider rider = floor.removeDownRider();
      elevators[e].board(rider);
      return true;
    }
  }
  return false;
}





