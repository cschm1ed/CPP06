/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:21:10 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/05 15:21:10 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>

Base::~Base() {
	std::cout << BOLDBLACK << "Base destructor called\n" << R;
}