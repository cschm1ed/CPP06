/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:21:15 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/05 12:21:43 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP06_SERIALIZER_HPP
#define CPP06_SERIALIZER_HPP

#include <iostream>

typedef struct Data {
	uint content;
	std::string string;
} Data;

class Serializer {

public:
	Serializer();

	Serializer(Serializer const &other);

	~Serializer();

	Serializer &operator=(Serializer const &rhs);

	static uintptr_t serialize(Data *ptr);

	static Data *deserialize(uintptr_t raw);

private:

};


#endif //CPP06_SERIALIZER_HPP
