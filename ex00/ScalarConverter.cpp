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

	std::cout << "char: ";
	if (isChar(literal)) {
		if (isprint(literal[0]))
			std::cout << static_cast<char>(literal[0]) << "\n";
		else
			std::cout << "Non displayable\n";
	}
	else {
		std::cout << "impossible\n";
	}

	std::cout << "int: ";
	if (isInt(literal)) {
		std::cout << literal << "\n";
	}
	else {
		std::cout << "impossible\n";
	}

	std::cout << "float:";
	if (isFloat(literal)) {
		std::cout << literal << "\n";
	}
	else {
		std::cout << "impossible\n";
	}

	std::cout << "double";
	if (isDouble(literal)) {
		std::cout << literal << "\n";
	}
	else {
		std::cout << "impossible\n";
	}
}

bool ScalarConverter::isChar(std::string const & str) {
	if (str.size() == 1) {
		return true;
	}
	return false;
}

bool ScalarConverter::isInt(std::string const & str) {
	std::stringstream cmp;
	cmp << atoi(str.c_str());

	if () {
		return false;
	}
	return true;
}
