/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:32:35 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/24 14:33:04 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// Test from eval sheet:
class Awesome
{
public:
	Awesome ( void ) : _n( 42 ) { return; }
	int get ( void ) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator << ( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	double doubleArray[]  = { 1.11,  2.22, 3.33, 4.44, 5.55 };
	std::string stringArray[5] = { "one", "two", "three", "for", "five" };

	// Call iter with print function
	std::cout << std::left << std::setw(50) << "Printing the int array elements: ";
	iter(intArray, 5, ft_print_elem);
	std::cout << std::endl;

	// Call iter with print function for float array
	std::cout << std::left << std::setw(50) << "Printing the float array elements: ";
	iter(floatArray, 5, ft_print_elem);
	std::cout << std::endl;

	// Call iter with print function for double array
	std::cout << std::left << std::setw(50) << "Printing the double array elements: ";
	iter(doubleArray, 5, ft_print_elem);
	std::cout << std::endl;

	// Call iter with print function for string array
	std::cout << std::left << std::setw(50) << "Printing the string array elements: ";
	iter(stringArray, 5, ft_print_elem);
	std::cout << std::endl;

	std::cout << "\nUsing the eval sheet class function on my Template: " << std::endl;

	int tab[] = { 0, 1, 2 ,3, 4};
	Awesome tab2[5];

	iter ( tab, 5 , print );
	iter ( tab2, 5, print );

	return 0;
}