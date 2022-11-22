#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "MainMenu.h"
#include "template.h"
#include <iterator>

MainMenu::MainMenu (){}
MainMenu::~MainMenu()
{
	p2d.clear();
	p2d.shrink_to_fit();
    p3d.clear();
	p3d.shrink_to_fit();
	l2d.clear();
	l2d.shrink_to_fit();
	l3d.clear();
	l3d.shrink_to_fit();
}
void MainMenu::displayMenu()
{
    cout<< endl << "Student ID   : 6564434" << endl;
	cout<< "Student Name : Lay Wee Chong" << endl;
	cout<< "--------------------------------------------" << endl;
	cout<< "Welcome to Assn3 Program" << endl<<endl;
	   
	cout<< "1)  Read in data" << endl;
	cout<< "2)  Specify filtering criteria (current: " <<filteringCriteria << ")"<<endl;
	cout<< "3)  Specify sorting criteria (current: " <<endl;

    if(filteringCriteria.compare("Point2D") == 0)
	{
		cout << point2DSort  << ")"<<endl;
	}
	else if (filteringCriteria.compare("Point3D") == 0)
	{
		cout << point3DSort << ")"<<endl;
	}
	else if (filteringCriteria.compare("Line2D") == 0)
	{
		cout << line2DSort << ")"<<endl;
	}
	else if (filteringCriteria.compare("Line3D") == 0)
	{
		cout << line3DSort << ")"<<endl;
	}
	cout<< "4)  Specify sorting order (current: " << order << ")" << endl;
	cout<< "5)  View data" << endl;
	cout<< "6)  Store data" << endl;
    cout<< "7)  Quit" << endl;

    while(1)
	{
		cout<<"Please enter your choice : ";
		cin >> this->option;

		if(!cin.fail())
		{
			if(this->option == '1' ||
			   this->option == '2' ||
			   this->option == '3' ||
			   this->option == '4' ||
			   this->option == '5' ||
			   this->option == '6' ||
			   this->option == '7')
			  break;
		}
		else
		{
			cin.clear();
			cin.ignore(50,'\n');
			cout << "Please enter a valid number"<<endl<<endl<<endl;
		}
    }
}
void MainMenu::processMainMenuChoice()
{
    switch (option)
	{
				case '1':
				  this->readInAndProcessMessyTxt();
				  cout<<"Press enter to go back to main menu"<<endl;
				  break;
				case '2':
				  cout<<"[Specify filtering criteria (current: "<<filteringCriteria << ")]"<<endl;
				  this->filteringMenu();
				  this->specFilteringCriteria();
				  cout<<"Press enter to go back to main menu"<<endl;
				  break;
				case '3':
				  {
					 cout << "[ Specifying sorting criteria (current: ";
					 if(filteringCriteria.compare("Point2D") == 0)
					 {
					     cout << point2DSort  << ") ]"<<endl;
					     Point2DSortMenu();
					     ProcessPoint2DSortMenu();
					 }
					 else if (filteringCriteria.compare("Point3D") == 0)
					 {
					     cout << point3DSort << ") ]"<<endl;
					     Point3DSortMenu();
					     ProcessPoint3DSortMenu();
					 }
					 else if (filteringCriteria.compare("Line2D") == 0)
					 {
					     cout << line2DSort << ") ]"<<endl;
					     Line2DSortMenu();
					     ProcessLine2DSortMenu();
					 }
					 else if (filteringCriteria.compare("Line3D") == 0)
					 {
				          cout << line3DSort << ") ]"<<endl;
					      Line3DSortMenu();
					      ProcessLine3DSortMenu();
					 }
					  
					 
					 cout<<"Press enter to go back to main menu"<<endl;
				  }
				  break;
				case '4':
				  cout << "[ Specifying sorting order (current: " << order 
		     << ") ]" << endl; 
				  this->sortingMenu();
				  this->ProcessSortingOrder();
				  cout<<"Press enter to go back to main menu"<<endl;
				  break;
				case '5':
				{
					cout << endl;
					cout << "[View data -------------------- ]" << endl;
					cout << "filtering criteria: " << filteringCriteria << endl;
					
					 if(filteringCriteria.find("Point2D") != string::npos)
					 {
					     cout<<"Sorting criteria: " << point2DSort  << ")"<<endl;
					
					     cout<<"Sorting order:" <<order<<endl;
					       this->sortPoint2D();
					       this->displayPoint2D();
					 					     
					 }
					 else if (filteringCriteria.compare("Point3D") == 0)
					 {
					     cout<<"Sorting criteria: " << point3DSort  << ")"<<endl;
					     this->sortPoint3D();
					     this->displayPoint3D();
					     cout<<"Sorting order:" <<order<<endl;
					 }
					 else if (filteringCriteria.compare("Line2D") == 0)
					 {
					     cout<<"Sorting criteria: " << line2DSort  << ")"<<endl;
					     this->sortLine2D();
					     this->displayLine2D();	
					     cout<<"Sorting order:" <<order<<endl;
					 }
					 else if (filteringCriteria.compare("Line3D") == 0)
					 {
				        cout<<"Sorting criteria: " << line3DSort  << ")"<<endl;
					    this->sortLine3D();
					    this->displayLine3D();
					    cout<<"Sorting order:" <<order<<endl;
					 }

				 
				 cout<<"Press enter to go back to main menu"<<endl;
				}
				 break;
				case '6':
				{
					cout << endl;
					cout << "Please enter filename: ";
					cin >>  outputFileName ;
					cin.clear();
		            cin.ignore(50,'\n');
                                        
                    txtfile.open(outputFileName);
					if(filteringCriteria.compare("Point2D") == 0)
					{
					     this->sortPoint2D();
					     this->printSortedPoint2D(txtfile);
					}
					else if (filteringCriteria.compare("Point3D") == 0)
					{
					     this->sortPoint3D();
					     this->printSortedPoint3D(txtfile);
					}
					else if (filteringCriteria.compare("Line2D") == 0)
					{
					    this->sortLine2D();
					    this->printSortedLine2D(txtfile);
					}
					else if (filteringCriteria.compare("Line3D") == 0)
					{
				        this->sortLine3D();
					    this->printSortedLine3D(txtfile);
					}
					
							
				}
				 

				cout<<"Press enter to go back to main menu"<<endl;
				break;
				
				case '7':
			 	cout<<"Thank's for your usage, bye."<<endl;
		         	exit(1);
				
	}
}
void MainMenu::readInAndProcessMessyTxt()
{
	string aline;
    cout << "1) Read in and process a valid text-file " << endl; // process file
	cout << "Please enter valid textfile : ";
	cin >> filename;
	fstream inFile;
	inFile.open(filename);
	int linecount = 0;
	if (inFile.good())
	{
		while(true)
		{
			getline(inFile,aline);
			processFile(aline);
			if(aline.size() >=1)
				linecount++;
			if(inFile.eof())
				break;
		}
    }
	else
	{
		cout << "No file found !"<<endl;	
	}
	
	
	inFile.close();

	/*sort(cityIDArray.begin(), cityIDArray.end()); // sort in descending order
	cityIDArray.erase(unique(cityIDArray.begin(), cityIDArray.end()), cityIDArray.end()); // eliminate duplicates*/
}

