#include "Line2D.h"
#include "Point2D.h"

Line2D::Line2D(){}
Line2D::Line2D(Point2D pt1, Point2D pt2)
{
    this -> pt1 = pt1;
    this -> pt2 = pt2;
    setLength();
}
Line2D::~Line2D(){}
Point2D Line2D::getPt1(){ return pt1;}
Point2D Line2D::getPt2(){ return pt2;}
double Line2D::getScalarValue()
{
    return length;
}
void Line2D::setLength()
{
    length = sqrt(pow((pt1.getX()-pt2.getX()),2)+pow((pt1.getY()-pt2.getY()),2));
}
ostream & operator << (ostream& output, Line2D &l2d)
{
    output << "[" << std::setfill(' ')<< std::setw (4) << std::right << l2d.getPt1().getX()<<","
    << std::setfill(' ') << std::setw(5)<< std::right << l2d.getPt1().getY()<<"]   "
    << "[" << std::setw(4) << std::right << l2d.getPt2().getX()<<","
    << std::setfill(' ')<< std::setw(5) << std::right << l2d.getPt2().getY()<<"]   "
    << std::setfill (' ') << std::fixed << std::setprecision (3) << l2d.getScalarValue()<<endl;
    return output;

}
double Line2D::operator - (Line2D minus)
{
    return abs(getScalarValue() - minus.getScalarValue());
}

bool Line2D::operator == (Line2D equals)
{
    if(!(equals.getPt1() == getPt1()))
        return false;
    else if (!(equals.getPt2() == getPt2()))
        return false;
    else
        return true;
}

