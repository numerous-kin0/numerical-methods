#include <iostream>
#include <iomanip>
#include <cmath>

double fy(double x, double y, double z) {
    return (4*x);
}

double f(double x, double y, double z) {
    return (((-1)*pow(x, 2)*fy(x, y, z)) + (4*x*y) + (2*pow(x, 3)) + (6*pow(x, 2)) - 2);
}

double fz(double x, double y, double z) {
    return (pow(x, 2));
}

int main() {
    double a = 0, b = 1, alpha = 0, beta = 2;
    double tol = 1e-4;
    int n = 5, m = 5;

    double tk = (beta - alpha) / (b - a);
    std::cout << "Nonlinear shooting method\n\n";
    std::cout << "x(i)\t\tw(i)\n";

    double w1[n + 1] = {0};
    double w2[n + 1] = {0};
    double h = (b - a) / n;
    int k = 1;

    while (k <= m) {
        w1[0] = alpha;
        w2[0] = tk;
        double u1 = 0, u2 = 1;

        for (int i = 0; i < n; ++i) {
            double x = a + i * h;
            double t = x + 0.5 * h;
            double k11 = h * w2[i];
            double k12 = h * f(x, w1[i], w2[i]);
            double k21 = h * (w2[i] + 0.5 * k12);
            double k22 = h * f(t, w1[i] + 0.5 * k11, w2[i] + 0.5 * k12);
            double k31 = h * (w2[i] + 0.5 * k22);
            double k32 = h * f(t, w1[i] + 0.5 * k21, w2[i] + 0.5 * k22);
            double k41 = h * (w2[i] + k32);
            double k42 = h * f(x + h, w1[i] + k31, w2[i] + k32);
            w1[i + 1] = w1[i] + (k11 + 2 * (k21 + k31) + k41) / 6;
            w2[i + 1] = w2[i] + (k12 + 2 * (k22 + k32) + k42) / 6;

            k11 = h * u2;
            k12 = h * (fy(x, w1[i], w2[i]) * u1 + fz(x, w1[i], w2[i]) * u2);
            k21 = h * (u2 + 0.5 * k12);
            k22 = h * (fy(t, w1[i], w2[i]) * (u1 + 0.5 * k11) + fz(t, w1[i], w2[i]) * (u2 + 0.5 * k21));
            k31 = h * (u2 + 0.5 * k22);
            k32 = h * (fy(t, w1[i], w2[i]) * (u1 + 0.5 * k21) + fz(t, w1[i], w2[i]) * (u2 + 0.5 * k22));
            k41 = h * (u2 + k32);
            k42 = h * (fy(x + h, w1[i], w2[i]) * (u1 + k31) + fz(x + h, w1[i], w2[i]) * (u2 + k32));
            u1 = u1 + (k11 + 2 * (k21 + k31) + k41) / 6;
            u2 = u2 + (k12 + 2 * (k22 + k32) + k42) / 6;
        }

        if (fabs(w1[n] - beta) < tol) {
            std::cout << a << "\t\t" << alpha << std::endl;
            for (int i = 1; i <= n; ++i) {
                double x = a + i * h;
                std::cout << x << "\t\t" << w1[i] << std::endl;
            }
            std::cout << "\nConvergence in " << k << " iterations t= " << tk << "\n\n";
            break;
        } else {
            tk = tk - (w1[n] - beta) / u1;
            ++k;
        }
    }

    return 0;
}
