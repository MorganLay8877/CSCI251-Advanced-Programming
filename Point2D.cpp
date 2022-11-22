#include "Point2D.h"

Point2D::Point2D(){}
Point2D::Point2D(int x, int y)
{
    this->x = x;
    this->y = y;
    setDistFrOrigin();
}
Point2D::~Point2D(){}
int Point2D::getX(){return x;}
int Point2D::getY(){return y;}
double Point2D::getScalarValue(){ return distFrOrigin; }
void Point2D::setX(int x){this->x = x;}
void Point2D::setY(int y){this->y = y;}
void Point2D::setDistFrOrigin()
{
    distFrOrigin = sqrt(pow((x-0),2)+pow((y-0),2));
}
ostream &operator << (ostream & output,  Point2D &p2d)
{
    output<<"["<< std::setfill(' ')<< std::setw(4) << std::right <<p2d.getX()<<","
    << std::setfill(' ')<<setw(5)<< std::right <<p2d.getY()<<"]   " 
    << std::setfill(' ')<<std::fixed<<std::setprecision(3)<<p2d.getScalarValue()<<endl;

    return output;
}

bool Point2D::operator < (Point2D other)
{
    return getX() < other.getX();
}
double Point2D::operator - (Point2D  minus)
{
    return abs(getScalarValue() - minus.getScalarValue());
}
bool Point2D:: operator == (Point2D  equals)
{
    if(equals.getX() != getX())
        return false;
    else if (equals.getY() != getY())
        return false;
    else
        return true;
}