void MainMenu::filteringMenu()
{
	cout << "  a)   Point2D records" << endl;
	cout << "  b)   Point3D records" << endl;
	cout << "  c)   Line2D records" << endl;
	cout << "  d)   Line3D records" << endl;
	cout << endl;
	while(1)
	{
			cout << "Please enter your criteria (a - d): ";
			cin >> this->filterOption;

			if(!cin.fail())
			{
				  if(this->filterOption == 'a'||
				     this->filterOption == 'b'||
			 	     this->filterOption == 'c'||
			         this->filterOption == 'd'||
			         this->filterOption == 'A'||
				     this->filterOption == 'B'||
			         this->filterOption == 'C'||
				     this->filterOption == 'D')
						break;
			}
			else
			{
			     cin.clear();
			     cin.ignore(50,'\n');
			     cout << "Please enter a valid choice"<<endl<<endl<<endl;
			}

	}
	
}

void MainMenu::specFilteringCriteria()
{
	switch (filterOption)
	{
			case 'a':
				filteringCriteria = "Point2D";
				break;
			case 'b':
				filteringCriteria = "Point3D";
				break;
			case 'c':
				filteringCriteria = "Line2D";
				break;
			case 'd':
				filteringCriteria = "Line3D";
				break;
			case 'A':
				filteringCriteria = "Point2D";
				break;
			case 'B':
				filteringCriteria = "Point3D";
				break;
			case 'C':
				filteringCriteria = "Line2D";
				break;
			case 'D':
				filteringCriteria = "Line3D";
				break;
	}
	cout << "Filtering criteria successfully set to "<<filteringCriteria<<endl;
	cout << endl;
}

void MainMenu::Point2DSortMenu()
{
	   cout << "  a)   X ordinate value" << endl;
		cout << "  b)   Y ordinate value" << endl;
		cout << "  c)   Dist. Fr Origin value" << endl << endl;
		
		while(1)
		{
			cout << "Please enter your criteria (a - c): ";
			cin >> this-> Point2DSortOption;

			if(!cin.fail())
			{
				  if(this->Point2DSortOption == 'a'||
				     this->Point2DSortOption == 'b'||
			 	     this->Point2DSortOption == 'c'||
			         this->Point2DSortOption == 'A'||
				     this->Point2DSortOption == 'B'||
			         this->Point2DSortOption == 'C')
						break;
			}
			else
			{
			     cin.clear();
			     cin.ignore(50,'\n');
			     cout << "Please enter a valid choice"<<endl<<endl<<endl;
			}
		}

}

void MainMenu::ProcessPoint2DSortMenu()
{
	switch (Point2DSortOption)
	{
			case 'a':
				point2DSort = "X-ordinate";
				break;
			case 'b':
				point2DSort = "Y-ordinate";
				break;
			case 'c':
				point2DSort = "Dist .Fr origin value";
				break;
			case 'A':
				point2DSort = "X-ordinate";
				break;
			case 'B':
				point2DSort = "Y-ordinate";
				break;
			case 'C':
				point2DSort = "Dist .Fr origin value";
				break;
			
	}
	cout << "Sorting criteria successfully set to "<<point2DSort<<endl;
	cout << endl;
}

