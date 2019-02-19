// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include <cstring>

#include "pShapes.h"

vector<string> parseString(string);

int main()
{
  cout << "Programmer: Inwoong Bae\n";
  cout << "Programmer's ID: 1505170\n";
  cout << "File: " << __FILE__ << endl;

  ifstream fin;
  ofstream fout;
  vector<string> tokens;
  string data;
  vector<const Shape*> myBag;

  fin.open("Shapes.input.txt");
  fout.open("Shapes.output.txt");

  while(fin.good())
  {
    getline(fin, data);
    tokens = parseString(data);

    if(tokens.size() == 0 )
      continue;
    else if(strcmp(tokens[0].c_str(), "SQUARE") == 0)
    {
      const Square* const s = new Square(tokens);
      myBag.push_back(s);
    }
    else if(strcmp(tokens[0].c_str(), "RECTANGLE") == 0)
    {
      const Rectangle* const r = new Rectangle(tokens);
      myBag.push_back(r);
    }
    else if(strcmp(tokens[0].c_str(), "TRIANGLE") == 0)
    {
      const Triangle* const t = new Triangle(tokens);
      myBag.push_back(t);
    }
    else if(strcmp(tokens[0].c_str(), "CIRCLE") == 0)
    {
      const Circle* const c = new Circle(tokens);

      myBag.push_back(c);
    }
    else if(strcmp(tokens[0].c_str(), "CYLINDER") == 0)
    {
      const Cylinder* const y = new Cylinder(tokens);
      myBag.push_back(y);
    }
    else if(strcmp(tokens[0].c_str(), "CUBE") == 0)
    {
      const Cube* const u = new Cube(tokens);
      myBag.push_back(u);
    }
    else if(strcmp(tokens[0].c_str(), "BOX") == 0)
    {
      const Box* const b = new Box(tokens);
      myBag.push_back(b);
    }
    else if(strcmp(tokens[0].c_str(), "PRISM") == 0)
    {
      const Prism* const p = new Prism(tokens);
      myBag.push_back(p);
    }
    else if(strcmp(tokens[0].c_str(), "EOF") == 0)
      break;
    else
    {
      cout << tokens[0] << " invalid object\n";
    }
  }

  fin.close();

  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    fout << *myBag[i];
  }

  fout.close();

  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    cout << *myBag[i];
  }

  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    delete myBag[i];
  }
}

vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}
