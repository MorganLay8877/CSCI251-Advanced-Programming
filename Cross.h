#ifndef CROSS_H
#define CROSS_H

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

using namespace std;

class Cross : public ShapeTwoD
{
   private :
     int x1; int x2; int x3; int x4; int x5; int x6; 
     int x7; int x8; int x9; int x10; int x11; int x12;
     int y1; int y2; int y3; int y4; int y5; int y6;
     int y7; int y8; int y9; int y10; int y11; int y12;
     double area, perimeter;
     int lineSet1a, lineSet1b,lineSet2a, lineSet2b;
     int lineSet3a, lineSet3b,lineSet4a, lineSet4b;
     int lineSet5a, lineSet5b,lineSet6a, lineSet6b;
  public :
// constructors and destructors
      Cross();
     ~Cross();
      Cross(int x1, int x2, int x3, int x4, int x5, int x6, int x7,
            int x8, int x9, int x10, int x11, int x12,
            int y1, int y2, int y3, int y4, int y5, int y6,
            int y7, int y8, int y9, int y10, int y11, int y12, 
            string name, bool containsWarpspace );
           
		    

// getters and setters
void setXY(int x1, int x2, int x3, int x4, int x5, int x6,
           int x7, int x8, int x9, int x10, int x11, int x12,
           int y1, int y2, int y3, int y4, int y5, int y6, int y7,
            int y8, int y9, int y10, int y11, int y12);
           
// inherit name from ShapeTwoD base class
      string getName();
// inherit containsWarpspace from ShapeTwoD base class
      bool getContainSpace();
// virtual functions computeArea(), computePerimeter(), isPointInShape(int x, int y),
// isPointOnShape(int x, int y), toString() from base class ShapeTwoD
// child class overriding virtual function from base class
      double computeArea()override;
      double computePerimeter()override;
      void setName(string name);
   
   // check x and y values are zero     
      bool checkZeroValue ();
      bool checkCrossLines();
	  bool isAcross();
      bool isPointInShape(int x, int y) override;
      bool isPointOnShape(int x, int y) override;
      string toString()override;
		

};
#endif
