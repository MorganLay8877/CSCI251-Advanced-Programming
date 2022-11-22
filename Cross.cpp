#include "ShapeTwoD.h"
#include "Cross.h"
#include <iostream> 
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <typeinfo>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>


// constructors and destructors
Cross::Cross(){}
Cross:: ~Cross(){}
Cross::Cross(int x1, int x2, int x3, int x4, int x5, int x6, int x7,
            int x8, int x9, int x10, int x11, int x12,
            int y1, int y2, int y3, int y4, int y5, int y6,
            int y7, int y8, int y9, int y10, int y11, int y12, 
            string name, bool containWarpSpace )
           {
                    this-> name = name; this-> containWarpSpace = containWarpSpace;
                    this-> x1 = x1;  this-> y1 = y1;
                    this-> x2 = x2;  this-> y2 = y2; 
                    this-> x3=  x3;  this-> y3 = y3; 
                    this-> x4 = x4;  this-> y4 = y4;
                    this-> x5 = x5;  this-> y5 = y5;
                    this-> x6 = x6;  this-> y6 = y6; 
                    this-> x7 = x7;  this-> y7 = y7; 
                    this-> x8 = x8;  this-> y8 = y8; 
                    this-> x9  = x9; this->y9  = y9;
                    this->x10 = x10; this->y10 = y10; 
                    this->x11 = x11; this->y11 = y11;
                    this->x12 = x12; this->y12 = y12;
            }

// getters and setters
void Cross::setXY(int x1, int x2, int x3, int x4, int x5, int x6,
           int x7, int x8, int x9, int x10, int x11, int x12,
           int y1, int y2, int y3, int y4, int y5, int y6, int y7,
            int y8, int y9, int y10, int y11, int y12)
           {
                    this-> x1 = x1;  this-> y1 = y1;
                    this-> x2 = x2;  this-> y2 = y2; 
                    this-> x3=  x3;  this-> y3 = y3; 
                    this-> x4 = x4;  this-> y4 = y4;
                    this-> x5 = x5;  this-> y5 = y5;
                    this-> x6 = x6;  this-> y6 = y6; 
                    this-> x7 = x7;  this-> y7 = y7; 
                    this-> x8 = x8;  this-> y8 = y8; 
                    this-> x9  = x9; this-> y9 = y9;
                    this->x10 = x10; this->y10 = y10; 
                    this->x11 = x11; this->y11 = y11;
                    this->x12 = x12; this->y12 = y12;
            }
// inherit name from ShapeTwoD base class
string Cross::getName(){ return name;}
// inherit containsWarpspace from ShapeTwoD base class
bool Cross::getContainSpace(){return containWarpSpace;}
// virtual functions computeArea(), computePerimeter(), isPointInShape(int x, int y),
// isPointOnShape(int x, int y), toString() from base class ShapeTwoD
// child class overriding virtual function from base class
double Cross::computeArea()
{
	area = (y12-y1) * (x2-x1) + (y10-y3) * (x4-x3) + (x6-x5) * (y7-y6); 
	return abs(area);
}
      
double Cross::computePerimeter()
{
	perimeter = (y12-y1) + 2 * (x2 - x1) + (x4 - x3) +
			   2 * (x6 - x5) + (y7 - y6) + 2 * (y9 - y8) + (y9 - y10);
			   
    return abs(perimeter);
}

void Cross::setName(string name){this -> name = name;}

bool Cross::checkCrossLines()
{
		lineSet1a = (y12 - y1); lineSet4a = (x6 - x5);
		lineSet1b = (y7 - y6);  lineSet4b = (x7 - x8);	
        lineSet2a = (x4 - x3);  lineSet5a = (y9 - y8);
		lineSet2b = (x9 - x10); lineSet5b = (y10 - y11);
		lineSet3a = (y2 - y3);  lineSet6a = (x11 - x12);
		lineSet3b = (x5 - x4);  lineSet6b = (x2 - x1);
	
        if (lineSet1a == lineSet1b || lineSet2a == lineSet2b ||
		   lineSet3a == lineSet3b || lineSet4a == lineSet4b ||	
		   lineSet5a == lineSet5b || lineSet5a == lineSet5b)
		{
			return true;
		}
        else
        {
            return false;
        }
}
   // check x and y values are zero     
