#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double equation3(double x);

double equation4(double x);
//Random equations, can be changed to approximate different
//roots 

int main()
{
    double point1 = -6.7636; //interval
    double point2 = -2.1479;
    int iterations = 50;
    double x1, x2;
    double x = 11;

    cout.setf(ios::fixed);
    setprecision(6);

    string array[9] = {"2nd","3rd","4th","5th","6th","7th","8th","9th"};
    
    cout << setw(18) << "x1" << setw(13) << "x2" << endl;
    cout << "1st iteration: " << point2 << "    " << point1 << endl;
    for(int i = 0; i < iterations; i++)
    {
        x1 = equation3(point1);
        x2 = equation4(point2);
        point1 = x2;
        point2 = x1;
        cout << x1 << setw(14) << x2 << endl;
    }
    
    return 0;
}

double equation3(double x)
{
    double equation = (0.5 - (sqrt(1 - 4*x)/2.00));
    double answer1 = equation;

    return answer1;
}
double equation4(double x)
{
    double equation = 1.00/(x + 2);
    double answer1 = equation;

    return answer1;
}
