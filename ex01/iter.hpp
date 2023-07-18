# include <iostream>

template <typename T>
void	iter(T * array, size_t len, void (*function)(T & element)) {
	for (size_t i = 0; i < len; i++) {
		(*function)(array[i]);
	}
}

template <typename T>
void	test_print(T & element) {
	std::cout << "[" << element << "] ";
}

template <typename T>
void	test_increment(T & element) {
	element++;
}