/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:16:13 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/05 16:30:43 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP_
#define CONVERSION_HPP_

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

class Conversion {
	private:
		std::string target;
		double		value;
	public:
		Conversion();
		Conversion(std::string target);
		Conversion(const Conversion& c);
		Conversion& operator=(const Conversion& c);
		~Conversion();

		char	convertToChar();
		int		convertToInt();
		float	convertToFloat();
		double	convertToDouble();
		void	printResult();
};

#endif