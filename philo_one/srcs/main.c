/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:51:12 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/09 15:55:38 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*philo(void *arg)
{
	(void)arg;
	pthread_mutex_lock(&g_mutex);
	ft_putendl_fd("here", 1);
	pthread_mutex_unlock(&g_mutex);
	return (NULL);
}

void	threads(void)
{
	pthread_t	tid[g_options.num_of_philo];
	int			i;

	i = 0;
	while (i < g_options.num_of_philo)
	{
		pthread_create(&tid[i], NULL, philo, NULL);
		i++;
	}
	i = 0;
	while (i < g_options.num_of_philo)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (!check_options(ac, av))
		return (1);
	pthread_mutex_init(&g_mutex, NULL);
	threads();
	pthread_mutex_destroy(&g_mutex);
	return (0);
}
