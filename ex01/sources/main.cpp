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

	std::cout << "------example 1------\n";

	ptr = Serializer::serialize(&sth);

	std::cout << BLUE"pointer before: " << &sth << "\n"R;
	std::cout << CYAN"pointer after: " << ptr << "\n"R;
	std::cout << YELLOW"casting new pointer back again: " << Serializer::deserialize(ptr) << "\n";

	std::cout << BOLDWHITE << "ptr: " << R << ptr << "\n";
	std::cout << BOLDYELLOW << "numeric content: " << R << Serializer::deserialize(ptr)->content << "\n";
	std::cout << BOLDCYAN << "content string: " << R << Serializer::deserialize(ptr)->string << "\n";

	Data sthelse;
	uintptr_t ptr2;

	sthelse.content = 321;
	sthelse.string = "This is a very long string indeed, it might even be to big to store it inside of an uintpr, but i dont know so lets try it out and see what happens!";

	std::cout << "------example 2------\n";

	ptr2 = Serializer::serialize(&sthelse);

	std::cout << BLUE"pointer before: " << &sthelse << "\n"R;
	std::cout << CYAN"pointer after: " << ptr2 << "\n"R;
	std::cout << YELLOW"casting new pointer back again: " << Serializer::deserialize(ptr2) << "\n";

	std::cout << BOLDWHITE << "ptr: " << R << ptr << "\n";
	std::cout << BOLDYELLOW << "numeric content: " << R << Serializer::deserialize(ptr2)->content << "\n";
	std::cout << BOLDCYAN << "content string: " << R << Serializer::deserialize(ptr2)->string << "\n";
	return 0;
}
