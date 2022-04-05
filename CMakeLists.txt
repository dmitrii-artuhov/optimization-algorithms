cmake_minimum_required(VERSION 3.15)


project(optimization_algorithms CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ternary Search
add_executable(
	ternary_search
	./1-ternary-search/main.cpp
)

# Golden Section Search
add_executable(
	golden_section_search
	./2-golden-section-search/main.cpp
)