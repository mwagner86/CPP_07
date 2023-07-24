/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FunctionTemplates.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:31:40 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/24 14:31:43 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
