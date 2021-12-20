/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:15:03 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/20 15:59:16 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	std::string cmd;
	PhoneBook phonebook;

	while (TRUE)
	{
		std::cout << "Enter the command : ";
		std::getline(std::cin, cmd);

		if (std::cin.eof())
		{
			std::cout << std::endl;
			return 0;
		}
		if (cmd == "ADD")
			phonebook.add_contact();
		else if (cmd == "SEARCH")
			phonebook.search_contact();
		else if (cmd == "EXIT")
			return 0;
		else
			std::cout << "Please enter the right command." << std::endl;	
	}
}