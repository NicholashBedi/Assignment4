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

int main()
{
	cout << convDeg(60,30) << endl;
	
	return EXIT_SUCCESS;
}
