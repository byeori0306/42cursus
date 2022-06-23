/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:20:41 by dahpark           #+#    #+#             */
/*   Updated: 2022/06/23 21:21:27 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP_
#define STACK_HPP_

#include "Vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {
		private:
			/* Member types */
			typedef T			value_type;
			typedef Container 	container_type;
			typedef size_t		size_type;	
		
		protected:
			container_type _container;

		public:
			/* Member functions */
			explicit stack (const container_type& container = container_type()) : _container(container) { }
			~stack() { }
			bool empty() const {
				return (_container.empty());
			}
			size_type size() const {
				return (_container.size());
			}
			const value_type& top() const {
				return (_container.back());
			}
			void push (const value_type& val) {
				_container.push_back(val);
			}
			void pop() {
				_container.pop_back();
			}
	};
	
	/* Non-member function overloads */
	// relational operators
	template <class T, class Container>
		bool operator== (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return (lhs._container == rhs._container);
		}
	template <class T, class Container>
		bool operator!= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return (lhs._container != rhs._container);
		}
	template <class T, class Container>
		bool operator<  (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return (lhs._container < rhs._container);
		}
	template <class T, class Container>
		bool operator<= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return (lhs._container <= rhs._container);
		}
	template <class T, class Container>
		bool operator>  (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return (lhs._container > rhs._container);
		}
	template <class T, class Container>
		bool operator>= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return (lhs._container >= rhs._container);
		}
} // namespace ft

#endif