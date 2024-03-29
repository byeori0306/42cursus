/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 21:05:33 by dahpark           #+#    #+#             */
/*   Updated: 2021/09/20 17:53:26 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	tb;

	if (basic_check(argc, argv) < 0)
		return (0);
	if (init(argc, argv, &tb) < 0)
		return (finish_dinning(&tb));
	if (prepare_forks(&tb) < 0)
		return (finish_dinning(&tb));
	if (invite_philos(&tb) < 0)
		return (finish_dinning(&tb));
	finish_dinning(&tb);
	return (0);
}
