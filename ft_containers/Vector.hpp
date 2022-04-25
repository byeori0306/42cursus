/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:17:32 by dahpark           #+#    #+#             */
/*   Updated: 2022/04/25 16:32:22 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector {
		private:
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			/*
			typedef _	iterator;
			typedef _	const_iterator;
			typedef _	reverse_iterator;
			typedef _	const_reverse_iterator;
			typedef _	difference_type;
			*/
			typedef size_t										size_type;
	};
}

#endif