void MainMenu::Point3DSortMenu()
{
	    cout << "  a)   X ordinate value" << endl;
		cout << "  b)   Y ordinate value" << endl;
		cout << "  c)   Z ordinate value" << endl;
		cout << "  d)   Dist. Fr Origin value" << endl << endl;
		
		while(1)
		{
			cout << "Please enter your criteria (a - d): ";
			cin >> this-> Point3DSortOption;

			if(!cin.fail())
			{
				  if(this->Point3DSortOption == 'a'||
				     this->Point3DSortOption == 'b'||
			 	     this->Point3DSortOption == 'c'||
				     this->Point3DSortOption == 'd'||
			         this->Point3DSortOption == 'A'||
				     this->Point3DSortOption == 'B'||
			        this->Point3DSortOption == 'C'||
				     this->Point3DSortOption == 'D')
						break;
			}
			else
			{
			     cin.clear();
			     cin.ignore(50,'\n');
			     cout << "Please enter a valid choice"<<endl<<endl<<endl;
			}
		}
}

void MainMenu::ProcessPoint3DSortMenu()
{
	switch (Point3DSortOption)
	{
			case 'a':
				point3DSort = "X-ordinate";
				break;
			case 'b':
				point3DSort = "Y-ordinate";
				break;
			case 'c':
				point3DSort = "Z-ordinate";
				break;
			case 'd':
				point3DSort = "Dist .Fr origin value";
				break;
			case 'A':
				point3DSort = "X-ordinate";
				break;
			case 'B':
				point3DSort = "Y-ordinate";
				break;
			case 'C':
				point3DSort = "Z-ordinate";
				break;
			case 'D':
				point3DSort = "Dist .Fr origin value";
				break;
			
	}
	cout << "Sorting criteria successfully set to "<<point3DSort<<endl;
	cout << endl;

}

void MainMenu::Line2DSortMenu()
{
	    cout << "  a)   Pt. 1 (x-y) values" << endl;
		cout << "  b)   Pt. 2 (x-y) values" << endl;
		cout << "  c)   Length value" << endl << endl;
		
		while(1)
		{
			cout << "Please enter your criteria (a - c): ";
			cin >> this-> Line2DSortOption;

			if(!cin.fail())
			{
				  if(this->Line2DSortOption == 'a'||
				     this->Line2DSortOption == 'b'||
			 	     this->Line2DSortOption == 'c'||
			         this->Line2DSortOption == 'A'||
				     this->Line2DSortOption == 'B'||
			         this->Line2DSortOption == 'C')
						break;
			}
			else
			{
			     cin.clear();
			     cin.ignore(50,'\n');
			     cout << "Please enter a valid choice"<<endl<<endl<<endl;
			}
		}
}

void MainMenu::ProcessLine2DSortMenu()
{
	switch (Line2DSortOption)
	{
			case 'a':
				line2DSort = "Pt. 1";
				break;
			case 'b':
				line2DSort = "Pt. 2";
				break;
			case 'c':
				line2DSort = "Length";
				break;
			case 'A':
				line2DSort = "Pt. 1";
				break;
			case 'B':
				line2DSort = "Pt. 2";
				break;
			case 'C':
				line2DSort = "Length";
				break;
						
	}
	cout << "Sorting criteria successfully set to "<<line2DSort<<endl;
	cout << endl;
}

void MainMenu::Line3DSortMenu()
{
	    cout << "  a)   Pt. 1 (x-y-z) values" << endl;
		cout << "  b)   Pt. 2 (x-y-z) values" << endl;
		cout << "  c)   Dist. Fr Origin value" << endl << endl;
		
		while(1)
		{
			cout << "Please enter your criteria (a - c): ";
			cin >> this-> Line3DSortOption;

			if(!cin.fail())
			{
				  if(this->Line3DSortOption == 'a'||
				     this->Line3DSortOption == 'b'||
			 	     this->Line3DSortOption == 'c'||
			         this->Line3DSortOption == 'A'||
				     this->Line3DSortOption == 'B'||
			         this->Line3DSortOption == 'C')
						break;
			}
			else
			{
			     cin.clear();
			     cin.ignore(50,'\n');
			     cout << "Please enter a valid choice"<<endl<<endl<<endl;
			}
		}
}

void MainMenu::ProcessLine3DSortMenu()
{
	switch (Line3DSortOption)
	{
			case 'a':
				line3DSort = "Pt. 1";
				break;
			case 'b':
				line3DSort = "Pt. 2";
				break;
			case 'c':
				line3DSort = "Length";
				break;
			case 'A':
				line3DSort = "Pt. 1";
				break;
			case 'B':
				line3DSort = "Pt. 2";
				break;
			case 'C':
				line3DSort = "Length";
				break;
						
	}
	cout << "Sorting criteria successfully set to "<<line3DSort<<endl;
	cout << endl;
}

