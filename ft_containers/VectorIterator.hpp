/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:30:21 by dahpark           #+#    #+#             */
/*   Updated: 2022/06/15 15:39:01 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP_
#define VECTOR_ITERATOR_HPP_

#include "Iterator.hpp"

namespace ft {
	template <typename T>
	class vector_iterator {
		public:
			typedef typename T								value_type;
			typedef	std::ptrdiff_t							difference_type;
			typedef	typename T*								pointer;
			typedef	typename T&								reference;
			typedef ft::random_access_iterator_tag			iterator_category;

		private:
			pointer _elem;
		
		public:
			vector_iterator() : _elem(NULL) { }
			vector_iterator(pointer elem) : _elem(elem) { }
			vector_iterator(const vector_iterator& iter) : _elem(iter->_elem) { }
			vector_iterator& operator=(const vector_iterator& iter) {
				if (this == &iter)
					return *this;
				_elem = iter->_elem;
				return *this;
			}
			~vector_iterator() { }
			
			bool operator==(const vector_iterator& iter) {
				return (_elem == iter->elem);
			}
			bool operator!=(const vector_iterator& iter) {
				return (_elem != iter->elem);
			}

			reference operator*() {
				return (*_elem);
			}
			pointer operator->() {
				return (_elem);
			}

			vector_iterator& operator++() {
				_elem++;
				return (*this);
			}
			vector_iterator operator++(int) {
				vector_iterator temp(*this);
				_elem++;
				return (temp);
			}
			vector_iterator& operator--() {
				_elem--;
				return (*this);
			}
			vector_iterator operator--(int) {
				vector_iterator temp(*this);
				_elem--;
				return (temp);
			}

			vector_iterator operator+(difference_type n) {
				return vector_iterator(_elem + n);
			}
			vector_iterator operator-(difference_type n) {
				return vector_iterator(_elem - n);
			}
			vector_iterator operator-(const vector_iterator& iter) {
				return vector_iterator(_elem - iter->_elem);
			}

			bool operator<(const vector_iterator& iter) {
				return (_elem < iter->elem);
			}
			bool operator>(const vector_iterator& iter) {
				return (_elem > iter->elem);
			}
			bool operator<=(const vector_iterator& iter) {
				return (_elem <= iter->elem);
			}
			bool operator>=(const vector_iterator& iter) {
				return (_elem >= iter->elem);
			}

			vector_iterator& operator+=(difference_type n) {
				_elem += n;
				return (*this);
			}
			vector_iterator& operator-=(difference_type n) {
				_elem -= n;
				return (*this);
			}
			
			reference operator[] (difference_type n) {
				return (*(elem + n));
			}
	};
} // namespace ft

#endif