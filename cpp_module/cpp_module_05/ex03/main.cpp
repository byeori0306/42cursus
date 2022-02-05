/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:08:38 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/05 13:58:19 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	Intern intern;
	Bureaucrat br1("One", 3);
	Bureaucrat br2("Two", 30);
	Bureaucrat br3("Three", 130);
	Form *form;

	std::cout << br1 << std::endl;
	std::cout << br2 << std::endl;
	std::cout << br3 << std::endl;
	std::cout << std::endl;

	try {
		form = intern.makeForm("presidential pardon", "Sam");
		br1.signForm(*form);
		br1.executeForm(*form);
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		form = intern.makeForm("robotomy request", "Smith");
		br2.signForm(*form);
		br2.executeForm(*form);
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		form = intern.makeForm("shrubbery creation", "school");
		br3.signForm(*form);
		br3.executeForm(*form);
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		form = intern.makeForm("unknown", "target"); // fail
		br3.signForm(*form);
		br3.executeForm(*form);
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}