/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:16:10 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/05 16:37:17 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(): target(""), value(0.0) { }

Conversion::Conversion(std::string target): target(target) {
	value = atof(target.c_str());
}

Conversion::Conversion(const Conversion& c): target(c.target), value(c.value) { }

Conversion& Conversion::operator=(const Conversion& c) {
	if (this == &c)
		return (*this);
	target = c.target;
	value = c.value;
	return (*this);
}

Conversion::~Conversion() { }

char Conversion::convertToChar() {
	return (static_cast<char>(value));
}

int Conversion::convertToInt() {
	return (static_cast<int>(value));
}

float Conversion::convertToFloat() {
	return (static_cast<float>(value));
}

double Conversion::convertToDouble() {
	return (static_cast<double>(value));
}

void Conversion::printResult() {
	if (std::isnan(value) || std::isinf(value)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << convertToFloat() << "f" << std::endl;
		std::cout << "double: " << convertToDouble() << std::endl; 
		return;
	}

	if (value > 31 && value < 127)
		std::cout << "char: \'" << convertToChar() << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	int	int_val = convertToInt();
	float float_val = convertToFloat();
	double double_val = convertToFloat();
	std::cout << "int: " << int_val  << std::endl;
	if (float_val == int_val)
		std::cout << "float: " << float_val << ".0f" << std::endl;
	else
		std::cout << "float: " << float_val << "f" << std::endl;
	if (double_val == int_val)
		std::cout << "double: " << double_val << ".0" << std::endl;
	else
		std::cout << "double: " << double_val << std::endl;
}