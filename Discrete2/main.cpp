#include <cmath>
#include <iostream>


class Binom {
private:
	int n;
	double a, b;

public:
	Binom(int n, double a, double b):n(n), a(a), b(b)  { }

	void Output() {
		std::cout << '(' << a << "*x + " << b << "*y)^" << n << '=' << std::endl;
		for (int i = 0; i <= n; i++) {
			OutputOne(n - i, i);
			if(i != n)
				std::cout << " + " << std::endl;
		}
		std::cout << " = " << std::endl;
		for (int i = 0; i <= n; i++) {
			std::cout << C(n, i) * std::pow(a, n - i) * std::pow(b, i) << "*x^" << n - i << "*y^" << i << std::flush;
			if (i != n)
				std::cout << " + " << std::endl;
		}
		std::cout << std::endl;
	}

	void Find() {
		int i, j;

		do {
			std::cout << "Enter i: " << std::flush;
			std::cin >> i;
			std::cout << "Enter j: " << std::flush;
			std::cin >> j;

		} while (i + j != n);

		OutputOne(i, j);
		std::cout << " = " << C(n, i) * std::pow(a, i) * std::pow(b, n - i) << "*x^" << i << "*y^" << n - i << std::endl;
	}

private:
	void OutputOne(int i, int j) {
		std::cout << 'C' << n << '/'<< j << "*(" << a << "*x)^" << i << "*(" << b << "*y)^" << j << std::flush;
	}

	int C(int n, int m) {
		return factorial(n) / (factorial(m) * factorial(n - m));
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
	double a, b;
	std::cout << "Enter n: " << std::flush;
	std::cin >> n;
	std::cout << "Enter a: " << std::flush;
	std::cin >> a;
	std::cout << "Enter b: " << std::flush;
	std::cin >> b;

	Binom binom(n, a, b);
	binom.Output();
	binom.Find();
}