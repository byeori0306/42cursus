/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:08:38 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/17 22:18:44 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat br1("One", 1);
		std::cout << br1 << std::endl;
		br1.incrementGrade();
		std::cout << br1 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat br2("Two", 10);
		std::cout << br2 << std::endl;
		br2.incrementGrade();
		std::cout << br2 << std::endl;
		br2.decrementGrade();
		std::cout << br2 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat br3("Three", 150);
		std::cout << br3 << std::endl;
		br3.decrementGrade(); 
		std::cout << br3 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}