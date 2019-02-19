// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include <cmath>

#include "pShapes.h"

const double PI = 3.14159265359;


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

void Square::output(ostream& out) const
{
  const double area = side * side;
  const double perimeter = side * 4;
  out << "SQUARE side=" << side;
  out << roundingOn;
  out << " area=" << area << " perimeter=" << perimeter;
  out << roundingOff;
  out << "\n";
}

Square& Square::operator=(const Square& copyThis)
{
  Square& host = *this;
  if(this != &copyThis)
    const_cast<double&>(host.side) = copyThis.side;
  return host;
}

void comsc::Rectangle::output(ostream& out) const
{
  const double area = length * width;
  const double perimeter = (length + width) * 2;
  out << "RECTANGLE length=" << length << " width=" << width;
  out << roundingOn;
  out << " area=" << area << " perimeter=" << perimeter;
  out << roundingOff;
  out << "\n";
}

comsc::Rectangle& comsc::Rectangle::operator=(const Rectangle& copyThis)
{
  Rectangle& host = *this;
  if(this != &copyThis)
  {
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
  }
  return host;
}

void Triangle::output(ostream& out) const
{
  const double area = 0.5 * side * side * 0.5 * sqrt(3.0);
  const double perimeter = side * 3;
  out << "TRIANGLE side=" << side;
  out << roundingOn;
  out << " area=" << area << " perimeter=" << perimeter;
  out << roundingOff;
  out << "\n";
}

Triangle& Triangle::operator=(const Triangle& copyThis)
{
  Triangle& host = *this;
  if(this != &copyThis)
    const_cast<double&>(host.side) = copyThis.side;
  return host;
}

void Circle::output(ostream& out) const
{
  const double area = PI * radius * radius;
  const double perimeter = 2 * PI * radius;
  out << "CIRCLE radius=" << radius;
  out << roundingOn;
  out << " area=" << area << " perimeter=" << perimeter;
  out << roundingOff;
  out << "\n";
}

Circle& Circle::operator=(const Circle& copyThis)
{
  Circle& host = *this;
  if(this != &copyThis)
    const_cast<double&>(host.radius) = copyThis.radius;
  return host;
}

void Cylinder::output(ostream& out) const
{
  double surface = 2 * PI * radius * radius + 2 * PI * radius * height;
  double volume = PI * radius * radius * height;
  out << "CYLINDER radius=" << radius << " height=" << height;
  out << roundingOn;
  out << " surface=" << surface << " volume=" << volume;
  out << roundingOff;
  out << "\n";
}

Cylinder& Cylinder::operator=(const Cylinder& copyThis)
{
  Cylinder& host = *this;
  if(this != &copyThis)
  {
    const_cast<double&>(host.radius) = copyThis.radius;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

void Cube::output(ostream& out) const
{
  const double surface = 6 * side * side;
  const double volume = side * side * side;
  out << "CUBE side=" << side;
  out << roundingOn;
  out << " surface=" << surface << " volume=" << volume;
  out << roundingOff;
  out << "\n";
}

Cube& Cube::operator=(const Cube& copyThis)
{
  Cube& host = *this;
  if(this != &copyThis)
    const_cast<double&>(host.side) = copyThis.side;
  return host;
}

void Prism::output(ostream& out) const
{
  const double surface = 2 * 0.5 * side * side * 0.5 * sqrt(3.0) + 3 * side * height;
  const double volume = 0.5 * side * side * 0.5 * sqrt(3.0) * height;
  out << "PRISM side=" << side << " height=" << height;
  out << roundingOn;
  out << " surface=" << surface << " volume=" << volume;
  out << roundingOff;
  out << "\n";
}

Prism& Prism::operator=(const Prism& copyThis)
{
  Prism& host = *this;
  if(this != &copyThis)
  {
    const_cast<double&>(host.side) = copyThis.side;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

void Box::output(ostream& out) const
{
  const double surface = 2 * length * width + 2 * length * height + 2 * width * height;
  const double volume = length * width * height;
  out << "BOX length=" << length << " width=" << width << " height=" << height;
  out << roundingOn;
  out << " surface=" << surface << " volume=" << volume;
  out << roundingOff;
  out << "\n";
}

Box& Box::operator=(const Box& copyThis)
{
  Box& host = *this;
  if(this != &copyThis)
  {
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

ostream& operator<<(ostream& out, const Shape& s)
{
  s.output(out);
  return out;
}
