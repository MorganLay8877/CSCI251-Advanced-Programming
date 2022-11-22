#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream> 
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>  
#include <iomanip>
#include <iterator>
#include <math.h> 
#include "template.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

class MainMenu
{
	private:
        string order = "ASC";
        string filteringCriteria;
        string point2DSort = "X-ordinate";
	    string point3DSort = "X-ordinate";
		string line2DSort = "Pt. 1";
		string line3DSort = "Pt. 1";
        char option = ' ';
        char filterOption = ' ';
		char Point2DSortOption = ' ';
		char Point3DSortOption = ' ';
		char Line2DSortOption = ' ';
		char Line3DSortOption = ' ';
		char SortOrderOption = ' ';
        string outputFileName = "";
        string filename;
        vector<Point2D*> p2d; //vector to store all 2D Points
        vector<Point3D*> p3d; //vector to store all 3D Points
        vector<Line2D*> l2d; //vector to store all 2D Lines
        vector<Line3D*> l3d; //vector to store all 3D Lines
        bool checkSame = false;
        
		ofstream txtfile;
    public:
        MainMenu ();
	    ~MainMenu();
        void displayMenu();
        void processMainMenuChoice();
        void readInAndProcessMessyTxt();
        void filteringMenu();
        void specFilteringCriteria();
        void Point2DSortMenu();
		void ProcessPoint2DSortMenu();
        void Point3DSortMenu();
		void ProcessPoint3DSortMenu();
        void Line2DSortMenu();
		void ProcessLine2DSortMenu();
        void Line3DSortMenu();
		void ProcessLine3DSortMenu();
        void sortingMenu();
		void ProcessSortingOrder();
        void displayPoint2D();
        void displayPoint3D();
        void displayLine2D();
        void displayLine3D();

        void sortPoint2D();
        void sortPoint3D();
        void sortLine2D();
        void sortLine3D();

        void printSortedPoint2D(ofstream& outputfile);
        void printSortedPoint3D(ofstream& outputfile);
        void printSortedLine2D(ofstream& outputfile);
        void printSortedLine3D(ofstream& outputfile);
        void processFile(string aline);
        
};
#endif
