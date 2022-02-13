/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:14:28 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/13 19:28:57 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
: Form("presidential pardon form", P_SIGN_GRADE, P_EXEC_GRADE, false), target("target") { }

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
: Form("presidential pardon form", P_SIGN_GRADE, P_EXEC_GRADE, false), target(target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ppf)
: Form(ppf.getName(), P_SIGN_GRADE, P_EXEC_GRADE, ppf.getSigned()), target(ppf.target) { } 

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ppf) {
	if (this == &ppf)
		return (*this);
	setSigned(ppf.getSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() { }

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	try {
		checkExecGrade(executor);
		std::cout << target << " has been pardoned by Zafod Beeblebrox." << std::endl; 
	} catch (std::exception& e) {
		throw e.what();
	}
}