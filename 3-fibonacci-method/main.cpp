#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>

template <typename Func>
double Fibonacci(double l, double r, Func& F, double EPS) {
	assert(l <= r);
	// calculate Fibonacci numbers
	std::vector <uint64_t> Fibs = {1, 1};
	uint64_t threshold = (r - l) / EPS; 
	while (Fibs.back() < threshold) {
		Fibs.push_back(Fibs[Fibs.size() - 1] + Fibs[Fibs.size() - 2]);
	}
	uint64_t N = Fibs.size();

	double p = 1 - (Fibs[N - 2] * 1.0) / (Fibs[N - 1] * 1.0);
	int k = 0;

	// calculate only 1 value instead of 2.
	bool left_value_saved = true;
	double saved_value = F(l + (r - l) * p);

	auto calc_value = [&](bool is_left, double x) -> double {
		if (is_left == left_value_saved) {
			return saved_value;
		}
		return F(x);
	};

	// implementation
	while (k < N) {
		k++;

		double m1 = l + (r - l) * p;
		double m2 = r - (r - l) * p;

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

		p = 1 - (Fibs[N - k - 2] * 1.0) / (Fibs[N - k - 1] * 1.0);
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

	double result = Fibonacci(left_bound, right_bound, Function, EPS);
	std::cout << "Point of minimum: " << result << std::endl;
	std::cout << "Value at minimum: " << Function(result) << std::endl;
}