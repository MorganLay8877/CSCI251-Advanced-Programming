#include "ShapeTwoD.h"
#include "Menu.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Cross.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

Menu::Menu()
{
    validShapes.push_back("square");
    validShapes.push_back("rectangle");
    validShapes.push_back("circle");
    validShapes.push_back("cross");

    specialTypes.push_back("ns");
    specialTypes.push_back("ws");
}
Menu::~Menu()
{
    validShapes.clear();
    validShapes.shrink_to_fit();
    specialTypes.clear();
    specialTypes.shrink_to_fit();
    sensorData.clear();
    sensorData.shrink_to_fit();
}

void Menu::userMenuOptions() // Main user menu
{
    cout<<"Student Name : Lay Wee Chong, Student ID : 6564434"<<endl;
    cout<<"\n Welcome to Assn2 program !" <<endl;
    cout<<"-------------------------------" <<endl;
    cout<<" 1) Input sensor data"<<endl;
    cout<<" 2) Compute area (for all records)"<<endl;
	cout<<" 3) Compute perimeter (for all records)"<<endl;
    cout<<" 4) Print shapes report"<<endl;
    cout<<" 5) Sort shapes data"<<endl;
    cout<<" 6) Exit program"<<endl<<endl;

    while(1)
    {
            cout << "Please Enter Your Choice: ";
            cin >>this->choice;

            if(!cin.fail())
            {
                    if(this->choice == '1'||this->choice == '2'||
                       this->choice == '3'||this->choice == '4'||
                       this->choice == '5'||this->choice == '6')
                    break;
            }
            else
            {
                    cin.clear();
                    cin.ignore(50, '\n');
                    cout << "Please Enter A Valid Number"<<endl<<endl;
            }
    }
    
    
}

void Menu::processMenuOptions()// user interface choice selection
{
    switch(choice)
    {
        case '1':
            this->enterSensorData();
            break;
        case '2':
            this->computeAllArea();
            break;
        case '3':
            this->computeAllPerimeter();
            break;
        case '4':
            this->displayData();
            break;
        case '5':
            this->sortMenu();
            break;
        case '6':
            cout << "Exiting, thanks for using."<<endl<<endl;
            exit(1);
    }
}

void Menu::enterSensorData()// process user input 
{
        cout << "[ Input Sensor Data ]" <<endl;
        cin.clear();
        cin.ignore(50, '\n');


        do
        {      
           ShapeTwoD* shape = new ShapeTwoD ();
           cout << "Please Enter Name Of Shape: " ;
            shape->getName() = shapeName;
            getline(cin, shapeName);
            shapeName = convertToLowerCase(shapeName);
            validShapeDetected = isShapeNameValid(shapeName);
            if (validShapeDetected == false)
            {
                cout << "Invalid Shape Detected ! " <<endl;              
            }
            cin.clear();
        }while(!validShapeDetected);

        do
        {
            ShapeTwoD* shape = new ShapeTwoD ();
            cout << "Please Enter Special Type: ";
            shape->getSpecialTypeName() = specialTypeName;
            getline(cin, specialTypeName);
            specialTypeName = convertToLowerCase(specialTypeName);
            validSpecialTypeNameDetected = isSpecialTypeNameValid(specialTypeName);
            if (validSpecialTypeNameDetected == false)
            {
                cout << "Invalid Special Type Detected ! " <<endl;              
            }
            cin.clear();
        }while(!validSpecialTypeNameDetected); 

        if(shapeName.find("square") != string::npos)
        {
            Square* s = new Square();
            if (specialTypeName.find("ns")!= string::npos)
            {
                s->setContainWrapSpace(false);
            }
            else if (specialTypeName.find("ws")!= string::npos)
            {
                s->setContainWrapSpace(true);
            }
            EnterSensorCoordinateData(4, s, shapeName);
        }

        if(shapeName.find("rectangle") != string::npos)
        {
            Rectangle* rec = new Rectangle();
            if (specialTypeName.find("ns")!= string::npos)
            {
                rec->setContainWrapSpace(false);
            }
            else if (specialTypeName.find("ws")!= string::npos)
            {
                rec->setContainWrapSpace(true);
            }
            EnterSensorCoordinateData(4, rec, shapeName);
        }

        if(shapeName.find("circle") != string::npos)
        {
            Circle* c = new Circle();
            if (specialTypeName.find("ns")!= string::npos)
            {
                c->setContainWrapSpace(false);
            }
            else if (specialTypeName.find("ws")!= string::npos)
            {
                c->setContainWrapSpace(true);
            }
            EnterSensorCoordinateData(1, c, shapeName);
        }

        if(shapeName.find("cross") != string::npos)
        {
            Cross* cr = new Cross();
            if (specialTypeName.find("ns")!= string::npos)
            {
                cr->setContainWrapSpace(false);
            }
            else if (specialTypeName.find("ws")!= string::npos)
            {
                cr->setContainWrapSpace(true);
            }
            EnterSensorCoordinateData(12, cr, shapeName);
        }

}

