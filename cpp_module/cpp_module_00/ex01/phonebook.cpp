/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:11:55 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/20 17:16:06 by dahpark          ###   ########seoul.kr  */
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
	int	idx;
	int	limit;

	if (this->cnt == 0)
		std::cout << "There is no contact yet." << std::endl;
	limit = this->cnt % 8;
	this->display_contacts(limit);
	std::cout << "Please input the index of the desired entry : ";
	std::cin >> idx;
	idx -= 1;
	// 숫자가 아닌 문자를 집어넣었다면?? 아무것도 입력을 안 했다면??
	if (idx < 0 || idx > limit)
		std::cout << "Index out of range." << std::endl;
	else
		this->contacts[idx].show_info();
}