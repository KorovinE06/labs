#include<iostream>
#include<clocale>
using namespace std;

double func(double x1)
{
	return ((acos(x1) - (pow(1 - (0.3 * (pow(x1, 3))), 0.5))) + x1);
}
int main()
{
	setlocale(LC_ALL, "Rus");
	float x, x1;
	double eps = 0.000001;
	int iter = 0;
	x = 1;
	x1 = 0;

	while (abs(x - x1) > eps)
	{
		x1 = x;
		x = func(x1);
		iter++;
		cout << "Итерация " << iter << "x = " << x << endl;
	}
	cout << "Корень: " << x << endl;
	cout << "Временных тиков: " << clock();
	return 0;
}