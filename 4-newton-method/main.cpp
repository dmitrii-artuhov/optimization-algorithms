#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>


template <typename Func, typename Dir>
double NewtonMethod(double l, double r, Func& F, Dir& D, double EPS) {
	assert(l <= r);
	
	double x_km = l; // x_{k - 1}
	double x_k = r; // x_{k}

	auto bound = [&](double& x, double& bl, double& br) {
		while (!(x >= l && x <= r)) {
			x = (bl + br) / 2;
		}
	};

	auto in_bounds = [&](double x) {
		return (
			x >= l && x <= r
		);
	};

	do {
		assert(x_km >= l && x_km <= r);
		assert(x_k >= l && x_k <= r);

		double dir_k = D(x_k);
		double dir_km = D(x_km);

		double x = (dir_k * x_km - dir_km * x_k) / (dir_k - dir_km);

		x_km = x_k;
		x_k = x;

		// bound Newton method to the [l, r] segment
		// bound the points
		if (!in_bounds(x_km)) bound(x_km, x_km, x_k);
		if (!in_bounds(x_k)) bound(x_k, x_km, x_k);
	}
	while (std::abs(x_k - x_km) > EPS);

	return (x_k + x_km) / 2;
}

int main() {
	// Golden Section Search (minimization)
	auto Function = [](double x) -> double {
		return x * x + 4 * x - 2;
	};
	auto Derivative = [](double x) -> double {
		return 2 * x + 4;
	};

	double EPS = 1e-12;
	double left_bound = -2;
	double right_bound = 12;

	double result = NewtonMethod(left_bound, right_bound, Function, Derivative, EPS);
	std::cout << "Point of minimum: " << result << std::endl;
	std::cout << "Value at minimum: " << Function(result) << std::endl;
}