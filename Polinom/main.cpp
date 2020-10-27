#include <iostream>
#include <cmath>

class Polinom
{
private:
	int n;
	double a, b, c;
public:

	Polinom(int n, double a, double b, double c) :n(n), a(a), b(b), c(c) { }

	void Output() {
		for (int k = 0; k <= n; k++)
		{
			for (int l = 0; l <= n; l++)
			{
				for (int m = 0; m <= n; m++)
				{
					if ((k + l + m) == n)
					{
						OutputOne(k, l, m);
						if (k != n)
							std::cout << '+' << std::flush;
						else
							std::cout << '=' << std::flush;
						std::cout << std::endl;
					}
				}
			}
		}

		for (int k = 0; k <= n; k++)
		{
			for (int l = 0; l <= n - k; l++)
			{
				for (int m = 0; m <= n - k - l; m++)
				{
					if ((k + l + m) == n)
					{
						std::cout << P(k, l, m) * std::pow(a, k) * std::pow(b, l) * std::pow(c, m) << "*x^" << k << "*y^" << l << "*z^" << m << std::flush;
						if (k != n)
							std::cout << '+' << std::flush;
						std::cout << std::endl;
					}
				}
			}
		}
	}

	void Find() {
		int k, l, m;
		do {
			std::cout << "Enter k: " << std::flush;
			std::cin >> k;
			std::cout << "Enter l: " << std::flush;
			std::cin >> l;
			std::cout << "Enter m: " << std::flush;
			std::cin >> m;
		} while (k + l + m != n);

		OutputOne(k, l, m);
		std::cout << " = " << P(k, l, m) * std::pow(a, k) * std::pow(b, l) * std::pow(c, m) << "*x^" << k << "*y^" << l << "*z^" << m << std::endl;

	}

	int P(int k, int l, int m)
	{
		return (factorial(n) / (factorial(k) * factorial(l) * factorial(m)));
	}

	void OutputOne(int k, int l, int m)
	{
		std::cout << "P(" << k << ", " << l << ", " << m << ")*(((" << a << "*x)^" << k << ")*((" << b << "*y)^" << l << ")*((" << c << "*z)^" << m << "))";
	}

	int factorial(int value) {
		if (value == 0)
			return 1;
		else
			return value * factorial(value - 1);
	}
};

int main() {
	int n;
	double a, b, c;

	std::cout << "Enter n: " << std::flush;
	std::cin >> n;
	std::cout << "Enter a: " << std::flush;
	std::cin >> a;
	std::cout << "Enter b: " << std::flush;
	std::cin >> b;
	std::cout << "Enter c: " << std::flush;
	std::cin >> c;


	Polinom polinom(n, a, b, c);
	polinom.Output();
	polinom.Find();


}