#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <vector>
#include <bits/stdc++.h>
#include "Structs.h"

using namespace std;


    
vector<string> tokenizeString (string input, string delimiter)
{
	size_t pos = 0;
	string token;
	vector<string> result;

	while ((pos = input.find(delimiter)) != string::npos) 
	{
    	token = input.substr(0, pos);
    	result.push_back (token);
		input.erase(0, pos + delimiter.length());
	}

	result.push_back (input);

	return (result);
}

weatherMap readAndProcessConfigFile()
{
	string filename;//readAndProcessConfigFile()
	string aline;
	//string rangeNumbers;
	

	cout << "Please enter file config name: ";// Enter txt filename
	cin >> filename;
    
	fstream infile(filename.c_str(), fstream::in); // initalize fstream infile for txt file

	if (infile.good())// check to ensure if txt file status is good
	{
		while (getline(infile, aline))// read infile txt line by line
		{
			if(Grid.gridX !=0 && Grid.gridY != 0)
			{
				break;
			}
			if (aline.find("GridX_IdxRange") != string :: npos)// find GridX_IdxRange string in txt
			{
				string rangeNumbers = aline.erase(0,15); // erase GridX_IdxRange=, ending at 0
				vector<string>range =tokenizeString(rangeNumbers, "-"); // split string 
				// for example 0-10, - is the delimiter in this case
				Grid.gridX = atoi(range.at(1).c_str()); // for example 0-10, 10 is the value is extracted 
														// and converted from a array string vector element
														// to a int value
		
				cout << "Reading in GridX range: "<<aline<< " done....."<<endl;
				//cout << "Value of gridX is : " << Grid.gridX<<endl;
				range.clear();
			}
			if (aline.find("GridY_IdxRange") != string :: npos)// find GridX_IdxRange string in txt
			{
				string rangeNumbers = aline.erase(0,15);// erase GridY_IdxRange=, ending at 0
				
				vector<string>range = tokenizeString(rangeNumbers, "-");
				Grid.gridY = atoi(range.at(1).c_str());
														// for example 0-10, 10 is the value is extracted 
														// and converted from a array string vector element
														// to a int value
				
				cout << "Reading in GridY range: "<<aline<< " done....."<<endl;
				//cout << "Value of gridY is : " << Grid.gridY<<endl;
				range.clear();
			}
		
		}
	}
	else
	{
		cerr << "File could not be opened!\n"; // exception message if file could not be opnened or located
	}
	cout<<endl;
	weather = new weatherMap * [Grid.gridX + 1]; // two D array dynamic memory allocation
	for(int y = 0 ; y < Grid.gridX + 1; y++)
	{
		weather[y] = new weatherMap[Grid.gridY + 1];
	}
	 
	for (int x = 0; x < Grid.gridX + 1; x++)
    {
        for (int y = 0; y < Grid.gridY + 1; y++)
        {
		    weather[x][y] = {};// initalize weather struct 2D array to zero
            weather[x][y].x = x;// initalize value x in weather struct 2D array according to
								//GridX Values
            weather[x][y].y = y;// initalize value y in weather struct 2D array according to
								//GridY Values
        }
    }

	int selectfile = 0;
	cout <<"Storing data from input files...."<<endl;
	if (infile.good())// check to ensure if txt file status is good
	{
		while (getline(infile, aline))// read line by line until reaching .txt
		{
			size_t position = aline.find(".txt");// find .txt file in config txt
			if (position != string::npos)
			{
				if (selectfile == 0)
				{
					readCityTxtFile(aline);// read citylocation.txt
					cout << aline << " done!....."<<endl;
				}
				else if (selectfile == 1)
				{
					readCloudTxtFile(aline);// read cloud.txt
					cout << aline << " done!....."<<endl;
				}
				else if (selectfile == 2)
				{
					readPressureTxtFile(aline);// read pressure.txt
					cout << aline << " done!....."<<endl;
				}
				selectfile++;				
			}
			
		}
	}
	else
	{
		cerr << "File could not be opened!\n";  // exception message if file could not be opnened or located
	}

	return **weather; // return double pointer of weather struct
}

