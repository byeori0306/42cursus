/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:57:35 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/21 23:07:55 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <numeric>
#include <algorithm>

Span::Span() : limit(0) { }

Span::Span(unsigned int n) : limit(n) { }

Span::Span(const Span& span) : limit(span.limit) {
	arr = span.arr;
}

Span& Span::operator=(const Span& span) {
	if (this == &span)
		return (*this);
	limit = span.limit;
	arr.clear();
	arr = span.arr;
	return (*this);
}

Span::~Span() { }

const char* Span::OutOfTheLimits::what() const throw() {
	return ("Already fully stored in the object.");
}

void	Span::addNumber(int n) {
	if (arr.size() < limit)
		arr.push_back(n);
	else
		throw OutOfTheLimits();
}

const char* Span::NoNumbers::what() const throw() {
	return ("There are no numbers stored, or only one.");
}

int trans(int n) {
	return (std::abs(n));
}

unsigned int	Span::shortestSpan() {
	if (arr.size() <= 1)
		throw NoNumbers();
	
	std::vector<int> arr2(arr);
	std::sort(arr2.begin(), arr2.end());
	std::adjacent_difference(arr2.begin(), arr2.end(), arr2.begin());
	std::transform(arr2.begin(), arr2.end(), arr2.begin(), trans);
	return (*min_element(arr2.begin(), arr2.end()));
}

unsigned int	Span::longestSpan() {
	if (arr.size() <= 1)
		throw NoNumbers();

	int smallest_element = *min_element(arr.begin(), arr.end());
	int largest_element  = *max_element(arr.begin(), arr.end());
	return (std::abs(largest_element - smallest_element));	
}