void MainMenu::sortingMenu()
{
	   cout << "  a)   ASC (Ascending Order)" << endl;
	   cout << "  b)   DSC (Descending Order)" << endl << endl;
		
		while(1)
		{
			cout << "Please enter your criteria (a - b): ";
			cin >> this-> SortOrderOption;

			if(!cin.fail())
			{
				  if(this->SortOrderOption == 'a'||
				     this->SortOrderOption == 'b'||
			         this->SortOrderOption == 'A'||
				     this->SortOrderOption == 'B')
						break;
			}
			else
			{
			     cin.clear();
			     cin.ignore(50,'\n');
			     cout << "Please enter a valid choice"<<endl<<endl<<endl;
			}
		}
}

void MainMenu::ProcessSortingOrder()
{
	switch (SortOrderOption)
	{
			case 'a':
				order = "ASC";
				break;
			case 'b':
				order = "DSC";
				break;
			case 'A':
				order = "ASC";
				break;
			case 'B':
				order = "DSC";
				break;		
	}
	cout << "Sorting order successfully set to "<<order<<endl;
	cout << endl;
}

void MainMenu::processFile(string aLine)
{
	if(aLine.find("Point2D") != string::npos)
	{
		int x = 1000; 
        int y = 1000;
        int x1 = -1000; 
		int y1  = -1000;
		size_t pos = aLine.find(",");// find position of comma
		char comma;
		char space;
		size_t pos2;
		

		aLine = aLine.substr(pos);// to extract string from comma onwards
		comma = aLine[0];
		space = aLine[1];
		pos = aLine.find("[");// find position of first bracket
		aLine = aLine.substr(pos + 1);// to extract string after "[" onwards

		pos = aLine.find(comma);
		string xPoint2D = aLine.substr(0,pos);//extract string values til comma 

		if ((stoi (xPoint2D) > x1) && (stoi (xPoint2D) < x))
		{
			x = stoi (xPoint2D);  // convert string xPoint2D to integer
		}

		pos = aLine.find(space);
		pos2 = aLine.find("]");// find position of closing bracket
		string yPoint2D = aLine.substr (pos+1, pos2);

	        if ((stoi (yPoint2D) > y1) && (stoi (yPoint2D) < y))
		{
			y = stoi (yPoint2D); // convert string yPoint2D to integer
			
		}
// check for duplicate values within messy textfiles
// if duplicate, do not populate vector p2d with duplicate values		
		for (int i = 0; i < p2d.size(); ++i)
		{
			if(x == p2d[i]->getX() && y == p2d[i]->getY())
				checkSame = true;
		}
		if( checkSame != true)
		{
			p2d.push_back(new Point2D(x,y));// create a new Point2D object and to stored it into p2d.
			p2d[p2d.size()-1]->setDistFrOrigin();

		}
		
	}
	else if(aLine.find("Point3D")!= string::npos) 
	{
		int x = 1000; 
		int y = 1000; 
		int z = 1000;
        int x1 = -1000; 
		int y1 = -1000; 
		int z1 = -1000;
		char comma;
		char space;
		size_t pos = aLine.find(",");// find position of comma
		size_t pos2;
		aLine = aLine.substr(pos);// to extract string from comma onwards
		comma = aLine[0];
		space = aLine[1];
		pos = aLine.find ("[");// find position of first bracket
		aLine =aLine.substr (pos+1);// to extract string after "[" onwards
		
		pos = aLine.find (comma); 
		string xpoint3D = aLine.substr (0, pos);//extract string values til comma  
					
		if ((stoi (xpoint3D) > x1) && (stoi (xpoint3D) < x))
		{
		    x = stoi (xpoint3D); // convert string xpoint3D to integer
		}
		pos2 = aLine.find("]");
		pos = aLine.find(space);
		aLine = aLine.substr (pos + 1, pos2);

		pos2 = aLine.find (comma);
		string ypoint3D = aLine.substr (0, pos2); 
					
		if ((stoi (ypoint3D) > y1) && (stoi (ypoint3D) < y))
		{
		    y = stoi (ypoint3D); // convert string ypoint3D to integer
		} 
		pos = aLine.find(space);
		pos2 = aLine.find("]");// find position of closing bracket
		string zpoint3D = aLine.substr (pos+1, pos2);
		if ((stoi (zpoint3D) > z1) && (stoi (zpoint3D) < z))
		{
		    z = stoi (zpoint3D);// convert string zpoint3D to integer
		}
// check for duplicate values within messy textfiles
// if duplicate, do not populate vector p3d with duplicate values
		for (int i = 0; i < p3d.size(); ++i)
		{
			if(x == p3d[i]->getX() && y == p3d[i]->getY() && 
			   z == p3d[i]->getZ() )
			checkSame = true;
		}
		if( checkSame != true)
		{
			p3d.push_back(new Point3D(x,y,z));//  create a new Point3D object and to stored it into p3d.
			p3d[p3d.size()-1]->setDistFrOrigin();
		}
			
	}
	else if(aLine.find("Line2D") != string::npos) 
	{
			int x = -1000;
		int y = -1000;
		int x1 = -1000;
		int y1 = -1000;
		size_t pos = 0;
		string delimit_1 = "";
		string delimit_2 = "";
		Point2D p1;
		Point2D p2;
		// erase Line2D header
		while ((pos = aLine.find("D, [")) != string::npos)
		{
			aLine.erase(0, pos + 4);
		}
		//seperate line into two parts with middle delimeter ", ["
		pos = 0;
		
		while ((pos = aLine.find(", [")) != string::npos)
		{
			delimit_1 = aLine.substr(0, pos);
			delimit_2 = aLine.erase(0, pos + 3);
		}
		pos = 0;
		//obtain x and y value first
		while ((pos = delimit_1.find(", ")) != string::npos)
		{
			x = stoi(delimit_1.substr(0, pos));
			delimit_1.erase(0, pos+2);
		}
		y = stoi(delimit_1.substr(0, delimit_1.length()-1));
		 p1 = Point2D(x,y);
		//obtain x1 and y1 value second
		while ((pos = delimit_2 .find(", ")) != string::npos)
		{
			x1 = stoi(delimit_2 .substr(0, pos));
			delimit_2 .erase(0, pos+2);
		}
		y1 = stoi(delimit_2 .substr(0, delimit_2.length()-1));
		
		p2 = Point2D(x1,y1);//create Point2D instances p1 and p2
// check for duplicate values within messy textfiles
// if duplicate, do not populate vector l2d with duplicate values
		for (int i = 0; i < l2d.size(); ++i)
		{
			if(l2d[i]->getPt1().getX() == x && l2d[i]->getPt1().getY() == y && 
			   l2d[i]->getPt2().getX() == x1 && l2d[i]->getPt2().getX() == y1)
			{
				checkSame = true;
			}
		}
		
		if (checkSame != true)
		{
			l2d.push_back(new Line2D(p1,p2));
			l2d[l2d.size()-1]->setLength();  
// create new line2D instance and a new Line2D object, then
// pushing them into l2d vector
		}
	}
	else if(aLine.find("Line3D") != string::npos) 
	{
		int x = -1000; 
		int y = -1000; 
		int z = -1000;
        int x1 = -1000; 
		int y1  = -1000; 
		int z1 = -1000;
		size_t pos = 0;
		size_t pos2 = 0;
		string delimit_1 = "";
		string delimit_2 = "";
		Point3D p1;
		Point3D p2;
		// erase Line3D header
		while ((pos = aLine.find("D, [")) != string::npos)
		{
			aLine.erase(0, pos + 4);
		}
		
		pos = 0;
	//seperate line into two parts with middle delimeter ", ["
		while ((pos = aLine.find(", [")) != string::npos)
		{
			delimit_1  = aLine.substr(0, pos);
			delimit_2  = aLine.erase(0, pos + 3);
		}
	
		pos = 0;
		
		//obtain x, y and z value first
		while ((pos = delimit_1.find(", ")) != string::npos)
		{
			if (x == -1000)
			{
				x = stoi(delimit_1.substr(0,pos));
				pos2 = pos;
			}
			else
			{
				y = stoi(delimit_1.substr(pos2,pos));
			}
			delimit_1.erase(0, pos + 2);
			pos2 = 0;
		}
		z = stoi(delimit_1.substr(0, delimit_1.length()-1));
		p1 = Point3D(x,y,z);
		pos = 0;
		//obtain x1, y1 and z1 value second
		pos2 = 0;
		while ((pos = delimit_2.find(", ")) != string::npos)
		{
			if (x1 == -1000)
			{
				x1 = stoi( delimit_2.substr(0,pos));
				pos2 = pos;
			}
			else
			{
				y1 = stoi(delimit_2.substr(pos2,pos));
			}
			delimit_2.erase(0, pos + 2);
			pos2 = 0;
		}
		z1 = stoi(delimit_2.substr(0, delimit_2.length()-1));
		p2 = Point3D(x1,y1,z1);//create Point3D instances p1 and p2
// check for duplicate values within messy textfiles
// if duplicate, do not populate vector l3d with duplicate values
		for (int i = 0; i < l3d.size(); ++i)
		{
			if(l3d[i]->getPt1().getX() == x && l3d[i]->getPt1().getY() == y
                           && l3d[i]->getPt1().getZ() == z )
			{
				checkSame = true;
			}
                        else if (l3d[i]->getPt2().getX() == x && l3d[i]->getPt2().getY() == y
                           && l3d[i]->getPt2().getZ() == z)	
			{
				checkSame = true;
			}	
		}
		if (checkSame != true)
		{
			
			 l3d.push_back (new Line3D(p1,p2));
			 l3d[l3d.size()-1]->setLength(); 
// create new line3D instance and a new Line3D object, then
// pushing them into l3d vector
		}			
	}
	
}



