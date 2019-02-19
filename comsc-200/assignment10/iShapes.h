// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#ifndef iShapes_h
#define iShapes_h

#include <string>
#include <vector>
using namespace std;

#include <cstdlib>

struct Shape{};

struct Square : public Shape
{
  Square(const vector<string>& tokens) : side(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0){}
  void outputSquare(ostream&) const;
  Square& operator=(const Square&);

  protected:
  const double side;
};

struct Cube : public Square
{
  Cube(const vector<string>& tokens) : Square(tokens){}
  void outputCube(ostream&) const;
  Cube& operator=(const Cube&);
};

struct Rectangle : public Shape
{
  Rectangle(const vector<string>& tokens) : length(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0), width(tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0){}
  void outputRectangle(ostream&) const;
  Rectangle& operator=(const Rectangle&);

  protected:
  const double length;
  const double width;
};

struct Box : public Rectangle
{
  Box(const vector<string>& tokens) : Rectangle(tokens), height(tokens.size() >= 4 ? atof(tokens[3].c_str()) : 0){}
  void outputBox(ostream&) const;
  Box& operator=(const Box&);

  protected:
  const double height;
};

struct Circle : public Shape
{
  Circle(const vector<string>& tokens) : radius(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0){}
  void outputCircle(ostream&) const;
  Circle& operator=(const Circle&);

  protected:
  const double radius;
};

struct Cylinder : public Circle
{
  Cylinder(vector<string> tokens) : Circle(tokens), height(tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0){}
  void outputCylinder(ostream&) const;
  Cylinder& operator=(const Cylinder&);

  protected:
  const double height;
};

struct Triangle : public Shape
{
  Triangle(const vector<string>& tokens) : side(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0){}
  void outputTriangle(ostream&) const;
  Triangle& operator=(const Triangle&);

  protected:
  const double side;
};

struct Prism : public Triangle
{
  Prism(vector<string> tokens) : Triangle(tokens), height(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0){}
  void outputPrism(ostream&) const;
  Prism& operator=(const Prism&);

  protected:
  const double height;
};
#endif
