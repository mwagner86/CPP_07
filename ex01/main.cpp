/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:32:35 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/13 20:32:36 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};

	// Call iter with print function
	std::cout << std::left << std::setw(50) << "Printing the int array elements: ";
	iter(intArray, 5, ft_print_elem);
	std::cout << std::endl;

	// Call iter with print function for float array
	std::cout << std::left << std::setw(50) << "Printing the float array elements: ";
	iter(floatArray, 5, ft_print_elem);
	std::cout << std::endl;

	// Call iter with print function for string array
	std::cout << std::left << std::setw(50) << "Printing the string array elements: ";
	iter(stringArray, 5, ft_print_elem<std::string>);
	std::cout << std::endl;

	// Call iter with increment function
	std::cout << std::left << std::setw(50) << "Incrementing the array elements: ";
	iter(intArray, 5, ft_increment_elem);
	iter(intArray, 5, ft_print_elem);
	std::cout << std::endl;

	// Call iter with increment function for float array
	std::cout << std::left << std::setw(50) << "Incrementing the float array elements: ";
	iter(floatArray, 5, ft_increment_elem);
	iter(floatArray, 5, ft_print_elem);
	std::cout << std::endl;

	// Dynamically allocate memory for integer array
	int* allocatedIntArray = new int[5];
	for (int i = 0; i < 5; ++i)
		allocatedIntArray[i] = i + 1;

	// Dynamically allocate memory for double array
	double* allocatedDoubleArray = new double[5];
	for (int i = 0; i < 5; ++i)
		allocatedDoubleArray[i] = (i + 1) * 1.1;

	// Call iter with print function
	std::cout << std::left << std::setw(50) << "Printing the allocated int array elements: ";
	iter(allocatedIntArray, 5, ft_print_elem);
	std::cout << std::endl;
	std::cout << std::left << std::setw(50) << "Printing the allocated double array elements: ";
	iter(allocatedDoubleArray, 5, ft_print_elem);
	std::cout << std::endl;
	// Function to square an element and print out values
	iter(allocatedIntArray, 5, ft_square_elem);
	std::cout << std::left << std::setw(50) << "Squaring the allocated int array elements: ";
	iter(allocatedIntArray, 5, ft_print_elem);
	std::cout << std::endl;
	// Function to square an element(double) and print out values
	iter(allocatedDoubleArray, 5, ft_square_elem);
	std::cout << std::left << std::setw(50) << "Squaring the allocated double array elements: ";
	iter(allocatedDoubleArray, 5, ft_print_elem);
	std::cout << std::endl;

/*	//THIS WON'T WORK SINCE OVERLOAD FUNCTION IS NOT IMPLEMENTED (and also wouldn't make sense)
	iter(stringArray, 5, ft_square_elem);
	std::cout << std::left << std::setw(50) << "Squaring the allocated double array elements: ";
	iter(stringArray, 5, ft_print_elem);
	std::cout << std::endl;*/

	// Deallocate memory
	delete[] allocatedIntArray;
	delete[] allocatedDoubleArray;

	return 0;
}
