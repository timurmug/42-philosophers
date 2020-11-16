/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_eats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:35:17 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/13 11:32:22 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	init_options(int ac, char **av)
{
	g_options.num_of_philo = ft_atoi(av[1]);
	g_options.time_to_die = ft_atoi(av[2]);
	g_options.time_to_eat = ft_atoi(av[3]);
	g_options.time_to_sleep = ft_atoi(av[4]);
	g_options.limit_count_eat = (ac == 6) ? ft_atoi(av[5]) : -1;
	g_options.start_time = get_millisecs();
	g_options.stop = 0;
	g_options.sem_forks = sem_open("sem_forks", O_CREAT, NULL, g_options.num_of_philo);
	g_options.sem_write = sem_open("sem_write", O_CREAT, NULL, 1);
	g_options.sem_steward = sem_open("sem_steward", O_CREAT, NULL, 1);
}

void	init_philo(t_philo *philo, int id)
{
	philo->id = id;
	philo->meal_time = get_millisecs();
	philo->limit_count_eat = g_options.limit_count_eat;
	// g_options.sem_steward = sem_open("sem_steward", O_CREAT, NULL, 1);
}

void	philo_eats(t_philo *philo)
{
	sem_wait(g_options.sem_steward);

	sem_wait(g_options.sem_forks);
	print_change(philo->id + 1, " has taken a fork\n", 1);
	sem_wait(g_options.sem_forks);
	print_change(philo->id + 1, " has taken a fork\n", 1);

	sem_post(g_options.sem_steward);


	print_change(philo->id + 1, " is eating\n", 1);
	philo->meal_time = get_millisecs();
	ft_sleep(g_options.time_to_eat);

	sem_post(g_options.sem_forks);
	sem_post(g_options.sem_forks);
}
