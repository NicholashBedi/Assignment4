//Nicholash Bedi
//Assignment 4 question 2
#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
using namespace std;

double findx(double b, double h, double incriment, double x = 0)
{
	double volume=(b-2*x)*(h-2*x)*x, PreviousVolume;
	
	do
	{
		x += incriment;
		PreviousVolume = volume;
		volume = (b-2*x)*(h-2*x)*x;
	} while(volume > PreviousVolume);
	x -= incriment;
//	cout << "volume f " << (b-2*x)*(h-2*x)*x << endl;
	return x;
}

int getLength(double number)
{
	if (number > 0)
		return floor(log10(fabs(number))) +1;
	else if (number < 0)
		return -(floor(log10(fabs(number))) +1);
	else
		return 0;
			
}

int main()
{
	double TotalMaxVolume = 0;
	for (int i = 0; i < 5; i++)
	{
		double b,h;
		do
		{
		cout << "Enter base then height" << endl;
		cin >> b >> h;
		if (b <= 0 || h <= 0)
			cout << "ERROR! Repeat input.\n" << endl;
		}while (b <= 0 || h <= 0);
		
		//WITH CALCULUS
		double xc,vc;
		xc = (1.0/6.0)*(b + h - sqrt(b*b - b*h + h*h));
		vc = (b-2*xc)*(h-2*xc)*xc;
		cout	<< fixed << setprecision(7) 
				<< "Cut size: "<< xc << " with calculus!" << endl;
		
		double incriment;
		if( b < h)
			incriment = pow(10, getLength(b) - 2);
		else
			incriment = pow(10, getLength(h) - 2);
		
		double x = 5 * incriment;
		for (; incriment >= 1e-7; incriment /= 10.0)
		{
			x -= 5*(incriment);
			x = findx(b,h,incriment,x);
		}
		double volume = (b-2*x)*(h-2*x)*x;
		cout << "Cut size: " << x << " with brute force!" << endl;
		cout << "Max Volume: " << volume << " with brute force" <<endl<<endl;
		
		if (volume > TotalMaxVolume)
			TotalMaxVolume = volume;
	}
	
	cout << "The biggest box has a size of " << TotalMaxVolume;

}

/*

Enter base then height
-1 1
ERROR! Repeat input.

Enter base then height
1 -1
ERROR! Repeat input.

Enter base then height
0 0
ERROR! Repeat input.

Enter base then height
25 125
Cut size: 5.9059346 with calculus!
Cut size: 5.9059346 with brute force!
Max Volume: 8816.0240706 with brute force

Enter base then height
0.12 0.1
Cut size: 0.0181075 with calculus!
Cut size: 0.0181075 with brute force!
Max Volume: 0.0000968 with brute force

Enter base then height
7895
358
Cut size: 88.4622836 with calculus!
Cut size: 88.4622826 with brute force!
Max Volume: 123630804.9698870 with brute force

Enter base then height
12 12
Cut size: 2.0000000 with calculus!
Cut size: 2.0000000 with brute force!
Max Volume: 128.0000000 with brute force

Enter base then height
36 36
Cut size: 6.0000000 with calculus!
Cut size: 6.0000000 with brute force!
Max Volume: 3456.0000000 with brute force

The biggest box has a size of 123630804.9698870
*/ 
