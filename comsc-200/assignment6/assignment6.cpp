// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include <cstring>

class Leg
{
  friend class Route;

  const char* const startcity;
  const char* const endcity;
  int const distance;

  public:
  Leg(const char* const s, const char* const e, int d) : startcity(s), endcity(e), distance(d){}
  void outputLeg(ostream&) const;
  int getDistance() const {return distance;}
  Leg& operator=(const Leg&);
};

class Route
{
  vector<const Leg*> legs;
  int const distance;

  public:
  Route(const Leg&);
  Route(const Route&, const Leg&);
  int getDistance() const {return distance;};
  void outputRoute(ostream&) const;
  Route& operator=(const Route&);
};

int main()
{
  cout << "Programmer: Inwoong Bae\n";
  cout << "Programmer's ID: 1505170\n";
  cout << "File: " << __FILE__ << endl;
  cout << endl;

  Leg legarray[] = {
               Leg("San Francisco", "Berkeley", 13),
               Leg("Berkeley", "Orinda", 8),
               Leg("Orinda", "Walnet Creek", 9),
               Leg("Walnet Creek", "Pleasant Hill", 3),
               Leg("Pleasant Hill", "Concord", 4),
               Leg("Concord", "Fairfield", 27),
               Leg("Fairfield", "Davis", 30),
               Leg("Davis", "Sacramento", 15),
               Leg("Sacramento", "Roseville", 20),
               Leg("Roseville", "Lake Tahoe", 97),
               Leg("Lake Tahoe", "Reno", 38),
               Leg("Reno", "Salt Lake City", 518)};

  Route routearrary[] = { Route(legarray[0]),
                          Route(routearrary[0], legarray[1]),
                          Route(routearrary[1], legarray[2]),
                          Route(routearrary[2], legarray[3]),
                          Route(routearrary[3], legarray[4]),
                          Route(routearrary[4], legarray[5]),
                          Route(routearrary[5], legarray[6]),
                          Route(routearrary[6], legarray[7]),
                          Route(routearrary[7], legarray[8]),
                          Route(routearrary[8], legarray[9]),
                          Route(routearrary[9], legarray[10]),
                          Route(routearrary[10], legarray[11])};

  //const int CAP = sizeof(leg)/sizeof(Leg);
  const int CAP1 = sizeof(routearrary)/sizeof(Route);

  for(int i = 0; i < CAP1; i++)
    for(int j = 0; j < i; j++)
      if(routearrary[j].getDistance() < routearrary[i].getDistance())
        swap(routearrary[j], routearrary[i]);

  for(int i = 0; i < CAP1; i++)
    routearrary[i].outputRoute(cout);
}

Leg& Leg::operator=(const Leg& copyThis)
{
  Leg& host = *this;
  if(this != &copyThis)
  {
    const_cast<const char*&>(host.startcity) = copyThis.startcity;
    const_cast<const char*&>(host.endcity) = copyThis.endcity;
    const_cast<int&>(host.distance) = copyThis.distance;
  }
  return host;
}

void Leg::outputLeg(ostream& out) const
{
  out << "Leg: " << startcity << " to " << endcity << ", " << distance << " miles. \n";
}

Route::Route(const Leg& leg) : distance(leg.getDistance())
{
  legs.push_back(&leg);
}

Route::Route(const Route& route, const Leg& leg) : legs(route.legs) , distance(route.distance + leg.distance)
{
  if(strcmp(route.legs.back()->endcity, leg.startcity) != 0)
    throw "No match!";

  legs.push_back(&leg);
}

Route& Route::operator=(const Route& copyThis)
{
  Route& host = *this;
  if(this != &copyThis)
  {
    const_cast<int&>(host.distance) = copyThis.getDistance();
    host.legs = copyThis.legs;
  }
  return host;
}

void Route::outputRoute(ostream& out) const
{
  string outputstart = "Route: ";
  string to = " to ";
  int totalDistance = 0;
  stringstream out1;
  for(unsigned int i = 0; i < legs.size(); i++)
  {
    outputstart += legs[i]->startcity;
    if(i != legs.size()-1)
      outputstart = outputstart + to;
    else
      outputstart = outputstart + to + legs[i]->endcity;
    totalDistance = totalDistance + legs[i]->getDistance();
  }
  out1 << totalDistance;
  outputstart = outputstart + " is " + out1.str() + " miles\n";
  out << outputstart;
}
