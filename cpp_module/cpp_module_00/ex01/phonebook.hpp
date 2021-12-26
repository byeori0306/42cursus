/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:11:58 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/26 14:36:00 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

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