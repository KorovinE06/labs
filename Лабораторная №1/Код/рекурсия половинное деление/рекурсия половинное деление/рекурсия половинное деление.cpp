#include <iostream>
#include <ctime>
#include <clocale>
#include <cmath>
using namespace std;
double eps = 1e-6;
double f(double x)
{
    return acos(x) - (pow(1 - (0.3 * (pow(x, 3))), 0.5));
}
double del(double a, double b, double eps)
{
    double x = (a + b) / 2;
    if ((abs(f(a) - f(b)) <= eps))
    {
        if (abs(f(x)) <= eps)
        {
            return (a + b) / 2;
        }
    }
    if (f(a) * f(x) <= 0.0) 
    {
        del(a, x, eps);
    }
    else {
        del(x, b, eps);
    }
}
int main()
{
    setlocale(LC_ALL, "Ru");
    int s = clock();
    double a = 0.0;
    double b = 0.9;

    cout << del(a, b, eps);
}