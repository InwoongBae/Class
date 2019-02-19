// identification comments code block
// Programmer: Inwoong Bae
// Programmer's ID: 1505170

#ifndef pSHAPES_h
#define pSHAPES_h

#include <string>
#include <vector>
using namespace std;

#include <cstdlib>

struct Shape
{
  virtual void output(ostream&) const = 0;
  virtual ~Shape(){}
};


  struct Square : public Shape
  {
    Square(const vector<string>& tokens) : side(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0){}
    void output(ostream&) const;
    Square& operator=(const Square&);

    protected:
    const double side;
  };

struct Cube : public Square
{
  Cube(const vector<string>& tokens) : Square(tokens){}
  void output(ostream&) const;
  Cube& operator=(const Cube&);
};

namespace comsc
{
	struct Rectangle : public Shape
	{
		Rectangle(const vector<string>& tokens) : length(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0), width(tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0) {}
		void output(ostream&) const;
		Rectangle& operator=(const Rectangle&);

	protected:
		const double length;
		const double width;
	};
}
struct Box : public comsc::Rectangle
{
  Box(const vector<string>& tokens) : comsc::Rectangle(tokens), height(tokens.size() >= 4 ? atof(tokens[3].c_str()) : 0){}
  void output(ostream&) const;
  Box& operator=(const Box&);

  protected:
  const double height;
};

struct Circle : public Shape
{
  Circle(const vector<string>& tokens) : radius(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0){}
  void output(ostream&) const;
  Circle& operator=(const Circle&);

  protected:
  const double radius;
};

struct Cylinder : public Circle
{
  Cylinder(vector<string> tokens) : Circle(tokens), height(tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0){}
  void output(ostream&) const;
  Cylinder& operator=(const Cylinder&);

  protected:
  const double height;
};

struct Triangle : public Shape
{
  Triangle(const vector<string>& tokens) : side(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0){}
  void output(ostream&) const;
  Triangle& operator=(const Triangle&);

  protected:
  const double side;
};

struct Prism : public Triangle
{
  Prism(vector<string> tokens) : Triangle(tokens), height(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0){}
  void output(ostream&) const;
  Prism& operator=(const Prism&);

  protected:
  const double height;
};

ostream& operator<<(ostream&, const Shape&);

#endif