bool Cross::checkZeroValue ()
{
	return (x1 != 0 || x2 != 0 || x3 !=0 || x4 != 0 ||
			x5 != 0 || x6 != 0 || x7 !=0 || x8 != 0 ||
                    x9 != 0 || x10 != 0 || x11 !=0 || x12 != 0 ||
                    y1 != 0 || y2 != 0 || y3 !=0 || y4 != 0 ||
		y5 != 0 || y6 != 0 || y7 !=0 || y8 != 0 ||
                    y9 != 0 || y10 != 0 || y11 !=0 || y12 != 0);
}

bool Cross::isAcross()
{
    return checkZeroValue () && checkCrossLines();
}

bool Cross::isPointInShape(int x, int y) 
{
		if(x > x1 && y > y1 && x < x11 && y < y11)
		{
			return true;
		}

		else if (x > x3 && y > y3 && x < x9 && y < y9)
		{
			return true;
		}
		else if (x > x5 && y > y5 && x < x7 && y < y7)
		{
			return true;
		}
		else
		{
			return false;
		}	
}

bool Cross::isPointOnShape(int x, int y)
{
	                if(x > x1 && x < x2 && y == y1)
			{
				return true;
			}

			else if(y > y3 && y < y2 && x == x2)
			{
				return true;
			}

			else if(x > x3 && x < x4 && y == y3)
			{
				return true;
			}

			else if(y > y4 && y < y5 && x == x4)
			{
				return true;
			}
			else if(x > x5 && x < x6 && y == y5)
			{
				return true;
			}
			else if(y > y6 && y < y7 && x == x6)
			{
				return true;
			}
			else if(x > x8 && x < x7 && y == y7)
			{
				return true;
			}
			else if(y > y8 && y < y9 && x == x8)
			{
				return true;
			}
			else if(x > x10 && x < x9 && y == y9)
			{
				return true;
			}
			else if(y > y11 && y < y10 && x == x10)
			{
				return true;
			}
			else if(x > x12 && x < x11 && y == y11)
			{
				return true;
			}
			else if (y > y1 && y < y12 && x == x12) 
			{
				return true;
			}

			else
			{
				return false;
			}
}