void MainMenu::sortPoint2D()
{
	if(order=="ASC" && point2DSort == "X-ordinate")
	{
		
		sort(p2d.begin(), p2d.end(), [](Point2D *p1, Point2D *p2) 
		{
    		if (p1->getX() == p2->getX())
			{
				return ascending(p1->getY(), p2->getY()); 
			}	
			return ascending(p1->getX(), p2->getX()); 
		});	
	}
	else if(order=="ASC" && point2DSort == "Y-ordinate")
	{
		sort(p2d.begin(), p2d.end(), [](Point2D *p1, Point2D *p2) 
		{
    		if (p1->getY() == p2->getY())
			{
				return ascending(p1->getX(), p2->getX()); 
			}	
			return ascending(p1->getY(), p2->getY()); 
		});	
	}
	else if (order == "ASC" && point2DSort == "Dist .Fr origin value")
	{
		sort(p2d.begin(), p2d.end(), [](Point2D *p1, Point2D *p2) 
		{
			return ascending(p1->getScalarValue(), p2->getScalarValue()); 
		});	
	}
	else if(order=="DSC" && point2DSort == "X-ordinate")
	{
		sort(p2d.begin(), p2d.end(), [](Point2D *p1, Point2D *p2) 
		{
    		if (p1->getX() == p2->getX())
			{
				return descending(p1->getY(), p2->getY()); 
			}	
			return descending(p1->getX(), p2->getX()); 
		});	
	}
	else if(order=="DSC" && point2DSort == "Y-ordinate")
	{
		sort(p2d.begin(), p2d.end(), [](Point2D *p1, Point2D *p2) 
		{
    		if (p1->getY() == p2->getY())
			{
				return descending(p1->getX(), p2->getX()); 
			}	
			return descending(p1->getY(), p2->getY()); 
		});	
	}
	else if (order == "DSC" && point2DSort == "Dist .Fr origin value")
	{
		sort(p2d.begin(), p2d.end(), [](Point2D *p1, Point2D *p2) 
		{
			return descending (p1->getScalarValue(), p2->getScalarValue()); 
		});	
	}	

}

