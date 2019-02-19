//Programmer: Dhanush Patel
//Programmer ID: 1553428

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Panel.h"

int Panel::Button::totalNumPress = 0;

ostream& operator<<(ostream& os, const Panel& p){
  for(unsigned int i = 0; i < p.buttons.size(); i++){
    if(p.buttons[i].lit){
      os << "[" << p.buttons[i].label << "]";
    }
  }
  return os;
}

void Panel::addButton(string l){
  Button b = {l,false};
  buttons.push_back(b);
}

void Panel::press(string l){
  for(int i = 0; i < buttons.size(); i++){
    if(buttons[i].label == l && !buttons[i].lit){
      buttons[i].lit = true;
      buttons[i].seqNum = Button::totalNumPress++;
    }
  }
}

void Panel::clear(string l){
  for(int i = 0; i < buttons.size(); i++){
    if(buttons[i].label == l){
      buttons[i].lit = false;
    }
  }
}

string Panel::getFirstLit() const{
  Button firstLit;
  bool anyLit = false;
  for(int i = 0; i < buttons.size(); i++){
    if(buttons[i].lit && firstLit.seqNum > buttons[i].seqNum){
      firstLit = buttons[i];
      anyLit = true;
    }
  }
  return anyLit ? firstLit.label : "";
}

bool Panel::isLit(string l) const{
  for(int i = 0; i < buttons.size(); i++){
    if(buttons[i].lit && buttons[i].label == l){
      return true;
    }
  }
  return false;
}

bool Panel::areAnyLit() const{
  for(int i = 0; i < buttons.size(); i++){
    if(buttons[i].lit){
      return true;
    }
  }
  return false;
}