weatherMap readCityTxtFile(string txtfile)
{
	fstream infile(txtfile.c_str(),fstream::in);//read Txt File
	string aline;
	string nextline;

	if (infile.good())// check to ensure if txt file status is good
	{
		while (getline(infile, aline))// read city txt file line by line
		{
			if(aline == "")// if reach end of txt file, exit while loop
			{
				break;
			}
				
			aline.erase(0,1); // erase first bracket '[' , e.g  [2, 1]-3-Big_City
			vector<string>val_one = tokenizeString(aline, ", "); //select , as a delimiter for 2, 1]-3-Big_City
			int x = atoi (val_one.at(0).c_str()); // extract string value 2 from 2, 1]-3-Big_City
													// converting it to int value
			//cout << "X is: " << x << endl;
			nextline = val_one[1]; //nextline is 1]-3-Big_City after split

			vector<string>val_two = tokenizeString(nextline, "]"); //select ] as a delimiter for 1]-3-Big_City
			int y = atoi (val_two.at(0).c_str());// extract string y value 1 from 1]-3-Big_City
												 // converting it to int value
			//cout << "Y is: " << y << endl;
			nextline = val_two[1]; // nextline is now -3-Big_City
			nextline = nextline.erase(0,1); // erase '-' from -3-Big_City becoming 3-Big_City
			//cout << "nextline is: " << nextline[0] << endl;

			if(nextline.size() == 2 && isdigit(nextline[0])
			                        && isdigit(nextline[1]))// check if txt file is in correct format
			{
				int cityID = stoi(nextline);
				weather[x][y].cityID = cityID;
				weather[x][y].isGridOccupied = true;
			}
			else if (nextline.size() == 1 && isdigit(nextline[0]))
			{
				int cityID = stoi(nextline);
				weather[x][y].cityID = cityID;
				weather[x][y].isGridOccupied = true;
			}
			else if (nextline.size()>=3 && isdigit(nextline[0]) 
			                            && nextline[1] == '-')
			{
				vector<string> val_third = tokenizeString(nextline, "-");//select - as a delimiter for 3-Big_City
				int cityID = atoi(val_third.at(0).c_str());// extract cityID string value 3 and converting to int
				//cout << "city Index is: " << cityID  << endl;
				nextline = val_third[1]; // extract Big_City string 
				string cityName = nextline;
				//cout << "city name is: " << cityName <<endl;
				weather[x][y].cityID = cityID; // storing values in struct 2D array
				weather[x][y].isGridOccupied = true; // boolean to check if grid is empty
				weather[x][y].cityName = cityName;
				
			}
			else if (nextline.size()>=3 && isdigit(nextline[0]) 
			                            && isdigit(nextline[1])
										&& nextline[2] == '-')
			{
				vector<string> val_third = tokenizeString(nextline, "-");
				int cityID = atoi(val_third.at(0).c_str());
				//cout << "city Index is: " << cityID  << endl;
				nextline = val_third[1];
				string cityName = nextline;
				//cout << "city name is: " << cityName <<endl;
				weather[x][y].cityID = cityID;
				weather[x][y].isGridOccupied = true;
				weather[x][y].cityName = cityName;
				
			}
			
		}
	}
	else
	{
		cerr << "File could not be opened!\n";  // exception message if file could not be opnened or changed
	}
	return **weather;
}

weatherMap readCloudTxtFile(string txtfile)
{
	fstream infile(txtfile.c_str(),fstream::in);// read cloud txt file 
	string aline;
	string nextline;

	if (infile.good())// check to ensure if txt file status is good
	{
		while (getline(infile, aline))// read cloud txt file line by line
		{
			    if(aline == "")// if reach end of txt file, exit while loop
				{
					break;
				}
				aline.erase(0,1);// erase first bracket '[' , e.g  [0, 5]-39

				vector<string>val_one = tokenizeString(aline, ", ");//select , as a delimiter for 0, 5]-39
				int x = atoi (val_one.at(0).c_str()); // extract string value 0 from 0, 5]-39
				//cout << "X is: " << x << endl;
				nextline = val_one[1]; // nextline is 5]-39 after split 

				vector<string>val_two = tokenizeString(nextline, "]"); //select ] as a delimiter for  5]-39
				int y = atoi (val_two.at(0).c_str()); // extract string y value 5 from 5]-39
												      // converting it to int value 
				//cout << "Y is: " << y << endl;
				nextline = val_two[1];// nextline is -39 after split
				nextline = nextline.erase(0,1); // erase '-' from -39 becoming 39

				if(nextline.size() == 2 && isdigit(nextline[0])
			                            && isdigit(nextline[1]))
				{
					
					int cloud = stoi(nextline);// convert 39 value to int
					int cloudIndex = getIndex(cloud); // get index value cloud from cloud value
					//cout << "Pressure index is: " << pressureIndex << endl;
					char cloudLMH = getLMH(cloud); // get LMH symbol from cloud value
					//cout << "cloud LMH is: " << pressureLMH << endl;

					weather[x][y].cloudCover = cloud; // storing values in struct 2D array weather
					weather[x][y].cloudIndex = cloudIndex ;
					weather[x][y].isCloudGridOccupied = true;
					weather[x][y].cloudLMH = cloudLMH;
				}
				else if (nextline.size() == 1 && isdigit(nextline[0]))
				{
					int cloud = stoi(nextline);
					//cout << "Pressure is: " << pressure << endl;
					int cloudIndex = getIndex(cloud);
					//cout << "Pressure index is: " << pressureIndex << endl;
					char cloudLMH = getLMH(cloud);
					//cout << "cloud LMH is: " << pressureLMH << endl;

					weather[x][y].cloudCover = cloud;
					weather[x][y].cloudIndex = cloudIndex ;
					weather[x][y].isCloudGridOccupied = true;
					weather[x][y].cloudLMH = cloudLMH;
				}
				
				
		}
	}
	else
	{
		cerr << "File could not be opened!\n";  // exception message if file could not be opnened or changed
	}

	return **weather;
}

