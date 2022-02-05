/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:39:53 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/05 17:47:30 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void) {
	Data* data = new Data("precious data");
	uintptr_t raw = data->serialize(data);
	Data* data2 = data->deserialize(raw);
	
	std::cout << data->getData() << std::endl;
	std::cout << data2->getData() << std::endl;
}