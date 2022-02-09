/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:36:33 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/09 20:49:44 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "karen.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Too few or too many arguments" << std::endl;
		return (1);
	}

	karen	Karen;

	std::string	level(argv[1]);
	Karen.complain(level);
	return (0);
}