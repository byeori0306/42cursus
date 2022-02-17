/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:08:45 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/17 22:19:41 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("John Doe"), grade(75) { }

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name), grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& br) : name(br.getName()), grade(br.getGrade()) { }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& br) {
	if (this == &br)
		return (*this);
	grade = br.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() { }

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error: Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low!");	
}

std::string Bureaucrat::getName() const {
	return (name);
}

int Bureaucrat::getGrade() const {
	return (grade);
}

void Bureaucrat::incrementGrade() {
	grade--;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	grade++;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << name << " signs " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}		
}

void Bureaucrat::executeForm(Form const & form) {
	if (form.getSigned() == false) {
		std::cout << form.getName() << " isn't signed yet." << std::endl;
		return;
	}
	try {
		form.execute(*this);
		std::cout << getName() << " executes " << form.getName() << "." << std::endl;
	} catch (const char *e) {
		std::cout << getName() << " can't execute because " << e << "." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& br) {
	out << "Name: " << br.getName() << ", Grade: " << br.getGrade();
	return (out);
}