string Menu::convertToLowerCase(string uppercase)// all user input are converted to lowercase r
{
	string lowercase;
    for(string::size_type i = 0; i < uppercase.length(); ++i)
    {
        lowercase.append(1u, tolower(uppercase[i]));
    }
    return lowercase;
}

bool Menu::isShapeNameValid(string name)// boolean function to check if user entered a valid shapename
{
	 for(auto sn =validShapes.begin(); sn !=validShapes.end(); sn++)
     {
		if(name.compare(*sn) == 0)
			return true;
     }
    return false;
}

bool Menu::isSpecialTypeNameValid(string name)// boolean function to check if user entered a valid special type name
{
    for(auto st = specialTypes.begin(); st != specialTypes.end(); st++)
    {
        if (name.compare(*st) == 0)
            return true;
    }
    return false;
}
void Menu::EnterSensorCoordinateData(int points, ShapeTwoD* shape, string shapename)// user enter x and y for shapes
{
        cin.clear();
        vector<int>xValue;
        vector<int>yValue;
        vector<int>radiusValue;

        if(shapename.find("square")!= string::npos || 
           shapename.find("rectangle") != string::npos || 
           shapename.find("cross")!= string::npos)
		{		
            for(int i=1;i<=points;++i)
			{
					
				do
				{
		
                        cout << "Please enter x-coord of point " << i << " : ";
                        cin >> x;

                        if(cin.bad())
                        {
                            invalidCoordsFound = true;
                        }
                        else if (cin.good())
                        {
                            validCoordsFound = false;	
                        }

                        cin.clear();
                        cin.ignore(50,'\n');


                        cout << "Please enter y-coord of point " << i << " : ";
                        cin >> y;

                        if(cin.bad())
                        {
                            invalidCoordsFound = true;
                        }
                        else if (cin.good())
                        {
                            validCoordsFound = false;	
                        }
                        cin.clear();
                        cin.ignore(50,'\n');


                        if(invalidCoordsFound || x < 0 || y < 0)
                        {
                            cout << "Entered coordinates are invalid!" << endl << endl;
                            invalidCoordsFound = true;
                        }
                        else if (validCoordsFound || x > 0 || y > 0)
                        {
                            xValue.push_back(x);
                            yValue.push_back(y);
                            validCoordsFound = true;
                        }

				}while(invalidCoordsFound);
			}
        }
        else if(shapename.find("circle") != string::npos )
        {    
			for(int i=1;i<=points;++i)
			{
				             
				do
				{
                        cout << "Please enter x-coord of center " << " : ";
                        cin >> x;

                        if(cin.bad())
                        {
                            invalidCoordsFound = true;
                        }
                        else if (cin.good())
                        {
                            validCoordsFound = true;
                        }

                        cin.clear();
                        cin.ignore(50,'\n');


                        cout << "Please enter y-coord of center " << " : ";
                        cin >> y;

                        if(cin.bad())
                        {
                            invalidCoordsFound = true;
                        }
                        else if (cin.good())
                        {
                            validCoordsFound = true;
                        }

                        cin.clear();
                        cin.ignore(50,'\n');

                                            
                        if(invalidCoordsFound || x < 0 || y < 0)
                        {
                            cout << "Entered coordinates are invalid!" << endl << endl;
                            invalidCoordsFound = true;
                        }
                        else if (validCoordsFound || x > 0 || y > 0)
                        {
                            xValue.push_back(x);
                            yValue.push_back(y);
                            validCoordsFound = true;
                        }

                                    
                        cout << "Please enter radius(units) "  << " : ";
                        cin >> rd;
                                    
                                    
                                    
                        if(cin.bad())
                        {
                            invalidRadiusFound = true;
                        }
                        else if (cin.good())
                        {
                            validRadiusFound = true;
                        }

                        cin.clear();
                        cin.ignore(50,'\n');
                            
                        if(invalidRadiusFound || rd < 0 )
                        {
                            cout << "Entered radius is invalid!" << endl << endl;
                            invalidRadiusFound = true;
                        }
                        else if (validRadiusFound || rd > 0 )
                        {
                            radiusValue.push_back(rd);
                            validRadiusFound = true;
                        }

				}while(invalidCoordsFound);
				                
			}
		
        }

        cout<<endl;

// dynamic casting  safely downcast
// can be also used for upcasting safely
//suitable for polymorphism
        if(shapename.find("square")!= string::npos )// 
		{
                Square* sq = dynamic_cast<Square *>(shape);
                sq->setXY(xValue[0],xValue[1],xValue[2],xValue[3],
                        yValue[0],yValue[1],yValue[2],yValue[3]);
                sq->setName(shapename);
                sq->setIndex(sensorData.size()+1);
                            
                if(sq->isASquare())
                {
                    sensorData.push_back(sq);
                    cout << "Record successfully stored. Going back to main menu ... " << endl;
                }			
                else if (!sq->isASquare())
                {
                    cout << "Data coordinates is invalid for a square. Going back to main menu ... " << endl;
                }
                       
		}

        else if(shapename.find("rectangle") != string::npos)
		{
                Rectangle* rec = dynamic_cast<Rectangle *>(shape);
                rec->setXY(xValue[0],xValue[1],xValue[2],xValue[3],
                        yValue[0],yValue[1],yValue[2],yValue[3]);
                rec->setName(shapename);
                rec->setIndex(sensorData.size()+1);
                if(rec->isARectangle ())
                {
                    sensorData.push_back(rec);
                    cout << "Record successfully stored. Going back to main menu ... " << endl;
                }			
                else if(!rec->isARectangle ())
                {
                    cout << "Data coordinates is invalid for a rectangle. Going back to main menu ... " << endl;
                }
		}
                
        else if(shapename.find("circle") != string::npos )
		{
                Circle* c = dynamic_cast<Circle *>(shape);
        
                c->setXY(xValue[0],yValue[0]);
                c->setName(shapename);
                c->setRadius(radiusValue[0]);
                c->setPi(pi);
                c->setIndex(sensorData.size()+1);
                            
                if(c->isACircle()) 
                {              
                    sensorData.push_back(c);
                    cout << "Record successfully stored. Going back to main menu ... " << endl;
                }
                else if(!c->isACircle()) 
                {
                    cout << "Data coordinates is invalid for a circle. Going back to main menu ... " << endl;
                }
                       
		}
        else if(shapename.find("cross") != string::npos)
		{
                Cross* cr = dynamic_cast<Cross *>(shape);
                cr->setXY(xValue[0],xValue[1],xValue[2],xValue[3],xValue[4],
                                    xValue[5],xValue[6],xValue[7],xValue[8],
                                    xValue[9],xValue[10],xValue[11],
                                    yValue[0],yValue[1],yValue[2],yValue[3],
                                    yValue[4],yValue[5],yValue[6],yValue[7],yValue[8],
                                    yValue[9],yValue[10],yValue[11]);
                            cr->setName(shapename);
                            cr->setIndex(sensorData.size()+1);
                if(cr->isAcross())
                {
                    sensorData.push_back(cr);
                    cout << "Record successfully stored. Going back to main menu ... " << endl;
                }			
                else if(!cr->isAcross()) 
                {
                    cout << "Data coordinates is invalid for a cross. Going back to main menu ... " << endl;
                }
		}
   
		else
		{
			cout << "Cannot recognise shape type. Going back to main menu ... " << endl; 
		}
        xValue.clear();
		xValue.shrink_to_fit();
		yValue.clear();
		yValue.shrink_to_fit();
		radiusValue.clear(); 
		radiusValue.shrink_to_fit();
        
}
void Menu::computeAllArea()//display and compute area
{
    if(sensorData.size() <=0 )
    {
        cout << "No sensor data entered !"<<endl;
    }
    else
    {
        for(int i = 0; i <sensorData.size(); ++i)
        {
            ShapeTwoD* Shape = sensorData.at(i);
            cout << "Area of shape" << "[" << Shape->getIndex()<< "]" << "is :" 
                 << Shape->computeArea() <<endl << endl;
                  
        }
    }
}
//display and compute perimeter
void Menu::computeAllPerimeter()
{
    if(sensorData.size() <=0 )
    {
        cout << "No sensor data entered !"<<endl;
    }
    else
    {
        for(int i = 0; i <sensorData.size(); ++i)
        {
            ShapeTwoD* Shape = sensorData.at(i);
            cout << "Perimeter of shape" << "[" << Shape->getIndex()<< "]" << "is :" 
                 << Shape->computePerimeter() <<endl << endl;
                  
        }
    }
}
void Menu::displayData()//display all shapes data
{
     if(sensorData.size() <=0 )
    {
        cout << "No sensor data entered !"<<endl;
    }
    else
    {
        for(int i = 0; i <sensorData.size(); ++i)
        {
            ShapeTwoD* Shape = sensorData.at(i);
            cout << "Area of shape" << "[" << Shape->getIndex()<< "]" << "is :" 
                 << Shape->toString() <<endl << endl;
                  
        }
    }
}
void Menu::sortMenu()// user sort menu selection
{
    cout<<"a)  Sort by area(ascending)"<<endl;
    cout<<"b)  Sort by area(descending)"<<endl;
    cout<<"c)  Sort by special type and area"<<endl;
	cout<<"d)  Sort by perimeter(ascending)"<<endl;
    cout<<"e)  Sort by perimeter(descending)"<<endl;
    cout<<"f)  Sort by special type and perimeter"<<endl; 

    while (1)
    {
        cout<<"Please select sort option ('q' to go to main menu) : ";
        cin >> this->sortChoice;

        if(!cin.fail())
        {
            if(this->sortChoice == 'a' || this->sortChoice == 'A' ||
               this->sortChoice == 'b' || this->sortChoice == 'B' ||
               this->sortChoice == 'c' || this->sortChoice == 'C' ||
               this->sortChoice == 'd' || this->sortChoice == 'D' ||
               this->sortChoice == 'e' || this->sortChoice == 'E' ||
               this->sortChoice == 'f' || this->sortChoice == 'F')
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(50, '\n');
            cout << "Invalid selection choice" <<endl;
        }
    }
}

