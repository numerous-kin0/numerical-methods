#include <iostream>
#include <iomanip>
#include <cmath>

void compute_four_step_adams_moulton(double w0, double w1, double w2, double w3, double t0,
                                     double t1, double t2, double t3, double h, double xVal);

double f(double t_i, double w_i);

int main()
{
    double t_0 = 0, t_1 = 0.2, t_2 = 0.4;
    double t_3 = 0.6, w_0 = 1, w_1 = 1.0627;
    double w_2 = 1.246, w_3 = 1.5169;
    double h = 0.2, xVal = 1.0;

    compute_four_step_adams_moulton(w_0, w_1, w_2, w_3, t_0, t_1, t_2, t_3, h, xVal);

    return 0;
}
void compute_four_step_adams_moulton(double w0, double w1, double w2, double w3, double t0,
                                     double t1, double t2, double t3, double h, double xVal)
{
    double nextWValue, nextTValue;
    double numOfIterations = 1;

    std::cout << "i" << std::setw(12) << "t_i" << std::setw(10) << "w_i" << std::endl;
    while (t3 < (xVal + 0.05))
    {
        std::cout << numOfIterations << std::setw(12) << std::setprecision(5) << t3 << std::setw(10) << w3 << std::endl;
        nextTValue = t3 + h;
        nextWValue = (720.00/(720.00 - (251*h*sin(M_PI*nextTValue)))*(w3 + (h/720.00)*(646*f(t3, w3) - 264*f(t2, w2) + 106*f(t1, w1) - 19*f(t0, w0))));

        w0 = w1;
        w1 = w2;
        w2 = w3;
        w3 = nextWValue;

        t0 = t1;
        t1 = t2;
        t2 = t3;
        t3 = nextTValue;
    }
}

double f(double t_i, double w_i)
{
    return (w_i*sin(M_PI*t_i));
}
