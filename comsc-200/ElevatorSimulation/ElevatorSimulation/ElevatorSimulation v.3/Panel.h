// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#ifndef Panel_h
#define Panel_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Panel
{
  struct Button
  {
    string label;
    bool status; // true = lit, false = unlit
    int timestamp;
    static int globaltime;
  };

  vector<Button> buttons;

  public:
  friend ostream& operator<<(ostream& , const Panel&);
  friend ostream& operator<<(ostream& , const Panel::Button&);
  void addButton(string);
  void press(string);
  void clear(string);
  string getFirstLit( ) const;
  bool isLit(string) const;
  bool areAnyLit( ) const;
};

#endif
