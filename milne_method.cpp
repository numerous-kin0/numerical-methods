//Created: 07-01-2024
//Milner method code for question 1.a
#include <iostream>
#include <cmath>
#include <iomanip>

void compute_milne_method_approximations(double xVal, double t1, double t2, double t3, double w0, double w1, double w2, double w3, double h);

double f(double t_i, double w_i);

int main()
{
    double t_1 = 0.2, t_2 = 0.4, t_3 = 0.6;
    double w_0 = 1, w_1 = 1.0627, w_2 = 1.246, w_3 = 1.5169;
    double x_value = 1.0;
    double h = 0.2;

    compute_milne_method_approximations(x_value, t_1, t_2, t_3, w_0, w_1, w_2, w_3, h);

    return 0;
}

void compute_milne_method_approximations(double xVal, double t1, double t2, double t3, double w0, double w1, double w2, double w3, double h)
{
    double next_w_value, next_t_value;
    int numOfIterations = 0;

    std::cout << "i" << std::setw(12) << "t_i" << std::setw(10) << "w_i" << std::endl;
    while (t3 <= xVal)
    {
        std::cout << numOfIterations << std::setw(12) << std::setprecision(5) << t3 << std::setw(10) << w3 << std::endl;
        next_w_value = w0 + (4*h/3)*(2*f(t3, w3) - f(t2, w2) + 2*f(t1, w1));

        next_t_value = t3 + h;
        t1 = t2;
        t2 = t3;
        t3 = next_t_value;

        w0 = w1;
        w1 = w2;
        w2 = w3;
        w3 = next_w_value;

        numOfIterations++;
    }

}

double f(double t_i, double w_i)
{
    return (w_i*sin(M_PI*t_i));
}
