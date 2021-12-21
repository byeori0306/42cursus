/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:11:55 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/21 14:22:27 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() : cnt(0) {}

void	PhoneBook::add_contact() {
	int	idx;
	
	idx = this->cnt % 8;
	this->contacts[idx].update_info();
	this->cnt++;
}

void	PhoneBook::display_contacts(int limit) {
	int	idx = -1;
	
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	while (++idx < limit)
		this->contacts[idx].display_info(idx + 1);
}

void	PhoneBook::search_contact() {
	std::string	input;
	int	idx;
	int	limit;

	if (this->cnt == 0)
	{
		std::cout << "There is no contact yet." << std::endl;
		return ;
	}
	limit = this->cnt % 8;
	this->display_contacts(limit);
	std::cout << "Please input the index of the desired entry : ";
	std::getline(std::cin, input);
	idx = atoi(input.c_str());
	if ((idx < 1 || idx > 8) || idx >= limit + 1)
	{
		std::cout << "Index out of range." << std::endl;
		return ;
	}
	else
		this->contacts[idx - 1].show_info();
}