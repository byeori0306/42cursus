/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:30:21 by dahpark           #+#    #+#             */
/*   Updated: 2022/05/19 22:16:56 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP_
#define VECTOR_ITERATOR_HPP_

#include "Iterator.hpp"

namespace ft {
	template <typename T>
	class vector_iterator {
		public:
			typedef	T										value_type;
			typedef	std::ptrdiff_t							difference_type;
			typedef	T*										pointer;
			typedef	T&										reference;
			typedef ft::random_access_iterator_tag			iterator_category;

		private:
			T _elem;
		
		public:
			
	};
} // namespace ft

#endif