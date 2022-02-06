/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:26:35 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/06 14:36:11 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP_
#define ITER_HPP_

#include <iostream>

template <typename T>
void iter(T *arr, unsigned int length, void (*f)(T&)) {
	for (unsigned int i = 0; i < length; i++)
		(*f)(arr[i]);
}

template <typename T>
void print(T &x) {
	std::cout << x << " ";
}

#endif