void Menu::processSortChoice()// process user sort choice
{
    switch (sortChoice)
    {
        case 'a':
				this->sortByAreaAscending();
				break;
			case 'b':
				this->sortByAreaDescending();
				break;
			case 'c':
				this->sortSSAndArea();
				break;
			case 'd':
				this->sortByPerimeterAscending();
				break;
			case 'e':
				this->sortByPerimeterDescending();
				break;
			case 'f':
				this->sortSSAndPerimeter();
				break;
			case 'A':
				this->sortByAreaAscending();
				break;
			case 'B':
				this->sortByAreaDescending();
				break;
			case 'C':
				this->sortSSAndArea();
				break;
			case 'D':
				this->sortByPerimeterAscending();
				break;
			case 'E':
				this->sortByPerimeterDescending();
				break;
			case 'F':
				this->sortSSAndPerimeter();
				break;
    }
    cin.clear();
    cin.ignore(50, '\n');
}


void Menu::sortByAreaAscending() // sort by area ascending
{
    vector<ShapeTwoD*>sortAreaAscending(sensorData);

    sort(sortAreaAscending.begin(), sortAreaAscending.end(), Menu::compareAreaAscending);

    for(int i = 0; i < sortAreaAscending.size(); ++i)
    {
        ShapeTwoD* sortedAreaAscending = sortAreaAscending.at(i);
        cout << "[" << sortedAreaAscending->getIndex() << "]"<<endl;
        cout <<  sortedAreaAscending->toString() << endl << endl;

    }
    sortAreaAscending.clear();
    sortAreaAscending.shrink_to_fit();
} 

