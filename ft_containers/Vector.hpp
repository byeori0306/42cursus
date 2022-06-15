/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:17:32 by dahpark           #+#    #+#             */
/*   Updated: 2022/05/10 18:16:52 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>
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
			/*
			typedef _	iterator;
			typedef _	const_iterator;
			typedef _	reverse_iterator;
			typedef _	const_reverse_iterator;
			typedef _	difference_type;
			*/
			typedef size_t										size_type;
		
		private:
			allocator_type	_alloc;
			pointer			_container;
			size_type		_size;
			size_type		_capacity;
		
		public:
			/* Member functions */
			// default constructor
			explicit vector (const allocator_type& alloc = allocator_type()): _alloc(alloc), _container(nullptr), _size(0), _capacity(0) { }
			// fill constructor
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()): _alloc(alloc), _container(alloc.allocate(n)), _size(n), _capacity(n) {
					int i = 0;
					while (i < _size) {
						_alloc.construct(_container + i, val);
						i++;
					}
				}
			// range constructor
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type()): _alloc(alloc) {
						_size = last - first;
						_capacity = size;
						_container = _alloc.allocate(_size);
						
						int i = 0;
						while (i < _size) {
							_alloc.construct(_container, *first);
							_container++;
							first++;
							i++;
						}
					}
			// copy constructor
			vector (const vector& x) : _alloc(alloc), _container(alloc.allocate(x._capacity)), _size(x._size), _capacity(x.capacity) {
				int i = 0;
				const_iterator start = x.begin();

				while (i < size) {
					_alloc.construct(_container, start);
					_container++;
					start++;
					i++;
				}
			}
			// destructor
			~vector() {
				_alloc.deallocate(_container, capacity());
			}
			vector& operator= (const vector& x) {
				if (x == *this)
					return (*this);
					
				_alloc.deallocate(_container, capacity());
				_alloc.allocate(x._capacity);
				_size = x.size;
				_capacity = x.capacity;
				
				int i = 0;
				const_iterator start = x.begin();

				while (i < size) {
					_alloc.construct(_container, start);
					_container++;
					start++;
					i++;
				}
				
				return (*this);
			}

			/* iterators */
			iterator begin() {
				return (_container);
			}
			const_iterator begin() const {
				return (_container);
			}
			iterator end() {
				return (begin() + _size);
			}
			const_iterator end() const {
				return (begin() + _size);
			}
			reverse_iterator rbegin() {
				return (begin() + _size);
			}
			const_reverse_iterator rbegin() const {
				return (begin() + _size);
			}
			reverse_iterator rend() {
				return (begin());
			}
			const_reverse_iterator rend() const {
				return (begin());
			}
			
			/* capacity */
			size_type size() const {
				return (_size);
			}
			size_type max_size() const {
				return (_alloc.max_size());
			}
			void resize (size_type n, value_type val = value_type()) {
				// if  (n > max_size())
				// 예외처리
				int diff = n - _size;
				if (diff < 0) {
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
				// if  (n > max_size())
				// 예외처리
				if (n <= _capacity)
					return;
				new_container = _alloc.allocate(n);
				const_iterator start = begin();
				int i = 0;
				while (i < _size) {
					_alloc.construct(new_container, start);
					new_container++;
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
				// if (n < 0 || n >= _size)
					// out_of_range
				return (*(_container + n));
			}
			const_reference at (size_type n) const {
				// if (n < 0 || n >= _size)
					// out_of_range
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
			  void assign (InputIterator first, InputIterator last) { }
			// fill
			void assign (size_type n, const value_type& val) {
				clear();
				if (n > _capacity)
					reserve(n);
				while (n--)
					push_back(val);
			}
			void push_back (const value_type& val) {
				// if (_size == _capacity)
				// capacity 늘리기
				_alloc.construct(_container + _size, val);
				size++;
			}
			void pop_back() {
				size--;
				_alloc.destroy(_container + _size);
			}
			// single element
			iterator insert (iterator position, const value_type& val) { }
			// fill
			void insert (iterator position, size_type n, const value_type& val) { }
			// range
			template <class InputIterator>
			  void insert (iterator position, InputIterator first, InputIterator last) { }
			iterator erase (iterator position) { }
			iterator erase (iterator first, iterator last) { }
			void swap (vector& x) { }
			void clear() {
				int i = 0;
				while (i < _size) {
					_alloc.destroy(_container + i);
					i++;
				}
			}

			/* Allocator */
			allocator_type get_allocator() const {
				return (_alloc);
			}
	};
} // namespace ft

#endif