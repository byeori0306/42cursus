/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:19:15 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/11 13:39:15 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char *last = NULL;

	while (*s != '\0')
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	return ((char *)last);
}
