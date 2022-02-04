/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:08:38 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/04 22:31:17 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat br1("One", 5);
	Bureaucrat br2("Two", 50);

	std::cout << br1 << std::endl;
	std::cout << br2 << std::endl;

	try {
		Form form1("form1", 0, 50, false); // out of range
		std::cout << form1 << std::endl;
		br1.signForm(form1);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try {
		Form form2("form2", 10, 50, false);
		std::cout << form2 << std::endl;
		br1.signForm(form2); // sucess
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	
	try {
		Form form3("form3", 10, 50, false);
		std::cout << form3 << std::endl;
		br2.signForm(form3); // fail
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}