// The same is for readPressureTxtFile from readCloudTxtFile(string txtfile)
weatherMap readPressureTxtFile(string txtfile)
{
	fstream infile(txtfile.c_str(),fstream::in);//readPressureFile
	string aline;
	string nextline;

	if (infile.good())
	{
		while (getline(infile, aline))
		{
			    if(aline == "")
				{
					break;
				}
				aline.erase(0,1);

				vector<string>val_one = tokenizeString(aline, ", ");
				int x = atoi (val_one.at(0).c_str());
				//cout << "X is: " << x << endl;
				nextline = val_one[1];

				vector<string>val_two = tokenizeString(nextline, "]");
				int y = atoi (val_two.at(0).c_str());
				//cout << "Y is: " << y << endl;
				nextline = val_two[1];
				nextline = nextline.erase(0,1);

				if(nextline.size() == 2 && isdigit(nextline[0])
			                            && isdigit(nextline[1]))
				{
					int pressure = stoi(nextline);

					int pressureIndex = getIndex(pressure);
					//cout << "Pressure index is: " << pressureIndex << endl;
					char pressureLMH = getLMH(pressure);
					//cout << "cloud LMH is: " << pressureLMH << endl;

					weather[x][y].pressure= pressure;
					weather[x][y].pressureIndex = pressureIndex;
					weather[x][y].pressureLMH = pressureLMH;
					weather[x][y].isPressureGridOccupied = true;
				}
				else if (nextline.size() == 1 && isdigit(nextline[0]))
				{
					int pressure = stoi(nextline);
					//cout << "Pressure is: " << pressure << endl;
					int pressureIndex = getIndex(pressure);
					//cout << "Pressure index is: " << pressureIndex << endl;
					char pressureLMH = getLMH(pressure);
					//cout << "cloud LMH is: " << pressureLMH << endl;

					weather[x][y].pressure= pressure;
					weather[x][y].pressureIndex = pressureIndex;
					weather[x][y].pressureLMH = pressureLMH;
					weather[x][y].isPressureGridOccupied = true;
				}
				
		}
	}
	else
	{
		cerr << "File could not be opened!\n"; // exception message if file could not be opnened or changed
	}

	return **weather;
}

int getIndex (int val)// get index value 
{
	if(val <= 10)
		return 0;
	else if (val >= 10 && val < 20)
	    return 1;
	else if (val >= 20 && val < 30)
	    return 2;
	else if (val >= 30 && val < 40)
	    return 3;
	else if (val >= 40 && val < 50)
	    return 4;
	else if (val >= 50 && val < 60)
	    return 5;
	else if (val >= 60 && val < 70)
	    return 6;
	else if (val >= 70 && val < 80)
	    return 7;
	else if (val >= 80 && val < 90)
	    return 8;
	else
		return 9;
	
}