void Menu::sortByAreaDescending() // sort by area descending
{
    vector<ShapeTwoD*>sortAreaDescending(sensorData);

    sort(sortAreaDescending.begin(), sortAreaDescending.end(), Menu::compareAreaDescending);

    for(int i = 0; i < sortAreaDescending.size(); ++i)
    {
        ShapeTwoD* sortedAreaDescending = sortAreaDescending.at(i);
        cout << "[" << sortedAreaDescending ->getIndex() << "]"<<endl;
        cout <<  sortedAreaDescending ->toString() << endl << endl;

    }
    sortAreaDescending.clear();
    sortAreaDescending.shrink_to_fit();
}

void Menu::sortSSAndArea() // sort by special type and area
{
    vector<ShapeTwoD*>sortAreaSS(sensorData);

    stable_sort(sortAreaSS.begin(), sortAreaSS.end(), Menu::compareAreaDescending);
    stable_sort(sortAreaSS.begin(), sortAreaSS.end(), Menu::compareSS);

    for(int i = 0; i < sortAreaSS.size(); ++i)
    {
        ShapeTwoD* sortedAreaSS = sortAreaSS.at(i);
        cout << "[" << sortedAreaSS->getIndex() << "]"<<endl;
        cout <<  sortedAreaSS->toString() << endl << endl;

    }
    sortAreaSS.clear();
    sortAreaSS.shrink_to_fit();
}

