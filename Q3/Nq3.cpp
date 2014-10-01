//Nicholash Bedi
//Assignment 4 question 2
#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
using namespace std;

double findx( 	double b, double h, double incriment = 1, double x = 0)
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
	b = 25;
	h = 125;
	
	double xc,vc;
	//WITH CALCULUS
	xc = (1.0/6.0)*(b + h - sqrt(b*b - b*h + h*h));
	vc = (b-2*xc)*(h-2*xc)*xc;
	cout	<< fixed << setprecision(4) <<"volume: " << vc << endl
			<< "x: "<< xc << " with CALCULUS!!!" << endl;
	
	
	//b = 6 h = 6 means x =1
	//b = 12 h = 12 means x =2 
	
	
	///INITIALY MADE FUNCTION
	double x = 0, v = 0, pv = 0;
	if(b > 12 && h > 12)
	{
		do
		{
			x++;
			pv = v;
			v = (b-2*x)*(h-2*x)*x;
		}while(v > pv);
		cout << "int brute force x: " << --x << endl;
	}
	cout << endl;
	
	
	//TRYING ABOVE FUNCTION
	x = 5;
	for (double incriment = 1.0; incriment >= 0.0001; incriment /= 10.0)
	{
		x -= 5*(incriment);
//		cout << x << endl;
		x = findx(b,h,incriment,x);
		cout << x << endl << endl;
	}
	cout << " Funtion method x; " << x << endl;


}
