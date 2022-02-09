/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:38:52 by dahpark           #+#    #+#             */
/*   Updated: 2022/02/09 14:54:01 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"
#include <iostream>

void	sed::change_content(std::string& content, std::string src, std::string dst, std::ofstream& file) {
	unsigned long	idx = 0;
	unsigned long	res = 0;

	while (true) {
		res = content.find(src, idx);

		if (res == std::string::npos) {
			file << content.substr(idx);
			return;
		}
		file << content.substr(idx, res - idx);
		file << dst;
		idx = res + src.length();
	}
}

int	sed::replace(char *_file_name, char *_s1, char *_s2) {
	std::string	file_name(_file_name);
	std::string	s1(_s1);
	std::string	s2(_s2);

	if (file_name.empty() || s1.empty() || s2.empty()) {
		std::cerr << "Empty string!" << std::endl;
		return (1);
	}

	std::ifstream ifile(file_name);
	if (ifile.fail()) {
		std::cerr << "Open file failed" << std::endl;
		return (1);
	}
	std::istreambuf_iterator<char> begin(ifile), end;
  	std::string buffer(begin, end);
	ifile.close();
		
	std::ofstream ofile(file_name);
	if (ofile.fail()) {
		std::cerr << "Open file failed" << std::endl;
		return (1);
	}
	sed::change_content(buffer, s1, s2, ofile);
	ofile.close();
	return (0);
}