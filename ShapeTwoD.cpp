#include "ShapeTwoD.h"

ShapeTwoD::ShapeTwoD()
{
    name = "";
	containWarpSpace = true;
	this->index = 1;
	specialTypeName = "";
}
ShapeTwoD::~ShapeTwoD(){}
ShapeTwoD:: ShapeTwoD(string name, bool containWarpspace)
{
    this ->name = name;
	this ->containWarpSpace = containWarpSpace;
}
string ShapeTwoD:: getName()const
{
   return name;      
}
string ShapeTwoD:: getSpecialTypeName()
{
	return specialTypeName;
}
bool ShapeTwoD:: getContainWarpSpace()
{
	return containWarpSpace;
} 

int ShapeTwoD:: getIndex()
{
    return index;
}

string ShapeTwoD:: toString() { return (  " " ); }
double ShapeTwoD:: computeArea(){ double a = 0.0; return a;}
double ShapeTwoD:: computePerimeter(){ double p = 0.0; return p;}
bool ShapeTwoD:: isPointInShape(int x, int y){ return true;} 
bool ShapeTwoD:: isPointOnShape(int x, int y){ return true;}

void ShapeTwoD:: setIndex(int index)
{
	this -> index = index;
}

void ShapeTwoD:: setName(string shapeName)
{
	this -> name = shapeName;
}

void ShapeTwoD:: setContainWrapSpace (bool containWarpSpace)
{
	this -> containWarpSpace = containWarpSpace;
}


