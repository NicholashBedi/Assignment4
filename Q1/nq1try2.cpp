//Nicholash Bedi
//Assignment 4 question 1
#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
using namespace std;


//RANDOM CODE
int main()
{
	ifstream routes("test.txt");	
	if(!routes)
	{
		cout << "Unable to open file" << endl;
		return EXIT_FAILURE;
	}
	
	double 	xinit, yinit, xchange, ychange, x, y,
			distanceTrip, distanceTotal = 0,
			costTrip = 0, costTotal = 0;
	int numstops, tripNum = 1;
	char NS, WE;
	while(routes >> numstops)
	{
		distanceTrip = 0;
		xinit = 0;
		yinit = 0;
		for(int i = 0; i < numstops; i++)
		{
			routes 	>> x >> NS
					>> y >> WE;
			xchange = x - xinit;
			ychange = y - yinit;
			
			xinit = x;
			yinit = y;
			distanceTrip += sqrt( pow(xchange,2) + pow(ychange,2) );
			
			cout 	<< "xinit, x, xchange " 
					<< xinit << ", " << x << ", " << xchange << ", " << endl
					<< "yinit, y, ychange " 
					<< yinit << ", " << y << ", " << ychange << ", " << endl
					<<"distance of trip thus far " << distanceTrip << endl;
		}
		cout << "\nend x y position " << x << " " << y << endl;
		
		distanceTrip += sqrt( pow(x,2) + pow(y,2) );
		costTrip = (numstops * 7.5) + (distanceTrip*3.25);
		
		cout << "distance of trip " << distanceTrip << endl;
		cout << "cost of trip " << costTrip << endl << endl;
		
		distanceTotal += distanceTrip;
		costTotal += costTrip;
		
		cout 	<<"distance of total " << distanceTotal << endl
				<<"Cost of total " << costTotal << endl << endl;
		
		tripNum++;
	}
	
	return EXIT_SUCCESS;
	
}
