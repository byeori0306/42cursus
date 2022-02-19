/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:11:33 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/19 15:36:39 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Wrong input!" << std::endl;
		return (0);
	}

	Conversion c(argv[1]);
	c.printResult();
}