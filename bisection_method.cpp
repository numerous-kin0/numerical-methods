//bisection algorithm with error bound
#include <iostream>
#include <cmath>
using namespace std;

double getYCo(double x);
//Postcondition: Gets the image of an x-coordinate
double bisect(double p1, double p2);
//Bisection algorithm

int main()
{
    double a = 0.00, b = 1.00;
    double y1, y2, p;

    double tolerance = pow(10,-4);
    double error, control = 1;
    int i = 1;
   
    while(control != 0)
    {
        y1 = getYCo(a); //-1
        y2 = getYCo(b); //0.46

        p = bisect(a,b);

        if((y1*getYCo(p)) < 0) //getYCo(p) = -0.170476
                b = p;
        else if((y2*getYCo(p)) < 0)
                a = p;

        cout << "p" << "i: " << p << endl; 

        error = p - bisect(a,b);
        i++;
 
        if(error < tolerance)
            control = 0;
    };
    
}
double getYCo(double x)
{
    double answer;
    answer = sqrt(x) - cos(x);
    return answer;
}
//this is gonna be the new value of a or b
double bisect(double p1, double p2)
{
    double answer;
    answer = (p1+p2)/2.00;
    return answer;
}
