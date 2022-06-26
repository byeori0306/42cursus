/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:21:40 by dahpark           #+#    #+#             */
/*   Updated: 2022/06/26 13:15:10 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP_
#define UTILITY_HPP_

namespace ft {
	/* pair */
	template <class T1, class T2>
	struct pair {
		public:
			/* member types */
			typedef T1	first_type;
			typedef T2	second_type;

			/* member variables */
			first_type	first;
			second_type	second;			
		
			/* constructor */
			// default
			pair() : first(first_type()), second(second_type()) { };
			// copy
			template<class U, class V>
			  pair (const pair<U, V>& pr) : first(pr.first), second(pr.second) { };
			// initialization	
			pair (const first_type& a, const second_type& b) : first(a), second(b) { };

			~pair() { };

			// assignment operator overload
			pair& operator= (const pair& pr) {
				first = pr.first;
				second = pr.second;
				return (*this);
			};
	};

	/* relational operators */
	template <class T1, class T2>
	  bool operator== (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		retun ((lhs.first == rhs.first) && (lhs.second == rhs.second));
	  };
	template <class T1, class T2>
	  bool operator!= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (!(lhs == rhs));
	  };
	template <class T1, class T2>
	  bool operator<  (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (lhs.first < rhs.first || lhs.second < rhs.second);
	  };
	template <class T1, class T2>
	  bool operator<= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (!(rhs < lhs));
	  };
	template <class T1, class T2>
	  bool operator>  (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (rhs < lhs);
	  };
	template <class T1, class T2>
	  bool operator>= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (!(lhs < rhs));
	  };

	/* make_pair */
	template <class T1,class T2>
	  pair<T1, T2> make_pair (T1 x, T2 y) {
	  	return (pair<T1, T2>(x, y));
	  }
} // namespace ft

#endif