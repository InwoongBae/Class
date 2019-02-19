// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170


#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Panel.h"

int Panel::Button::globaltime = 0;

ostream& operator<<(ostream& os, const Panel::Button& b)
{
  if(b.status)
  os << "[" << b.label << "]";
  return os;
}

ostream& operator<<(ostream& os, const Panel& p)
{
  for(unsigned int i = 0; i < p.buttons.size(); i++)
  {
    os << p.buttons[i];
  }
  return os;
}

void Panel::addButton(string label)
{
  Button b = {label, false};
  buttons.push_back(b);
}

bool Panel::areAnyLit() const
{
  for(unsigned int i = 0; i < buttons.size(); i++)
  {
    if(buttons[i].status)
    {
      return true;
    }
  }
  return false;
}

void Panel::press(string label)
{
  int index = -1;
  for(unsigned int i = 0; i < buttons.size(); i++)
  {
    if(buttons[i].label == label)
    {
      index = i;
      break;
    }
  }
  if(index < 0) return;
  if(!buttons[index].status)
  {
    buttons[index].status = true;
    buttons[index].timestamp = Button::globaltime;
    Button::globaltime++;
  }
}

bool Panel::isLit(string label) const
{
  for(unsigned int i = 0; i < buttons.size(); i++)
  {
    if(buttons[i].label == label && buttons[i].status)
    {
      return true;
    }
  }
  return false;
}

string Panel::getFirstLit() const
{
  Button first;
  bool lit = false;
  for(unsigned int i = 0; i < buttons.size(); i++)
  {
    if(buttons[i].status && first.timestamp > buttons[i].timestamp)
    {
      first = buttons[i];
      lit = true;
    }
  }
  return lit ? first.label : "";
}

void Panel::clear(string label)
{
  for(unsigned int i = 0; i < buttons.size(); i++)
  {
    if(buttons[i].label == label)
    {
      buttons[i].status = false;
    }
  }
}





