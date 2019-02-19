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

#include "iShapes.h"

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
  vector<char> myBagType;

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
      myBagType.push_back('s');
    }
    else if(strcmp(tokens[0].c_str(), "RECTANGLE") == 0)
    {
      const Rectangle* const r = new Rectangle(tokens);
      myBag.push_back(r);
      myBagType.push_back('r');
    }
    else if(strcmp(tokens[0].c_str(), "TRIANGLE") == 0)
    {
      const Triangle* const t = new Triangle(tokens);
      myBag.push_back(t);
      myBagType.push_back('t');
    }
    else if(strcmp(tokens[0].c_str(), "CIRCLE") == 0)
    {
      const Circle* const c = new Circle(tokens);
      myBag.push_back(c);
      myBagType.push_back('c');
    }
    else if(strcmp(tokens[0].c_str(), "CYLINDER") == 0)
    {
      const Cylinder* const y = new Cylinder(tokens);
      myBag.push_back(y);
      myBagType.push_back('y');
    }
    else if(strcmp(tokens[0].c_str(), "CUBE") == 0)
    {
      const Cube* const u = new Cube(tokens);
      myBag.push_back(u);
      myBagType.push_back('u');
    }
    else if(strcmp(tokens[0].c_str(), "BOX") == 0)
    {
      const Box* const b = new Box(tokens);
      myBag.push_back(b);
      myBagType.push_back('b');
    }
    else if(strcmp(tokens[0].c_str(), "PRISM") == 0)
    {
      const Prism* const p = new Prism(tokens);
      myBag.push_back(p);
      myBagType.push_back('p');
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
    if (myBagType[i] == 's')
    {
      const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
      const Square& rSquare = *pSquare;
      rSquare.outputSquare(fout);
    }
    else if (myBagType[i] == 'r')
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
      const Rectangle& rRectangle = *pRectangle;
      rRectangle.outputRectangle(fout);
    }
    else if (myBagType[i] == 'c')
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
      const Circle& rCircle = *pCircle;
      rCircle.outputCircle(fout);
    }
    else if (myBagType[i] == 't')
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
      const Triangle& rTriangle = *pTriangle;
      rTriangle.outputTriangle(fout);
    }
    else if (myBagType[i] == 'u')
    {
      const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
      const Cube& rCube = *pCube;
      rCube.outputCube(fout);
    }
    else if (myBagType[i] == 'b')
    {
      const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
      const Box& rBox = *pBox;
      rBox.outputBox(fout);
    }
    else if (myBagType[i] == 'y')
    {
      const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
      const Cylinder& rCylinder = *pCylinder;
      rCylinder.outputCylinder(fout);
    }
    else if (myBagType[i] == 'p')
    {
      const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
      const Prism& rPrism = *pPrism;
      rPrism.outputPrism(fout);
    }
  }

  fout.close();

  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    if (myBagType[i] == 's')
    {
      const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
      const Square& rSquare = *pSquare;
      rSquare.outputSquare(cout);
    }
    else if (myBagType[i] == 'r')
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
      const Rectangle& rRectangle = *pRectangle;
      rRectangle.outputRectangle(cout);
    }
    else if (myBagType[i] == 'c')
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
      const Circle& rCircle = *pCircle;
      rCircle.outputCircle(cout);
    }
    else if (myBagType[i] == 't')
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
      const Triangle& rTriangle = *pTriangle;
      rTriangle.outputTriangle(cout);
    }
    else if (myBagType[i] == 'u')
    {
      const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
      const Cube& rCube = *pCube;
      rCube.outputCube(cout);
    }
    else if (myBagType[i] == 'b')
    {
      const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
      const Box& rBox = *pBox;
      rBox.outputBox(cout);
    }
    else if (myBagType[i] == 'y')
    {
      const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
      const Cylinder& rCylinder = *pCylinder;
      rCylinder.outputCylinder(cout);
    }
    else if (myBagType[i] == 'p')
    {
      const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
      const Prism& rPrism = *pPrism;
      rPrism.outputPrism(cout);
    }
  }

  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    if (myBagType[i] == 's')
    {
      const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
      delete pSquare;
    }
    else if (myBagType[i] == 'r')
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
      delete pRectangle;
    }
    else if (myBagType[i] == 'c')
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
      delete pCircle;
    }
    else if (myBagType[i] == 't')
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
      delete pTriangle;
    }
    else if (myBagType[i] == 'u')
    {
      const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
      delete pCube;
    }
    else if (myBagType[i] == 'b')
    {
      const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
      delete pBox;
    }
    else if (myBagType[i] == 'y')
    {
      const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
      delete pCylinder;
    }
    else if (myBagType[i] == 'p')
    {
      const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
      delete pPrism;
    }
  }
}

vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}
