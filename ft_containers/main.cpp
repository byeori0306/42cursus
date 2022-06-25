/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:42:50 by dahpark           #+#    #+#             */
/*   Updated: 2022/06/25 21:28:46 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "test/Test.hpp"
 
int main(void) {
	test_vector();
	test_vector_iterator();
	test_reverse_iterator_with_vector();
	test_stack();
}