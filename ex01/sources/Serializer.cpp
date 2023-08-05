/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:21:15 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/05 12:21:43 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Serializer.hpp>

Serializer::Serializer() {
	std::cout << "Serializer default constructor called\n";
}

Serializer::~Serializer() {
	std::cout << "Serializer default destructor called\n";
}

Serializer::Serializer(Serializer const &other) {
	(void)other;
	std::cout << "Serializer copy constructor called\n";
}

Serializer &Serializer::operator=(Serializer const &rhs) {
	(void)rhs;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t >(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
