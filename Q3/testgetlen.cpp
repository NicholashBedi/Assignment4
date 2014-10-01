//Nicholash Bedi
//Assignment 4 question 3 testing
#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
using namespace std;

int getlength(double v)
{
	if(v ==0)
		return 0;
	else
		return floor(log10(v))+1;
		
}
int main()
{
	cout << getlength(-65) << endl;
	return EXIT_SUCCESS;
}
//MUST HAVE IF STATEMENT FOR MIN
