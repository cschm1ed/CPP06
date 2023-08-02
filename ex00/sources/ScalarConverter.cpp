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

	displayChar(literal);
	displayInt(literal);
	displayFloat(literal);
	displayDouble(literal);
}

bool ScalarConverter::isInt(std::string const & str) {
	char* pEnd;
	double n = strtod(str.c_str(), &pEnd);

	if (n > INT_MAX || n < INT_MIN) {
		return false;
	}
	return checkRemainingInt(pEnd);
}

bool ScalarConverter::isFloat(const std::string &str) {
	char* pEnd;
	double n = strtod(str.c_str(), &pEnd);

	if (n > FLT_MAX || n < FLT_MIN) {
		return false;
	}
	return checkRemainingFloat(pEnd);
}

bool ScalarConverter::isDouble(const std::string &str) {
	char* pEnd;
	long double n = strtold(str.c_str(), &pEnd);

	if (n > DBL_MAX|| n < DBL_MIN) {
		return false;
	}
	return checkRemainingFloat(pEnd);
}

bool ScalarConverter::checkRemainingFloat(const std::string &str) {
	const char *end;

	end = str.c_str();
	while (isdigit(*end))
		end ++;
	if (*end == '.' && *(end + 1) != '\0') {
		end++;
		while (isdigit(*end))
			end ++;
	}
	return *end == '\0' || *end == 'f' || *end == 'F';
}

bool ScalarConverter::checkRemainingInt(const std::string & str) {
	const char *end;

	end = str.c_str();
	while (isdigit(*end))
		end ++;
	if (*end == '.' && *(end + 1) != '\0') {
		end++;
		while (*end == '0')
			end ++;
	}
	return *end == '\0' || *end == 'f' || *end == 'F';
}

void ScalarConverter::displayChar(std::string const & literal) {
	std::istringstream iss(literal);
	int n;

	iss >> n;
	std::cout << "char: ";
	if (!iss.eof()) {
		std::cout << RED << "impossible\n" << RESET;
		return ;
	}
	if (isprint(n)) {
		std::cout << GREEN << static_cast<char>(n) << "\n" << RESET;
	}
	else if (n < 128 && n >= 0) {
		std::cout << MAGENTA << "Non displayable\n" << RESET;
	}
	else {
		std::cout << RED << "impossible\n" << RESET;
	}
}

void ScalarConverter::displayInt(const std::string &str) {
	std::cout << "int: ";
	if (isInt(str)) {
		int n;
		std::istringstream iss(str);

		iss >> n;
		std::cout << GREEN << n << "\n" << RESET;
	}
	else {
		std::cout << RED << "impossible" << "\n" << RESET;
	}
}

void ScalarConverter::displayFloat(std::string const & str) {
	std::cout << "float: ";

	if (isFloat(str)) {
		char *pEnd;
		float n = strtof(str.c_str(), &pEnd);

		std::cout << GREEN << n;
		if (str.find('.') == std::string::npos) {
			std::cout << ".0";
		}
		std::cout << "f\n" << RESET;
	}
	else {
		std::cout << RED << "impossible\n" << RESET;
	}
}

void ScalarConverter::displayDouble(const std::string &str) {
	std::cout << "double: ";

	if (isDouble(str)) {
		char *pEnd;
		double n = strtod(str.c_str(), &pEnd);
		std::cout << GREEN <<  n;
		if (str.find('.') == std::string::npos) {
			std::cout << ".0";
		}
		std::cout << "\n" << RESET;
	}
	else {
		std::cout << RED << "impossible\n" << RESET;
	}
}
