#include <iostream>
#include <cmath>
using namespace std;

double ofunc1(double x);
//This represents function f

double dfunc1(double x);
//Represents f'(x)

double ralphNewton(double p, double x, double y);

int main()
{
     double p = 1.00;
     double ans1, ans2;

     cout << p << endl;
     for(int i = 0; i < 4; i++)
     {
        ans1 = ofunc1(p);
        ans2 = dfunc1(p);

        p = ralphNewton(p, ans1, ans2);
        cout << p << endl;
     }

     return 0;
}
double ofunc1(double x)
{
    double function = pow(x,3) - (2*x) - 5; //Can be changed
    return function;
}
double dfunc1(double x)
{
    double function = (pow(x,2)*cos(x))-3*x; //Can be changed
    return function;
}
double ralphNewton(double p, double x, double y)
{
    return (p - (x/y));
}
