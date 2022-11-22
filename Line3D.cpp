#include "Line3D.h"
#include "Point3D.h"
#include "Line2D.h"

Line3D::Line3D(){}
Line3D::Line3D(Point3D pt1, Point3D pt2)
{
    this->pt1 = pt1;
    this->pt2 = pt2;
    setLength();
}
Line3D::~Line3D(){}
Point3D Line3D::getPt1(){ return pt1; }
Point3D Line3D::getPt2(){ return pt2; }
void Line3D::setPt1(Point3D pt1){ this->pt1 = pt1;}
void Line3D::setPt2(Point3D pt2){ this->pt2 = pt2;}
void Line3D::setLength()
{
    length = sqrt(pow((pt1.getX()-pt2.getX()),2)+pow((pt1.getY()-pt2.getY()),2)+pow((pt1.getZ()-pt2.getZ()),2));
}

ostream & operator << (ostream& output, Line3D &l3d)
{
    output << "[" << std::setfill(' ')<< std::setw (4) << std::right << l3d.getPt1().getX()<<","
    << std::setfill (' ') << std::setw (5) << std::right << l3d.getPt1().getY()<<","
    << std::setfill (' ') << std::setw (5) << std::right << l3d.getPt1().getZ()<<"]   " 
    << "[" << std::setw (4) << std::right << l3d.getPt2().getX()<<","
    << std::setfill (' ') << std::setw (5) << std::right << l3d.getPt2().getY()<<","
    << std::setfill (' ') << std::setw (5) << std::right << l3d.getPt2().getZ()<<"]   "
    << std::setfill (' ') << std::fixed << std::setprecision (3) << l3d.getScalarValue()<<endl;
    return output;
}
double Line3D::operator - (Line3D minus)
{
    return abs(getScalarValue() - minus.getScalarValue());
}
bool Line3D::operator == (Line3D equals)
{
    if(!(equals.getPt1() == getPt1()))
        return false;
    else if (!(equals.getPt2() == getPt2()))
        return false;
    else
        return true;
}
