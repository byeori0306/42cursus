/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:46:48 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/11 18:38:45 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::bits = 8;

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : value(integer << bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floating) : value(std::roundf(floating * (1 << bits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;	
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixed) {
	std::cout << "Assignation operator called" << std:: endl;
	if (this == &fixed)
		return *this;
	value = fixed.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed &n) {
	return (value > n.value);
}

bool	Fixed::operator<(Fixed &n) {
	return (value < n.value);
}

bool	Fixed::operator>=(Fixed &n) {
	return (value >= n.value);
}

bool	Fixed::operator<=(Fixed &n) {
	return (value <= n.value);
}

bool	Fixed::operator==(Fixed &n) {
	return (value == n.value);
}

bool	Fixed::operator!=(Fixed &n) {
	return (value != n.value);
}

Fixed	Fixed::operator+(const Fixed &n) {
	return (Fixed(this->toFloat() + n.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &n) {
	return (Fixed(this->toFloat() - n.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &n) {
	return (Fixed(this->toFloat() * n.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &n) {
	return (Fixed(this->toFloat() / n.toFloat()));
}

Fixed&	Fixed::operator++(void) {
	value++;
	return (*this);
}

Fixed&	Fixed::operator--(void) {
	value--;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	n(*this);
	value++;
	return (n);
}

Fixed	Fixed::operator--(int) {
	Fixed	n(*this);
	value--;
	return (n);
}

int	Fixed::getRawBits(void) const {
	return (value);
}

void	Fixed::setRawBits(int const raw) {
	value = raw;
}

float	Fixed::toFloat(void) const {
	return (float(value) / (1 << bits));
}

int		Fixed::toInt(void) const {
	return (value >> bits);
}

Fixed&	Fixed::max(Fixed& n1, Fixed& n2) {
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

Fixed&	Fixed::min(Fixed& n1, Fixed& n2) {
	if (n1 > n2)
		return (n2);
	else
		return (n1);
}

const Fixed&	Fixed::max(const Fixed& n1, const Fixed& n2) {
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	else
		return (n2);
}

const Fixed&	Fixed::min(const Fixed& n1, const Fixed& n2) {
	if (n1.getRawBits() > n2.getRawBits())
		return (n2);
	else
		return (n1);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}