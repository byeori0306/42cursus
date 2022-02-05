/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:56:16 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/05 13:50:16 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP_
#define INTERN_HPP_

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private:
	public:
		Intern();
		Intern(const Intern& intern);
		Intern& operator=(const Intern& intern);
		~Intern();

		class unknownForm : public std::exception {
			public:
				const char* what() const throw();
		};

		Form* makeForm(const std::string name, const std::string target);
};

#endif