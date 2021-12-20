/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:15:56 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/20 17:16:18 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	contact::update_info() {
	std::cout << "1. first name : ";
	std::getline(std::cin, this->first_name);
	std::cout << "2. last name : ";
	std::getline(std::cin, this->last_name);
	std::cout << "3. nickname : ";
	std::getline(std::cin, this->nickname);
	std::cout << "4. phone number : ";
	std::getline(std::cin, this->phone_number);
	std::cout << "5. darkest secret : ";
	std::getline(std::cin, this->darkest_secret);
}

void	contact::display_info(int idx) {
	std::cout << "|" << std::setw(10) << idx;
	std::cout << "|" << std::setw(10) << this->first_name;
	std::cout << "|" << std::setw(10) << this->last_name;
	std::cout << "|" << std::setw(10) << this->nickname << "|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
}

void	contact::show_info() {
	std::cout << "1. first name : " << this->first_name << std::endl;
	std::cout << "2. last name : " << this->last_name << std::endl;
	std::cout << "3. nickname : " << this->nickname << std::endl;
	std::cout << "4. phone number : " << this->phone_number << std::endl;
	std::cout << "5. darkest secret : " << this->darkest_secret << std::endl;
}
