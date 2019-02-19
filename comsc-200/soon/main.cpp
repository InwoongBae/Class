// Programmer: Dhanush Patel
// Programmer's ID: 1553428

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
using namespace std;

#include <cstring>

class Leg{
  friend class Route;
  friend class ShortestRoute;

  const char* const startCity;
  const char* const endCity;
  int const dist;

  public:
  Leg(const char* const s, const char* const e, int d) : startCity(s), endCity(e), dist(d){}
  int getDist() const {return dist;}
  Leg& operator=(const Leg&);
  void niceOutput(ostream&) const;
};

class Route{
  friend class ShortestRoute;
  vector<const Leg*> legs;
  int const dist;

  public:
  Route(const Leg&);
  Route(const Route&, const Leg&);
  int getDistance() const {return dist;}
  void niceOutput(ostream&) const;
  Route& operator=(const Route&);
  friend bool operator<(const Route&, const Route&);
};

class ShortestRoute{
  public:
  static Route anyRoute(const char* const, const char* const);
  static const Route shortestRoute(const char* const, const char* const);
  static const Leg lary[];
};

const Leg ShortestRoute::lary[] = {
        Leg("San Francisco","Berkeley",14),
        Leg("San Francisco","San Jose",48),
        Leg("San Francisco","Santa Cruz",73),
        Leg("San Jose","Sacramento",120),
        Leg("Berkeley","Sacramento",78),
        Leg("Berkeley","Bakersfield",78),
        Leg("San Jose","Bakersfield",241),
        Leg("Santa Cruz","San Jose",32),
        Leg("Santa Cruz","Bakersfield",247),
        Leg("Santa Cruz","Reno",277),
        Leg("San Jose","Provo",810),
        Leg("Sacramento","Santa Fe",1141),
        Leg("Bakersfield","Santa Fe",864),
        Leg("Chicago","Pittsburgh",461),
        Leg("Oklahoma City","St. Louis",499),
        Leg("Memphis","Nashville",212),
        Leg("Oklahoma City","Nashville",678),
        Leg("Nashville","Greensboro",465),
        Leg("Denver","Omaha",537),
        Leg("Santa Fe","Omaha",880),
        Leg("Provo","Santa Fe",582),
        Leg("Provo","Denver",582),
        Leg("Bakersfield","Denver",1032),
        Leg("Greensboro","Baltimore",355),
        Leg("Baltimore","New York City",191),
        Leg("Pittsburgh","New York City",371),
        Leg("Pittsburgh","Baltimore",248),
        Leg("Sacramento","Reno",132),
        Leg("Denver","Oklahoma City",680),
        Leg("Santa Fe","Oklahoma City",680),
        Leg("Santa Fe","Dallas",637),
        Leg("Oklahoma City","Dallas",206),
        Leg("Denver","Memphis",1095),
        Leg("Chicago","Greensboro",738),
        Leg("Nashville","Pittsburgh",560),
        Leg("Oklahoma City","Memphis",467),
        Leg("Dallas","Memphis",452),
        Leg("Omaha","St. Louis",435),
        Leg("Dallas","Greensboro",1127),
        Leg("Omaha","Chicago",471),
        Leg("Bakersfield","Chicago",2032),
        Leg("St. Louis","Baltimore",821),
        Leg("Greensboro","Baltimore",355),
        Leg("St. Louis","Nashville",309),
        Leg("San Francisco","New York City",21000),
};

int main(){
  cout << "Programmer: Dhanush Patel\n";
  cout << "Programmer's ID: 1553428\n";
  cout << "File: " << __FILE__ << "\n\n";

  const Route route1 = ShortestRoute::anyRoute("San Francisco", "New York City");
  route1.niceOutput(cout);

  const Route route2 = ShortestRoute::shortestRoute("San Francisco", "New York City");
  route2.niceOutput(cout);
}

Route ShortestRoute::anyRoute(const char* const start, const char* const end) {
  for (int i = 0; i < 44; i++) {
    if (strcmp(ShortestRoute::lary[i].endCity, end) == 0) {
      if (strcmp(ShortestRoute::lary[i].startCity, start) == 0) {
        Route r(lary[i]);
        return r;
      }
      else {
        Route x(ShortestRoute::anyRoute(start, ShortestRoute::lary[i].startCity),lary[i]);
        return x;
      }
    }
  }
}

const Route ShortestRoute::shortestRoute(const char* const start, const char* const end){
  set<Route> s;
  for (int j = 0; j < 44; j++) {
    for (int i = 0; i < 44; i++) {
      if (strcmp(ShortestRoute::lary[i].endCity, end) == 0) {
        if (strcmp(ShortestRoute::lary[i].startCity, start) == 0) {
          Route r(lary[i]);
          return r;
        }
        else {
          Route x(ShortestRoute::anyRoute(start, ShortestRoute::lary[i].startCity), lary[i]);
          s.insert(x);
        }
      }
    }
  }
  return *(s.begin());
}

bool operator<(const Route& a, const Route& b)
{
  return a.dist < b.dist;
}

Leg& Leg::operator=(const Leg& copyThis){
  Leg& host = *this;
  if(this != &copyThis){
    const_cast<const char*&>(host.startCity) = copyThis.startCity;
    const_cast<const char*&>(host.endCity) = copyThis.endCity;
    const_cast<int&>(host.dist) = copyThis.dist;
  }
  return host;
}

void Leg::niceOutput(ostream& os) const{
  os << startCity << " to " << endCity << " is " << dist << " miles" << endl;
}

Route::Route(const Leg& leg) : dist(leg.getDist()){
  legs.push_back(&leg);
}

Route::Route(const Route& route, const Leg& leg)
        : legs(route.legs), dist(route.dist+leg.dist){
    if (strcmp(route.legs.back()->endCity, leg.startCity) != 0)
      throw "Mismatch";

  legs.push_back(&leg);
}

void Route::niceOutput(ostream& out) const
{
  string outputstart = "Route: ";
  string to = " to ";
  int totalDistance = 0;
  stringstream out1;
  for(unsigned int i = 0; i < legs.size(); i++)
  {
    outputstart += legs[i]->startCity;
    if(i != legs.size()-1)
      outputstart = outputstart + to;
    else
      outputstart = outputstart + to + legs[i]->endCity;
    totalDistance = totalDistance + legs[i]->getDist();
  }
  out1 << totalDistance;
  outputstart = outputstart + " is " + out1.str() + " miles\n";
  out << outputstart;
}

Route& Route::operator=(const Route& copyThis){
  Route& host = *this;
  if(this != &copyThis){
    const_cast<int&>(host.dist) = copyThis.getDistance();
    host.legs = copyThis.legs;
  }
  return host;
}
