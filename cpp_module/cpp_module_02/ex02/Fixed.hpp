/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:46:45 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/11 18:51:23 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H_
#define FIXED_H_

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					value;
		static const int	bits;
	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float floating);
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed& operator=(const Fixed &fixed);

		bool			operator>(const Fixed &n) const;
		bool			operator<(const Fixed &n) const;
		bool			operator>=(const Fixed &n) const;
		bool			operator<=(const Fixed &n) const;
		bool			operator==(const Fixed &n) const;
		bool			operator!=(const Fixed &n) const;

		Fixed			operator+(const Fixed &n) const;
		Fixed			operator-(const Fixed &n) const;
		Fixed			operator*(const Fixed &n) const;
		Fixed			operator/(const Fixed &n) const;

		Fixed&			operator++(void);
		Fixed&			operator--(void);
		Fixed			operator++(int);
		Fixed			operator--(int);

		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;
		static Fixed&	max(Fixed& n1, Fixed& n2);
		static Fixed&	min(Fixed& n1, Fixed& n2);
		static const Fixed&	max(const Fixed& n1, const Fixed& n2);
		static const Fixed&	min(const Fixed& n1, const Fixed& n2);
};

std::ostream&	operator<<(std::ostream &out, const Fixed &fixed);

#endif