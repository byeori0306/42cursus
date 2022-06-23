/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeTraits.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:38:49 by dahpark           #+#    #+#             */
/*   Updated: 2022/06/20 15:27:05 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft {
	// is_integral
	template <class T>
	struct is_integral {
		public:
			static const bool value = false;
	};

	template <>
	struct is_integral<bool> {
		static const bool value = true;
	};
	
	template <>
	struct is_integral<char> {
		static const bool value = true;
	};

	template <>
	struct is_integral<char16_t> {
		static const bool value = true;
	};

	template <>
	struct is_integral<char32_t> {
		static const bool value = true;
	};

	template <>
	struct is_integral<signed char> {
		static const bool value = true;
	};

	template <>
	struct is_integral<short int> {
		static const bool value = true;
	};

	template <>
	struct is_integral<int> {
		static const bool value = true;
	};

	template <>
	struct is_integral<long int> {
		static const bool value = true;
	};

	template <>
	struct is_integral<long long int> {
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned char> {
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned short int> {
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned int> {
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned long int> {
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned long long int> {
		static const bool value = true;
	};

	// enable_if
	template <bool Cond, class T = void>
	struct enable_if {
	};

	template<class T>
	struct enable_if<true, T> { 
		typedef T type; 
	};
} // namespace ft 

#endif