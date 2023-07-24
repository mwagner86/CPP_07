//
// Created by Maximilian Wagner on 24.07.23.
//

#ifndef EX02_ARRAY_HPP
#define EX02_ARRAY_HPP

#ifndef VERBOSE
# define VERBOSE 0
#endif

#include <iostream>
#include <stdexcept>
#include "colors.hpp"

template <typename T>

class Array {

public:

	Array(void);
	Array(unsigned int size);
	Array(Array const & src);
	~Array(void);

	Array & operator=(Array<T> const & src);
	T & operator[](unsigned int index);
	const T & operator[](unsigned int index) const;

	unsigned int	size(void);

private:

	T*			 	_array;
	unsigned int	_size;
};

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {
	if (VERBOSE)
		std::cout << COLOR_GREEN << "[Array] Default Constructor called." << std::endl << COLOR_DEFAULT;
}

template <typename T>
Array<T>::Array(unsigned int size) : _array(NULL), _size(size) {
	if (VERBOSE)
		std::cout << COLOR_GREEN << "[Array] Parametric Constructor called." << std::endl << COLOR_DEFAULT;
	_array = new (std::nothrow) T[size]; // Memory allocation using new (nothrow)
	if (!_array)
		throw std::bad_alloc(); // Exception handling if memory allocation fails
	for (unsigned int i = 0; i < size; i++)
		_array[i] = T(); // Default-initialize each element to the default value of type T
}

template <typename T>
Array<T>::Array(const Array<T> & src) : _array(NULL), _size(0) {
	if (VERBOSE)
		std::cout << COLOR_GREEN << "[Array] Copy Constructor called." << std::endl << COLOR_DEFAULT;
	*this = src;
}

template <typename T>
Array<T>::~Array() {
	if (VERBOSE)
		std::cout << COLOR_RED << "[Array] Destructor called." << std::endl << COLOR_DEFAULT;
	delete[] _array;
	_array = NULL;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> & src) {
	if (VERBOSE)
		std::cout << COLOR_YELLOW << "[Array] Assignment Operator called." << std::endl << COLOR_DEFAULT;
	if (this == & src)
		return *this;
	// Create a temporary array to ensure exception safety
	T* tempArray = new (std::nothrow) T[src._size];
	if (!tempArray)
		throw std::bad_alloc(); // Exception handling if memory allocation fails

	for (unsigned int i = 0; i < src._size; i++)
		tempArray[i] = src._array[i]; // Deep copy the elements from source array

	delete[] _array; // Deallocate the existing array
	_array = tempArray; // Update the pointer to the new array
	_size = src._size; // Update the size

	return *this;
}

//  When accessing an element with the [] operator, if its index is out of bounds, a
//	std::exception is thrown.
template <typename T>
T & Array<T>::operator[](unsigned int index) {
	if (index >= this->_size)
		throw std::out_of_range("Array::Index out of bounds!");
	return (this->_array[index]);
}

// A const version of the subscript operator:
// returns a constant reference for read-only access to elements of a constant object.
template <typename T>
const T & Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("Array::Index out of bounds!");
	return _array[index];
}

//	A member function size() that returns the number of elements in the array. This
//	member function takes no parameter and mustn't modify the current instance.
template <typename T>
unsigned int	Array<T>::size(void) {
	return (this->_size);
}

#endif //EX02_ARRAY_HPP
