/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:15:03 by dahpark           #+#    #+#             */
/*   Updated: 2021/10/25 18:52:14 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	std::string cmd;

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
			std::cout << "Add contact" << std::endl;
		else if (cmd == "SEARCH")
			std::cout << "Search phone book" << std::endl;
		else if (cmd == "EXIT")
			return 0;
		else
			std::cout << "Please enter the right command." << std::endl;	
	}
}