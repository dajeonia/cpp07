#ifndef ITER_HPP
# define ITER_HPP

template<typename T, typename T2>
void	iter(T address[], unsigned int length, T2 function)
{
	for (size_t i=0; i!=length; ++i)
		function(address[i]);
}

#endif
