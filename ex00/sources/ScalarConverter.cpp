/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:46:23 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/01 12:46:23 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter constructor called\n";
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	std::cout << "ScalarConverter copy constructor called\n";
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	std::cout << "ScalarConverter copy assignemnt alled\n";
	(void)rhs;
	return *this;
}

void ScalarConverter::convert(std::string &literal) {
	long double n;
	char	*pEnd;

	n = strtold(literal.c_str(), &pEnd);

	//char
	if (n < 128 && n >= 0) {
		if (isprint(n))
			std::cout << std::setw(10) << "char: " << GREEN << static_cast<char>(n) << "\n" << RESET;
		else
			std::cout << "char: " << MAGENTA << "Non displayable\n" << RESET;
	}
	else
		std::cout << "char: " << RED << "impossible\n" << RESET;

	//int
	if (n < INT_MAX && n > INT_MIN)
		std::cout << "int: " << GREEN << static_cast<int>(n) << "\n" << RESET;
	else
		std::cout << "int " << RED << "impossible\n" << RESET;

	//float
	if (n < FLT_MAX && n > FLT_MIN)
		std::cout << "float: " << GREEN << static_cast<float>(n) << "\n" << RESET;
	else
		std::cout << "float: " << RED << "impossible\n" << RESET;

	//double
	std::cout << "double: ";
	if (n < DBL_MAX && n > DBL_MIN)
		std::cout << GREEN << static_cast<double>(n) << "\n" << RESET;
	else
		std::cout << RED << "impossible\n" << RESET;
}
