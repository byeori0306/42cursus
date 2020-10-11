/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:40:22 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/11 12:01:15 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*p;
	int		i;

	i = 0;
	if ((p = malloc(count * size)) == NULL)
		return (0);
	while (*p[i])
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
