#ifndef MENU_H
#define MENU_H

#include "ShapeTwoD.h"
#include "Menu.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <typeinfo>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Menu
{
    private:
        vector<string>validShapes;
        vector<string>specialTypes;
        vector<ShapeTwoD*>sensorData;
        int x, y, rd; 
        char choice;
        int shapesNumber = 0;
        double pi = 3.14159;
        char sortChoice = ' ';
        string shapeName = "";
        string specialTypeName = "";
        bool validShapeDetected = false;
        bool validSpecialTypeNameDetected = false;
        bool invalidCoordsFound = false;
        bool validCoordsFound = false;
        bool invalidRadiusFound = false;
        bool validRadiusFound = false;

    public:
        Menu();
        ~Menu();
        void userMenuOptions();
        void processMenuOptions();
        void enterSensorData();
        void EnterSensorCoordinateData(int points, ShapeTwoD* shape, string shapename);
        void computeAllArea();
        void computeAllPerimeter();
        void displayData();
        void sortMenu();
        void processSortChoice();

        string convertToLowerCase(string uppercase);
        bool isShapeNameValid(string name);
        bool isSpecialTypeNameValid(string name);

        void sortByAreaAscending();
        void sortByAreaDescending();
        void sortSSAndArea();
        void sortByPerimeterAscending();
        void sortByPerimeterDescending();
        void sortSSAndPerimeter();

        static bool compareAreaAscending (ShapeTwoD* a, ShapeTwoD* b);
        static bool compareAreaDescending (ShapeTwoD* a, ShapeTwoD* b);
        static bool compareSS(ShapeTwoD* a, ShapeTwoD* b);
        static bool comparePerimeterAscending (ShapeTwoD* a, ShapeTwoD* b);
        static bool comparePerimeterDescending (ShapeTwoD* a, ShapeTwoD* b);

};
#endif