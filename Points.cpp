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
#include "MainMenu.h"


using namespace std;


int main()
{
	MainMenu m;
	while(1)
	{
		m.displayMenu();
		m.processMainMenuChoice();
        //m.processSortChoice();
	}
	
}