void MainMenu::sortPoint3D()
{
	if(order=="ASC" && point3DSort == "X-ordinate")
	{
		sort(p3d.begin(), p3d.end(), [](Point3D *p1, Point3D *p2) 
		{
    		 if(p1->getX() == p2->getX())
			 {
				if(p1->getY() == p2->getY())
				{
					return descending(p1->getZ(), p2->getZ());
				}
				return descending(p1->getY(), p2->getY());
			 }
			 return ascending(p1->getX(), p2->getX());
		});	
	}
	else if (order=="ASC" && point3DSort == "Y-ordinate")
	{
		sort(p3d.begin(), p3d.end(), [](Point3D *p1, Point3D *p2) 
		{
    		 if(p1->getY() == p2->getY())
			 {
				if(p1->getX() == p2->getX())
				{
					return descending(p1->getZ(), p2->getZ());
				}
				return descending(p1->getX(), p2->getX());
			 }
			 return ascending(p1->getY(), p2->getY());
		});	
	}
	else if (order=="ASC" && point3DSort == "Z-ordinate")
	{
		sort(p3d.begin(), p3d.end(), [](Point3D *p1, Point3D *p2) 
		{
    		 if(p1->getZ() == p2->getZ())
			 {
				if(p1->getX() == p2->getX())
				{
					return descending(p1->getY(), p2->getY());
				}
				return descending(p1->getX(), p2->getX());
			 }
			 return ascending(p1->getZ(), p2->getZ());
		});	
	}
	else if (order == "ASC" && point3DSort == "Dist .Fr origin value")
	{
		sort(p3d.begin(), p3d.end(), [](Point3D *p1, Point3D *p2) 
		{
			return ascending(p1->getScalarValue(), p2->getScalarValue()); 
		});	
	}
	else if(order=="DSC" && point3DSort == "X-ordinate")
	{
		sort(p3d.begin(), p3d.end(), [](Point3D *p1, Point3D *p2) 
		{
    		 if(p1->getX() == p2->getX())
			 {
				if(p1->getY() == p2->getY())
				{
					return ascending(p1->getZ(), p2->getZ());
				}
				return ascending(p1->getY(), p2->getY());
			 }
			 return descending(p1->getX(), p2->getX());
		});	
	}
	else if (order=="DSC" && point3DSort == "Y-ordinate")
	{
		sort(p3d.begin(), p3d.end(), [](Point3D *p1, Point3D *p2) 
		{
    		 if(p1->getY() == p2->getY())
			 {
				if(p1->getX() == p2->getX())
				{
					return ascending(p1->getZ(), p2->getZ());
				}
				return ascending(p1->getX(), p2->getX());
			 }
			 return descending(p1->getY(), p2->getY());
		});	
	}
	else if (order=="DSC" && point3DSort == "Z-ordinate")
	{
		sort(p3d.begin(), p3d.end(), [](Point3D *p1, Point3D *p2) 
		{
    		if(p1->getZ() == p2->getZ())
			 {
				if(p1->getX() == p2->getX())
				{
					return ascending(p1->getY(), p2->getY());
				}
				return ascending(p1->getX(), p2->getX());
			 }
			 return descending(p1->getZ(), p2->getZ()); 
		});		
	}
	else if (order == "DSC" && point3DSort == "Dist .Fr origin value")
	{
		sort(p3d.begin(), p3d.end(), [](Point3D *p1, Point3D *p2) 
		{
			return descending(p1->getScalarValue(), p2->getScalarValue()); 
		});	
	}
}


