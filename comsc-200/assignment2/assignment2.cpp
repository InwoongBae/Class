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
};
void outputSquare(ostream&, const Square&);

struct Rectangle
{
  double length;
  double width;
};
void outputRectangle(ostream&, const Rectangle&);

struct Circle
{
  double radius;
};
void outputCircle(ostream&, const Circle&);

struct Triangle
{
  double side;
};
void outputTriangle(ostream&, const Triangle&);

struct Cube
{
  double side;
};
void outputCube(ostream&, const Cube&);

struct Box
{
  double length;
  double width;
  double height;
};
void outputBox(ostream&, const Box&);

struct Cylinder
{
  double radius;
  double height;
};
void outputCylinder(ostream&, const Cylinder&);

struct Prism
{
  double side;
  double height;
};
void outputPrism(ostream&, const Prism&);

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
      if(tokens.size() == 1)
        s->side = 0;
      else
        s->side = atof(tokens[1].c_str());
      myBag.push_back(s);
      myBagType.push_back('s');
    }
    else if(strcmp(tokens[0].c_str(), "RECTANGLE") == 0)
    {
      Rectangle* r = new Rectangle;
      if(tokens.size() == 1)
      {
        r->length = 0;
        r->width = 0;
      }
      else if(tokens.size() == 2)
      {
        r->length = atof(tokens[1].c_str());
        r->width = 0;
      }
      else
      {
        r->length = atof(tokens[1].c_str());
        r->width = atof(tokens[2].c_str());
      }
      myBag.push_back(r);
      myBagType.push_back('r');
    }
    else if(strcmp(tokens[0].c_str(), "TRIANGLE") == 0)
    {
      Triangle* t = new Triangle;
      if(tokens.size() == 1)
        t->side = 0;
      else
        t->side = atof(tokens[1].c_str());
      myBag.push_back(t);
      myBagType.push_back('t');
    }
    else if(strcmp(tokens[0].c_str(), "CIRCLE") == 0)
    {
      Circle* c = new Circle;
      if(tokens.size() == 1)
        c->radius = 0;
      else
        c->radius = atof(tokens[1].c_str());
        myBag.push_back(c);
        myBagType.push_back('c');
    }
    else if(strcmp(tokens[0].c_str(), "CYLINDER") == 0)
    {
      Cylinder* y = new Cylinder;
      if(tokens.size() == 1)
      {
        y->height = 0;
        y->radius = 0;
      }
      else if(tokens.size() == 2)
      {
        y->radius = atof(tokens[1].c_str());
        y->height = 0;
      }
      else
      {
        y->radius = atof(tokens[1].c_str());
        y->height = atof(tokens[2].c_str());
      }
      myBag.push_back(y);
      myBagType.push_back('y');
    }
    else if(strcmp(tokens[0].c_str(), "CUBE") == 0)
    {
      Cube* u = new Cube;
      if(tokens.size() == 1)
        u->side = 0;
      else
        u->side = atof(tokens[1].c_str());
      myBag.push_back(u);
      myBagType.push_back('u');

    }
    else if(strcmp(tokens[0].c_str(), "BOX") == 0)
    {
      Box* b = new Box;
      if(tokens.size() == 1)
      {
        b->height = 0;
        b->length = 0;
        b->width = 0;
      }
      else if(tokens.size() == 2)
      {
        b->length = atof(tokens[1].c_str());
        b->width = 0;
        b->height = 0;
      }
      else if(tokens.size() == 3)
      {
        b->length = atof(tokens[1].c_str());
        b->width = atof(tokens[2].c_str());
        b->height = 0;
      }
      else
      {
        b->length = atof(tokens[1].c_str());
        b->width = atof(tokens[2].c_str());
        b->height = atof(tokens[3].c_str());
      }
      myBag.push_back(b);
      myBagType.push_back('b');
    }
    else if(strcmp(tokens[0].c_str(), "PRISM") == 0)
    {
      Prism* p = new Prism;
      if(tokens.size() == 1)
      {
        p->side = 0;
        p->height = 0;
      }
      else if(tokens.size() == 2)
      {
        p->side = atof(tokens[1].c_str());
        p->height = 0;
      }
      else
      {
        p->side = atof(tokens[1].c_str());
        p->height = atof(tokens[2].c_str());
      }
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
      outputSquare(fout, rSquare);
    }
     else if (myBagType[i] == 'r'){
       Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
       Rectangle& rRectangle = *pRectangle;
       outputRectangle(fout, rRectangle);
     }
     else if (myBagType[i] == 'c'){
       Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
       Circle& rCircle = *pCircle;
       outputCircle(fout, rCircle);
     }
     else if (myBagType[i] == 't'){
       Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
       Triangle& rTriangle = *pTriangle;
       outputTriangle(fout, rTriangle);
     }
     else if (myBagType[i] == 'u'){
       Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
       Cube& rCube = *pCube;
       outputCube(fout, rCube);
     }
     else if (myBagType[i] == 'b'){
       Box* pBox = reinterpret_cast<Box*>(myBag[i]);
       Box& rBox = *pBox;
       outputBox(fout, rBox);
     }
     else if (myBagType[i] == 'y'){
       Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
       Cylinder& rCylinder = *pCylinder;
       outputCylinder(fout, rCylinder);
     }
     else if (myBagType[i] == 'p'){
       Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
       Prism& rPrism = *pPrism;
       outputPrism(fout, rPrism);
     }
  }

  fout.close();

  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    if (myBagType[i] == 's')
    {
      Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
      Square& rSquare = *pSquare;
      outputSquare(cout, rSquare);
    }
    else if (myBagType[i] == 'r')
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
      Rectangle& rRectangle = *pRectangle;
      outputRectangle(cout, rRectangle);
    }
    else if (myBagType[i] == 'c')
    {
      Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
      Circle& rCircle = *pCircle;
      outputCircle(cout, rCircle);
    }
    else if (myBagType[i] == 't')
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
      Triangle& rTriangle = *pTriangle;
      outputTriangle(cout, rTriangle);
    }
    else if (myBagType[i] == 'u')
    {
      Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
      Cube& rCube = *pCube;
      outputCube(cout, rCube);
    }
    else if (myBagType[i] == 'b')
    {
      Box* pBox = reinterpret_cast<Box*>(myBag[i]);
      Box& rBox = *pBox;
      outputBox(cout, rBox);
    }
    else if (myBagType[i] == 'y')
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
      Cylinder& rCylinder = *pCylinder;
      outputCylinder(cout, rCylinder);
    }
    else if (myBagType[i] == 'p')
    {
      Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
      Prism& rPrism = *pPrism;
      outputPrism(cout, rPrism);
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
void outputSquare(ostream& out, const Square& s)
{
  double area = s.side * s.side;
  double perimeter = s.side * 4;
  out << "SQUARE side=" << s.side;
  out.setf(ios::fixed);
  out.precision(2);
  out << " area=" << area << " perimeter=" << perimeter;
  out.unsetf(ios::fixed);
  out.precision(6);
  out << "\n";
}
void outputRectangle(ostream& out, const Rectangle& r)
{
  double area = r.length * r.width;
  double perimeter = (r.length + r.width) * 2;
  out << "RECTANGLE length=" << r.length << " width=" << r.width;
  out.setf(ios::fixed);
  out.precision(2);
  out << " area=" << area << " perimeter=" << perimeter;
  out.unsetf(ios::fixed);
  out.precision(6);
  out << "\n";
}
void outputTriangle(ostream& out, const Triangle& t)
{
  double area = 0.5 * t.side * t.side * 0.5 * sqrt(3.0);
  double perimeter = t.side * 3;
  out << "TRIANGLE side=" << t.side;
  out.setf(ios::fixed);
  out.precision(2);
  out << " area=" << area << " perimeter=" << perimeter;
  out.unsetf(ios::fixed);
  out.precision(6);
  out << "\n";
}
void outputCircle(ostream& out, const Circle& c)
{
  double area = PI * c.radius * c.radius;
  double perimeter = 2 * PI * c.radius;
  out << "CIRCLE radius=" << c.radius;
  out.setf(ios::fixed);
  out.precision(2);
  out << " area=" << area << " perimeter=" << perimeter;
  out.unsetf(ios::fixed);
  out.precision(6);
  out << "\n";
}
void outputCylinder(ostream& out, const Cylinder& y)
{
  double surface = 2 * PI * y.radius * y.radius + 2 * PI * y.radius * y.height;
  double volume = PI * y.radius * y.radius * y.height;
  out << "CYLINDER radius=" << y.radius << " height=" << y.height;
  out.setf(ios::fixed);
  out.precision(2);
  out << " surface=" << surface << " volume=" << volume;
  out.unsetf(ios::fixed);
  out.precision(6);
  out << "\n";
}
void outputCube(ostream& out, const Cube& u)
{
  double surface = 6 * u.side * u.side;
  double volume = u.side * u.side * u.side;
  out << "CUBE side=" << u.side;
  out.setf(ios::fixed);
  out.precision(2);
  out << " surface=" << surface << " volume=" << volume;
  out.unsetf(ios::fixed);
  out.precision(6);
  out << "\n";
}
void outputPrism(ostream& out, const Prism& p)
{
  double surface = 2 * 0.5 * p.side * p.side * 0.5 * sqrt(3.0) + 3 * p.side * p.height;
  double volume = 0.5 * p.side * p.side * 0.5 * sqrt(3.0) * p.height;
  out << "PRISM side=" << p.side << " height=" << p.height;
  out.setf(ios::fixed);
  out.precision(2);
  out << " surface=" << surface << " volume=" << volume;
  out.unsetf(ios::fixed);
  out.precision(6);
  out << "\n";
}
void outputBox(ostream& out, const Box& b)
{
  double surface = 2 * b.length * b.width + 2 * b.length * b.height + 2 * b.width * b.height;
  double volume = b.length * b.width * b.height;
  out << "BOX length=" << b.length << " width=" << b.width << " height=" << b.height;
  out.setf(ios::fixed);
  out.precision(2);
  out << " surface=" << surface << " volume=" << volume;
  out.unsetf(ios::fixed);
  out.precision(6);
  out << "\n";
}
vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}



