#ifndef VISUALBUILDING_H
#define VISUALBUILDING_H

#include "Building.h"
#include "Floor.h"
#include "Elevator.h"

#include <vector>
using namespace std;

#include <cmath>

class VisualBuilding : public Building
{
  int width; // width of MFC window, in pixels
  int height; // height of MFC window, in pixels
  int rheight; // height of a rider, in pixels
  int separation; // pixels separating riders
  int margin; // half-separation between elevators
  int max, min, overallHeight; // metrics

  int ridersPerHalfSecond;
  int upFloorX; // x-location of end of up floor
  int downFloorX; // x-location of start of up floor
  vector<int> elevatorX;
  vector<int> floorY;

  public:
  void initializeForMfc(int width, int height, int rheight, int separation, int margin)
  {
    VisualBuilding::width = width;
    VisualBuilding::height = height;
    VisualBuilding::rheight = rheight;
    VisualBuilding::separation = separation;
    VisualBuilding::margin = margin;

    int i;
    int shaftWidth = 0;
    for (i = 0; i < Building::ELEVATORS; i++)
      shaftWidth += getElevatorWidth(i) + 2 * margin;

    upFloorX = (width - shaftWidth) / 2;
    downFloorX = width - upFloorX;

    int x = upFloorX + margin; 
    for (i = 0; i <  Building::ELEVATORS; i++)
    {
      elevatorX.push_back(x);
      x += (getElevatorWidth(i) + 2 * margin);
    }

    for (i = 0; i < Building::FLOORS; i++)
    {
      int elevation = Building::floors[i].elevation; 
      if (i == 0 || elevation > max) max = elevation;
      if (i == 0 || elevation < min) min = elevation;
    }
    max += (2 + getElevatorHeight() * (max - min + 4) / (height - rheight));
    min -= 2;
    overallHeight = (max - min);

    for (i = 0; i < Building::FLOORS; i++)
    {
      int y = height * (max - Building::floors[i].elevation) / overallHeight;
      floorY.push_back(y);
    } 

    ridersPerHalfSecond = 2;
  }
  
  VisualBuilding() // "seed" the elevators with 6 Riders
  {
    for (int i = 0; i < 3; i++)
    {
      elevators[1].board(Rider(4, 1));
      elevators[2].board(Rider(0, 2));
    }
  }
  
  int getElevatorWidth(int index) const {return (Building::elevators[index].CAPACITY + 1) * separation + Building::elevators[index].CAPACITY + 2;}
  int getElevatorHeight() const {return 5 * rheight / 4;}
  int getElevatorX(int index) const {return elevatorX[index];}
  int getElevatorY(int index) const {return height * (max - Building::elevators[index]) / overallHeight;}
  int getUpFloorX() const {return upFloorX;}
  int getDownFloorX() const {return downFloorX;}
  int getFloorY(int index) const {return floorY[index];}
  int getRiderCount(int index) const {return Building::elevators[index].getNumberOfRiders();}
  int getRiderSeparation() const {return separation;}
  int getRiderHeight() const {return rheight;}
  void incrementRidersPerSecond() {ridersPerHalfSecond++;}
  void decrementRidersPerSecond() {if (ridersPerHalfSecond > 0) ridersPerHalfSecond--;}
  double getRidersPerSecond() const {return 0.5 * ridersPerHalfSecond;}
  
  unsigned int getUpRiderCount(int index) const {return Building::floors[index].getNumberOfUpRiders();}
  unsigned int getDownRiderCount(int index) const {return Building::floors[index].getNumberOfDownRiders();}
  bool isDirectionUp(int index) const {return Building::elevators[index].goingUp();}
  bool isDirectionDown(int index) const {return Building::elevators[index].goingDown();}

  int poissonHits() const
  {
    int hits = 0;
    double probOfnHits = exp(-getRidersPerSecond()); // for n=0
    for(double randomValue = double(rand() % 1000) / double(1000);
      (randomValue -= probOfnHits) > 0.0; 
      probOfnHits *= getRidersPerSecond() / double(++hits));
    return hits;
  }
};

#endif
