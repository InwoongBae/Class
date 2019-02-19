// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#ifndef BUILDING_H

#define BUILDING_H


#include "Floor.h"

#include "Elevator.h"



struct Building

{

  static Floor floors[];

  static Elevator elevators[];

  static const int FLOORS;

  static const int ELEVATORS;

  // helper functions


  static void getDifferentInts(int&, int&);

  static int getPoisson(double);

  static void placeNewRiders(double);
  
  // actions

  static void action(double); // the main "action function"

  static bool openDoorToDisembarkRider(int); // step 1 of 9

  static bool disembarkRider(int); // step 2, parameter is an elevator's index
  static bool boardRider(int); // step 3, parameter is an elevator's index
  static bool waitingForMoreRiders(int); // step 4
  static bool doneWaitingMove(int); // step 5
  static bool moveableMove(int);
};


#endif