#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

class Rectangle: public ShapeTwoD
{
	private :
	  
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int x4, y4;
	double area;
	double perimeter;
	int lineSet1a;
    int lineSet1b;
	int lineSet2a;
    int lineSet2b;
       	
	public :
// constructors and destructors
	Rectangle();
	
	    
    Rectangle(string name, bool containsWarpspace , int x1, int x2, int x3, int x4, 
              int y1, int y2, int y3, int y4, double area);
		

     void setXY(int x1, int x2, int x3, int x4, 
                int y1, int y2, int y3, int y4);
               
	~Rectangle();
		
// getters and setters 

// inherit name from ShapeTwoD base class 
	string getName();
		
// inherit containsWarpspace from ShapeTwoD base class
	bool getContainSpace();
	void setName(string name);
                
// virtual functions computeArea(), computePerimeter(), isPointInShape(int x, int y),
// isPointOnShape(int x, int y), toString() from base class ShapeTwoD
// child class overriding virtual function from base class
	double computeArea()override;
	double computePerimeter()override;
	bool checkReactangleLength();
		

 // check x and y values are zero  		
	bool checkZeroValue ();
	bool isARectangle ();
    bool isPointOnShape(int x, int y) override;
	bool isPointInShape(int x, int y) override;
	string toString() override;
		
		
};
#endif
