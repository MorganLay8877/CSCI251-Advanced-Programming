#ifndef LINE2D_H
#define LINE2D_H

#include "Point2D.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

class Line2D
{
    private:
        Point2D pt1;
        Point2D pt2;

    protected:
        double length;
        //virtual void setLength();
    public:
        Line2D();
        Line2D(Point2D pt1, Point2D pt2);
        ~Line2D();
        Point2D getPt1();
        Point2D getPt2();
        double getScalarValue();
        virtual void setLength();
        void setPt1(Point2D pt1);
        void setPt2(Point2D pt2);
        friend ostream & operator << (ostream& output, Line2D &l2d);
        double operator - (Line2D minus);
        bool operator == (Line2D equals);        

};


#endif