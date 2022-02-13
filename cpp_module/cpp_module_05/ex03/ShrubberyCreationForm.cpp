/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:14:39 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/13 19:31:08 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
: Form("shrubbery creation form", S_SIGN_GRADE, S_EXEC_GRADE, false), target("target") { }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
: Form("shrubbery creation form", S_SIGN_GRADE, S_EXEC_GRADE, false), target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& scf)
: Form(scf.getName(), S_SIGN_GRADE, S_EXEC_GRADE, scf.getSigned()), target(scf.target) { } 

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& scf) {
	if (this == &scf)
		return (*this);
	setSigned(scf.getSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() { }

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	try {
		checkExecGrade(executor);
		std::string file = target + "_shrubbery";
		std::ofstream form(file);
		form << "            ,@@@@@@@,\n"
			<< "    ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
			<< " ,&$&$&&$,@@@@@/@@@@@@,8888\\88/8o\n"
			<< ",$&\\$&&$&&$,@@@\\@@@/@@@88\\88888/88'\n"
			<< "$&&$&$&/$&&$@@\\@@/ /@@@88888\\88888'\n"
			<< "$&&$/ $&$&&@@\\ V /@@' `88\\8 `/88'\n"
			<< "`&$\\ ` /$&'    |.|        \\ '|8'\n"
			<< "    |o|        | |         | |\n"
			<< "    |.|        | |         | |\n";
		form.close();
	}  catch (std::exception& e) {
		throw e.what();
	}
}