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
//	ifstream routes("taxiDir_rev.txt");
	ifstream routes("text.txt");
	
	if(!routes)
	{
		cout << "Unable to open file" << endl;
		return EXIT_FAILURE;
	}
	
	
	while((routes >> numstops) != false)
	{
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
		cout << endl;
	}
	
	return EXIT_SUCCESS;
	
}
