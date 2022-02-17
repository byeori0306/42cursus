/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:14:34 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/17 22:09:18 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
: Form("robotomy request form", R_SIGN_GRADE, R_EXEC_GRADE, false), target("target") { }

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: Form("robotomy request form", R_SIGN_GRADE, R_EXEC_GRADE, false), target(target) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rrf)
: Form(rrf.getName(), R_SIGN_GRADE, R_EXEC_GRADE, rrf.getSigned()), target(rrf.target) { } 

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rrf) {
	if (this == &rrf)
		return (*this);
	setSigned(rrf.getSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() { }

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	srand((unsigned int)time(NULL));
	int result = rand() % 2;
	try {
		checkExecGrade(executor);
		std::cout << "* DRRRRRRRRRRRRR *" << std::endl;
		if (result)
			std::cout << target << " has been robotomized successfully" << std::endl;
		else
			std::cout << target << " has failed to be robotomized." << std::endl;
	} catch (std::exception& e) {
		throw e.what();
	}
}