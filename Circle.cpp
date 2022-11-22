#include "ShapeTwoD.h"
#include "Circle.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>


// constructors and destructors
Circle::Circle() {}
Circle::~Circle() {}
Circle::Circle(string name, int radius,  double pi , int x1, int y1, double area)
{ 
    this->name = name ;
    this->radius = radius; this-> pi = pi; this->x1= x1; this ->y1 = y1;
    this->area = area;
}
  // getters and setters   
void Circle:: setXY(int x1, int y1){this -> x1 = x1; this -> y1 = y1;}
void Circle:: setRadius(int radius){this -> radius = radius;}
void Circle:: setPi(double pi)
{ 
    pi = 3.14159;
    this -> pi = pi; 
}
// inherit name from ShapeTwoD base class
string Circle:: getName(){ return name;}
// inherit containsWarpspace from ShapeTwoD base class
bool Circle:: getContainSpace()
{
	return containWarpSpace;
}

// virtual functions computeArea(), computePerimeter(), isPointInShape(int x, int y),
// isPointOnShape(int x, int y), toString() from base class ShapeTwoD
// child class overriding virtual function from base class
double Circle:: computeArea() 
{
	area = pi * radius * radius;
	return abs(area);
}
double Circle:: computePerimeter()
{
	circumference =  pi * (radius + radius);
	return abs (circumference);
}
// compute points on perimeter of circle
int Circle:: computeXRC1 ()
{
	xrc1 = x1 - radius;
	return xrc1;
}
int Circle:: computeXRC2 ()
{
	xrc2 = x1 + radius;
	return xrc2;
}
int Circle:: computeYRC1 ()
{
	yrc1 = y1 - radius;
	return yrc1;
}
int Circle:: computeYRC2 ()
{
	yrc2 = y1 + radius;
	return yrc2;
}
bool Circle:: isPointInShape(int x, int y) 
{
	
			for (int i = 1; i < radius; ++i)
			{
				if(y == y1 - radius + i && (x == x1 + i || x == x1 - i))
				{
					return true;
				}

				if(y == y1 - radius + i && (x < x1 + i && x > x1 - i))
				{
					return true;
				}

				if(y == y1 + radius - i && (x == x1 + i || x == x1 - i))
				{
					return true;
				}

				if(y == y1 + radius - i && (x < x1 + i && x > x1 - i))
				{
					return true;
				}
				
				if(x == x1 - radius + i && (y == y1 + i || y == y1 - i))
				{
					return true;
				}

				if(x == x1 - radius + i && (y < y1 + i && y > y1 - i))
				{
					return true;
				}

				if(x == x1 + radius - i && (y == y1 + i || y == y1 - i))
				{
					return true;
				}

				if(x == x1 + radius - i && (y < y1 + i && y > y1 - i))
				{
					return true;
				}
			}

			if (x == x1 && y >= y1 - radius && y <= y1 + radius)
			{
				return true;
			}

			else if(y == y1 && x >= x1 - radius && x <= x1 + radius)
			{
				return true;
			}
				
			else
			{
				return false;
			}
}
 
 // check values for circle   
bool Circle:: isACircle(){return(radius == radius);}
void Circle:: setName(string name){this -> name = name;}
string Circle:: toString()
{
// stringstream associates a string object with a stream enabling user to read from  string as if it were a stream 
         stringstream ss;
         ss<<"Name: "<< name<< endl;
          if(containWarpSpace == false )
             ss<<"Special Type : NS"<<endl;
          else
             ss<<"Special Type : WS"<<endl;

	     ss << "Area : " <<setprecision (2) << fixed << computeArea()<< endl;
	     
	     ss<< "Circumference of circle object : "<<setprecision (2) << fixed << computePerimeter() << endl;
	     ss << "Points on perimeter : " ;
             ss <<  "[" << computeXRC1 () << "," << y1 <<"],";
	     ss <<  "[" << x1 << "," << computeYRC1 () <<"],";
	     ss <<  "[" <<computeXRC2 () << "," << y1 <<"],";
	     ss <<  "[" << x1 << "," << computeYRC2 () <<"]"<<endl;
             ss << "Points within shape: ";
	     for (int i = x1 - radius; i <= x1 + radius; ++i)
			{
				int pointOnLine1 = 0;
				pointOnLine1 += i;
				for (int j = y1 - radius; j <= y1 + radius; ++j)
				{
					int pointOnLine2 = 0;
					pointOnLine2 += j;
					if(isPointInShape(i,j) == true)
					{
						ss << "[" << pointOnLine1 << "," << pointOnLine2 <<"],";
					}
				}
			}
          return ss.str();
	
}
                   

