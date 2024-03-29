#include "Polinom.h"
pair<double, int> NewtonMethod_Modification(Polinom& func, double a, double b)
{
    double epsilon = 0.000001;
    double x_0 = a + (b - a) / 2; // выбираем корень 
    vector <double> x_k;
    x_k.push_back(x_0);
    double x_1 = x_0 - (point(func, x_0)) / (point(derivation(func), x_0));
    x_k.push_back(x_1);
    int k = 1;
    while (abs(x_k[k] - x_k[k - 1]) > epsilon)
    {
        x_k.push_back(x_k[k] - (point(func, x_k[k])) / (point(derivation(func), x_0)));
        k++;
    }

    return { x_k[k - 1],k };
}