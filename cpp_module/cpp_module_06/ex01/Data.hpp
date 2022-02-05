/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:29:31 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/05 17:46:54 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP_
#define DATA_HPP_

#include <iostream>

class Data {
	private:
		std::string data;
	public:
		Data();
		Data(std::string data);
		Data(const Data& d);
		Data& operator=(const Data& d);
		~Data();

		std::string getData();
		uintptr_t serialize(Data *ptr);
		Data* deserialize(uintptr_t raw);	
};

#endif