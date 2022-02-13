/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:14:31 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/13 18:58:18 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP_
#define PRESIDENTIAL_PARDON_FORM_HPP_

#include "Form.hpp"
#define P_SIGN_GRADE 25
#define P_EXEC_GRADE 5

class PresidentialPardonForm : public Form {
	private:
		std::string const target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(const PresidentialPardonForm& ppf);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& ppf);
		~PresidentialPardonForm();
		void execute(Bureaucrat const & executor) const;
};

#endif