void MainMenu::sortLine2D()
{
	if(order=="ASC" && line2DSort ==  "Pt. 1")
	{
		sort(l2d.begin(), l2d.end(), [](Line2D *l1, Line2D *l2) 
		{
				if(l1->getPt1().getX()==l2->getPt1().getX())
				{
					return ascending(l1->getPt1().getY(), l2->getPt1().getY());
				}
				return ascending(l1->getPt1().getX(), l2->getPt1().getX());
			
		});
	}
	else if(order=="ASC" && line2DSort ==  "Pt. 2")
	{
		sort(l2d.begin(), l2d.end(), [](Line2D *l1, Line2D *l2) 
		{		
				if(l1->getPt2().getX()==l2->getPt2().getX())
				{
					return ascending(l1->getPt2().getY(), l2->getPt2().getY());
				}
				return ascending(l1->getPt2().getX(), l2->getPt2().getX());	
		});
	}
	else if(order=="ASC" && line2DSort ==  "Length")
	{
		sort(l2d.begin(), l2d.end(), [](Line2D *l1, Line2D *l2)
		{
		        return ascending(l1->getScalarValue(), l2->getScalarValue());
		});
	}
	if(order=="DSC" && line2DSort ==  "Pt. 1")
	{
		sort(l2d.begin(), l2d.end(), [](Line2D *l1, Line2D *l2) 
		{
				if(l1->getPt1().getX()==l2->getPt1().getX())
				{
					return descending(l1->getPt1().getY(), l2->getPt1().getY());				
				}
				return descending(l1->getPt1().getX(), l2->getPt1().getX());	
		});
	}
	else if(order=="DSC" && line2DSort ==  "Pt. 2")
	{
		sort(l2d.begin(), l2d.end(), [](Line2D *l1, Line2D *l2) 
		{
				if(l1->getPt2().getX()==l2->getPt2().getX())
				{
					return descending(l1->getPt2().getY(), l2->getPt2().getY());
				}
				return descending(l1->getPt2().getX(), l2->getPt2().getX());			
		});
	}
	else if(order=="DSC" && line2DSort ==  "Length")
	{
		sort(l2d.begin(), l2d.end(), [](Line2D *l1, Line2D *l2)
		{
		        return descending(l1->getScalarValue(), l2->getScalarValue());
		});
	}
}

void MainMenu::sortLine3D()
{
	if(order=="ASC" && line3DSort ==  "Pt. 1")
	{
		sort(l3d.begin(), l3d.end(), [](Line3D *l1, Line3D *l2) 
		{
				if(l1->getPt1().getX()==l2->getPt1().getX())
				{
					return ascending(l1->getPt1().getY(), l2->getPt1().getY());
				}
				return ascending(l1->getPt1().getX(), l2->getPt1().getX());
			
		});
	}
	else if(order=="ASC" && line3DSort ==  "Pt. 2")
	{
		sort(l3d.begin(), l3d.end(), [](Line3D *l1, Line3D *l2) 
		{		
				if(l1->getPt2().getX()==l2->getPt2().getX())
				{
					return ascending(l1->getPt2().getY(), l2->getPt2().getY());
				}
				return ascending(l1->getPt2().getX(), l2->getPt2().getX());	
		});
	}
	else if(order=="ASC" && line3DSort ==  "Length")
	{
		sort(l3d.begin(), l3d.end(), [](Line3D *l1, Line3D *l2)
		{
		        return ascending(l1->getScalarValue(), l2->getScalarValue());
		});
	}
	if(order=="DSC" && line3DSort ==  "Pt. 1")
	{
		sort(l3d.begin(), l3d.end(), [](Line3D *l1, Line3D *l2) 
		{
				if(l1->getPt1().getX()==l2->getPt1().getX())
				{
					return descending(l1->getPt1().getY(), l2->getPt1().getY());				
				}
				return descending(l1->getPt1().getX(), l2->getPt1().getX());	
		});
	}
	else if(order=="DSC" && line3DSort ==  "Pt. 2")
	{
		sort(l3d.begin(), l3d.end(), [](Line3D *l1, Line3D *l2) 
		{
				if(l1->getPt2().getX()==l2->getPt2().getX())
				{
					return descending(l1->getPt2().getY(), l2->getPt2().getY());
				}
				return descending(l1->getPt2().getX(), l2->getPt2().getX());			
		});
	}
	else if(order=="DSC" && line3DSort ==  "Length")
	{
		sort(l3d.begin(), l3d.end(), [](Line3D *l1, Line3D *l2)
		{
		        return descending(l1->getScalarValue(), l2->getScalarValue());
		});
	}
}
void MainMenu::displayPoint2D()
{
	cout << setfill (' ') << setw (5) << "X" 
		 << setfill (' ') << setw (6) << "Y"
		 << setfill (' ') << right << setw (19) << "Dist. Fr Origin"
		 << endl
		 << setfill ('-') << setw (42) << "-" << endl;
			
	vector<Point2D*>::iterator display2d;
	for ( display2d = p2d.begin(); display2d != p2d.end(); display2d++) 
	{ 
		cout << **display2d;
	}

	
}
void MainMenu::displayPoint3D()
{
	 cout << setfill (' ') << setw (5) << "X" 
		  << setfill (' ') << setw (6) << "Y"
		  << setfill (' ') << setw (5) << "Z"
		  << setfill (' ') << right << setw (19) << "Dist. Fr Origin"
		  << endl
	      << setfill ('-') << setw (48) << "-" << endl;

	vector<Point3D*>::iterator display3d;
	for (display3d = p3d.begin(); display3d != p3d.end(); display3d++) 
	{ 
		cout << **display3d;
	}
}
void MainMenu::displayLine2D()
{
	cout << setfill (' ') << setw (5) << "P1-X" 
		 << setfill (' ') << setw (6) << "P1-Y"
		 << setfill (' ') << setw (9) << "P2-X" // including 3 spaces in between + 1 for [ 
		 << setfill (' ') << setw (6) << "P2-Y"
		 << setfill (' ') << right << setw (10) << "Length"
		 << endl
	     << setfill ('-') << setw (36) << "-" << endl;
	vector<Line2D*>::iterator displayl2d;
	for (displayl2d = l2d.begin(); displayl2d != l2d.end(); displayl2d++) 
	{ 
		cout << **displayl2d;
	}
}
void MainMenu::displayLine3D()
{
	cout << setfill (' ') << setw (5) << "P1-X" 
		 << setfill (' ') << setw (6) << "P1-Y"
		 << setfill (' ') << setw (6) << "P1-Z"
		 << setfill (' ') << setw (9) << "P2-X" // including 3 spaces in between + 1 for [ 
		 << setfill (' ') << setw (6) << "P2-Y"
		 << setfill (' ') << setw (6) << "P2-Z"
		 << setfill (' ') << right << setw (10) << "Length"
		 << endl
         << setfill ('-') << setw (49) << "-" << endl;

	vector<Line3D*>::iterator displayl3d;
	for (displayl3d = l3d.begin(); displayl3d != l3d.end(); displayl3d++) 
	{ 
		cout << **displayl3d;
	}
}

