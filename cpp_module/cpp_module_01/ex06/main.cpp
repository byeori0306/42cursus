/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:36:33 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/25 14:55:37 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "karen.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return (1);
	karen	Karen;

	std::string	level(argv[1]);
	Karen.complain(level);
	return (0);
}