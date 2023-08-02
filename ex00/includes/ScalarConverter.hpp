/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:49:53 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/21 11:49:56 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP06_SCALARCONVERTER_HPP
#define CPP06_SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <colors.hpp>
#include <climits>
#include <float.h>

class ScalarConverter {
public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(ScalarConverter const &other);
	ScalarConverter &operator=(ScalarConverter const &rhs);

	static void convert(std::string &literal);

private:
	static bool isInt(std::string const & str);
	static bool isFloat(std::string const & str);
	static bool isDouble(std::string const & str);
	static void displayChar(std::string const & str);
	static bool checkRemainingInt(std::string const & str);
	static bool checkRemainingFloat(std::string const & str);
	static void displayFloat(std::string const & str);
	static void displayDouble(std::string const & str);
	static void displayInt(std::string const & str);

};


#endif //CPP06_SCALARCONVERTER_HPP
