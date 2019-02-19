//Programmer: Dhanush Patel
//Programmer ID: 1553428

#include "Rider.h"
#include "Building.h"

Rider::Rider(int f, int t)
:from(f), to(t), goingUp(!(Building::floors[to] < Building::floors[from])),goingDown(Building::floors[to] < Building::floors[from]){
}

Rider& Rider::operator=(const Rider& r){
  const_cast<int&>(this->from) = r.from;
  const_cast<int&>(this->to) = r.to;
  const_cast<bool&>(this->goingUp) = r.goingUp;
  const_cast<bool&>(this->goingDown) = r.goingDown;
  return *this;
}
