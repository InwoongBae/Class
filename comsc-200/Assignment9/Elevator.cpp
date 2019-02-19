// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#include "Elevator.h"
#include "Panel.h"
#include "Building.h"

#include <iostream>
#include <vector>
using namespace std;

#include <cstdlib>

Elevator::Elevator(unsigned int capacity, int speed, int start)
:speed(speed), CAPACITY(capacity), direction(IDLE), atFloorIndex(-1), location(Building::floors[start]), timer(0)
{
  for(int i = 0; i < Building::FLOORS; i++)
    panel.addButton(Building::floors[i].label);
}

ostream& operator<<(ostream& out, const Elevator& e)
{
  out << "Elevator at";
  out.width(6);
  out << e.location;

  out.width(13);
  if(e.direction == e.UP)
    out << " going UP ";
  else if(e.direction == e.DOWN)
    out << " going DOWN ";
  else
    out << " idle ";

  out.width(4);
  out << e.riders.size() << " " << "riders";

  if (e.atFloorIndex != -1)
    out << " door is OPEN|" << e.timer << " ";

  out << e.panel;
  return out;
}

void Elevator::openDoorTo(int f)
{
  panel.clear(Building::floors[f].label);
  atFloorIndex = f;
  resetTimer();
}

void Elevator::board(const Rider& r)
{
  riders.push_back(r);
  panel.press(Building::floors[r.to].label);
  r.goingUp ? direction = UP : direction = DOWN;
  resetTimer();
}

bool Elevator::hasRiderForFloor() const
{
  if(!isOpen())
  {
    return false;
  }

  for(int i = 0; i < riders.size(); i++)
  {
    if(riders[i].to == atFloorIndex)
    {
      return true;
    }
  }
  return false;
}

void Elevator::removeRider()
{
  for(int i = 0; i < riders.size(); i++)
  {
    if(riders[i].to == atFloorIndex)
    {
      riders.erase(riders.begin() + i);
      panel.clear(Building::floors[riders[i].to].label);
      resetTimer();
      break;
    }
  }
}