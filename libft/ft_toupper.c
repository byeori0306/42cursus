/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:48:49 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/08 20:46:55 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	   	c -= 32;
	return c;
}

int main(void)
{
	printf("%c\n", ft_toupper('A'));
	printf("%c\n", toupper('A'));
}
