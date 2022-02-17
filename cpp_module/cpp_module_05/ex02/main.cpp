/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:08:38 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/17 21:37:21 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		Bureaucrat br1("One", 3);
		std::cout << br1 << std::endl;
		PresidentialPardonForm ppf("Sam");
		br1.signForm(ppf);
		br1.executeForm(ppf);
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat br2("Two", 30);
		std::cout << br2 << std::endl;
		RobotomyRequestForm rrf("Smith");
		br2.signForm(rrf);
		br2.executeForm(rrf);
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat br3("Three", 130);
		std::cout << br3 << std::endl;
		ShrubberyCreationForm scf("school");
		br3.signForm(scf);
		br3.executeForm(scf);
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat br1("One", 3);
		std::cout << br1 << std::endl;
		Bureaucrat br2("Two", 30);
		std::cout << br2 << std::endl;
		PresidentialPardonForm ppf("Sam");
		br1.signForm(ppf);
		br2.executeForm(ppf); // fail
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}