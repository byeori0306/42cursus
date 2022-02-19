/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:41:09 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/19 20:47:28 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>

template <class T>
class Array {
	private:
		unsigned int n;
		T *arr;
	public:
		Array() : n(0), arr(new T[n]) { }
		Array(unsigned int n) : n(n), arr(new T[n]) { }
		Array(const Array<T>& array) : n(array.n), arr(new T[n]) {
			for (unsigned int i = 0; i < n; i++)
				arr[i] = array.arr[i];
		}
		Array<T>& operator=(const Array<T>& array) {
			if (this == &array)
				return (*this);
			n = array.n;
			delete[] arr;
			arr = new T[n];
			for (unsigned int i = 0; i < n; i++)
				arr[i] = array.arr[i];
			return (*this);
		}
		~Array() {
			delete[] arr;
		}

		class outOfTheLimits : public std::exception {
			public:
				const char* what() const throw () {
					return ("Out of the limits");
				}	
		};

		T& operator[](unsigned int idx) {
			if (idx >= n)
				throw Array<T>::outOfTheLimits();
			return (arr[idx]);
		}
		unsigned int size(void) {
			return (n);
		}
};

#endif