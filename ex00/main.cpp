#include <iostream>
#include "whatever.hpp"

int	main(void)
{
	std::string a("chicken");
	std::string b("hamburger");

	std::cout << "ORIGINAL =========================================" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << std::endl;

	std::cout << "SWAPPED ==========================================" << std::endl;
	swap(a, b);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << std::endl;

	std::cout << "WHICH IS MIN ? ===================================" << std::endl;
	std::cout << "min(3, 5): " << ::min(3, 5) << std::endl;
	std::cout << "min(9, 5): " << ::min(9, 5) << std::endl;
	std::cout << "min(\"chicken\", \"hamburger\"): " << ::min(a, b) << std::endl;
	std::cout << std::endl;

	std::cout << "WHICH IS THE MAX? ================================" << std::endl;
	std::cout << "max(3, 5): " << ::max(3, 5) << std::endl;
	std::cout << "max(9, 5): " << ::max(9, 5) << std::endl;
	std::cout << "max(\"chicken\", \"hamburger\"): " << ::max(a, b) << std::endl;
	std::cout << std::endl;

	return (0);
}
