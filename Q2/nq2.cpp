//Nicholash Bedi
//Assignment 4 question 2
#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
using namespace std;

double convDeg(int deg, int mins)
{
	return deg + double(mins)/60;
}

double toRadians(long double degrees)
{
	return ( degrees * M_PI / 180.0  ) ;
}

double toDegrees(double radians)
{
	return radians / M_PI * 180;
}

double Xcoor(double lat, double lon)
{
	return ( 111 * lon * cos( toRadians(lat) ) );
}

double Ycoor(double lat)
{
	return ( 111 * lat );
}

int main()
{
	ifstream coord("message.txt");
	if (!coord)
	{
		cout << "unable to open file" << endl;
		return EXIT_FAILURE;
	}
	
	
	int initDegIntLat, initDegMinLat, initDegIntLon, initDegMinLon, numSites;
	coord 	>> initDegIntLat >> initDegMinLat
			>> initDegIntLon >> initDegMinLon
			>> numSites;
	 
	double 	initDegLat = convDeg(initDegIntLat, initDegMinLat),
			initDegLon = convDeg(initDegIntLon, initDegMinLon);
	
	double 	initX = Xcoor(initDegLat, initDegLon),
			initY = Ycoor(initDegLat);
	
	int DegIntLat,DegMinLat,DegIntLon,DegMinLon;
	double Lat, Lon, dx, dy, angle; 
	char NS,WE;
	for (int i = 0; i < numSites; i++)
	{
		coord 	>> DegIntLat >> DegMinLat
				>> DegIntLon >> DegMinLon;
		Lat = convDeg(DegIntLat, DegMinLat);
		Lon = convDeg(DegIntLon, DegMinLon);
		dx = Xcoor(Lat, Lon) - initX;
		dy = Ycoor(Lat) - initY;
		angle = toDegrees(atan2(dx,dy));
		cout << sqrt(dx*dx+dy*dy) << " km in the direction" << endl;
		if (angle == 0)
			cout << "North (0 degrees)" << endl;
		else if (angle == 90)
			cout << "East" << endl;
		else if (angle == -90)
			cout << "West";
		else if (angle == -180)
			cout << "South" << endl;	
		else if (angle > -90 && angle < 0)
			cout << "North " << fabs(angle) << " degrees West" << endl;
		else if (angle < 90 && angle > 0)
			cout << "North " << angle << " degrees East" << endl;
		else if (angle < 180 && angle > 90)
			cout << "South " << 180-angle << " degrees East" << endl;
		else if (angle < -90)
			cout << "South " << angle -180 << " degrees West" << endl;
		cout << endl;
	}
	 
	
	return EXIT_SUCCESS;
}
/*
382.058 km in the direction
North 31.0108 degrees West

527.084 km in the direction
South 33.7117 degrees East

360.469 km in the direction
South -291.054 degrees West

1769.64 km in the direction
North 24.9915 degrees West

221.513 km in the direction
North 24.4489 degrees East

135.218 km in the direction
North 87.6477 degrees West

1415.07 km in the direction
North 77.5426 degrees East
*/
