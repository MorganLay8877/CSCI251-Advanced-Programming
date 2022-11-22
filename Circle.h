#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

class Circle : public ShapeTwoD
{
    private :
     int radius;
     double pi = 3.14159;
     int x1, y1;
     int xrc1, xrc2;
     int yrc1, yrc2;
     double area;
     double circumference;

    public:
// constructors and destructors
     Circle();
     ~Circle();
     Circle(string name, int radius,  double pi , int x1, int y1, double area);
    
  // getters and setters   
     void setXY(int x1, int y1);
     void setRadius(int radius);
     void setPi(double pi);
// inherit name from ShapeTwoD base class
     string getName();
// inherit containsWarpspace from ShapeTwoD base class
     bool getContainSpace();
// virtual functions computeArea(), computePerimeter(), isPointInShape(int x, int y),
// isPointOnShape(int x, int y), toString() from base class ShapeTwoD
// child class overriding virtual function from base class
     double computeArea() override;
     double computePerimeter()override;
    
// compute points on perimeter of circle
     int computeXRC1 ();
     int computeXRC2 ();
     int computeYRC1 ();
     int computeYRC2 ();
    
     bool isPointInShape(int x, int y) override;
// check values for circle   
     bool isACircle();
     void setName(string name);
     string toString()override;
                        
};
#endif
