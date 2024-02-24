#include "Array.hpp"
#include <iostream>

void	leaks(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	atexit(leaks);
	/*
	std::string test("hi");
	std::cout << test.at(5) << std::endl;
	*/
	int sz(5);
	std::cout << "\033[33m" << "= ARRAY TESTS ====================================" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "= default constructor ============================" << "\033[0m" << std::endl;
	Array<int> empty;
	std::cout << "empty.size(): " << empty.size() << std::endl;

	std::cout << "\033[32m" << "= unsigned int n constructor =====================" << "\033[0m" << std::endl;
	Array<int> arr1(sz);
	std::cout << "arr1.size(): " << arr1.size() << std::endl;
	for (int i=0; i!=sz; ++i) // T& operator[](size_t); // 쓰기(입력)
		arr1[i] = i;
	for (int i=0; i!=sz; ++i) // T& operator[](size_t); // 읽기(출력)
		std::cout << "arr1[" << i << "]: " << arr1[i] << std::endl;

	std::cout << "\033[32m" << "= copy construcctor ==============================" << "\033[0m" << std::endl;
	Array<int> arr2(arr1);
	std::cout << "- arr2: copied well? -----------------------------" << std::endl;
	std::cout << "arr2.size(): " << arr2.size() << std::endl;
	for (int i=0; i!=sz; ++i)
		std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
	std::cout << "- arr1: value change (multiply 2 to each value) --" << std::endl;
	for (int i=0; i!=sz; ++i)
		std::cout << "arr1[" << i << "] *= 2: " << (arr1[i] *= 2) << std::endl;
	std::cout << "- arr2: is independent to arr1? ------------------" << std::endl;
	for (int i=0; i!=sz; ++i)
		std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;

	std::cout << "\033[32m" << "= copy assignment operator =======================" << "\033[0m" << std::endl;
	Array<int> arr3(7);
	std::cout << "arr3.size(): " << arr3.size() << std::endl;
	std::cout << "- arr3 = arr1; -----------------------------------" << std::endl;
	arr3 = arr1;
	std::cout << "- arr3: copied well? -----------------------------" << std::endl;
	std::cout << "arr3.size(): " << arr3.size() << std::endl;
	for (int i=0; i!=sz; ++i)
		std::cout << "arr3[" << i << "]: " << arr3[i] << std::endl;
	std::cout << "- arr1: value change (multiply 2 to each value) --" << std::endl;
	for (int i=0; i!=sz; ++i)
		std::cout << "arr3[" << i << "]: " << (arr1[i] *= 2) << std::endl;
	std::cout << "- arr3: is independent to arr1? ------------------" << std::endl;
	for (int i=0; i!=sz; ++i)
		std::cout << "arr3[" << i << "]: " << arr3[i] << std::endl;

	std::cout << "\033[32m" << "= arr3[5] out of range error =====================" << "\033[0m" << std::endl;
	try {
		std::cout << arr3[sz] << std::endl;
		std::cout << "OK: not error" << std::endl;
	} // std::out_of_range
	catch (std::exception& e) {
		std::cout << "Error: std::out_of_range(" << e.what() << ")" << std::endl;
	} 

	std::cout << "\033[32m" << "= const test =====================================" << "\033[0m" << std::endl;
	std::cout << "- const Array<T>& rarr = arr1; -------------------" << std::endl;
	const Array<int>& rarr(arr1);
	/* 
	std::cout << "- const operator[] test --------------------------" << std::endl;
	for (int i=0; i!=sz; ++i) // const T& operator[](size_t) const; // Error: 읽기 전용(const)
		(*parr)[i] += 1;
	*/
	for (int i=0; i!=sz; ++i) // const T& operator[](size_t) const; // OK: 읽기 전용
		std::cout << "rarr[" << i << "]: " << rarr[i] << std::endl;

	std::cout << "\033[32m" << "= leaks test =====================================" << "\033[0m" << std::endl;
	return (0);
}
