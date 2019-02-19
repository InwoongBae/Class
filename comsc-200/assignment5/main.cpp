#include <iostream>
#include <string>
using namespace std;

class Leg{
  const char* const startCity;
  const char* const endCity;
  const int dist;

public:
  Leg(const char* const s, const char* const e, int d) : startCity(s), endCity(e), dist(d){}
  int getDist() const {return dist;}
  Leg& operator=(const Leg&);
  void niceOutput(ostream&) const;
};

int main(){
  Leg ary[] = {
      Leg("San Ramon","Dublin",1),
      Leg("Dublin","Livermore",5),
      Leg("Livermore","Fremont",20),
      Leg("Fremont","Union City",3),
      Leg("Union City","San Jose",19),
      Leg("San Jose","Cupertino",4),
      Leg("Cupertino","Redwood City",15),
      Leg("Redwood City","San Francisco",18)
  };

  for (int i = 0; i < 8; i++){
    for (int j = i + 1; j < 8; j++){
      if (ary[j].getDist() < ary[i].getDist()){
        swap(ary[i], ary[j]);
      }
    }
  }

  cout << "Programmer: Inwoong Bae\n";
  cout << "Programmer's ID: 1505170\n";
  cout << "File: " << __FILE__ << "\n\n";

  for(unsigned int i = 0; i < sizeof(ary)/sizeof(Leg); i++){
    ary[i].niceOutput(cout);
  }

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
