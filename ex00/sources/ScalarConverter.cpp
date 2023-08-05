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

		if (literal.size() == 1) {
			n = static_cast<int>(literal[0]);
		} else {
			n = strtold(literal.c_str(), &pEnd);
			if (*pEnd) {
				validString = false;
			}
		}
		displayChar(n, pEnd, validString);
		displayInt(n, validString && literal != "nan" && literal != "-inf" && literal != "+inf");
		displayFloat(literal, n, validString);
		displayDouble(literal, n, validString);
	}

	void ScalarConverter::displayInt(long double n, bool validString) {
		if (n < INT_MAX && n > INT_MIN && validString)
			std::cout << "int: " << GREEN << static_cast<int>(n) << "\n" << RESET;
		else
			std::cout << "int " << RED << "impossible\n" << RESET;
	}

	void ScalarConverter::displayChar(long double n, const char *pEnd, bool validString) {
		if (n < 128 && n >= 0 && (pEnd == NULL || *pEnd == 'f' || *pEnd == 0) && validString) {
			if (isprint(n))
				std::cout << "char: " << GREEN << static_cast<char>(n) << "\n" << RESET;
			else
				std::cout << "char: " << MAGENTA << "Non displayable\n" << RESET;
		} else
			std::cout << "char: " << RED << "impossible\n" << RESET;
	}

	void ScalarConverter::displayDouble(const std::string &literal, long double n, bool validString) {
		std::cout << "double: ";

		if (displayPseudoLiteral(literal)) {
			return;
		}

		if (n <= std::numeric_limits<double>::max() && n >= -std::numeric_limits<double>::max()
			&& (n <= -std::numeric_limits<double>::min() || n >= std::numeric_limits<double>::min())
			&& validString) {
			std::cout << GREEN << static_cast<double>(n);
			if (literal.find('.') == std::string::npos) {
				std::cout << ".0";
			}
			std::cout << "\n" << RESET;
		} else
			std::cout << RED << "impossible\n" << RESET;
	}

	void ScalarConverter::displayFloat(const std::string &literal, long double n, bool validString) {
		std::cout << "float: ";

		if (displayPseudoLiteral(literal)) {
			return;
		}

		if (n <= std::numeric_limits<float>::max() && n >= -std::numeric_limits<float>::max()
			&& (n <= -std::numeric_limits<float>::min() || n >= std::numeric_limits<float>::min())
			&& validString) {
			std::cout << static_cast<float>(n);
			if (literal.find('.') == std::string::npos) {
				std::cout << ".0f\n";
			} else {
				std::cout << "f\n";
			}
		} else
			std::cout << RED << "impossible\n" << RESET;
	}

	int ScalarConverter::displayPseudoLiteral(std::string const &literal) {
		if (literal == "nan" || literal == "+inf" || literal == "-inf") {
			if (literal == "nan") {
				std::cout << BLUE << "nan\n" << RESET;
				return 1;
			}
			if (literal == "+inf") {
				std::cout << BLUE << "inf\n" << RESET;
				return 1;
			}

			if (literal == "-inf") {
				std::cout << BLUE << "-inf\n" << RESET;
				return 1;
			}
		}
		return 0;
	}
