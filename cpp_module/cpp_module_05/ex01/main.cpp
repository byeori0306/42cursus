/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:08:38 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/03 22:34:27 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Form form1("form1", 10, 50, false);
	Form form2("form2", 10, 50, false);
	Bureaucrat br1("One", 5);
	Bureaucrat br2("Two", 50);

	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << br1 << std::endl;
	std::cout << br2 << std::endl;

	try {
		form1.beSigned(br1);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {
		form2.beSigned(br2);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	br1.signForm(form1);
	br2.signForm(form2);
}