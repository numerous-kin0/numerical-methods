//Experiment program
//Created: 14-03-2024
//Author: Mabo Giqwa
//Description: Program that uses the modified Euler method to approximate
//the solution to an ODE with an initial value.
#include <iostream>
#include <cmath>
#include <iomanip>

double get_output_of_d_function(double t, double y);
//Postcondition: Returns the image from the input t_i and w_i
//where i >= 0 in the differential equation/

double get_output_of_solution_curve(double t);
//Postcondition: Returns the image from plugging in t_i
//where i >= 0 in the solution curve.

double calculate_error(double w_val, double actual_val);

int main()
{
    double valOfLowerBound = -1.0; //[a, b] represents a
    double currentValOfT = 0.0; //t_0
    double currentValOfW = 2.0; //w_0
    double stepSize = 0.2; //h value
    std::string iterations[6] = {"First iteration","Second iteration","Third iteration", "Fourth iteration",
                                "Fifth iteration", "Sixth iteration"};

    int iter = 0;
    do
    {
        double nextValOfT, nextValOfW, actualValue;
        double tempYValue1, tempYValue2;
        double tempYValue3, absoluteError;

        tempYValue1 = get_output_of_d_function(currentValOfT, currentValOfW);
        //tempYValue1 computes f(t_i,w_i) where i >= 0 for each iteration
        iter = iter + 1;
        nextValOfT = valOfLowerBound + (stepSize)*(iter); //calculates t_(i+1)
        iter = iter - 1;

        tempYValue2 = currentValOfW + (stepSize*tempYValue1);
        //tempYValue2 computes w_0 + 0.25*f(t_0, w_0))
        tempYValue3 = get_output_of_d_function(nextValOfT, tempYValue2);
        //tempYValue3 computes f(t_1, w_0 + h*(f(t_0, w_0)))
        nextValOfW = currentValOfW + (stepSize*tempYValue3);
        //Computes w_(i+1)

        currentValOfT = nextValOfT;
        currentValOfW = nextValOfW;

        actualValue = get_output_of_solution_curve(currentValOfT);
        absoluteError = calculate_error(currentValOfW, actualValue);

        std::setprecision(6);
        std::cout << iterations[iter] << " where i is " << iter+1 << ":" << std::endl;
        std::cout << "Value of t_i: " << currentValOfT << std::endl;
        std::cout << "Value of w_i: " << currentValOfW << std::endl;
        std::cout << "Magnitude of error is: " << absoluteError << std::endl;
        std::cout << std::endl;


        iter = iter + 1;
    } while (iter < 5);
    
    return 0;
}

double get_output_of_d_function(double t, double y)
{
    return (-3*pow(t,2)*pow(y,2));
    //This function returned can be replace with some other 
    //ordinary differential equations.
}

double get_output_of_solution_curve(double t)
{
    return (2.00/double(2*pow(t, 3) + 1));
    //Same case here, the solution curve the DE returned in get_output_of_d_function
    //can be replaced. 
}

double calculate_error(double w_val, double actual_val)
{
    return (fabs(actual_val - w_val));
}
