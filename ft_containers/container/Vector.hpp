/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:17:32 by dahpark           #+#    #+#             */
/*   Updated: 2022/06/25 20:20:15 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>
#include <stdexcept>
#include "../util/TypeTraits.hpp"
#include "../util/Algorithm.hpp"
#include "../util/Iterator.hpp"
#include "VectorIterator.hpp"

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			/* Member types */
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::vector_iterator<value_type>				iterator;
			typedef ft::const_vector_iterator<value_type>		const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;
		
		private:
			allocator_type	_alloc;
			pointer			_container;
			size_type		_size;
			size_type		_capacity;
		
		public:
			/* Member functions */
			// default constructor
			explicit vector (const allocator_type& alloc = allocator_type()): _alloc(alloc), _container(_alloc.allocate(0)), _size(0), _capacity(0) { }
			// fill constructor
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()): _alloc(alloc), _container(_alloc.allocate(n)), _size(n), _capacity(n) {
					size_type i = 0;
					while (i < _size) {
						_alloc.construct(_container + i, val);
						i++;
					}
				}
			// range constructor
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
					: _alloc(alloc), _container(_alloc.allocate(0)), _size(0), _capacity(0) {
						assign(first, last);
					}
			// copy constructor
			vector (const vector& x) : _alloc(x._alloc), _container(_alloc.allocate(0)), _size(0), _capacity(0) {
				*this = x;
			}
			// destructor
			~vector() {
				clear();
				_alloc.deallocate(_container, capacity());
			}
			vector& operator= (const vector& x) {
				assign(x.begin(), x.end());
				return (*this);
			}

			/* iterators */
			iterator begin() {
				return (iterator(_container));
			}
			const_iterator begin() const {
				return (const_iterator(_container));
			}
			iterator end() {
				return (iterator(begin() + _size));
			}
			const_iterator end() const {
				return (const_iterator(begin() + _size));
			}
			reverse_iterator rbegin() {
				return (reverse_iterator(begin() + _size));
			}
			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(begin() + _size));
			}
			reverse_iterator rend() {
				return (reverse_iterator(begin()));
			}
			const_reverse_iterator rend() const {
				return (const_reverse_iterator(begin()));
			}
			
			/* capacity */
			size_type size() const {
				return (_size);
			}
			size_type max_size() const {
				return (_alloc.max_size());
			}
			void resize (size_type n, value_type val = value_type()) {
				int diff = n - _size;
				if (diff < 0) {
					diff *= -1;
					while (diff--) {
						_alloc.destroy(_container + _size);
						_size--;
					}
				} else if (diff > 0) {
					if (n > _capacity)
						reserve(n);
					while (diff--) {
						_alloc.construct(_container + _size, val);
						_size++;
					}
				}
			}
			size_type capacity() const {
				return (_capacity);
			}
			bool empty() const {
				if (_size == 0)
					return (1);
				return (0);
			}
			void reserve (size_type n) {
				if (n > max_size())
					throw std::length_error("Exceed max size");
				if (n <= _capacity)
					return;
				pointer new_container = _alloc.allocate(n);
				iterator start = begin();
				size_type i = 0;
				while (i < _size) {
					_alloc.construct(new_container + i, *start);
					start++;
					i++;
				}
				_alloc.deallocate(_container, _capacity);
				_container = new_container;
				_capacity = n;
			}

			/* Element access */
			reference operator[] (size_type n) {
				return (*(_container + n));
			}
			const_reference operator[] (size_type n) const {
				return (*(_container + n));
			}
			reference at (size_type n) {
				if (n < 0 || n >= _size)
					throw std::out_of_range("vector");
				return (*(_container + n));
			}
			const_reference at (size_type n) const {
				if (n < 0 || n >= _size)
					throw std::out_of_range("vector");
				return (*(_container + n));
			}
			reference front() { 
				return (*_container);
			}
			const_reference front() const {
				return (*_container);
			}
			reference back() {
				return (*(_container + _size - 1));
			}
			const_reference back() const {
				return (*(_container + _size - 1));
			}

			/* modifiers */
			// range
			template <class InputIterator>
			  void assign (InputIterator first, InputIterator last, 
			  typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
				clear();
				size_type n = last - first;
				if (n > _capacity)
					reserve(n);
				for (InputIterator iter = first; iter != last; iter++)
					push_back(*iter);
			  }
			// fill
			void assign (size_type n, const value_type& val) {
				clear();
				if (n > _capacity)
					reserve(n);
				while (n--)
					push_back(val);
			}
			void push_back (const value_type& val) {
				if (_size == _capacity)
					_size == 0 ? reserve(1) : reserve(_size * 2);
				_alloc.construct(_container + _size, val);
				_size++;
			}
			void pop_back() {
				_alloc.destroy(_container + _size);
				_size--;
			}
			// single element
			iterator insert (iterator position, const value_type& val) {
				pointer new_container = _alloc.allocate(_size + 1);
				size_type idx = 0;
				for (iterator iter = begin(); iter != position; iter++) {
					_alloc.construct(new_container + idx, *iter);
					idx++;
				}
				size_type pos = idx++;
				for (iterator iter = position; iter != end(); iter++) {
					_alloc.construct(new_container + idx, *iter);
					idx++;
				}
				*(new_container + pos) = val;
				size_type tmp = _size + 1;
				clear();
				_alloc.deallocate(_container, _capacity);
				_container = new_container;
				_size = tmp;
				_capacity = _size;
				return (begin() + pos);
			}
			// fill
			void insert (iterator position, size_type n, const value_type& val) {
				pointer new_container = _alloc.allocate(_size + n);
				size_type idx = 0;
				for (iterator iter = begin(); iter != position; iter++) {
					_alloc.construct(new_container + idx, *iter);
					idx++;
				}
				size_type pos = idx;
				idx += n;
				for (iterator iter = position; iter != end(); iter++) {
					_alloc.construct(new_container + idx, *iter);
					idx++;
				}
				for (size_type i = 0; i < n; i++) {
					_alloc.construct(new_container + pos, val);
					pos++;
				}
				size_type tmp = _size + n;
				clear();
				_alloc.deallocate(_container, _capacity);
				_container = new_container;
				_size = tmp;
				_capacity = _size;
			}
			// range
			template <class InputIterator>
			  void insert (iterator position, InputIterator first, InputIterator last,
			  typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
					size_type n = last - first;
					pointer new_container = _alloc.allocate(_size + n);
					size_type idx = 0;
					for (iterator iter = begin(); iter != position; iter++) {
						_alloc.construct(new_container + idx, *iter);
						idx++;
					}
					size_type pos = idx;
					idx += n;
					for (iterator iter = position; iter != end(); iter++) {
						_alloc.construct(new_container + idx, *iter);
						idx++;
					}
					for (InputIterator iter = first; iter != last; iter++) {
						try {
							_alloc.construct(new_container + pos, *iter);
							pos++;
						} catch (...) {
							while (idx--)
								_alloc.destroy(new_container + idx);
							_alloc.deallocate(new_container, _size + n);
							throw std::exception();
							return;
						}	
					}
					size_type tmp = _size + n;
					clear();
					_alloc.deallocate(_container, _capacity);
					_container = new_container;
					_size = tmp;
					_capacity = _size;
			  }
			iterator erase (iterator position) {
				size_type idx = 0;
				for (iterator iter = begin(); iter != position; iter++)
					idx++;
				_alloc.destroy(position.get_ptr());
				for (iterator iter = position + 1; iter != end(); iter++) {
					*(_container + idx) = *iter;
					idx++;
				}
				_size--;
				return (position);
			}
			iterator erase (iterator first, iterator last) {
				size_type idx = 0;
				for (iterator iter = begin(); iter != first; iter++)
					idx++;
				for (iterator iter = first; iter != last; iter++)
					_alloc.destroy(iter.get_ptr());
				for (iterator iter = last; iter != end(); iter++) {
					*(_container + idx) = *iter;
					idx++;
				}
				_size = idx;
				return (first);
			}
			void swap (vector& x) {
				allocator_type tmp_alloc = _alloc;
				pointer tmp_container = _container;
				size_type tmp_size = _size;
				size_type tmp_capacity = _capacity;
				_alloc = x._alloc;
				_container = x._container;
				_size = x._size;
				_capacity = x._capacity;
				x._alloc = tmp_alloc;
				x._container = tmp_container;
				x._size = tmp_size;
				x._capacity = tmp_capacity;
			}
			void clear() {
				size_type i = 0;
				while (i < _size) {
					_alloc.destroy(_container + i);
					i++;
				}
				_size = 0;
			}

			/* Allocator */
			allocator_type get_allocator() const {
				return (_alloc);
			}
	};

	/* Non-member function overloads */
	// relational operators
	template <class T, class Alloc>
	  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		  if (lhs.size() != rhs.size())
		  	return (false);
		  return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	  }
	
	template <class T, class Alloc>
	  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		  return (!(lhs == rhs));
	  }
	  
	template <class T, class Alloc>
	  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		  return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	  }

	template <class T, class Alloc>
	  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		  return (!(rhs < lhs));
	  }

	template <class T, class Alloc>
	  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		  return (rhs < lhs);
	  }
	
	template <class T, class Alloc>
	  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		  return (!(lhs < rhs));
	  }

	// swap
	template <class T, class Alloc>
	  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		  x.swap(y);
	  }
	
} // namespace ft

#endif