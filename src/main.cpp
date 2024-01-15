#include <iostream>
#include <iomanip>

int main() {
	float f = 0.7f;

	std::cout << std::fixed << std::setprecision(8) << f;
}