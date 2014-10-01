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
	if (v == 0)
		return 0;
	else if(v>0)
		return floor(log10(fabs(v)))+1;
	else
		return -(floor(log10(fabs(v)))+1);
		
}

double findx(double b, double h, double incriment = 1, double x = 0)
{
	double v=(b-2*x)*(h-2*x)*x, pv;
	cout << "x initial " << x << endl;
	cout << "incriment " << incriment << endl;
	cout << "volume i " << v << endl;
	
	do
	{
		x += incriment;
		pv = v;
		v = (b-2*x)*(h-2*x)*x;
	} while(v > pv);
	x -= incriment;
	cout << "volume f " << (b-2*x)*(h-2*x)*x << endl;
	return x;
}

int main()
{
	double b,h;
//	cout << "Enter base then height" << endl;
//	cin >> b >> h;
	b = 600;
	h = 600;
	
	
	//b = 6 h = 6 means x =1
	//b = 12 h = 12 means x =2 
	
	//TRYING ABOVE FUNCTION
	double minInput = 0;
	if(b < h)
		minInput = b;
	else
		minInput = h;
	cout <<"mininput is: " << minInput << endl;
	double incriment = pow(10,(getlength(minInput/6.0)-2));
	
	
	double x = incriment * 5;
	for (; incriment >= 1e-8; incriment /= 10.0)
	{
		x -= 5*(incriment);
		x = findx(b,h,incriment,x);
		cout << x << endl << endl;
	}
	cout 	<< fixed << setprecision(8)
			<< "Bruted x; \t\t" << x << endl;
	
		
	
	double xc,vc;
	//WITH CALCULUS
	xc = (1.0/6.0)*(b + h - sqrt(b*b - b*h + h*h));
	vc = (b-2*xc)*(h-2*xc)*xc;
	cout	<< "With CALCULUS!!! x:\t" << xc << endl
	
			<< "\nVolume with calc: " << vc << endl
			<< "Volume with brute: " << (b-2*x)*(h-2*x)*x;
}

