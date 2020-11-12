/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:27:48 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/12 11:14:31 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_takes_forks(t_philo *philo, int first, int second)
{
	pthread_mutex_lock(&g_options.forks_mutexes[first]);
	print_change(philo->id + 1, " has taken a fork\n", 1);
	pthread_mutex_lock(&g_options.forks_mutexes[second]);
	print_change(philo->id + 1, " has taken a fork\n", 1);
}

void	philo_breaks_forks(int first, int second)
{
	pthread_mutex_unlock(&g_options.forks_mutexes[first]);
	pthread_mutex_unlock(&g_options.forks_mutexes[second]);
}

void	philo_eats(t_philo *philo)
{
	int right;

	right = (philo->id + 1) % g_options.num_of_philo;
	if (philo->id % 2)
		philo_takes_forks(philo, philo->id, right);
	else
		philo_takes_forks(philo, right, philo->id);
	print_change(philo->id + 1, " is eating\n", 1);
	philo->meal_time = get_millisecs();
	ft_sleep(g_options.time_to_eat);
	if (philo->id % 2)
		philo_breaks_forks(right, philo->id);
	else
		philo_breaks_forks(philo->id, right);
}
