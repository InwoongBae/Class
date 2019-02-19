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

#include <stdlib.h>
#include <string.h>
#include <cmath>

const double PI = 3.14159265359;

vector<string> parseString(string);


  double side;
  double length;
  double width;
  double radius;
  double height;
  double area;
  double perimeter;
  double surface;
  double volume;
  ifstream fin;
  ofstream fout;
  string data;
  vector<string> tokens;

  fin.open("Shapes.input.txt");
  fout.open("Shapes.output.txt");
  while(fin.good())
  {
    getline(fin, data);
    tokens = parseString(data);

    if(tokens.size() == 0) continue;

    else if(strcmp(tokens[0].c_str(), "SQUARE") == 0)
    {
      if(tokens.size() == 1)
      {
        side = 0;
        area = side * side;
        perimeter = 4 * side;
        fout << tokens[0] << " side=" << side;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " area=" << area << " perimeter=" << perimeter;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      else
      {
        side = atof(tokens[1].c_str());
        area = side * side;
        perimeter = 4 * side;
        fout << tokens[0] << " side=" << side;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " area=" << area << " perimeter=" << perimeter;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      fout << "\n";
    }
    else if(strcmp(tokens[0].c_str(), "RECTANGLE") == 0)
    {
      if(tokens.size() == 1)
      {
        length = 0;
        width = 0;
        area = length * width;
        perimeter = 2 * length + 2 * width;
        fout << tokens[0] << " length=" << length << " width=" << width;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " area=" << area << " perimeter=" << perimeter;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      else
      {
        length = atof(tokens[1].c_str());
        width = atof(tokens[2].c_str());
        area = length * width;
        perimeter = 2 * length + 2 * width;
        fout << tokens[0] << " length=" << length << " width=" << width;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " area=" << area << " perimeter=" << perimeter;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      fout << "\n";
    }
    else if(strcmp(tokens[0].c_str(), "CIRCLE") == 0)
    {
      if(tokens.size() == 1)
      {
        radius = 0;
        area = PI * radius * radius;
        perimeter = 2 * radius * PI;
        fout << tokens[0] << " radius=" << radius;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " area=" << area << " perimeter=" << perimeter;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      else
      {
        radius = atof(tokens[1].c_str());
        area = PI * radius * radius;
        perimeter = 2 * PI * radius;
        fout << tokens[0] << " radius=" << radius;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " area=" << area << " perimeter=" << perimeter;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      fout << "\n";
    }
    else if(strcmp(tokens[0].c_str(), "TRIANGLE") == 0)
    {
      if(tokens.size() == 1)
      {
        side = 0;
        area = 0.5 * side * side * 0.5 * sqrt(3.0);
        perimeter = 3 * side;
        fout << tokens[0] << " side=" << side;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " area=" << area << " perimeter=" << perimeter;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      else
      {
        side = atof(tokens[1].c_str());
        area = 0.5 * side * side * 0.5 * sqrt(3.0);
        perimeter = 3 * side;
        fout << tokens[0] << " side=" << side;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " area=" << area << " perimeter=" << perimeter;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      fout << "\n";
    }
    else if(strcmp(tokens[0].c_str(), "CUBE") == 0)
    {
      if(tokens.size() == 1)
      {
        side = 0;
        surface = 6 * side * side;
        volume = side * side * side;
        fout << tokens[0] << " side=" << side;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " surface area=" << surface << " volume=" << volume;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      else
      {
        side = atof(tokens[1].c_str());
        surface = 6 * side * side;
        volume = side * side * side;
        fout << tokens[0] << " side=" << side;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " surface area=" << surface << " volume=" << volume;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      fout << "\n";
    }
    else if(strcmp(tokens[0].c_str(), "BOX") == 0)
    {
      if(tokens.size() == 1)
      {
        length = 0;
        width = 0;
        height = 0;
        surface = 2* length * width + 2 * width * height + 2 * length * height;
        volume = height * length * width;
        fout << tokens[0] << " length=" << length << " width=" << width << " height=" << height;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " surface area=" << surface << " volume=" << volume;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      else
      {
        length = atof(tokens[1].c_str());
        width = atof(tokens[2].c_str());
        height = atof(tokens[3].c_str());
        surface = 2* length * width + 2 * width * height + 2 * length * height;
        volume = height * length * width;
        fout << tokens[0] << " length=" << length << " width=" << width << " height=" << height;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " surface area=" << surface << " volume=" << volume;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      fout << "\n";
    }
    else if(strcmp(tokens[0].c_str(), "CYLINDER") == 0)
    {
      if(tokens.size() == 1)
      {
        radius = 0;
        height = 0;
        surface = 2* PI * radius * radius + 2 * PI * radius * height;
        volume = radius * radius * PI * height;
        fout << tokens[0] << " radius=" << radius << " height=" << height;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " surface area=" << surface << " volume=" << volume;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      else
      {
        radius = atof(tokens[1].c_str());
        height = atof(tokens[2].c_str());
        surface = 2* PI * radius * radius + 2 * PI * radius * height;
        volume = radius * radius * PI * height;
        fout << tokens[0] << " radius=" << radius << " height=" << height;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " surface area=" << surface << " volume=" << volume;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      fout << "\n";
    }
    else if(strcmp(tokens[0].c_str(), "PRISM") == 0)
    {
      if(tokens.size() == 1)
      {
        side = 0;
        height = 0;
        surface = 2 * 0.5 * side * side * 0.5 * sqrt(3.0) + 3 * side * height;
        volume = 0.5 * side * side * 0.5 * sqrt(3.0) * height;
        fout << tokens[0] << " side=" << side << " height=" << height;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " surface area=" << surface << " volume=" << volume;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      else
      {
        side = atof(tokens[1].c_str());
        height = atof(tokens[2].c_str());
        surface = 2 * 0.5 * side * side * 0.5 * sqrt(3.0) + 3 * side * height;
        volume = 0.5 * side * side * 0.5 * sqrt(3.0) * height;
        fout << tokens[0] << " side=" << side << " height=" << height;
        fout.setf(ios::fixed);
        fout.precision(2);
        fout << " surface area=" << surface << " volume=" << volume;
        fout.unsetf(ios::fixed);
        fout.precision(6);
      }
      fout << "\n";
    }
    else if(strcmp(tokens[0].c_str(), "EOF") == 0)
      break;
    else
      fout << tokens[0] << " Invalid Object" << "\n";
  }
  fin.close( );
  fout.close();

}

vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}
