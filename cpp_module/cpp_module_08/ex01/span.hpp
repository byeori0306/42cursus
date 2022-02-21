/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:57:38 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/21 22:27:29 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <iostream>
#include <vector>

class Span {
	private:
		unsigned int limit;
		std::vector<int> arr;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& span);
		Span& operator=(const Span& span);
		~Span();

		class OutOfTheLimits : public std::exception {
			public:
				const char* what() const throw();	
		};

		void	addNumber(int n);
		template <typename InputIt>
		void	addNumber(InputIt first, InputIt last) {
			if (limit >= arr.size() + std::distance(first, last))
				arr.insert(arr.end(), first, last);
			else
				throw OutOfTheLimits();
		}

		class NoNumbers : public std::exception {
			public:
				const char* what() const throw();	
		};

		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};

#endif