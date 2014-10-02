// setprecision example
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
using namespace std;
int main () 
{
  double f = 3.14159;
  cout << setw(12);
  cout << setprecision(5) << f << '\n';
  cout << setprecision(9) << f << '\n';
  cout << fixed;
  cout << setprecision(5) << f << '\n';
  cout << setprecision(9) << f << '\n';
  
  return 0;
}
//
//<< "Stop # " << tripNum << endl
//<< "Trip Distance " << distanceTrip << endl
//<< "Trip Cost " << costTrip << endl
//<< "Total Distance " << distanceTotal <<endl
//<< "Total Cost " << costTotal << endl << endl;
