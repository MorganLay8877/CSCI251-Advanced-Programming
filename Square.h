#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

class Square:public ShapeTwoD
{
	private :
	  
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int x4, y4;
	double area;
	double perimeter;
	int line1, line2, line3, line4;	
	public :
// constructors and destructors
	Square();
	~Square();
	Square(string name, bool containWarpSpace , int x1, int x2, int x3, int x4, 
                                    int y1, int y2, int y3, int y4, double area);
	
// getters and setters  
    void setXY(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4);
    
      
// inherit name from ShapeTwoD base class                 
    string getName();
		
// inherit containsWarpspace from ShapeTwoD base class
	bool getContainSpace();
		
// virtual functions computeArea(), computePerimeter(), isPointInShape(int x, int y),
// isPointOnShape(int x, int y), toString() from base class ShapeTwoD
// child class overriding virtual function from base class
	double computeArea() override;
	double computePerimeter()override;
	void setName(string name);
    bool isASquare();
	bool checkXYLength();
		
 // check x and y values are zero  
	bool checkZeroValue ();
	bool isPointOnShape(int x, int y) override;
	bool isPointInShape(int x, int y) override;
	string toString()override;
				
};

#endif
