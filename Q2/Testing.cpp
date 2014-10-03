//Nicholash Bedi
//Assignment 4 question 2
#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
using namespace std;

double toRadians(long double degrees)
{
	return ( degrees * M_PI / 180.0  ) ;
}

double toDegrees(double radians)
{
	return radians / M_PI *180;
}

int main()
{
	cout << toDegrees(atan2(1,1)) << endl;
	return EXIT_SUCCESS;
}

