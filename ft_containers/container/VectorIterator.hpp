/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:30:21 by dahpark           #+#    #+#             */
/*   Updated: 2022/06/23 20:17:32 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP_
#define VECTOR_ITERATOR_HPP_

#include "../util/Iterator.hpp"

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
			pointer _ptr;
		
		public:
			vector_iterator() : _ptr(NULL) { }
			vector_iterator(pointer ptr) : _ptr(ptr) { }
			vector_iterator(const vector_iterator& iter) : _ptr(iter._ptr) { }
			vector_iterator& operator=(const vector_iterator& iter) {
				if (this == &iter)
					return (*this);
				_ptr = iter._ptr;
				return (*this);
			}
			~vector_iterator() { }
			
			bool operator==(const vector_iterator& iter) const {
				return (_ptr == iter._ptr);
			}
			bool operator!=(const vector_iterator& iter) const {
				return (_ptr != iter._ptr);
			}

			reference operator*() const {
				return (*_ptr);
			}
			pointer operator->() const{
				return (_ptr);
			}

			vector_iterator& operator++() {
				_ptr++;
				return (*this);
			}
			vector_iterator operator++(int) {
				vector_iterator temp(*this);
				_ptr++;
				return (temp);
			}
			vector_iterator& operator--() {
				_ptr--;
				return (*this);
			}
			vector_iterator operator--(int) {
				vector_iterator temp(*this);
				_ptr--;
				return (temp);
			}

			vector_iterator operator+(difference_type n) const {
				return vector_iterator(_ptr + n);
			}
			vector_iterator operator-(difference_type n) const {
				return vector_iterator(_ptr - n);
			}
			difference_type operator-(const vector_iterator& iter) const {
				return (_ptr - iter._ptr);
			}

			bool operator<(const vector_iterator& iter) const {
				return (_ptr < iter._ptr);
			}
			bool operator>(const vector_iterator& iter) const {
				return (_ptr > iter._ptr);
			}
			bool operator<=(const vector_iterator& iter) const {
				return (_ptr <= iter._ptr);
			}
			bool operator>=(const vector_iterator& iter) const {
				return (_ptr >= iter._ptr);
			}

			vector_iterator& operator+=(difference_type n) {
				_ptr += n;
				return (*this);
			}
			vector_iterator& operator-=(difference_type n) {
				_ptr -= n;
				return (*this);
			}
			
			reference operator[] (difference_type n) const {
				return (*(_ptr + n));
			}

			pointer get_ptr() const {
				return (_ptr);
			}
	};
} // namespace ft

#endif