void MainMenu::printSortedPoint2D(ofstream& outputfile)
{
	outputfile << setfill (' ') << setw (5) << "X" 
		 << setfill (' ') << setw (6) << "Y"
		 << setfill (' ') << right << setw (19) << "Dist. Fr Origin"
		 << endl
		 << setfill ('-') << setw (42) << "-" << endl;


		 vector<Point2D*>::iterator display2D;
		 for (display2D = p2d.begin(); display2D != p2d.end(); display2D++) 
		 { 
			 outputfile << **display2D;
		 }
		 outputfile.close();
}
void MainMenu::printSortedPoint3D(ofstream& outputfile)
{
	outputfile << setfill (' ') << setw (5) << "X" 
		  << setfill (' ') << setw (6) << "Y"
		  << setfill (' ') << setw (5) << "Z"
		  << setfill (' ') << right << setw (19) << "Dist. Fr Origin"
		  << endl
	      << setfill ('-') << setw (48) << "-" << endl;

                                    
		vector<Point3D*>::iterator display3D;
		for (display3D= p3d.begin(); display3D != p3d.end(); display3D++) 
		{ 
			outputfile << **display3D;
		}
		outputfile.close();
}

void MainMenu::printSortedLine2D(ofstream& outputfile)
{
	outputfile << setfill (' ') << setw (5) << "P1-X" 
		 << setfill (' ') << setw (6) << "P1-Y"
		 << setfill (' ') << setw (9) << "P2-X" // including 3 spaces in between + 1 for [ 
		 << setfill (' ') << setw (6) << "P2-Y"
		 << setfill (' ') << right << setw (10) << "Length"
		 << endl
	     << setfill ('-') << setw (36) << "-" << endl;
	vector<Line2D*>::iterator displayl2d;
	for (displayl2d = l2d.begin(); displayl2d != l2d.end(); displayl2d++) 
	{ 
		outputfile << **displayl2d;
	}
	outputfile.close();
}
void MainMenu::printSortedLine3D(ofstream& outputfile)
{
	outputfile<< setfill (' ') << setw (5) << "P1-X" 
		 << setfill (' ') << setw (6) << "P1-Y"
		 << setfill (' ') << setw (6) << "P1-Z"
		 << setfill (' ') << setw (9) << "P2-X" // including 3 spaces in between + 1 for [ 
		 << setfill (' ') << setw (6) << "P2-Y"
		 << setfill (' ') << setw (6) << "P2-Z"
		 << setfill (' ') << right << setw (10) << "Length"
		 << endl
		 << setfill ('-') << setw (50) << "-" << endl;

	vector<Line3D*>::iterator displayl3d;
	for (displayl3d = l3d.begin(); displayl3d != l3d.end(); displayl3d++) 
	{ 
		outputfile << **displayl3d;
	}
	outputfile.close();
}
