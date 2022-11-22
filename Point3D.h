#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

class Point3D: public Point2D
{
    protected:
        int z;
        //void setDistFrOrigin() override;
    public:
        Point3D();
        Point3D(int x, int y, int z);
        Point3D(const Point3D& p3d);
        ~Point3D();
        int getZ();
        void setZ(int z);
        void setDistFrOrigin() override;
        friend ostream & operator << (ostream &output, Point3D & p3d);
        double operator - (Point3D minus);
        bool operator == (Point3D equals);

};
#endif