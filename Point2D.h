#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

class Point2D
{
    protected:
        int x;
        int y;
        double distFrOrigin;
        //virtual void setDistFrOrigin();
    
    public:
        Point2D();
        Point2D(int x, int y);
        ~Point2D();
        int getX();
        int getY();
        virtual void setDistFrOrigin();
        double getScalarValue();
        void setX(int x);
        void setY(int y);
        friend ostream &operator << (ostream & output, Point2D &p2d);
        bool operator<(Point2D other); //less then
   
        double operator - (Point2D  minus);
        bool operator == (Point2D  equals);

};
#endif
