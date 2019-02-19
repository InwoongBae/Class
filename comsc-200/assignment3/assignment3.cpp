// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

#include <cmath>
#include <cstdlib>
#include <cstring>

const double PI = 3.14159265359;

struct Square
{
  double side;
  void outputSquare(ostream&);
};
struct Rectangle
{
  double length;
  double width;
  void outputRectangle(ostream&);
};
struct Circle
{
  double radius;
  void outputCircle(ostream&);
};
struct Triangle
{
  double side;
  void outputTriangle(ostream&);
};
struct Cube
{
  double side;
  void outputCube(ostream&);
};
struct Box
{
  double length;
  double width;
  double height;
  void outputBox(ostream&);
};
struct Cylinder
{
  double radius;
  double height;
  void outputCylinder(ostream&);
};
struct Prism
{
  double side;
  double height;
  void outputPrism(ostream&);
};

vector<string> parseString(string);
ostream& roundingOn(ostream&);
ostream& roundingOff(ostream&);

int main()
{
  cout << "Programmer: Inwoong Bae\n";
  cout << "Programmer's ID: 1505170\n";
  cout << "File: " << __FILE__ << endl;

  ifstream fin;
  ofstream fout;
  vector<string> tokens;
  string data;
  vector<void*> myBag;
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
      Square* s = new Square;
      s->side = tokens.size() > 1 ? atof(tokens[1].c_str()) : 0;
      myBag.push_back(s);
      myBagType.push_back('s');
    }
    else if(strcmp(tokens[0].c_str(), "RECTANGLE") == 0)
    {
      Rectangle* r = new Rectangle;
      r->length = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
      r->width = tokens.size() >= 3 ? atof((tokens[2].c_str())) : 0;
      myBag.push_back(r);
      myBagType.push_back('r');
    }
    else if(strcmp(tokens[0].c_str(), "TRIANGLE") == 0)
    {
      Triangle* t = new Triangle;
      t->side = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
      myBag.push_back(t);
      myBagType.push_back('t');
    }
    else if(strcmp(tokens[0].c_str(), "CIRCLE") == 0)
    {
      Circle* c = new Circle;
      c->radius = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
      myBag.push_back(c);
      myBagType.push_back('c');
    }
    else if(strcmp(tokens[0].c_str(), "CYLINDER") == 0)
    {
      Cylinder* y = new Cylinder;
      y->radius = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
      y->height = tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0;
      myBag.push_back(y);
      myBagType.push_back('y');
    }
    else if(strcmp(tokens[0].c_str(), "CUBE") == 0)
    {
      Cube* u = new Cube;
      u->side = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
      myBag.push_back(u);
      myBagType.push_back('u');

    }
    else if(strcmp(tokens[0].c_str(), "BOX") == 0)
    {
      Box* b = new Box;
      b->length = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
      b->width = tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0;
      b->height = tokens.size() >= 4 ? atof(tokens[3].c_str()) : 0;
      myBag.push_back(b);
      myBagType.push_back('b');
    }
    else if(strcmp(tokens[0].c_str(), "PRISM") == 0)
    {
      Prism* p = new Prism;
      p->side = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;;
      p->height = tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0;;
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
      Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
      Square& rSquare = *pSquare;
      rSquare.outputSquare(fout);
    }
    else if (myBagType[i] == 'r')
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
      Rectangle& rRectangle = *pRectangle;
      rRectangle.outputRectangle(fout);
    }
    else if (myBagType[i] == 'c')
    {
      Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
      Circle& rCircle = *pCircle;
      rCircle.outputCircle(fout);
    }
    else if (myBagType[i] == 't')
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
      Triangle& rTriangle = *pTriangle;
      rTriangle.outputTriangle(fout);
    }
    else if (myBagType[i] == 'u')
    {
      Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
      Cube& rCube = *pCube;
      rCube.outputCube(fout);
    }
    else if (myBagType[i] == 'b')
    {
      Box* pBox = reinterpret_cast<Box*>(myBag[i]);
      Box& rBox = *pBox;
      rBox.outputBox(fout);
    }
    else if (myBagType[i] == 'y')
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
      Cylinder& rCylinder = *pCylinder;
      rCylinder.outputCylinder(fout);
    }
    else if (myBagType[i] == 'p')
    {
      Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
      Prism& rPrism = *pPrism;
      rPrism.outputPrism(fout);
    }
  }

  fout.close();

  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    if (myBagType[i] == 's')
    {
      Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
      Square& rSquare = *pSquare;
      rSquare.outputSquare(cout);
    }
    else if (myBagType[i] == 'r')
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
      Rectangle& rRectangle = *pRectangle;
      rRectangle.outputRectangle(cout);
    }
    else if (myBagType[i] == 'c')
    {
      Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
      Circle& rCircle = *pCircle;
      rCircle.outputCircle(cout);
    }
    else if (myBagType[i] == 't')
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
      Triangle& rTriangle = *pTriangle;
      rTriangle.outputTriangle(cout);
    }
    else if (myBagType[i] == 'u')
    {
      Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
      Cube& rCube = *pCube;
      rCube.outputCube(cout);
    }
    else if (myBagType[i] == 'b')
    {
      Box* pBox = reinterpret_cast<Box*>(myBag[i]);
      Box& rBox = *pBox;
      rBox.outputBox(cout);
    }
    else if (myBagType[i] == 'y')
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
      Cylinder& rCylinder = *pCylinder;
      rCylinder.outputCylinder(cout);
    }
    else if (myBagType[i] == 'p')
    {
      Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
      Prism& rPrism = *pPrism;
      rPrism.outputPrism(cout);
    }
  }

  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    if (myBagType[i] == 's')
    {
      Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
      delete pSquare;
    }
    else if (myBagType[i] == 'r')
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
      delete pRectangle;
    }
    else if (myBagType[i] == 'c')
    {
      Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
      delete pCircle;
    }
    else if (myBagType[i] == 't')
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
      delete pTriangle;
    }
    else if (myBagType[i] == 'u')
    {
      Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
      delete pCube;
    }
    else if (myBagType[i] == 'b')
    {
      Box* pBox = reinterpret_cast<Box*>(myBag[i]);
      delete pBox;
    }
    else if (myBagType[i] == 'y')
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
      delete pCylinder;
    }
    else if (myBagType[i] == 'p')
    {
      Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
      delete pPrism;
    }
  }
}
void Square::outputSquare(ostream& out)
{
  double area = side * side;
  double perimeter = side * 4;
  out << "SQUARE side=" << side;
  out << roundingOn;
  out << " area=" << area << " perimeter=" << perimeter;
  out << roundingOff;
  out << "\n";
}
void Rectangle::outputRectangle(ostream& out)
{
  double area = length * width;
  double perimeter = (length + width) * 2;
  out << "RECTANGLE length=" << length << " width=" << width;
  out << roundingOn;
  out << " area=" << area << " perimeter=" << perimeter;
  out << roundingOff;
  out << "\n";
}
void Triangle::outputTriangle(ostream& out)
{
  double area = 0.5 * side * side * 0.5 * sqrt(3.0);
  double perimeter = side * 3;
  out << "TRIANGLE side=" << side;
  out << roundingOn;
  out << " area=" << area << " perimeter=" << perimeter;
  out << roundingOff;
  out << "\n";
}
void Circle::outputCircle(ostream& out)
{
  double area = PI * radius * radius;
  double perimeter = 2 * PI * radius;
  out << "CIRCLE radius=" << radius;
  out << roundingOn;
  out << " area=" << area << " perimeter=" << perimeter;
  out << roundingOff;
  out << "\n";
}
void Cylinder::outputCylinder(ostream& out)
{
  double surface = 2 * PI * radius * radius + 2 * PI * radius * height;
  double volume = PI * radius * radius * height;
  out << "CYLINDER radius=" << radius << " height=" << height;
  out << roundingOn;
  out << " surface=" << surface << " volume=" << volume;
  out << roundingOff;
  out << "\n";
}
void Cube::outputCube(ostream& out)
{
  double surface = 6 * side * side;
  double volume = side * side * side;
  out << "CUBE side=" << side;
  out << roundingOn;
  out << " surface=" << surface << " volume=" << volume;
  out << roundingOff;
  out << "\n";
}
void Prism::outputPrism(ostream& out)
{
  double surface = 2 * 0.5 * side * side * 0.5 * sqrt(3.0) + 3 * side * height;
  double volume = 0.5 * side * side * 0.5 * sqrt(3.0) * height;
  out << "PRISM side=" << side << " height=" << height;
  out << roundingOn;
  out << " surface=" << surface << " volume=" << volume;
  out << roundingOff;
  out << "\n";
}
void Box::outputBox(ostream& out)
{
  double surface = 2 * length * width + 2 * length * height + 2 * width * height;
  double volume = length * width * height;
  out << "BOX length=" << length << " width=" << width << " height=" << height;
  out << roundingOn;
  out << " surface=" << surface << " volume=" << volume;
  out << roundingOff;
  out << "\n";
}
vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}
ostream& roundingOn(ostream& out)
{
  out.setf(ios::fixed);
  out.precision(2);
  return out;
}
ostream& roundingOff(ostream& out)
{
  out.unsetf(ios::fixed);
  out.precision(6);
  return out;
}



