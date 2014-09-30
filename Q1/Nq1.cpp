//Nicholash Bedi
//Assignment 4 question 1
#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main()
{
	double serviceCharge = 7.50, perkm = 3.25,x,y,dy,dx,distance = 0.0;
	int numstops;
	char NS, WE;
	ifstream routes("taxiDir_rev.txt");
	
	for(int a = 0; a < 2; a++)
	{
		routes >> numstops;
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
		}
	}
	
	return EXIT_SUCCESS;
	
}
