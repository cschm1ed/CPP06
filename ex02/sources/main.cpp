/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:18:51 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/05 15:18:51 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

Base* generate();
void identify(Base *p);
void identify(Base &p);

int main() {
	Base	*random;

	random = generate();
	identify(random);
	identify(*random);

	delete random;
}

Base* generate() {
	std::srand(std::time(nullptr));
	int x = rand() % 3;

	switch (x) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return nullptr;
}

void identify(Base *p) {
	std::cout << "identifiying by pointer\n";
	std::cout << "identified --> ";
	if (dynamic_cast<A *>(p)) {
		std::cout << BLUE << "A\n" << R;
	}
	else if (dynamic_cast<B *>(p)) {
		std::cout << YELLOW << "B\n" << R;
	}
	else
		std::cout << CYAN << "C\n" << R;

}

void identify(Base &p) {
	std::cout << "identifiying by reference\n";
	std::cout << "identified --> ";
	if (dynamic_cast<A *>(&p)) {
		std::cout << BLUE << "A\n" << R;
	}
	else if (dynamic_cast<B *>(&p)) {
		std::cout << YELLOW << "B\n" << R;
	}
	else
		std::cout << CYAN << "C\n" << R;
}
