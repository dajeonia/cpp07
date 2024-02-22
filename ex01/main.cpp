#include <iostream>
#include "iter.hpp"

int	ft_putchar(int a)
{
	std::cout << a << std::endl;
	return (a);
}

int	main(void)
{
	int	test1[5] = {1, 2, 3, 4, 5};
	const char* test2 = "0123456789";

	std::cout << "==================================================" << std::endl;
	iter(test1, 5, ft_putchar);

	std::cout << "==================================================" << std::endl;
	iter(test2, 10, ft_putchar);
	return (0);
}
