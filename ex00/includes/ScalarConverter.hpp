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
#include <float.h>
#include <iomanip>


class ScalarConverter {
public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(ScalarConverter const &other);
	ScalarConverter &operator=(ScalarConverter const &rhs);

	static void convert(std::string &literal);

private:

};


#endif //CPP06_SCALARCONVERTER_HPP
