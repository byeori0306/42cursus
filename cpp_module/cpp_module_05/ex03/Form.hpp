/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:04:23 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/13 19:29:41 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP_
#define FORM_HPP_

#include <iostream>

class Bureaucrat;

class Form {
	private:
		std::string const name;
		int const sign_grade;
		int const excute_grade;
		bool is_signed;
	public:
		Form();
		Form(std::string const name, int const sign_grade, int const excute_grade, bool is_signed);
		Form(const Form& form);
		Form& operator=(const Form& form);
		~Form();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		void setSigned(bool const status);
		std::string const getName() const;
		int const getSignGrade() const;
		int const getExcuteGrade() const;
		bool const getSigned() const;
		void beSigned(Bureaucrat& br);
		void checkExecGrade(Bureaucrat const & executor) const;
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, Form& form);

#endif