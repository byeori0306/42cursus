/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:38:27 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/06 14:21:28 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP_
#define WHATEVER_HPP_

#include <iostream>

template <typename T>
void swap(T &a, T &b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b) {
	if (a < b)
		return (a);
	else
		return (b);
} 

template <typename T>
T max(T a, T b) {
	if (a > b)
		return (a);
	else
		return (b);
}

#endif