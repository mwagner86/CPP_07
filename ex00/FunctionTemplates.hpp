//
// Created by max on 7/16/23.
//

#ifndef EX00_FUNCTIONTEMPLATES_HPP
#define EX00_FUNCTIONTEMPLATES_HPP

template < typename T >
void	swap(T & x, T & y) {
	T tmp = x;
	x = y;
	y = tmp;
}

template < typename T>
T const &	min(T const & x, T const & y) {
	return (x < y ? x : y);
}

template < typename T>
T const &	max(T const & x, T const & y) {
	return (x > y ? x : y);
}

#endif //EX00_FUNCTIONTEMPLATES_HPP
