// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#include "Building.h"
#include "Floor.h"
#include "Elevator.h"

#include <iostream>
using namespace std;

#include <cstdlib>
#include <cmath>

Floor Building::floors[] = 
{
  Floor(0, "Garage Floor", "G"),  
  Floor(100, "Main Floor", "A"), 
  Floor(200, "Second Floor", "2"),
  Floor(300, "Third Floor", "3"),
  Floor(400, "Fourth Floor", "4"),
  Floor(500, "Fifth Floor", "5"),
}; 
const int Building::FLOORS = sizeof(floors) / sizeof(Floor);

Elevator Building::elevators[] =
{
  Elevator(30, 5, 0), // capacity, speed, start floor
  Elevator(25, 10, 1),
  Elevator(20, 15, 3),
  Elevator(15, 20, 4),
  Elevator(10, 25, 5),
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

void Building::action(double arrivalsPerSecond)
{
  placeNewRiders(arrivalsPerSecond);
  
  // one action per elevator
  for (int e = 0; e < ELEVATORS; e++)
  {
    if (openDoorToDisembarkRider(e)) continue; // step 1 of 9
    if (disembarkRider(e)) continue; // step 2 of 9
    if (boardRider(e)) continue; // step 3 of 9
    if (waitingForMoreRiders(e)) continue; // step 4 of 9
    if (doneWaitingMove(e)) continue; // step 5 of 9
    if (moveableMove(e)) continue; // step 6 of 9
    if (setIdleElevatorInMotion(e)) continue; // step 7 of 9
    if (sendIdleElevatorToCallingFloor(e)) continue; // step 8 of 9
	elevators[e].goIdle();
  }
}

void Building::placeNewRiders(double arrivalsPerSecond) {
  int n = getPoisson(arrivalsPerSecond);
  for (int i = 0; i < n; i++) {
    int from, to;
    getDifferentInts(from, to);
    Rider rider(from, to);
    floors[from].addRider(rider);
  }
}

bool Building::openDoorToDisembarkRider(int e)
{
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

bool Building::disembarkRider(int e)
{
  // if open and rider to disembark, do that
  if (elevators[e].isOpen() && elevators[e].hasRiderForFloor())
  {
    elevators[e].removeRider();
    return true;
  }
  return false;
}

bool Building::boardRider(int e) 
{
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

bool Building::waitingForMoreRiders(int e)
{ //isIdle or goingUp/Down - diff
  if(elevators[e].isOpen() && (elevators[e].goingDown() || elevators[e].goingUp()) && !elevators[e].timedOut()){
    elevators[e].tickTimer();
    return true;
  }
  return false;
}

bool Building::doneWaitingMove(int e)
{
  if(!elevators[e].isOpen() || elevators[e].isIdle() || !elevators[e].timedOut()){ 
    return false;
  }
  else{
    elevators[e].closeDoor();
    elevators[e].move();
    return true;
  }
}

bool Building::moveableMove(int e) 
{
  if(elevators[e].isOpen() || elevators[e].isIdle())
  {
    return false;
  }
  else
  {
    return elevators[e].move();
  }
}

bool Building::setIdleElevatorInMotion(int e)
 {
  if (!elevators[e].isIdle())
  {
    return false;
  }
  else {
    for (int i = 0; i < Building::FLOORS; i++)
     {
      if (elevators[e] != floors[i])
      {
        continue;
      }
      if (floors[i].panel.getFirstLit() == Floor::UP) { //const not string - diff
        elevators[e].openDoorTo(i);
        elevators[e].setDirectionUp();
        return true;
      }
      else if (floors[i].panel.getFirstLit() == Floor::DOWN) {
        elevators[e].openDoorTo(i);
        elevators[e].setDirectionDown();
        return true;
      }
    }
  }
  return false;  
}

bool Building::sendIdleElevatorToCallingFloor(int e)
 {
  if (!elevators[e].isIdle())
  {
    return false;
  }
  else 
  {
    for (int i = 0; i < Building::FLOORS; i++)
     {
      if (!Building::floors[i].panel.areAnyLit())
      {
        continue;
      }
      if (floors[i] > elevators[e]) 
      {
        elevators[e].setDirectionUp();
        elevators[e].move();
        return true;
      }
      else if (floors[i] < elevators[e]) 
      {
        elevators[e].setDirectionDown();
        elevators[e].move();
        return true;
      }
    }
  }
  return false; 
}