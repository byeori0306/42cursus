/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:29:28 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/05 17:47:21 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): data("data") { }

Data::Data(std::string data): data(data) { }

Data::Data(const Data& d): data(d.data) { }

Data& Data::operator=(const Data& d) {
	if (this == &d)
		return (*this);
	data = d.data;
	return (*this);
}

Data::~Data() { };

std::string Data::getData() {
	return (data);
}

uintptr_t Data::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Data::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}