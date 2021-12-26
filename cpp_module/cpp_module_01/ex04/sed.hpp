/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:38:55 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/26 14:26:22 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H_
#define SED_H_

#include <fstream>
#include <string>
#include <iterator>

class sed {
	private:
		static void	change_content(std::string& content, std::string src, std::string dst, std::ofstream& file);
	public:
		static int	replace(char *file_name, char *s1, char *s2);
};

#endif