#include <iostream>
#include <cmath>
using namespace std;

double eqFalsi(double p0, double p1);

double eq1(double x);

int main()
{
    double p0 = 0.00, p1 = 3.00, root, yco;
    int iters = 16;

    for(int i = 0; i < iters; i++)
    {
        root = eqFalsi(p0,p1);
        yco = eq1(root);
        if(eq1(p0)*eq1(root) < 0)
            p1 = root;
        else if(eq1(p1)*eq1(root) < 0)
            p0 = root;

        cout << p0 << " " << p1 << endl;
    }

    return 0;
}
double eqFalsi(double p0, double p1)
{
     double answer;
     answer = p1 - ((eq1(p1)*(p1 - p0))/(eq1(p1) - eq1(p0)));
     return answer;
}
double eq1(double x) //returns the y coordinate of the x coordinate
{
    return (pow(x,3) - (2*x) - 5);
}
