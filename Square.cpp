#include "ShapeTwoD.h"
#include "Square.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
// constructors and destructors
Square::Square(){}
Square::~Square(){}
Square::Square(string name, bool containWarpSpace , int x1, int x2, int x3, int x4, 
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
void Square::setXY(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4)
{
    this->y1 = y1;   this->x1 = x1; 
    this->y2 = y2;   this->x2 = x2; 
    this->y3 = y3;   this->x3 = x3;
    this->y4 = y4;   this->x4 = x4; 
}
// getters and setters 
// inherit name from ShapeTwoD base class 
string Square::getName()
{
    return name;
}
// inherit containsWarpspace from ShapeTwoD base class
bool Square::getContainSpace()
{
    return containWarpSpace;
}
// virtual functions computeArea(), computePerimeter(), isPointInShape(int x, int y),
// isPointOnShape(int x, int y), toString() from base class ShapeTwoD
// child class overriding virtual function from base class
double Square::computeArea()
{
	area = ( y4 - y1) * (x2 - x1);
	return abs(area);
}
double Square::computePerimeter()
{
	perimeter = 2 * (( y4 - y1) + (x2 - x1));
	return abs (perimeter);
}
void Square::setName(string name)
{
            this->name = name;
}
bool Square::isASquare()
{
        return  checkXYLength() &&  checkZeroValue();		
}
bool Square::checkXYLength()
{
	
		line1 = (x2 - x1);
		if (line1 < 0)
		line1 = line1 * -1;
	
		line2 = (x3 - x4);
		if (line2 < 0)
		line2 = line2 * -1;
	
		line3 = (y3 - y2);
		if (line3 < 0)
		line3 = line3 * -1;
	
		line4 = (y4 - y1);
		if (line4 < 0)
		line4 = line4 * -1;
	
		return (line1 == line2 && line3 == line1 && line1 == line4);
}
// check x and y values are zero  
bool Square::checkZeroValue ()
{
			return (y1 != 0 || y2 != 0 || y3 !=0 || y4 != 0 ||
				x1 != 0 || x2 != 0 || x3 !=0 || x4 != 0 );
}
bool Square::isPointOnShape(int x, int y) 
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
bool Square::isPointInShape(int x, int y) 
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

string Square::toString()
{
// stringstream associates a string object with a stream enabling user to read from  string as if it were a stream 
			stringstream ss;
			
                            
            ss << "Name : "<< name <<endl;
            if(containWarpSpace == false )
                ss<<"Special Type : NS"<<endl;
            else
                ss<<"Special Type : WS"<<endl;
		    ss << "Area : " << setprecision (2) << fixed << computeArea()<< endl ;
			ss << "Point [1]: "<< "(" << x1 << "," << y1 <<")"<<endl;
			ss << "Point [2]: "<< "(" << x2 << "," << y2 <<")"<<endl;
			ss << "Point [3]: "<< "(" << x3 << "," << y3 <<")"<<endl;
			ss << "Point [4]: "<< "(" << x4 << "," << y4 <<")"<<endl;
			ss<< "Perimeter of square object : "<<setprecision (2) << fixed<< computePerimeter() << endl;
			ss << "Points on perimeter : " ;
		

				
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



