cmake_minimum_required(VERSION 3.15)


project(optimization_algorithms CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ternary Search
add_executable(
	1_ternary_search
	./1-ternary-search/main.cpp
)

# Golden Section Search
add_executable(
	2_golden_section_search
	./2-golden-section-search/main.cpp
)

# Fibonacci Method
add_executable(
	3_fibonacci_method
	./3-fibonacci-method/main.cpp
)

# Newton Method
add_executable(
	4_newton_method
	./4-newton-method/main.cpp
)