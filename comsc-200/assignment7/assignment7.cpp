// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

#include <cstring>

class Leg
{
  friend class Route;
  friend class ShortestRoute;

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
  friend class ShortestRoute;
  vector<const Leg*> legs;
  int const distance;

  public:
  Route(const Leg&);
  Route(const Route&, const Leg&);
  int getDistance() const {return distance;}
  void outputRoute(ostream&) const;
  Route& operator=(const Route&);
  friend bool operator<(const Route&, const Route&);
};

class ShortestRoute{
  public:
  static Route anyRoute(const char* const, const char* const);
  static const Route shortestRoute(const char* const, const char* const);
  static const Leg legarray[];
};

const Leg ShortestRoute::legarray[] = {
  Leg("San Francisco", "Oakland", 12), Leg("Oakland", "Berkeley", 5),
  Leg("San Francisco", "Berkeley", 13), Leg("Berkeley", "Pleasant Hill", 20),
  Leg("San Francisco", "Pleasant Hill", 27), Leg("Orinda", "Pleasant Hill", 11),
  Leg("Berkeley", "Orinda", 8), Leg("Orinda", "Walnet Creek", 9),
  Leg("Oakland", "Walnet Creek", 16), Leg("Walnet Creek", "Pleasant Hill", 3),
  Leg("Pleasant Hill", "Concord", 4), Leg("Berkeley", "Walnet Creek", 16),
  Leg("Pleasant Hill", "Fairfield", 28), Leg("Concord", "Fairfield", 27),
  Leg("Fairfield", "Davis", 30), Leg("Fairfield", "Vacaville", 9),
  Leg("Vacaville", "Davis", 20), Leg("Davis", "Sacramento", 15),
  Leg("Sacramento", "Roseville", 20), Leg("Davis", "Carson City", 143),
  Leg("Fairfield", "Sacramento", 44), Leg("Sacramento", "Carson City", 131),
  Leg("Roseville", "Lake Tahoe", 97), Leg("Lake Tahoe", "Carson City", 21),
  Leg("Roseville", "Carson City", 127), Leg("Lake Tahoe", "Reno", 38),
  Leg("Carson City", "Reno", 32), Leg("Reno", "Las Vegas", 450),
  Leg("Reno", "Denver", 992), Leg("Reno", "Salt Lake City", 518),
  Leg("Las Vegas", "Denver", 748), Leg("Las Vegas", "Salt Lake City", 421),
  Leg("Salt Lake City", "Denver", 525), Leg("Denver", "Albuquerque", 450),
  Leg("Albuquerque", "Oklahoma City", 541), Leg("Denver", "Kansas City", 602),
  Leg("Oklahoma City", "Kansas City", 347), Leg("Albuquerque", "Kansas City", 788),
  Leg("Kansas City", "Minneapolis", 438), Leg("Minneapolis", "Milwaukee", 337),
  Leg("Milwaukee", "ST. Louis", 373), Leg("Milwaukee", "Chicago", 92),
  Leg("Chicago", "St. Louis", 297), Leg("Chicago", "Cincinnati", 294),
  Leg("St. Louis", "Columbus", 448), Leg("Kansas City", "St. Louis", 251),
  Leg("St. Louis", "Indianapolis", 185), Leg("Indianapolis", "Cincinnati", 112),
  Leg("Indianapolis", "Louisville", 114), Leg("Louisville", "Cincinnati", 99),
  Leg("Cincinnati", "Columbus", 107), Leg("Columbus", "Detroit", 207),
  Leg("Detroit", "Cleveland", 199), Leg("Columbus", "Cleveland", 143),
  Leg("Columbus", "Pittsburgh", 189), Leg("Cleveland", "Pittsburgh", 134),
  Leg("Pittsburgh", "Washington", 241), Leg("Pittsburgh", "Philadelphia", 305),
  Leg("Pittsburgh", "Baltimore", 275), Leg("Washington", "Baltimore", 38),
  Leg("Baltimore", "Philadelphia", 106), Leg("Philadelphia", "New York", 97),
  Leg("San Francisco", "New York", 21000)
};

int main()
{
  cout << "Programmer: Inwoong Bae\n";
  cout << "Programmer's ID: 1505170\n";
  cout << "File: " << __FILE__ << endl;
  cout << endl;

  const Route route1 = ShortestRoute::anyRoute("San Francisco", "New York");
  route1.outputRoute(cout);

  const Route route2 = ShortestRoute::shortestRoute("San Francisco", "New York");
  route2.outputRoute(cout);
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

bool operator<(const Route& r1, const Route& r2)
{
  return r1.distance < r2.distance;
}

Route ShortestRoute::anyRoute(const char* const from, const char* const to)
{
  for(int i = 0; i < 63; i++)
  {
    if(strcmp(ShortestRoute::legarray[i].endcity, to) == 0)
    {
      if(strcmp(ShortestRoute::legarray[i].startcity, from) == 0)
      {
        Route o1(legarray[i]);
        return o1;
      }
      else
      {
        Route o2(ShortestRoute::anyRoute(from, ShortestRoute::legarray[i].startcity), legarray[i]);
        return o2;
      }
    }
  }
  throw "No match!";
}

const Route ShortestRoute::shortestRoute(const char* const from, const char* const to)
{
  set<Route> shortestroute;

  for(int i = 0; i < 63; i++)
  {
    if(strcmp(ShortestRoute::legarray[i].endcity, to) == 0)
    {
      if(strcmp(ShortestRoute::legarray[i].startcity, from) == 0)
      {
        Route r1(legarray[i]);
        shortestroute.insert(r1);
      }
      else
      {
        Route r2(ShortestRoute::anyRoute(from, ShortestRoute::legarray[i].startcity), legarray[i]);
        shortestroute.insert(r2);
      }
    }
  }
  if(shortestroute.empty() != 0)
    throw "No Match!";
  return *(shortestroute.begin());
}
