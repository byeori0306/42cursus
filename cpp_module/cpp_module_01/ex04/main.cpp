/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:11:30 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/24 22:08:01 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc, char **argv) {
	if (argc != 4)
		return (1);
	else
		return (sed::replace(argv[1], argv[2], argv[3]));
}