char getLMH(int val) //return char LMH according to value
{
   if(val <= 35)
	return 'L';
   else if (val >= 35 && val <= 65)
    return 'M';
   else 
    return 'H';
}
/*void plotDisplayCityMap(int gridX, int gridY)
{
	for (int y= gridY + 1; y >=- 2; y--)//clod
	{
		for(int x = -3; x <= gridX + 1 ; x++)
		{
			cout << "";
			if((y == gridY + 1 && x >=-1) ||(y == -1 && x >= -1))
			   cout<<setw(2)<< " #"<<" ";
			else if ((x == -1 && y >= -1)||(x == gridX + 1 && y >= -1))
			   cout<<setw(2)<< " #"<<" ";
			else if ( x == -2 && y >= 0 && y <= gridY)
				cout<<setw(2)<< y << "";

			else if (y == -2 && x >=0 && x <= gridX)
			{
				cout<< setw(2)<<""<< x;
			}
			else if (x <= gridX &&
                x >= 0 &&
                y <= gridY &&
                y >= 0 && weather[x][y].isGridOccupied == true)

                cout << setw(2)<< weather[x][y].cityID << " ";
			else
				cout << "  ";	

		}
		cout << endl;
	}
	cout << endl;
	//returnToMenu();
	cout << endl;
}*/
void plotDisplayCityMap(int gridX, int gridY)// plot grid values according struct 2D values
{
	
	for (int y = gridY + 1; y >= -2; y--) 
	{
        for (int x = -3; x <= gridX + 1; x++) 
		{
			cout << "";
			/*if(y == gridY + 1 && x >=-1)
				cout<<setw(2)<< " #"<<"";
			else if (y == -1 && x >= -1)
				cout<<setw(2)<< " #"<<"";
			else if (x == -1 && y >= -1)
				cout<<setw(2)<< " #"<<" ";
			else if (x == gridX + 1 && y >= -1)
				cout<<"#"<<"";
			else if ( x == -2 && y >= 0 && y <= gridY)
				cout<<setw(2)<< y << "";
            else if (y == -2 && x >=0 && x <= gridX)
				cout<<" "<< x;*/
			if(y == gridY + 1 && x >=-1)// print first vertical # pattern
				cout<<setw(2)<< " #"<<"";
			else if (y == -1 && x >= -1)
				cout<<setw(2)<< " #"<<"";// print second vertical # pattern
			else if (x == -1 && y >= -1)
				cout<<setw(2)<< " #"<<" ";// print first vertical # pattern
			else if (x == gridX + 1 && y >= -1)
				cout<<"#"<<"";  // print second vertical # pattern
			else if ( x == -2 && y >= 0 && y <= gridY)
				cout<<setw(2)<< y << ""; // print y grid values
            else if (y == -2 && x >=0 && x <= gridX)// print x grid values
			{
				if (x <= 10)
					cout<<" "<< x;
				else if (x >= 11)
					cout<<""<< x;
			}

			else if (x <= gridX && // map 2D struct values into grid, boolean to check for any grid
                x >= 0 &&			// spaces
                y <= gridY &&
                y >= 0 && weather[x][y].isGridOccupied == true)
                cout << weather[x][y].cityID << " ";
			
			else
				cout << "  ";			
			
        }
        cout << endl;
    }
    cout << endl;
	cout << endl;
}
/*void plotDisplayCloudMap(int gridX, int gridY)
{
	for (int y= gridY + 1; y >=- 2; y--)//clod
	{
		for(int x = -3; x <= gridX + 1 ; x++)
		{
			cout << "";
			if((y == gridY + 1 && x >=-1) ||(y == -1 && x >= -1))
			   cout<<setw(2)<< " #"<<" ";
			else if ((x == -1 && y >= -1)||(x == gridX + 1 && y >= -1))
			   cout<<setw(2)<< " #"<<" ";
			else if ( x == -2 && y >= 0 && y <= gridY)
				cout<<setw(2)<< y << "";

			else if (y == -2 && x >=0 && x <= gridX)
			{
				cout<< setw(2)<<""<< x;
			}
			else if (x <= gridX &&
                x >= 0 &&
                y <= gridY &&
                y >= 0 && weather[x][y].isGridOccupied == true)

                cout << setw(2)<< weather[x][y].cloudLMH << " ";
			else
				cout << "  ";	

		}
		cout << endl;
	}
	cout << endl;
	//returnToMenu();
	cout << endl;
}*/

