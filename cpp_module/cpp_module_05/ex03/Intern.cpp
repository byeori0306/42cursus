/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:56:20 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/17 21:42:43 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() { }

Intern::Intern(const Intern&) { }

Intern& Intern::operator=(const Intern&) {
	return (*this);
}

Intern::~Intern() { };

const char* Intern::unknownForm::what() const throw() {
	return ("the requested form is unknown.");
}

Form* Intern::makeForm(std::string const name, std::string const target) {
	int idx = 0;
	Form* form = NULL;
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	
	for (idx = 0; idx < 3; idx++) {
		if (name.compare(forms[idx]) == 0)
			break;
	}
	switch (idx) {
		case 0:
			form = new PresidentialPardonForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			throw Intern::unknownForm();
	}
	std::cout << "Intern creates " << form->getName() << "." << std::endl;
	return (form);
}
