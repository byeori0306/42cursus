/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:36:39 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/09 20:47:16 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "karen.hpp"

void	karen::debug(void) {
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	karen::info(void) {
	std::cout <<  "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	karen::warning(void) {
	std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	karen::error(void) {
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	karen::complain(std::string level) {
	std::string	level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(karen::*pFn[4])(void);

	pFn[0] = &karen::debug;
	pFn[1] = &karen::info;
	pFn[2] = &karen::warning;
	pFn[3] = &karen::error;
	std::string *res = std::find(level_arr, level_arr + 4, level);
	int idx = res - level_arr;
	if (idx < 0 || idx > 3)
		return;
	(this->*pFn[idx])();
}