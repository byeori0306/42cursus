/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:11:30 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/09 14:54:26 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Too many or too few arguments" << std::endl;
		return (1);
	}
	else
		return (sed::replace(argv[1], argv[2], argv[3]));
}