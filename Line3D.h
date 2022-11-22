#ifndef LINE3D_H
#define LINE3D_H

#include "Point3D.h"
#include "Line2D.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

class Line3D :public Line2D
{
    private:
        Point3D pt1;
        Point3D pt2;

    /*protected:
        virtual void setLength();*/
    public:
        Line3D();
        Line3D(Point3D pt1, Point3D pt2);
        ~Line3D();
        Point3D getPt1();
        Point3D getPt2();
        virtual void setLength();
        void setPt1(Point3D pt1);
        void setPt2(Point3D pt2);
        friend ostream & operator << (ostream& output, Line3D &l3d);
        double operator - (Line3D minus);
        bool operator == (Line3D equals);
};

#endif