void Menu::sortByPerimeterAscending() // sort by perimeter ascending
{
    vector<ShapeTwoD*>sortPerimeterAscending(sensorData);

    sort(sortPerimeterAscending.begin(), sortPerimeterAscending.end(), 
         Menu::comparePerimeterAscending);

    for(int i = 0; i < sortPerimeterAscending.size(); ++i)
    {
        ShapeTwoD* sortedPerimeterAscending = sortPerimeterAscending.at(i);
        cout << "[" << sortedPerimeterAscending->getIndex() << "]"<<endl;
        cout <<  sortedPerimeterAscending->toString() << endl << endl;

    }
    sortPerimeterAscending.clear();
    sortPerimeterAscending.shrink_to_fit();
}

void Menu::sortByPerimeterDescending()// sort by perimeter descending
{
    vector<ShapeTwoD*>sortPerimeterDescending(sensorData);

    sort(sortPerimeterDescending.begin(), sortPerimeterDescending.end(), 
         Menu::comparePerimeterDescending);

    for(int i = 0; i < sortPerimeterDescending.size(); ++i)
    {
        ShapeTwoD* sortedPerimeterDescending = sortPerimeterDescending.at(i);
        cout << "[" << sortedPerimeterDescending ->getIndex() << "]"<<endl;
        cout <<  sortedPerimeterDescending ->toString() << endl << endl;

    }
    sortPerimeterDescending.clear();
    sortPerimeterDescending.shrink_to_fit();
}

void Menu::sortSSAndPerimeter() // sort by special type and perimeter
{
    vector<ShapeTwoD*>sortSSPerimeter(sensorData);

    stable_sort(sortSSPerimeter.begin(), sortSSPerimeter.end(), Menu::comparePerimeterDescending);
    stable_sort(sortSSPerimeter.begin(), sortSSPerimeter.end(), Menu::compareSS);

    for(int i = 0; i < sortSSPerimeter.size(); ++i)
    {
        ShapeTwoD* sortedPerimeterSS = sortSSPerimeter.at(i);
        cout << "[" << sortedPerimeterSS->getIndex() << "]"<<endl;
        cout <<  sortedPerimeterSS->toString() << endl << endl;

    }
    sortSSPerimeter.clear();
    sortSSPerimeter.shrink_to_fit();
}

// boolean iterator functions for sorting area and perimeter
bool Menu::compareAreaAscending (ShapeTwoD* a, ShapeTwoD* b) 
{
    return(a->computeArea()) < (b->computeArea());
}

bool Menu::compareAreaDescending (ShapeTwoD* a, ShapeTwoD* b)
{
    return(a->computeArea()) > (b->computeArea());
}

bool Menu::comparePerimeterAscending (ShapeTwoD* a, ShapeTwoD* b)
{
    return(a->computeArea()) < (b->computeArea());
}

bool Menu::comparePerimeterDescending (ShapeTwoD* a, ShapeTwoD* b)
{
    return(a->computeArea()) > (b->computeArea());
}

bool Menu::compareSS(ShapeTwoD* a, ShapeTwoD* b)
{
    if(a->getContainWarpSpace() == true && b->getContainWarpSpace() == false)
        return true;
    else
        return false;

}
