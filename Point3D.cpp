#include "Point3D.h"
#include "Point2D.h"

Point3D::Point3D(){}
Point3D::Point3D(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    setDistFrOrigin();
}

Point3D::Point3D(const Point3D& p3d)
{
    this->x = p3d.x;
    this->y = p3d.y;
    this->z = p3d.z;
    this-> distFrOrigin = p3d. distFrOrigin;
}
Point3D::~Point3D(){}
int Point3D::getZ(){ return z; }
void Point3D::setZ(int z){this->z = z;}
void Point3D::setDistFrOrigin()
{
    distFrOrigin = sqrt(pow((x-0),2)+pow((y-0),2)+pow((z-0),2));
}
ostream & operator << (ostream &output, Point3D & p3d)
{

    output<<"["<< std::setfill(' ')<< std::setw(4)<< std::right <<p3d.getX()<<","
    << std::setfill(' ')<< std::setw(5) << std::right << p3d.getY()<< ","
    << std::setfill(' ')<< std::setw(4) << std::right <<p3d.getZ()<< "]   "
    << std::setfill (' ') << std::fixed << std::setprecision (3)<<p3d.getScalarValue() << std::setw(0) <<endl;

    return output;
}
double Point3D::operator - (Point3D  minus)
{
    return abs(getScalarValue() - minus.getScalarValue());
}
bool Point3D::operator == (Point3D equals)
{
    if(equals.getX() != getX())
        return false;
    else if (equals.getY() != getY())
        return false;
    else if (equals.getZ() != getZ())
        return false;
    else 
        return true;
}