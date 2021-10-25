/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:48:19 by dahpark           #+#    #+#             */
/*   Updated: 2021/10/25 15:05:59 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char* argv[])
{
	int i = 1;
	int j;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			argv[i][j] = std::toupper(argv[i][j]);
  			j++;
		}
		std::cout << argv[i];
		i++;
	}
	std::cout << std::endl;
	return 0;
}