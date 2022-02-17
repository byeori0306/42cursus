/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:04:20 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/17 21:54:00 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("form"), sign_grade(50), excute_grade(10), is_signed(false) { }

Form::Form(std::string const name, int const sign_grade, int const excute_grade, bool is_signed = false) 
: name(name), sign_grade(sign_grade), excute_grade(excute_grade), is_signed(is_signed) {
	if (sign_grade < 1 || excute_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150 || excute_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& form) 
: name(form.getName()), sign_grade(form.getSignGrade()), excute_grade(form.getExcuteGrade()), is_signed(form.getSigned()) { }

Form& Form::operator=(const Form& form) {
	if (this == &form)
		return (*this);
	is_signed = form.getSigned();
	return (*this);
}

Form::~Form() { }

const char* Form::GradeTooHighException::what() const throw() {
	return ("grade is too high");	
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("grade is too low");	
}

std::string Form::getName() const {
	return (name);
}

int Form::getSignGrade() const {
	return (sign_grade);
}

int Form::getExcuteGrade() const {
	return (excute_grade);
}

bool Form::getSigned() const {
	return (is_signed);
}

void Form::beSigned(Bureaucrat& br) {
	if (br.getGrade() < sign_grade)
		is_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, Form& form) {
	out << "Form name: " << form.getName() << ", grade for sign: " << form.getSignGrade() << ", grade for executing: " << form.getExcuteGrade() << ", signed: " << form.getSigned();
	return (out);
}