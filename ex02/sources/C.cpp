/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:21:02 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/05 15:21:02 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <C.hpp>

C::~C() {
	std::cout << CYAN << "C destructor called\n" << R;
}
