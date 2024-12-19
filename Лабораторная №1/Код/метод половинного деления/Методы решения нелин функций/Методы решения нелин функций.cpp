#include<iostream>
#include<clocale>
using namespace std;

double func(double x)
{
	return acos(x) - (pow(1 - (0.3 * (pow(x, 3))), 0.5));
}
int main()
{
	setlocale(LC_ALL, "Rus");
	float a, b, c;
	float fA, fB, fC;
	double eps = 0.000001;
	int iter = 0;

	a = 0;
	b = 1;

	while (b - a > eps)
	{
		c = (a + b) / 2;
		fA = func(a);
		fB = func(b);
		fC = func(c);

		if (fA * fC < 0)
		{
			b = c; 
		}
		else 
			if (fC * fB < 0) 
			{ 
				a = c;
			}
			else 
			{ 
				cout << "Error" << endl; 
			}
		iter++;
		cout << "Итераций " << iter << "x = " << c << endl;
		
	}
	cout << "Корень: " << c << endl;
	cout << "Временных тиков: " << clock();
	return 0;
}