#include <iostream> 
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <typeinfo>
#include <algorithm>
#include "Menu.h"
#include "ShapeTwoD.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Cross.h"
#include <bits/stdc++.h>

using namespace std;
   
int main()
{
    	Menu m;

	while(1)
	{
		m.userMenuOptions();
		m.processMenuOptions();
        m.processSortChoice();
	}	
}