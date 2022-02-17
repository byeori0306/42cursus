/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:08:42 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/17 21:54:19 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <iostream>

class Bureaucrat {
	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat& br);
		Bureaucrat& operator=(const Bureaucrat& br);
		~Bureaucrat();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& br);

#endif