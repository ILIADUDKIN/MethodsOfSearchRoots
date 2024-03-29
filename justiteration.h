#include "Polinom.h"
using namespace std;
pair<double, int> JustItera(Polinom& func, double a, double b)
{
    Polinom Iks ({ monom(1,1) });
    double epsilon = 0.000001;
    double x_0 = a + (b - a) / 2; // выбираем корень
    cout << point(derivation(func + Iks), x_0) << endl; //проверка на колебания
    vector <double> x_k;
    x_k.push_back(x_0);
    double x_1 = point((func + Iks), x_0);
    x_k.push_back(x_1);
    cout << x_0 << "  " << x_1 << "  " << point(func + Iks, x_1);
    int k = 1; 
    while (abs(x_k[k] - x_k[k - 1]) > epsilon)
    {
        cout <<"x_k: "<< x_k[k] << ", x_(k-1): "<<x_k[k-1]<<endl;
        cout << "ABS: " << x_k[k] - x_k[k - 1] << endl;
        x_k.push_back(point(func + Iks, x_k[k]));
        k++;
    }


    return { x_k[k - 1],k };
}