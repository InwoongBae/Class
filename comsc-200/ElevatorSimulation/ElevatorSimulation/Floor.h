// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include <string>
#include <queue>
using namespace std;

#include "Panel.h"
#include "Rider.h"

class Floor{
  queue<Rider> upRiders, downRiders;
  
  public:
  Floor(const int, const char* const, const char* const); 
  operator int() const {return elevation;}
  
  static const char* const UP;
  static const char* const DOWN;
  static int TOP, BOTTOM;
  
  Panel panel;
  const string name; 
  const string label; 
  const int elevation; 

  friend ostream& operator<<(ostream&, const Floor&); 
  bool hasUpRider() const {return !upRiders.empty();}
  bool hasDownRider() const {return !downRiders.empty();};
  void addRider(const Rider&);
  Rider removeUpRider();
  Rider removeDownRider();
  int getNumberOfUpRiders() const {return upRiders.size();}
  unsigned int getNumberOfDownRiders() const {return downRiders.size();}
};

#endif