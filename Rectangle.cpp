#include "ShapeTwoD.h"
#include "Rectangle.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>


// constructors and destructors
Rectangle::Rectangle(){}
	    
Rectangle::Rectangle(string name, bool containWarpSpace , int x1, int x2, int x3, int x4, 
                                           int y1, int y2, int y3, int y4, double area)
{
		this -> name = name;
		this -> area = area;
		this ->containWarpSpace = containWarpSpace;
		this -> x1 = x1;
		this -> x2 = x2;
		this -> x3 = x3;
		this -> x4 = x4;
		this -> y1 = y1;
		this -> y2 = y2;
		this -> y3 = y3;
		this -> y4 = y4;
}

void Rectangle::setXY(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4)
{
        this->y1 = y1;   this->x1 = x1;
        this->y2 = y2;   this->x2 = x2;
        this->y3 = y3;   this->x3 = x3;
        this->y4 = y4;   this->x4 = x4;
                  
                   
} 
Rectangle::~Rectangle(){}
// getters and setters 

// inherit name from ShapeTwoD base class 
string Rectangle:: getName()
{
	return name;
}
// inherit containsWarpspace from ShapeTwoD base class
bool Rectangle:: getContainSpace()
{
	return containWarpSpace;
}
void Rectangle:: setName(string name)
{
    this->name = name;
}
// virtual functions computeArea(), computePerimeter(), isPointInShape(int x, int y),
// isPointOnShape(int x, int y), toString() from base class ShapeTwoD
// child class overriding virtual function from base class
double Rectangle::computeArea()
{
	area = ( y4 - y1) * (x2 - x1);
	return abs(area);
}
double Rectangle::computePerimeter()
{
	perimeter = 2 * (( y4 - y1) + (x2 - x1));
	return abs (perimeter);
}
		
bool Rectangle::checkReactangleLength()
{
	lineSet1a  = (x2 - x1);
    lineSet1b  = (x3 - x4);
	lineSet2a  = (y3 - y2);
	lineSet2b  = (y4 - y1);

	if(lineSet1a == lineSet1b || lineSet2a  == lineSet2b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

 // check x and y values are zero  		
bool Rectangle::checkZeroValue ()
{
	return (y1 != 0 || y2 != 0 || y3 !=0 || y4 != 0 &&
			x1 != 0 || x2 != 0 || x3 !=0 || x4 != 0 );
}

bool Rectangle::isARectangle ()
{
    return checkReactangleLength() && checkZeroValue();
}
bool Rectangle::isPointOnShape(int x, int y)
{
	if(x > x1 && x < x2 && y == y1)
	{
		return true;
	}

	else if(y > y1 && y < y4 && x == x1)
	{
		return true;
	}

	else if(x > x4 && x < x3 && y == y4)
	{
		return true;
	}

	else if(y > y2 && y < y3 && x == x2)
	{
		return true;
	}

	else
	{
		return false;
	}
}
bool Rectangle::isPointInShape(int x, int y)
{
	if((x > x1 && y > y1 && x < x3 && y < y3)||
	   (x > x2 && y > y2 && x < x4 && y < y4))
	{
		return true;
	}

	else
	{
		return false;
	}
}

string Rectangle::toString()
{
// stringstream associates a string object with a stream enabling user to read from  string as if it were a stream 
			
       stringstream ss;
			
                                        
                                        //ss << "Shape [" << index << "]"<<endl;
        ss << "Name : "<< name <<endl;
        if(containWarpSpace == false )
            ss<<"Special Type : NS"<<endl;
        else
            ss<<"Special Type : WS"<<endl;

		ss<< "Area : " << computeArea()<< endl ;
		ss<< "Point [1]: "<< "(" << x1 << "," << y1 <<")"<<endl;
	    ss<< "Point [2]: "<< "(" << x2 << "," << y2 <<")"<<endl;
		ss<< "Point [3]: "<< "(" << x3 << "," << y3 <<")"<<endl;
		ss<< "Point [4]: "<< "(" << x4 << "," << y4 <<")"<<endl;
		ss<< setprecision (2) << fixed << "Perimeter of rectangle object : "<<computePerimeter() << endl;
		ss<< "Points on perimeter : " ;
		
			
				
					for(int i = x1 ; i < x2 ; i++)// line 1
					{
						int pointOnLine1 = 0;
						pointOnLine1 += i;
					
					        if(isPointOnShape(pointOnLine1, y1) == true)
						{
						   ss <<  "[" << pointOnLine1 << "," << y1 <<"],";						
						}
					
						}
			    		
					for(int i = y1 ; i < y4 ; i++)// line 2
					{
						int pointOnLine1 = 0;
						pointOnLine1 += i;
					
						if(isPointOnShape(x2, pointOnLine1) == true)
						{
					           ss << "[" << x2 << "," << pointOnLine1 <<"],";
						}
				
						}
				
					for(int i = x4 ; i < x3 ; i++)// line 3
					{
						int pointOnLine1 = 0;
						pointOnLine1 += i;
					
						if(isPointOnShape(pointOnLine1, y3) == true)
					        {
					           ss<< "[" << pointOnLine1 << "," << y3 <<"],";
						}
					
					}
				
					for(int i = y2 ; i < y3 ; i++)// line 4
					{
						int pointOnLine1 = 0;
						pointOnLine1 += i;
					
						if(isPointOnShape(y2, pointOnLine1) == true)
						{
					           ss << "[" << x4 << "," << pointOnLine1 <<"]";
						}
					
					}
						cout<<endl;
				                ss << "\nPoints within shape : ";


					for (int i = x1; i < x3; ++i)
					{
						int pointOnLine1 = 0;
						pointOnLine1 += i;
						
						for (int j = y1; j < y3; ++j)
						{    
							int pointOnLine2 = 0;
							pointOnLine2 += j;
							if(isPointInShape(i,j) == true)
							{
							ss << "[" << pointOnLine1 << "," << pointOnLine2 <<"]";
							}
						}
					}
					for (int i = x2; i < x4; ++i)
					{
						int pointOnLine1 = 0;
						pointOnLine1 += i;
						
						for (int j = y4; j < y2; ++j)
						{    
							int pointOnLine2 = 0;
							pointOnLine2 += j;
							if(isPointInShape(i,j) == true)
							{
							ss << "[" << pointOnLine1 << "," << pointOnLine2 <<"]";
							}
						}
					}							
                        
			
                        return ss.str();
			
}
		

