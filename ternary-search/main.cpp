#include <iostream>
#include <cassert>

template <typename Func>
double TernarySearch(double l, double r, Func& F, double EPS) {
	assert(l <= r);

	while (r - l > EPS) {
		double m1 = l + (r - l) / 3;
		double m2 = r - (r - l) / 3;

		if (F(m1) <= F(m2)) {
			r = m2;
		}
		else {
			l = m1;
		}
	}

	return (l + r) / 2;
}

int main() {
	// Ternary Search (minimization)
	auto Function = [](double x) -> double {
		return x * x + 4 * x - 2;
	};
	double EPS = 1e-12;
	double left_bound = -6;
	double right_bound = 2;

	double result = TernarySearch(left_bound, right_bound, Function, EPS);
	std::cout << "Point of minimum: " << result << std::endl;
	std::cout << "Value at minimum: " << Function(result) << std::endl;
}