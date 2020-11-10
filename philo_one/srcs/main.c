/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:51:12 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/10 15:54:07 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*philo_life(void *arg)
{
	t_philo	philo;

	philo = *(t_philo *)arg;
	while (philo.limit_count_eat--)
	{
		if (!philo_eats(&philo))
			break ;
		if (!check_time_from_meal(philo))
			break ;
		print_change(philo.meal_time, philo.id + 1, "is sleeping");
		ft_sleep(g_options.time_to_sleep);
		if (!check_time_from_meal(philo))
			break ;
		print_change(philo.meal_time, philo.id + 1, "is thinking");
		if (!check_time_from_meal(philo))
			break ;
	}
	return (NULL);
}

void	all_threads_create_join(pthread_t *tids)
{
	t_philo	philo[g_options.num_of_philo];
	int		i;

	i = 0;
	while (i < g_options.num_of_philo)
	{
		init_philo(&philo[i], i);
		pthread_create(&tids[i], NULL, philo_life, &philo[i]);
		i++;
	}
	i = 0;
	while (i < g_options.num_of_philo)
		pthread_join(tids[i++], NULL);
}

void	start(void)
{
	pthread_t		tids[g_options.num_of_philo];
	pthread_mutex_t	forks_mutexes[g_options.num_of_philo];
	int				i;

	init_forks_mutexes(forks_mutexes);
	all_threads_create_join(tids);
	i = 0;
	while (i < g_options.num_of_philo)
		pthread_mutex_destroy(&g_options.forks_mutexes[i++]);
}

int		main(int ac, char **av)
{
	if (!check_options(ac, av))
		return (1);
	start();
	pthread_mutex_destroy(&g_options.mutex);
	return (0);
}
