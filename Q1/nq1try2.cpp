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
	ifstream routes("taxiDir_rev.txt");	
	if(!routes)
	{
		cout << "Unable to open file" << endl;
		return EXIT_FAILURE;
	}
	ofstream DandC("DistancesAndCost.txt");
	
	DandC << "Stop Number | Trip Dist  |  Trip Cost | Total Dist | Total Cost |" 
		  << endl
		  << setfill('-') << setw(65) << '-' << endl << setfill(' ');
	
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
		}
		
		distanceTrip += sqrt( pow(x,2) + pow(y,2) );
		costTrip = (numstops * 7.5) + (distanceTrip*3.25);
		
		distanceTotal += distanceTrip;
		costTotal += costTrip;
		
		if(tripNum <= 4 || (tripNum - 4) % 10 == 0)
		{
			int w = 11;
			DandC 	<< setprecision(2) << fixed
					<< setw(w) << tripNum 		<< " |"
					<< setw(w) << distanceTrip 	<< " |"
					<< setw(w) << costTrip 		<< " |"
					<< setw(w) << distanceTotal << " |"
					<< setw(w) << costTotal 	<< " |"
					<< endl;
		}
		tripNum++;
	}
	DandC 	<< setfill('-') << setw(65) << '-' << endl
			<< "      Total |" << setfill(' ') << setw(26) << ' '
			<< setw(11) << distanceTotal << " |"
			<< setw(11) << costTotal 	<< " |" 
			<< endl;
	
	
	return EXIT_SUCCESS;	
}

/*
FILE OUTPUT

Stop Number | Trip Dist  |  Trip Cost | Total Dist | Total Cost |
-----------------------------------------------------------------
          1 |      20.40 |      73.80 |      20.40 |      73.80 |
          2 |      12.00 |      54.00 |      32.40 |     127.80 |
          3 |      14.21 |      53.69 |      46.61 |     181.49 |
          4 |      45.73 |     208.61 |      92.34 |     390.11 |
         14 |      31.42 |     139.63 |     443.36 |    1928.40 |
         24 |      43.99 |     187.96 |     781.23 |    3371.50 |
         34 |      57.48 |     246.81 |    1259.00 |    5419.25 |
         44 |      52.25 |     229.80 |    1718.25 |    7384.33 |
         54 |      61.52 |     267.45 |    2058.58 |    8835.37 |
         64 |      24.05 |      85.67 |    2479.46 |   10653.23 |
         74 |       3.94 |      20.30 |    2836.93 |   12190.02 |
         84 |      55.98 |     234.44 |    3217.94 |   13825.79 |
-----------------------------------------------------------------
      Total |                              3217.94 |   13825.79 |

*/
