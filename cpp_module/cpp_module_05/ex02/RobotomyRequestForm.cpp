/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:14:34 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/04 22:47:35 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
: Form("robotomy request form", R_SIGN_GRADE, R_EXEC_GRADE, false), target("target") { }

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: Form("robotomy request form", R_SIGN_GRADE, R_EXEC_GRADE, false), target(target) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ppf)
: Form(ppf.getName(), R_SIGN_GRADE, R_EXEC_GRADE, ppf.getSigned()), target(ppf.target) { } 

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ppf) {
	if (this == &ppf)
		return (*this);
	target = ppf.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() { }

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	try {
		checkExecGrade(executor);
		std::cout << "* DRRRRRRRRRRRRR *" << std::endl;
		std::cout << target << " has been robotomized successfully 50\% of the time." << std::endl;
	} catch (std::exception& e) {
		throw e.what();
	}
}