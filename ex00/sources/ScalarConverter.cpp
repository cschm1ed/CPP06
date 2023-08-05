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
	(void) other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	std::cout << "ScalarConverter copy assignemnt alled\n";
	(void) rhs;
	return *this;
}

void ScalarConverter::convert(std::string &literal) {
	long double n;
	char *pEnd = nullptr;
	bool validString = true;

	if (literal.size() == 1 && isprint(static_cast<int>(literal[0]))
		&& !(static_cast<int>(literal[0]) <= '9' && static_cast<int>(literal[0]) >= '0')) {
		n = static_cast<int>(literal[0]);
	} else {
		n = strtold(literal.c_str(), &pEnd);
		if (*pEnd && strncmp(pEnd, "f", 2)) {
			validString = false;
		}
	}
	displayChar(n, validString);
	displayInt(n, validString && literal != "nan" && literal != "-inf" && literal != "+inf");
	displayFloat(literal, n, validString);
	displayDouble(literal, n, validString);
}

void ScalarConverter::displayInt(long double n, bool validString) {
	if (n < INT_MAX && n > INT_MIN && validString)
		std::cout << "int: " << GREEN << static_cast<int>(n) << "\n" << R;
	else
		std::cout << "int " << RED << "impossible\n" << R;
}

void ScalarConverter::displayChar(int n, bool validString) {
	if (n < 128 && n >= 0 && validString) {
		if (isprint(n))
			std::cout << "char: " << GREEN << static_cast<char>(n) << "\n" << R;
		else
			std::cout << "char: " << MAGENTA << "Non displayable\n" << R;
	} else
		std::cout << "char: " << RED << "impossible\n" << R;
}

void ScalarConverter::displayDouble(const std::string &literal, long double n, bool validString) {
	std::cout << "double: ";

	if (displayPseudoLiteral(literal)) {
		return;
	}
	if (n <= std::numeric_limits<double>::max() && n >= -std::numeric_limits<double>::max()
		&& (n <= -std::numeric_limits<double>::min() || n >= std::numeric_limits<double>::min() || n == 0)
		&& validString) {
		std::cout << GREEN << static_cast<double>(n);
		if (literal.find('.') == std::string::npos && literal.find('e') == std::string::npos) {
			std::cout << ".0";
		}
		std::cout << "\n" << R;
	} else
		std::cout << RED << "impossible\n" << R;
}

void ScalarConverter::displayFloat(const std::string &literal, long double n, bool validString) {
	std::cout << "float: ";

	if (displayPseudoLiteral(literal)) {
		return;
	}
	if (n <= std::numeric_limits<float>::max() && n >= -std::numeric_limits<float>::max()
		&& (n <= -std::numeric_limits<float>::min() || n >= std::numeric_limits<float>::min() || n == 0)
		&& validString) {
		std::cout << static_cast<float>(n);
		if (literal.find('.') == std::string::npos && literal.find('e') == std::string::npos) {
			std::cout << ".0f\n";
		} else {
			std::cout << "f\n";
		}
	} else
		std::cout << RED << "impossible\n" << R;
}

int ScalarConverter::displayPseudoLiteral(std::string const &literal) {
	std::string pseudoLiterals[] = {"+inf", "-inf", "nan", "+inff", "-inff", "nanf"};
	int i = 0;

	while (i < 6) {
		if (literal == pseudoLiterals[i])
			break;
		i++;
	}
	switch (i) {
		case (0):
			std::cout << BLUE << static_cast<float>(std::numeric_limits<double>::infinity()) << "\n" << R;
			return 1;
		case 1:
			std::cout << BLUE << static_cast<float>(-std::numeric_limits<double>::infinity()) << "\n" << R;
			return 1;
		case 2:
			std::cout << BLUE << static_cast<float>(std::numeric_limits<double>::quiet_NaN()) << "\n" << R;
			return 1;
		case 3:
			std::cout << BLUE << static_cast<float>(std::numeric_limits<double>::infinity()) << "\n" << R;
			return 1;
		case 4:
			std::cout << BLUE << static_cast<float>(-std::numeric_limits<double>::infinity()) << "\n" << R;
			return 1;
		case 5:
			std::cout << BLUE << static_cast<float>(std::numeric_limits<double>::quiet_NaN()) << "\n" << R;
	}
	return 0;
}
