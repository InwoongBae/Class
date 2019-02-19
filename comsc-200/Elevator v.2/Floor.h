// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#ifndef Floor_h
#define Floor_h

#include <iostream>
#include <string>
#include <queue>
using namespace std;

#include "Panel.h"
#include "Rider.h"

class Floor
{
  queue<Rider> upRiders, downRiders;

  public:
  Floor(const int, const char* const, const char* const); // elevation (inches above ground) of floor, name and label
  operator int() const {return elevation;}

  static const char* const UP;
  static const char* const DOWN;
  static int TOP, BOTTOM;

  Panel panel;
  const int elevation; // inches above ground level
  const string name; // name of floor, for example: Mezzanine
  const string label; // as it appears on the button panel


  // for external reporting
  friend ostream& operator<<(ostream&, const Floor&); // say name, location, #'s of up/down riders waiting
  bool hasUpRider() const {return !upRiders.empty();}
  bool hasDownRider() const {return !downRiders.empty();};
  void addRider(const Rider&);
  Rider removeUpRider( );
  Rider removeDownRider( );
};

#endif
