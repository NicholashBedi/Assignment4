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
	double 	serviceCharge = 7.50, perkm = 3.25,x,y,dy,dx,
			distanceTotal = 0.0,distanceTrip = 0.0, distanceStop =0.0,
			locationX = 0.0, locationY = 0.0;
	int numstops;
	char NS, WE;
	ifstream routes("taxiDir_rev.txt");
	
	if(!routes)
	{
		cout << "Unable to open file" << endl;
		return EXIT_FAILURE;
	}
	
	double cost;
	while((routes >> numstops) != false)
	{
		cost = numstops*7.5;
		for(int i = 0; i < numstops; i++)
		{
			routes >> dy;
			routes >> NS;
			if(NS == 'S')
				dy*=-1;
			cout << dy << endl;
			
			routes >> dx;
			routes >> WE;
			if(WE == 'E')
				dx *= -1;
			cout << dx << endl;
			
			distanceTrip = sqrt(dy*dy + dx*dx);
			cout << "Distance stop: " << distanceTrip << endl;
			
			locationX += dx;
			locationY += dy;
			distanceTotal += distanceTrip;
			
		}
		distanceTotal += sqrt(pow(locationX,2)+pow(locationY,2));
		cout << "Distance total: " << distanceTotal << endl;
		cout << endl;
	}
	
	return EXIT_SUCCESS;
	
}

