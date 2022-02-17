/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:08:38 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/17 22:20:26 by dahpark          ###   ########seoul.kr  */
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
	Form *form;

	try {
		Bureaucrat br1("One", 3);
		std::cout << br1 << std::endl;
		form = intern.makeForm("presidential pardon", "Sam");
		br1.signForm(*form);
		br1.executeForm(*form);
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat br2("Two", 30);
		std::cout << br2 << std::endl;
		form = intern.makeForm("robotomy request", "Smith");
		br2.signForm(*form);
		br2.executeForm(*form);
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat br3("Three", 130);
		std::cout << br3 << std::endl;
		form = intern.makeForm("shrubbery creation", "school");
		br3.signForm(*form);
		br3.executeForm(*form);
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat br3("Three", 130);
		std::cout << br3 << std::endl;
		form = intern.makeForm("unknown", "target"); // fail
		br3.signForm(*form);
		br3.executeForm(*form);
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}