string Cross::toString()
{
// stringstream associates a string object with a stream enabling user to read from  string as if it were a stream 
			stringstream ss;
			    
                    ss << "Name : "<< name <<endl;
                        if(containWarpSpace == false )
                            ss<<"Special Type : NS"<<endl;
                        else
                            ss<<"Special Type : WS"<<endl;

					ss << "Area : "<< setprecision (2) << fixed  << computeArea()<< endl ;
					ss << "Point [1]: "<< "(" << x1 << "," << y1 <<")"<<endl;
					ss << "Point [2]: "<< "(" << x2 << "," << y2 <<")"<<endl;
					ss << "Point [3]: "<< "(" << x3 << "," << y3 <<")"<<endl;
					ss << "Point [4]: "<< "(" << x4 << "," << y4 <<")"<<endl;
                    ss << "Point [5]: "<< "(" << x5 << "," << y5 <<")"<<endl;
                    ss << "Point [6]: "<< "(" << x6 << "," << y6 <<")"<<endl;
                    ss << "Point [7]: "<< "(" << x7 << "," << y7 <<")"<<endl;
                    ss << "Point [8]: "<< "(" << x8 << "," << y8 <<")"<<endl;
                    ss << "Point [9]: "<< "(" << x9 << "," << y9 <<")"<<endl;
                    ss << "Point [10]: "<< "(" << x10 << "," << y10 <<")"<<endl;
                    ss << "Point [11]: "<< "(" << x11 << "," << y11 <<")"<<endl;
                    ss << "Point [12]: "<< "(" << x12 << "," << y12 <<")"<<endl;
					ss << "Perimeter of cross object : "<< setprecision (2) << fixed <<computePerimeter() << endl;
					ss << "Points on perimeter : " ;
		
			
				
						for(int i = x1 ; i < x2 ; i++)// line 1
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
					
						    if(isPointOnShape (pointOnLine1, y1) == true)
						    {
							 ss <<  "[" << pointOnLine1 << "," << y1 <<"],";						
						    }
					
						}
			    		
						for(int i = y3 ; i < y2 ; i++)// line 2
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
					
							if(isPointOnShape (x2, pointOnLine1) == true)
							{
							  ss << "[" << x2 << "," << pointOnLine1 <<"],";
							}
				
						}
				
						for(int i = x3 ; i < x4 ; i++)// line 3
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
					
							 if(isPointOnShape (pointOnLine1, y3) == true)
							 {
							   ss<< "[" << pointOnLine1 << "," <<  y3 <<"],";
							 }
					
						}
				
						for(int i = y4 ; i < y5 ; i++)// line 4
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
					
							if(isPointOnShape (x4, pointOnLine1) == true)
							{
							  ss << "[" <<  x4 << "," << pointOnLine1 <<"],";
							}
					
						}
                                                for(int i = x5 ; i < x6 ; i++)// line 5
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
					
							if(isPointOnShape (pointOnLine1, y5) == true)
							{
							  ss << "[" << pointOnLine1 << "," << y5 <<"],";
							}
					
						}
                                                for(int i = y6 ; i < y7 ; i++)// line 6
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
					
							if(isPointOnShape (x6, pointOnLine1) == true)
							{
							  ss << "[" << x6  << "," << pointOnLine1 <<"],";
							}
					
						}
                                                for(int i = x8 ; i < x7 ; i++)// line 7
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
					
							if(isPointOnShape (pointOnLine1, y7) == true)
							{
							  ss << "[" <<  pointOnLine1  << "," << y7 <<"],";
							}
					
						}
                                                for(int i = y8 ; i < y9 ; i++)// line 8
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
					
							if(isPointOnShape (x8, pointOnLine1) == true)
							{
							  ss << "[" <<  x8  << "," << pointOnLine1 <<"],";
							}
					
						}
                                                for(int i = x10 ; i < x9 ; i++)// line 9
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
					
							if(isPointOnShape (pointOnLine1, y9) == true)
							{
							  ss << "[" <<  pointOnLine1  << "," << y9 <<"],";
							}
					
						}

                                                for(int i = y11 ; i < y10 ; i++)// line 10
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
					
							if(isPointOnShape (x10, pointOnLine1) == true)
							{
							  ss << "[" <<  x10  << "," << pointOnLine1 <<"],";
							}
					
						}
                                                for(int i = x12 ; i < x11 ; i++)// line 11
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
					
							if(isPointOnShape (pointOnLine1, y11) == true)
							{
							  ss << "[" <<  pointOnLine1  << "," << y11  <<"],";
							}
					
						}
                                                for(int i = y1 ; i < y12 ; i++)// line 11
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
					
							if(isPointOnShape (x12, pointOnLine1) == true)
							{
							  ss << "[" <<  x12  << "," << pointOnLine1   <<"]";
							}
					
						}
				                ss << "\nPoints within shape : ";
						for (int i = x1; i < x11; ++i)
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
						
							for (int j = y1; j < y3; ++j)
							{    
								int pointOnLine2 = 0;
								pointOnLine2 += j;
								if(isPointInShape(i,j) == true)
								{
								ss << "[" << pointOnLine1 << "," << pointOnLine2 <<"],";
								}
							}
						}
						for (int i = x3; i < x9; ++i)
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
						
							for (int j = y3; j < y9; ++j)
							{    
								int pointOnLine2 = 0;
								pointOnLine2 += j;
								if(isPointInShape(i,j) == true)
								{
								ss << "[" << pointOnLine1 << "," << pointOnLine2 <<"],";
								}
							}
						}
						for (int i = x5; i < x7; ++i)
						{
							int pointOnLine1 = 0;
							pointOnLine1 += i;
						
							for (int j = y5; j < y7; ++j)
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



