#include <iostream>
#include <iomanip>

template <typename T>
void	iter(T * array, size_t len, void (*function)(T & element)) {
	for (size_t i = 0; i < len; i++) {
		(*function)(array[i]);
	}
}

template <typename T>
void ft_print_elem(T& element) {
	std::cout << "[" << std::setw(5) << std::right << element << "] ";
}

template <typename T>
void	ft_increment_elem(T & element) {
	element++;
}

template <typename T>
void ft_square_elem(T & element) {
	element *= element;
}