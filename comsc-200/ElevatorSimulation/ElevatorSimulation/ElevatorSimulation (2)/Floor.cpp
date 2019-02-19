// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#include "Floor.h"
#include "Rider.h"
#include "Panel.h"
#include "Building.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include <climits>

const char* const Floor::UP = "Up";
const char* const Floor::DOWN = "Down";
int Floor::TOP = INT_MIN; // defined in climits
int Floor::BOTTOM = INT_MAX; // also in climits

Floor::Floor(const int elevation, const char* const name, const char* const label)
:elevation(elevation), name(name), label(label)
{
  panel.addButton(UP);
  panel.addButton(DOWN);
  if (TOP < elevation) TOP = elevation;
  if (elevation < BOTTOM) BOTTOM = elevation;
}

ostream& operator<<(ostream& out, const Floor& floor)
{
  out << setw(2) << floor.label << setw(15) << floor.name << " at" << setw(8) << floor.elevation << "\" Up/Down:  " << setw(2) << floor.upRiders.size() << "/" << floor.downRiders.size() << setw(12) << "Buttons: " << floor.panel;
  return out;
}

void Floor::addRider(const Rider& r)
{
  if(r.goingUp)
  {
    upRiders.push(r);
    panel.press(UP);
  }
  else
  {
    downRiders.push(r);
    panel.press(DOWN);
  }
}

Rider Floor::removeUpRider()
{
  if(upRiders.empty())
    throw "Uprider is empty!";
  
  Rider r = upRiders.front();
  upRiders.pop();
  return r;
}

Rider Floor::removeDownRider() 
{
  if(downRiders.empty())
    throw "Downrider is empty";

  Rider r = downRiders.front();
  downRiders.pop();
  return r;
}