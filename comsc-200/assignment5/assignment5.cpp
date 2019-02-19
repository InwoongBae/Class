// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#include <iostream>
#include <string>
using namespace std;

class Leg
{
  const char* const startcity;
  const char* const endcity;
  const int distance;

  public:
  Leg(const char* s, const char* e, const int d) : startcity(s), endcity(e), distance(d){};
  void outputLeg(ostream&) const;
  int getDistance() const {return distance;};
  Leg& operator=(const Leg&);
};

int main()
{
  cout << "Programmer: Inwoong Bae\n";
  cout << "Programmer's ID: 1505170\n";
  cout << "File: " << __FILE__ << endl;
  cout << endl;

  Leg route[] = {Leg("San Francisco", "Oakland", 12), Leg("San Francisco", "Berkeley", 13),
                 Leg("Berkeley", "Orinda", 8), Leg("Berkeley", "Pleasant Hill", 20),
                 Leg("San Francisco", "Pleasant Hill", 27), Leg("Orinda", "Pleasant Hill", 11),
                 Leg("Orinda", "Walnet Creek", 9), Leg("Walnet Creek", "Pleasant Hill", 3),
                 Leg("Oakland", "Walnet Creek", 16), Leg("Berkeley", "Walnet Creek", 16),
                 Leg("Pleasant Hill", "Concord", 4), Leg("Pleasant Hill", "Fairfield", 28),
                 Leg("Concord", "Fairfield", 27), Leg("Fairfield", "Davis", 30),
                 Leg("Fairfield", "Vacaville", 10), Leg("Davis", "Sacramento", 15),
                 Leg("Vacaville", "Davis", 20), Leg("Fairfield", "Sacramento", 44),
                 Leg("Sacramento", "Roseville", 20), Leg("Sacramento", "Carson City", 131),
                 Leg("Roseville", "Lake Tahoe", 97), Leg("Lake Tahoe", "Reno", 38),
                 Leg("Reno", "Salt Lake City", 518), Leg("Reno", "Las Vegas", 450),
                 Leg("Las Vegas", "Salt Lake City", 421), Leg("Salt Lake City", "Denver", 525),
                 Leg("Denver", "Kansas City", 602), Leg("Kansas City", "ST. Louis", 251),
                 Leg("ST. Louis", "Indianapolis", 242), Leg("Indianapolis", "Cincinnati", 112),
                 Leg("Cincinnati", "Columbus", 107), Leg("Columbus", "Cleveland", 143),
                 Leg("Columbus", "Pittsburgh", 189), Leg("Cleveland", "Pittsburgh", 134),
                 Leg("Pittsburgh", "Washington", 241), Leg("Washington", "Baltimore", 38),
                 Leg("Pittsburgh", "Baltimore", 275), Leg("Baltimore", "Philadelphia", 106),
                 Leg("Philadelphia", "New York", 97), Leg("Washington", "Philadelphia", 8)};

  const int CAP = sizeof(route)/sizeof(Leg);

  for(int i = 0; i < CAP; i++)
    for(int j = 0; j < i; j++)
      if(route[j].getDistance() > route[i].getDistance())
        swap(route[j], route[i]);

  for(int i = 0; i < CAP; i++)
    route[i].outputLeg(cout);
}

Leg& Leg::operator=(const Leg& copyThis){
  Leg& host = *this;
  if(this != &copyThis){
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
