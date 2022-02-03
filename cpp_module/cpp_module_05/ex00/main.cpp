/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:08:38 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/03 21:00:56 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat br1("One", 1);
	Bureaucrat br2("Two", 10);
	Bureaucrat br3("Three", 150);

	std::cout << br1 << std::endl;
	std::cout << br2 << std::endl;
	std::cout << br3 << std::endl;

	try {
		br1.incrementGrade();
		std::cout << br1 << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		br2.incrementGrade();
		std::cout << br2 << std::endl;
		br2.decrementGrade();
		std::cout << br2 << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		br3.decrementGrade(); 
		std::cout << br3 << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}