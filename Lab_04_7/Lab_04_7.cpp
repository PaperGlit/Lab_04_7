// Lab_04_7.cpp
// Лазар Владислав
// Лабораторна робота No 4.7
// Обчислення суми ряду Тейлора за допомогою ітераційних циклів та рекурентних співвідношень
// Варіант 11

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
	int n;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		 << setw(10) << "arcth(x)" << " |"
		 << setw(7) << "S" << " |"
		 << setw(5) << "n" << " |"
		 << endl;
	cout << "-------------------------------------------------" << endl;

	x = xp;

	while (x <= xk && abs(x) > 1)
	{
		n = 0;
		a = 1 / x;
		S = a;

		do{
			n++;
			R = (2.0 * n - 1) / (2.0 * n + 1) * (1 / (x * x));
			a *= R;
			S += a;
		}while (abs(a) >= eps);

		cout << "|" << setw(7) << setprecision(2) << x << " |"
					<< setw(10) << setprecision(5) << atanh(1 / x) << " |"
					<< setw(10) << setprecision(5) << S << " |"
					<< setw(5) << n << " |"
					<< endl;
		
		x += dx;
	}
	cout << "-------------------------------------------------" << endl;

	return 0;
}