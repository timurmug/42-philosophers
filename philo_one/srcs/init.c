/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:35:17 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/11 14:36:36 by qtamaril         ###   ########.fr       */
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
	pthread_mutex_init(&g_options.write_mutex, NULL);
}

void	init_forks_mutexes(pthread_mutex_t *forks_mutexes)
{
	int i;

	i = 0;
	while (i < g_options.num_of_philo)
		pthread_mutex_init(&forks_mutexes[i++], NULL);
	g_options.forks_mutexes = forks_mutexes;
}

void	init_philo(t_philo *philo, int id)
{
	philo->id = id;
	philo->meal_time = get_millisecs();
	philo->limit_count_eat = g_options.limit_count_eat;
	pthread_mutex_init(&philo->philo_mutex, NULL);
}
