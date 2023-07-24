/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:32:31 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/24 14:31:51 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FunctionTemplates.hpp"

class
Awesome {
public:
	Awesome( int n ) : _n( n ) {}
	bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
	bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
	bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
	bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
	bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
	bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }

	int getValue() const { return _n; } // required because _n is a private variable.
private:
	int _n;
};


int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "Simple types:"<< std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << "\n" << std::endl;

	Awesome AwesomeClassA(42);
	Awesome AwesomeClassB(21);

	std::cout << "Complex types:"<< std::endl;
	std::cout << "Before swap: AwesomeClassA = " << AwesomeClassA.getValue() << ", AwesomeClassB = " << AwesomeClassB.getValue() << std::endl;
	::swap(AwesomeClassA, AwesomeClassB);
	std::cout << "After swap: AwesomeClassA = " << AwesomeClassA.getValue() << ", AwesomeClassB = " << AwesomeClassB.getValue() << std::endl;

	Awesome minVal = min(AwesomeClassA, AwesomeClassB);
	Awesome maxVal = max(AwesomeClassA, AwesomeClassB);

	std::cout << "Minimum value: " << minVal.getValue() << std::endl;
	std::cout << "Maximum value: " << maxVal.getValue() << std::endl;

	return 0;
}
