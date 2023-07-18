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

	// Call iter with test_print function
	std::cout << "Printing the array elements: ";
	iter(intArray, 5, test_print<int>);
	std::cout << std::endl;

	// Call iter with test_increment function
	std::cout << "Incrementing the array elements: ";
	iter(intArray, 5, test_increment<int>);
	iter(intArray, 5, test_print<int>);
	std::cout << std::endl;

	// Dynamically allocate memory for integer array
	int* allocatedIntArray = new int[5];
	for (int i = 0; i < 5; ++i)
		allocatedIntArray[i] = i + 1;

	// Dynamically allocate memory for double array
	double* allocatedDoubleArray = new double[5];
	for (int i = 0; i < 5; ++i)
		allocatedDoubleArray[i] = (i + 1) * 1.1;

	// Call iter with test_print function
	iter(allocatedIntArray, 5, test_print<int>);
	std::cout << std::endl;
	iter(allocatedDoubleArray, 5, test_print<double>);
	std::cout << std::endl;

	// Deallocate memory
	delete[] allocatedIntArray;
	delete[] allocatedDoubleArray;

	return 0;
}