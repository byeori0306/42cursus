/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:11:58 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/20 17:15:23 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>

#define TRUE 1

class contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		void	update_info();
		void	display_info(int idx);
		void	show_info();
};

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