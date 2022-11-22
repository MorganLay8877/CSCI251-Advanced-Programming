#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct gridSize
{
	int gridX = 0;
	int gridY = 0;
}Grid;

struct weatherMap
{
	int x = 0;
	int y = 0;
	int cityID;
	string cityName;
	bool isGridOccupied;
	bool isCloudGridOccupied;
	bool isPressureGridOccupied;
	int cloudCover, cloudIndex;
	int pressure, pressureIndex; 
	char cloudLMH, pressureLMH;
};

struct summaryValues
{
	double cloudArea = 0.0;
	double pressureArea = 0.0;
	double cloudTotal = 0.0;
	double pressureTotal = 0.0;
	double cloudAverage = 0.0; 
	double pressureAverage = 0.0;
	double rainProbability;
}summary;

weatherMap **weather;

void plotDisplayCityMap(int gridX, int gridY);
void plotDisplayCloudMap(int gridX, int gridY);
void plotDisplayCloudLMHMap(int gridX, int gridY);
void plotDisplayPressureMap(int gridX, int gridY);
void plotDisplayPressureLMHMap(int gridX, int gridY);
weatherMap readAndProcessConfigFile();
weatherMap readCityTxtFile(string txtfile);
weatherMap readCloudTxtFile(string txtfile);
weatherMap readPressureTxtFile(string txtfile);
char getLMH(int val);
int getIndex (int val);
vector<string> tokenizeString (string input, string delimiter);
vector<int>cityIDArray;
double calcAvg(double  sum, double  num);
double calcRainProbability(char cloudAverage, char pressureAverage);
void createWeatherForecastSummary();
int printCityNamesForecastSummary(int x, int y, vector<int>cityID, int i);


#endif
