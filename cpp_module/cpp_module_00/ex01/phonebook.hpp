/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:11:58 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/20 21:00:57 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "contact.hpp"

#define TRUE 1

class PhoneBook {
	private:
		int		cnt;
		contact contacts[8];
	public:
		PhoneBook();
		void	add_contact();
		void	display_contacts(int limit);
		void	search_contact();
};

#endif