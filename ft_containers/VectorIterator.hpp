/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:30:21 by dahpark           #+#    #+#             */
/*   Updated: 2022/06/19 23:44:36 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP_
#define VECTOR_ITERATOR_HPP_

#include "Iterator.hpp"

namespace ft {
	template <typename T>
	class vector_iterator {
		public:
			typedef T								value_type;
			typedef	std::ptrdiff_t					difference_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef ft::random_access_iterator_tag	iterator_category;

		private:
			pointer _elem;
		
		public:
			vector_iterator() : _elem(NULL) { }
			vector_iterator(pointer elem) : _elem(elem) { }
			vector_iterator(const vector_iterator& iter) : _elem(iter._elem) { }
			vector_iterator& operator=(const vector_iterator& iter) {
				if (this == &iter)
					return (*this);
				_elem = iter._elem;
				return (*this);
			}
			~vector_iterator() { }
			
			bool operator==(const vector_iterator& iter) {
				return (_elem == iter._elem);
			}
			bool operator!=(const vector_iterator& iter) {
				return (_elem != iter._elem);
			}

			reference operator*() {
				return (*_elem);
			}
			pointer operator->() const{
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
			difference_type operator-(const vector_iterator& iter) {
				return (_elem - iter._elem);
			}

			bool operator<(const vector_iterator& iter) {
				return (_elem < iter._elem);
			}
			bool operator>(const vector_iterator& iter) {
				return (_elem > iter._elem);
			}
			bool operator<=(const vector_iterator& iter) {
				return (_elem <= iter._elem);
			}
			bool operator>=(const vector_iterator& iter) {
				return (_elem >= iter._elem);
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
				return (*(_elem + n));
			}

			pointer get_elem() const{
				return (_elem);
			}
	};
} // namespace ft

#endif