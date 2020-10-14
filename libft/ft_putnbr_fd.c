/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 21:34:56 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/14 22:09:48 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nbr(int n, int fd)
{
	if (n <= 0)
		return ;
	else
	{
		print_nbr(n / 10, fd);
		n = (n % 10) + 48;
		write(fd, &n, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int input;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n < 0)
	{
		input = n * (-1);
		write(fd, "-", 1);
	}
	else
		input = n;
	print_nbr(n, fd);
}