//same for cloud and pressure maps
void plotDisplayCloudMap(int gridX, int gridY) 
{
   for (int y = gridY + 1; y >= -2; y--) 
	{
        for (int x = -3; x <= gridX + 1; x++) 
		{
			cout << "";
			if(y == gridY + 1 && x >=-1)
				cout<<setw(2)<< " #"<<"";
			else if (y == -1 && x >= -1)
				cout<<setw(2)<< " #"<<"";
			else if (x == -1 && y >= -1)
				cout<<setw(2)<< " #"<<" ";
			else if (x == gridX + 1 && y >= -1)
				cout<<"#"<<"";
			else if ( x == -2 && y >= 0 && y <= gridY)
				cout<<setw(2)<< y << "";
            else if (y == -2 && x >=0 && x <= gridX)
			{
				if (x <= 10)
					cout<<" "<< x;
				else if (x >= 11)
					cout<<""<< x;
			}
				
			else if (x <= gridX &&
                x >= 0 &&
                y <= gridY &&
                y >= 0 && weather[x][y].isCloudGridOccupied == true )
                cout<< weather[x][y].cloudIndex << " ";	
			else
				cout << "  ";			
			
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void plotDisplayCloudLMHMap(int gridX, int gridY) 
{ 
	for (int y = gridY + 1; y >= -2; y--) 
	{
        for (int x = -3; x <= gridX + 1; x++) 
		{
			cout << "";
			if(y == gridY + 1 && x >=-1)
				cout<<setw(2)<< " #"<<"";
			else if (y == -1 && x >= -1)
				cout<<setw(2)<< " #"<<"";
			else if (x == -1 && y >= -1)
				cout<<setw(2)<< " #"<<" ";
			else if (x == gridX + 1 && y >= -1)
				cout<<"#"<<"";
			else if ( x == -2 && y >= 0 && y <= gridY)
				cout<<setw(2)<< y << "";
            else if (y == -2 && x >=0 && x <= gridX)
			{
				if (x <= 10)
					cout<<" "<< x;
				else if (x >= 11)
					cout<<""<< x;
			}
				
			else if (x <= gridX &&
                x >= 0 &&
                y <= gridY &&
                y >= 0 && weather[x][y].isCloudGridOccupied == true)
                cout << weather[x][y].cloudLMH << " ";
			
			else
				cout << "  ";			
			
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void plotDisplayPressureMap(int gridX, int gridY) 
{
    for (int y = gridY + 1; y >= -2; y--) 
	{
        for (int x = -3; x <= gridX + 1; x++) 
		{
			cout << "";
			if(y == gridY + 1 && x >=-1)
				cout<<setw(2)<< " #"<<"";
			else if (y == -1 && x >= -1)
				cout<<setw(2)<< " #"<<"";
			else if (x == -1 && y >= -1)
				cout<<setw(2)<< " #"<<" ";
			else if (x == gridX + 1 && y >= -1)
				cout<<"#"<<"";
			else if ( x == -2 && y >= 0 && y <= gridY)
				cout<<setw(2)<< y << "";
            else if (y == -2 && x >=0 && x <= gridX)
			{
				if (x <= 10)
					cout<<" "<< x;
				else if (x >= 11)
					cout<<""<< x;
			}
				
			else if (x <= gridX &&
                x >= 0 &&
                y <= gridY &&
                y >= 0 && weather[x][y].isPressureGridOccupied == true)
                cout << weather[x][y].pressureIndex << " ";
			
			else
				cout << "  ";			
			
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void plotDisplayPressureLMHMap(int gridX, int gridY)
{
	for (int y = gridY + 1; y >= -2; y--) 
	{
        for (int x = -3; x <= gridX + 1; x++) 
		{
			cout << "";
			if(y == gridY + 1 && x >=-1)
				cout<<setw(2)<< " #"<<"";
			else if (y == -1 && x >= -1)
				cout<<setw(2)<< " #"<<"";
			else if (x == -1 && y >= -1)
				cout<<setw(2)<< " #"<<" ";
			else if (x == gridX + 1 && y >= -1)
				cout<<"#"<<"";
			else if ( x == -2 && y >= 0 && y <= gridY)
				cout<<setw(2)<< y << "";
            else if (y == -2 && x >=0 && x <= gridX)
			{
				if (x <= 10)
					cout<<" "<< x;
				else if (x >= 11)
					cout<<""<< x;
			}
			else if (x <= gridX &&
                x >= 0 &&
                y <= gridY &&
                y >= 0 && weather[x][y].isPressureGridOccupied == true)
                cout << weather[x][y].pressureLMH << " ";
			
			else
				cout << "  ";			
			
        }
        cout << endl;
    }
    cout << endl;
	cout << endl;
}

/*void plotDisplayCloudLMHMap(int gridX, int gridY) 
{ 
	for (int y= gridY + 1; y >=- 2; y--)//clod
	{
		for(int x = -3; x <= gridX + 1 ; x++)
		{
			cout << "";
			if((y == gridY + 1 && x >=-1) ||(y == -1 && x >= -1))
			   cout<<setw(2)<< " #"<<" ";
			else if ((x == -1 && y >= -1)||(x == gridX + 1 && y >= -1))
			   cout<<setw(2)<< " #"<<" ";
			else if ( x == -2 && y >= 0 && y <= gridY)
				cout<<setw(2)<< y << "";

			else if (y == -2 && x >=0 && x <= gridX)
			{
				cout<< setw(2)<<""<< x;
			}
			else if (x <= gridX &&
                x >= 0 &&
                y <= gridY &&
                y >= 0)

                cout << setw(2)<< weather[x][y].cloudLMH << " ";
			else
				cout << "  ";	

		}
		cout << endl;
	}
	cout << endl;
	//returnToMenu();
	cout << endl;
}

/*void plotDisplayPressureMap(int gridX, int gridY) 
{
    for (int y= gridY + 1; y >=- 2; y--)//clod
	{
		for(int x = -3; x <= gridX + 1 ; x++)
		{
			cout << "";
			if((y == gridY + 1 && x >=-1) ||(y == -1 && x >= -1))
			   cout<<setw(2)<< " #"<<" ";
			else if ((x == -1 && y >= -1)||(x == gridX + 1 && y >= -1))
			   cout<<setw(2)<< " #"<<" ";
			else if ( x == -2 && y >= 0 && y <= gridY)
				cout<<setw(2)<< y << "";

			else if (y == -2 && x >=0 && x <= gridX)
			{
				cout<< setw(2)<<""<< x;
			}
			else if (x <= gridX &&
                x >= 0 &&
                y <= gridY &&
                y >= 0)

                cout << setw(2)<< weather[x][y].pressureIndex << " ";
			else
				cout << "  ";	

		}
		cout << endl;
	}
	cout << endl;
	//returnToMenu();
	cout << endl;
}


void plotDisplayPressureLMHMap(int gridX, int gridY) 
{
    for (int y= gridY + 1; y >=- 2; y--)//clod
	{
		for(int x = -3; x <= gridX + 1 ; x++)
		{
			cout << "";
			if((y == gridY + 1 && x >=-1) ||(y == -1 && x >= -1))
			   cout<<setw(2)<< " #"<<" ";
			else if ((x == -1 && y >= -1)||(x == gridX + 1 && y >= -1))
			   cout<<setw(2)<< " #"<<" ";
			else if ( x == -2 && y >= 0 && y <= gridY)
				cout<<setw(2)<< y << "";

			else if (y == -2 && x >=0 && x <= gridX)
			{
				cout<< setw(2)<<""<< x;
			}
			else if (x <= gridX &&
                x >= 0 &&
                y <= gridY &&
                y >= 0)

                cout << setw(2)<< weather[x][y].pressureLMH << " ";
			else
				cout << "  ";	

		}
		cout << endl;
	}
	cout << endl;
	//returnToMenu();
	cout << endl;
}
*/
double calcAvg(double  sum, double  num)// calculate average
{
	return  sum / num;
}
double calcRainProbability(char cloudAverage, char pressureAverage)// return double rain probability according to LMH
{
		if(cloudAverage == 'L' && cloudAverage == 'H')
			return (90.00);
		else if (cloudAverage == 'L' && pressureAverage == 'M')
			return (80.00);
		else if (cloudAverage == 'L' && pressureAverage == 'L')
			return (70.00);
		else if (cloudAverage == 'M' && pressureAverage == 'H')
			return (60.00);
		else if (cloudAverage == 'M' && pressureAverage == 'M')
			return (50.00);
		else if (cloudAverage == 'M' && pressureAverage == 'L')
			return (40.00);
		else if (cloudAverage == 'H' && pressureAverage == 'H')
			return (30.00);
		else if (cloudAverage == 'H' && pressureAverage == 'M')
			return (20.00);
		else 
			return (10.00);
		
}

int printCityNamesForecastSummary(int gridX, int gridY, vector<int>cityID, int i)// print city Names functions
{
	for (int x = 0; x < gridX + 1; x++)
		{
			for (int y = 0; y < gridY + 1; y++)
			{
			    if(weather[x][y].cityID == cityID[i])
				{
						cout << "City Name: " << weather[x][y].cityName << endl; 
						return 0;
				}
			}
		}
	return 0;
}
void createWeatherForecastSummary(int gridX, int gridY)// print weather forecast summary
{
	for (int x = 0; x < gridX + 1; x++)
    {
        for (int y = 0; y < gridY + 1; y++)
        {
           if(weather[x][y].isGridOccupied == true)// 
			{
					cityIDArray.push_back(weather[x][y].cityID);// store cityID value struct 2D value into vector
			}
        }
    }

	sort(cityIDArray.begin(), cityIDArray.end(), greater<int>()); // sort in descending order
	cityIDArray.erase(unique(cityIDArray.begin(), cityIDArray.end()), cityIDArray.end()); // eliminate duplicates


	for(int i = 0; i < cityIDArray.size(); i++)
	{
		//calcuate cloud grid area pressure grid area and cloud or pressure total
		printCityNamesForecastSummary(gridX, gridY, cityIDArray, i);
		for (int x = 0; x < gridX + 1; x++)
        {
			for (int y = 0; y < gridY + 1; y++)
			{
				if(weather[x][y].cityID == cityIDArray[i])
				{
					summary.cloudArea++;
					summary.cloudTotal += weather[x][y].cloudCover;
					summary.pressureArea++;
					summary.pressureTotal += weather[x][y].pressure;
				}
				else if (y + 1 <= gridY && weather[x][y + 1].cityID == cityIDArray[i])
				{
					summary.cloudArea++;
					summary.cloudTotal += weather[x][y].cloudCover;
					summary.pressureArea++;
					summary.pressureTotal += weather[x][y].pressure;
				}
				else if (y + 1 <= gridY && x - 1 <= gridX && x - 1 >= 0 
				                                && weather[x - 1][y + 1].cityID == cityIDArray[i] )
				{
					summary.cloudArea++;
					summary.cloudTotal += weather[x][y].cloudCover;
					summary.pressureArea++;
					summary.pressureTotal += weather[x][y].pressure;
				}
				else if (y + 1 <= gridY && x + 1 <= gridX
				                        && weather[x + 1][y + 1].cityID == cityIDArray[i])
				{
					summary.cloudArea++;
					summary.cloudTotal += weather[x][y].cloudCover;
					summary.pressureArea++;
					summary.pressureTotal += weather[x][y].pressure;
				}
				else if (x - 1 <= gridX && x - 1 >= 0
				         && weather[x - 1][y].cityID == cityIDArray[i])
				{
					summary.cloudArea++;
					summary.cloudTotal += weather[x][y].cloudCover;
					summary.pressureArea++;
					summary.pressureTotal += weather[x][y].pressure;
				}
				else if (x + 1 <= gridX && weather[x + 1][y].cityID == cityIDArray[i])
				{
					summary.cloudArea++;
					summary.cloudTotal += weather[x][y].cloudCover;
					summary.pressureArea++;
					summary.pressureTotal += weather[x][y].pressure;
				}
				else if (y - 1 <= gridY && y - 1 >= 0 
				         && weather[x][y - 1].cityID == cityIDArray[i])
				{
					summary.cloudArea++;
					summary.cloudTotal += weather[x][y].cloudCover;
					summary.pressureArea++;
					summary.pressureTotal += weather[x][y].pressure;
				}
				else if (y - 1 <= gridY && y - 1 >= 0 && 
			             x - 1 <= gridX && x - 1 >= 0 && 
			            weather[x - 1][y - 1].cityID == cityIDArray[i])
				{
					summary.cloudArea++;
					summary.cloudTotal += weather[x][y].cloudCover;
					summary.pressureArea++;
					summary.pressureTotal += weather[x][y].pressure;
				}
				else if (y - 1 <= gridY && y - 1 >= 0 && 
			             x + 1 <= gridX && weather[x + 1][y - 1].cityID == cityIDArray[i])
				{
					summary.cloudArea++;
					summary.cloudTotal += weather[x][y].cloudCover;
					summary.pressureArea++;
					summary.pressureTotal += weather[x][y].pressure;
				}
			}
        }
		summary.cloudAverage = calcAvg(summary.cloudTotal, summary.cloudArea); // calculate cloud averages
	    summary.pressureAverage = calcAvg(summary.pressureTotal, summary.pressureArea);// calculate pressure averages

         cout<< "City ID : "<< cityIDArray[i] <<endl; // display city ID
	    cout<< "Ave. Cloud Cover (ACC): "<< setprecision (2) << fixed<< summary.cloudAverage; // display cloud average
		cout<<"("<< getLMH ((int)summary.cloudAverage)<<")"<<endl; // get LMH according cloud average values
		cout<< "Ave. Pressure (AP): "<< setprecision (2) << fixed<< summary.pressureAverage; // display pressure average
		cout<<"("<< getLMH ((int)summary.pressureAverage)<<")"<<endl;// get LMH according pressure average values

        summary.rainProbability = calcRainProbability(getLMH ((int)summary.cloudAverage),
		                                              getLMH ((int)summary.pressureAverage));// get rain probability  according
													  										// to LMH values for cloud average 
																							// and pressure average
		
		cout <<"Probability of rain (%) :"<< setprecision (2) << fixed 
		     <<summary.rainProbability<<endl; // display probability of rain
		
		if(summary.rainProbability == 90.00)// display weather symbols acording to rain probability
		{
		     cout<< "~~~~"<<endl;
		     cout<< "~~~~~"<<endl;
		     cout<< "\\\\\\\\\\"<<endl;
		}
		else if (summary.rainProbability == 80.00)
		{
		     cout<< "~~~~"<<endl;
		     cout<< "~~~~~"<<endl;
		     cout<< "\\\\\\\\"<<endl;
		}
		else if (summary.rainProbability == 70.00)
		{
		     cout<< "~~~~"<<endl;
		     cout<< "~~~~~"<<endl;
		     cout<< "\\\\\\"<<endl;
		}
		else if (summary.rainProbability == 60.00)
		{
		     cout<< "~~~~"<<endl;
		     cout<< "~~~~~"<<endl;
		     cout<< "\\\\"<<endl;
		}
		else if (summary.rainProbability == 50.00)
		{
		     cout<< "~~~~"<<endl;
		     cout<< "~~~~~"<<endl;
		     cout<< "\\"<<endl;
		}
		else if (summary.rainProbability == 40.00)
		{
		     cout<< "~~~~"<<endl;
		     cout<< "~~~~~"<<endl;
		}
		else if (summary.rainProbability == 30.00)
		{
		     cout<< "~~~"<<endl;
		     cout<< "~~~~"<<endl;
		}
		else if (summary.rainProbability == 20.00)
		{
		     cout<< "~~"<<endl;
		     cout<< "~~~"<<endl;
		}
		else if (summary.rainProbability == 10.00)
		{
		     cout<< "~"<<endl;
		     cout<< "~~"<<endl;
		}

		cout<<endl;
	}

}
int main()
{
	
	   char useroption = '0';
		
		while (useroption != '8')
		{
			char userInputOptions;
			//display main menu.
			cout << "Student ID: 6564434" << endl;
			cout << "Student Name: Lay Wee Chong" << endl;
			cout << "---------------------------------------" << endl;
			cout << "Welcome to Weather Information Processing System!" << endl;
	
			cout << "\n"
				 << "1)\t Read in and process a configuration file" << endl;
			cout << "2)\t Display city map" << endl;
			cout << "3)\t Display cloud average map (cloudiness index)" << endl;
			cout << "4)\t Display cloud coverage map (LMH symbols)" << endl;
			cout << "5)\t Display atmospheric pressure map (pressure index)" << endl;
			cout << "6)\t Display atmospheric pressure map (LMH symbols)" << endl;
			cout << "7)\t Show weather forecast summary report" << endl;
			cout << "8)\t Quit" << endl;
			cout << endl;
	
			cout<< "Enter your choice: ";
			cin >> useroption;
			cout << endl;
// switch case statements for user menu options
			switch (useroption)
			{
				case '1':
				{
					//searchConfigFile();
					**weather = readAndProcessConfigFile();
					cout << "Press <enter> to go back to main menu..." << endl;	
				}
				break;
				case '2':
				{
					cout << "Map of city: " << endl;
					cout << "----------------------------------------------------" << endl;
					
					plotDisplayCityMap(Grid.gridX, Grid.gridY);
					cout << "Press <enter> to go back to main menu..." << endl;
					
				}
				break;
				case '3':
				{
					cout << "Cloud Coverage Map of city (cloudiness index): " << endl;
					cout << "----------------------------------------------------" << endl;
					plotDisplayCloudMap(Grid.gridX, Grid.gridY);
					cout << "Press <enter> to go back to main menu..." << endl;
				}
				break;
				case '4':
				{
					cout << "Cloud Coverage Map of city (LMH symbols): " << endl;
					cout << "----------------------------------------------------" << endl;
					plotDisplayCloudLMHMap(Grid.gridX, Grid.gridY) ;
					cout << "Press <enter> to go back to main menu..." << endl;
				}
				break;
				case '5':
				{	
					cout << "Atmospheric Pressure Map of city (pressure index): " << endl;
					cout << "----------------------------------------------------" << endl;
					plotDisplayPressureMap(Grid.gridX, Grid.gridY) ;
					cout << "Press <enter> to go back to main menu..." << endl;
				}
				break;
				case '6':
				{
					cout << "Atmospheric Pressure Map of city (LMH symbols): " << endl;
					cout << "----------------------------------------------------" << endl;
					plotDisplayPressureLMHMap(Grid.gridX, Grid.gridY);
					cout << "Press <enter> to go back to main menu..." << endl;
				}
				break;
				case '7':
				{
					cout << "Weather Forecast Summary Report" << endl;
					cout << "------------------------------------" << endl;
					createWeatherForecastSummary(Grid.gridX, Grid.gridY);
					cout << "Press <enter> to go back to main menu..." << endl;
				}
				break;
//dellocate remaining dellocate memory and vectors
				case '8':
				{
					
					cout << "Thank you for using Weather Information Processing System, goodbye." << endl;
					return 0;
				}
				break;
				default:
				{
					
					cout<<"Please valid options (1-8)"<<endl;
				}
			}
		}//end of while loop
				
	for (int x = 0; x < Grid.gridX ; x++)
	{
		delete weather[x]; //dellocate 2D struct array memory 
	}
	delete weather;
	  return 0;
}
