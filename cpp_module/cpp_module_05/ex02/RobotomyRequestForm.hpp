/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:14:36 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/13 18:58:26 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP_
#define ROBOTOMY_REQUEST_FORM_HPP_

#include "Form.hpp"
#define R_SIGN_GRADE 72
#define R_EXEC_GRADE 45

class RobotomyRequestForm : public Form {
	private:
		std::string const target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(const RobotomyRequestForm& rrf);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &rrf);
		~RobotomyRequestForm();
		void execute(Bureaucrat const & executor) const;
};

#endif