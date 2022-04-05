#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>

template <typename Func>
double GoldenSectionSearch(double l, double r, Func& F, double EPS) {
	assert(l <= r);
	double phi = (3 + sqrt(5)) / 2;

	// calculate only 1 value instead of 2.
	bool left_value_saved = true;
	double saved_value = F(l + (r - l) / phi);

	auto calc_value = [&](bool is_left, double x) -> double {
		if (is_left == left_value_saved) {
			return saved_value;
		}

		return F(x);
	};

	// implementation 
	while (r - l > EPS) {
		double m1 = l + (r - l) / phi;
		double m2 = r - (r - l) / phi;

		double F1 = calc_value(true, m1); 
		double F2 = calc_value(false, m2); 
		
		if (F1 <= F2) {
			r = m2;
			left_value_saved = false;
			saved_value = F1;
		}
		else {
			l = m1;
			left_value_saved = true;
			saved_value = F2;
		}
	}

	return (l + r) / 2;
}

int main() {
	// Golden Section Search (minimization)
	auto Function = [](double x) -> double {
		return std::sin(x) - 10 / x;
	};
	double EPS = 1e-12;
	double left_bound = 8;
	double right_bound = 12;

	double result = GoldenSectionSearch(left_bound, right_bound, Function, EPS);
	std::cout << "Point of minimum: " << result << std::endl;
	std::cout << "Value at minimum: " << Function(result) << std::endl;
}