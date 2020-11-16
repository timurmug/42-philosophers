/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:35:17 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/16 14:51:53 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	init_options(int ac, char **av)
{
	g_options.num_of_philo = ft_atoi(av[1]);
	g_options.time_to_die = ft_atoi(av[2]);
	g_options.time_to_eat = ft_atoi(av[3]);
	g_options.time_to_sleep = ft_atoi(av[4]);
	g_options.limit_count_eat = (ac == 6) ? ft_atoi(av[5]) : -1;
	g_options.start_time = get_millisecs();
	g_options.stop = 0;
	pthread_mutex_init(&g_options.mutex_write, NULL);
	pthread_mutex_init(&g_options.mutex_die, NULL);
	pthread_mutex_init(&g_options.mutex_time, NULL);
}

void	init_forks_mutexes(pthread_mutex_t *forks_mutexes)
{
	int i;

	i = 0;
	while (i < g_options.num_of_philo)
		pthread_mutex_init(&forks_mutexes[i++], NULL);
	g_options.mutexes_forks = forks_mutexes;
}
