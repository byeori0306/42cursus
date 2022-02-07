/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:47:46 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/07 13:46:21 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP_
#define EASYFIND_HPP_

#include <iostream>
#include <algorithm>

class notFound : public std::exception {
	public:
		const char* what() const throw() {
			return ("Target can't be found.");
		}
};

template<typename T>
typename T::iterator easyfind(T& arr, int target) {
	typename T::iterator res;
	res = find(arr.begin(), arr.end(), target);
	if (res == arr.end())
		throw notFound();
	return (res);
}

#endif