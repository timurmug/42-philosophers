/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:27:48 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/16 15:29:02 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		philo_takes_forks(t_philo *philo, int first, int second)
{
	pthread_mutex_lock(&g_options.mutexes_forks[first]);
	if (g_options.stop)
	{
		pthread_mutex_unlock(&g_options.mutexes_forks[first]);
		return (0);
	}
	print_change(philo->id + 1, " has taken a fork\n");
	pthread_mutex_lock(&g_options.mutexes_forks[second]);
	if (g_options.stop)
	{
		pthread_mutex_unlock(&g_options.mutexes_forks[second]);
		pthread_mutex_unlock(&g_options.mutexes_forks[first]);
		return (0);
	}
	print_change(philo->id + 1, " has taken a fork\n");
	return (1);
}

void	philo_breaks_forks(t_philo *philo, int left, int right)
{
	if (philo->id % 2)
	{
		pthread_mutex_unlock(&g_options.mutexes_forks[right]);
		pthread_mutex_unlock(&g_options.mutexes_forks[left]);
	}
	else
	{
		pthread_mutex_unlock(&g_options.mutexes_forks[left]);
		pthread_mutex_unlock(&g_options.mutexes_forks[right]);
	}
}

void	philo_eats(t_philo *philo)
{
	int right;

	right = (philo->id + 1) % g_options.num_of_philo;
	if (philo->id % 2)
	{
		if (!philo_takes_forks(philo, philo->id, right))
			return ;
	}
	else
	{
		if (!philo_takes_forks(philo, right, philo->id))
			return ;
	}
	if (g_options.stop)
	{
		philo_breaks_forks(philo, philo->id, right);
		return ;
	}
	print_change(philo->id + 1, " is eating\n");
	philo->limit_count_eat--;
	pthread_mutex_lock(&g_options.mutex_time);
	philo->meal_time = get_millisecs();
	pthread_mutex_unlock(&g_options.mutex_time);
	ft_sleep(g_options.time_to_eat);
	philo_breaks_forks(philo, philo->id, right);
}
