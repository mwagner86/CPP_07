/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:35:07 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/24 14:35:08 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

// #define MAX_VAL 750

/*
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/

#define MAX_VAL 25

int main(int, char**) {
	// Construction with no parameter: Creates an empty array.
	Array<int> emptyArray;
	std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl; // Should output 0

	// Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
	Array<int> numbers(MAX_VAL);
	for (unsigned int i = 0; i < MAX_VAL; i++) {
		std::cout << numbers[i] << " "; // Output the numbers array
	}
	std::cout << std::endl;

	// Construction by copy and assignment operator
	Array<int> copiedArray = numbers; // Copy constructor
	Array<int> assignedArray;
	assignedArray = numbers; // Assignment operator

	// Modifying either the original array or its copy after copying must not affect the other array.
	copiedArray[0] = 999;
	std::cout << "Original Array after modifying copy: " << numbers[0] << std::endl; // Should be unchanged
	std::cout << "Copied Array: " << copiedArray[0] << std::endl; // Should be 999

	// Out-of-bounds access: Should throw std::exception (std::out_of_range)
	try {
		numbers[-2] = 0;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n'; // Output: "Array::Index out of bounds!"
	}
	try {
		numbers[MAX_VAL] = 0;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n'; // Output: "Array::Index out of bounds!"
	}

	// Additional functionality test: Randomly fill and output the array
	for (unsigned int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}

	std::cout << "Numbers Array: ";
	for (unsigned int i = 0; i < MAX_VAL; i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
