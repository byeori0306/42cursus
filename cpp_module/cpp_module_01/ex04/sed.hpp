/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:38:55 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/24 23:45:03 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
#define SED_H

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