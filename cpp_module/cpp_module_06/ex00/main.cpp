/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:11:33 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/05 16:05:01 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Wrong input!" << std::endl;
		return (0);
	}

	Conversion c(argv[1]);
	c.printResult();
}