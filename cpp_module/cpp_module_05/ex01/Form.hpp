/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:04:23 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/03 22:17:48 by dahpark          ###   ########seoul.kr  */
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
		Form(std::string name, int sign_grade, int excute_grade, bool is_signed);
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

		std::string const getName() const;
		int getSignGrade() const;
		int getExcuteGrade() const;
		bool getSigned() const;
		void beSigned(Bureaucrat& br);
};

std::ostream& operator<<(std::ostream& out, Form& form);

#endif