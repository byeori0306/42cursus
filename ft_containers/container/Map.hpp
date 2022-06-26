/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:56:13 by dahpark           #+#    #+#             */
/*   Updated: 2022/06/26 17:58:28 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP_
#define MAP_HPP_

#include <functional>
#include "../util/Utility.hpp"

namespace ft {
	template < class Key,
           class T,
           class Compare = std::less<Key>,
           class Alloc = std::allocator<pair<const Key,T>> >
	class map {
		/* member types */
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef ft::pair<const key_type, mapped_type>		value_type;
		typedef Compare										key_compare;
		// value_compare
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference 	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		// iterator
		// const_iterator
		// reverse_iterator
		// const_reverse_iterator
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;			

		/* member functions */
		// default constructor
		explicit map (const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()) { }
		// range constructor
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) { }
		// copy constructor
		map (const map& x) {
			
		}
		// destructor
		~map() {}
		// assignment operator overload
		map& operator= (const map& x) {
			
		}

		/* Iterators */
		iterator begin() {

		}
		const_iterator begin() const {
			
		}
		iterator end() {
			
		}
		const_iterator end() const {
			
		}
		reverse_iterator rbegin() {
			
		}
		const_reverse_iterator rbegin() const {
			
		}
		reverse_iterator rend() {
			
		}
		const_reverse_iterator rend() {
			
		}

		/* Capacity */
		bool empty() const {
			
		}
		size_type size() const {
			
		}
		size_type max_size() const {
			
		}

		/* Element access */
		mapped_type& operator[] (const key_type& k) {
			
		}

		/* Modifiers */
		// insert (single element)
		pair<iterator,bool> insert (const value_type& val) {

		}
		// insert (with hint)
		iterator insert (iterator position, const value_type& val) {
			
		}
		// insert (range)
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			
		}
		// erase (position)
		void erase (iterator position) {
			
		}
		// erase (key)
		size_type erase (const key_type& k) {
			
		}
		// erase (range)
		void erase (iterator first, iterator last) {
			
		}
		void swap (map& x) {
			
		}
		void clear() {
			
		}

		/* Observers */
		key_compare key_comp() const {
			
		}
		value_compare value_comp() const {
			
		}

		/* Operations */
		iterator find (const key_type& k) {
			
		}
		const_iterator find (const key_type& k) const {
			
		}
		size_type count (const key_type& k) const {
			
		}
		iterator lower_bound (const key_type& k) {
			
		}
		const_iterator lower_bound (const key_type& k) const {
			
		}
		iterator upper_bound (const key_type& k) {
			
		}
		const_iterator upper_bound (const key_type& k) const {
			
		}
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			
		}
		pair<iterator,iterator> equal_range (const key_type& k) {
			
		}

		/* Allocator */
		allocator_type get_allocator() const {
			
		}
	};
} // namespace ft

#endif