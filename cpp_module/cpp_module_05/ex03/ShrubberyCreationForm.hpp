/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:14:42 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/13 18:58:58 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP_
#define SHRUBBERY_CREATION_FORM_HPP_

#include "Form.hpp"
#define S_SIGN_GRADE 145
#define S_EXEC_GRADE 137

class ShrubberyCreationForm : public Form {
	private:
		std::string const target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const target);		
		ShrubberyCreationForm(const ShrubberyCreationForm& scf);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& scf);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const & executor) const;
};

#endif