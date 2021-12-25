/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:36:33 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/25 14:18:48 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "karen.hpp"

int main(void) {
	karen	Karen;

	Karen.complain("debug");
	Karen.complain("info");
	Karen.complain("warning");
	Karen.complain("error");
}