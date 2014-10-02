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

double toRadians(double degrees)
{
	//2pi =360degree
	return ( degrees * M_PI / 180.0  ) ;
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
	
	return EXIT_SUCCESS;
}
