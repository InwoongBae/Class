// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#include "Rider.h"
#include "Building.h"

Rider::Rider(int f, int t)
:from(f), to(t), goingUp(Building::floors[to] > Building::floors[from]), goingDown(Building::floors[to] < Building::floors[from])
{
}

Rider& Rider::operator=(const Rider& r)
{
  Rider& host = *this;
  if(this != &host){	
	  const_cast<int&>(host.from) = r.from;
	  const_cast<int&>(host.to) = r.to;
	  const_cast<bool&>(host.goingUp) = r.goingUp;
	  const_cast<bool&>(host.goingDown) = r.goingDown;
  }	
  return host;
}
