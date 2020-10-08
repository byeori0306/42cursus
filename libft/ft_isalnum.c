/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:29:52 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/08 19:39:10 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int ft_isalnum(int c)
{
	if (isalpha(c) || isdigit(c))
		return (1);
	return (0);
}

int main(void)
{
	printf("%d\n", isalnum('A')); 
	printf("%d\n", ft_isalnum('A')); 
}
