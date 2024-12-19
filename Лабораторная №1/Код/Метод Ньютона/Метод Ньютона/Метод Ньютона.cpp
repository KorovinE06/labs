#include<iostream>
#include<clocale>
using namespace std;

double func(double a)
{
	double f = acos(a) - (pow(1 - (0.3 * (pow(a, 3))), 0.5));
	return f;
}
double f_new(double b)
{
	double s1 = (9 * (pow(b, 2))) / (2 * 3.16227766017 * (pow(10 - 3 * (pow(b, 3)), 0.5)));
	double s2 = (1 / (pow(1 - (pow(b, 2)), 0.5)));
	return  s1 - s2;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	double x, x1;
	double eps = 0.000001;
	int iter = 0;
	x = 0.9;
	x1 = 0;

	while (abs(x - x1) > eps)
	{
		x1 = x;
		x = x1 - func(x1) / f_new(x1);
		iter++;
		cout << "Итераций " << iter << "x = " << x << endl;
	}
	cout << "Корень: " << x << endl;
	cout << "Временных тиков: "<<clock();
	return 0;
}