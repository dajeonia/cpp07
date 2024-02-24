#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <stdexcept>

typedef unsigned long size_t;

template<typename T>
class Array {
	T* arr;
	size_t sz;
public:
	Array() : arr(new T[0]), sz(0) { }
	Array(unsigned int n) : arr(new T[n]), sz(n) { }
	Array(const Array& a) : arr(new T[a.sz]), sz(a.sz)
	{
		for (size_t i=0; i!=sz; ++i)
			arr[i] = a.arr[i];
	}
	Array& operator=(const Array& a)
	{
		T* tmp = new T[a.sz];
		delete[] arr;
		arr = tmp;
		sz = a.sz;
		for (size_t i=0; i!=sz; ++i)
			arr[i] = a.arr[i];
		return (*this);
	}
	~Array() { delete[] arr; };
	T& operator[](size_t i) { 
		if (i >= sz)
			throw (std::out_of_range("Array"));
		return (arr[i]);
	}
	const T& operator[](size_t i) const { 
		if (i >= sz)
			throw (std::out_of_range("Array"));
		return (arr[i]);
	}
	size_t size() { return (sz); }
};

#endif
