#ifndef SHAPETWOD_H
#define SHAPETWOD_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class ShapeTwoD
{
    protected:
        string name;
        bool containWarpSpace;
        int index;
        string specialTypeName;
    public:
        ShapeTwoD();
        ~ShapeTwoD(); // destructor
        ShapeTwoD(string name, bool containWarpspace);
        string getName()const;
        string getSpecialTypeName();
        bool getContainWarpSpace();
        int getIndex();
// virtual function for parent class 
        virtual string toString();
		virtual double computeArea();
		virtual double computePerimeter();
		virtual bool isPointInShape(int x, int y); 
        virtual bool isPointOnShape(int x, int y); 

        void setIndex(int index);
        void setName(string shapeName);
        void setContainWrapSpace (bool containWarpspace);



};
#endif
