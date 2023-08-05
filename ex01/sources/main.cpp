/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:21:45 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/05 12:22:43 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Serializer.hpp>
#include <colors.hpp>

int main() {
	Data sth;
	uintptr_t ptr;

	sth.content = 123;
	sth.string = "Hello World";

	ptr = Serializer::serialize(&sth);

	std::cout << BOLDWHITE << "ptr: " << R << ptr << "\n";
	std::cout << BOLDYELLOW << "numeric content: " << R << Serializer::deserialize(ptr)->content << "\n";
	std::cout << BOLDCYAN << "content string: " << R << Serializer::deserialize(ptr)->string << "\n";

	return 0;
}
