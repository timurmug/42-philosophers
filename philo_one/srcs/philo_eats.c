/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:27:48 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/10 15:54:32 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		check_time_from_meal(t_philo philo)
{
	long int	curr_time;

	curr_time = get_millisecs();
	if (curr_time - g_options.time_to_die < curr_time - philo.meal_time)
	{
		print_change(curr_time, philo.id + 1, "died");
		return (0);
	}
	return (1);
}

void	philo_breaks_forks(t_philo philo)
{
	if (philo.id == 0)
	{
		pthread_mutex_unlock(&g_options.forks_mutexes[g_options.num_of_philo \
			- 1]);
		pthread_mutex_unlock(&g_options.forks_mutexes[0]);
	}
	else if (philo.id == g_options.num_of_philo - 1)
	{
		pthread_mutex_unlock(&g_options.forks_mutexes[g_options.num_of_philo \
			- 1]);
		pthread_mutex_unlock(&g_options.forks_mutexes[g_options.num_of_philo \
			- 2]);
	}
	else
	{
		pthread_mutex_unlock(&g_options.forks_mutexes[philo.id - 1]);
		pthread_mutex_unlock(&g_options.forks_mutexes[philo.id]);
	}
}

int		philo_takes_forks(t_philo philo)
{
	if (philo.id == 0)
	{
		pthread_mutex_lock(&g_options.forks_mutexes[0]);
		if (!check_time_from_meal(philo))
			return (0);
		print_change(get_millisecs(), philo.id + 1, "has taken a fork");
		pthread_mutex_lock(&g_options.forks_mutexes[g_options.num_of_philo \
			- 1]);
		if (!check_time_from_meal(philo))
			return (0);
		print_change(get_millisecs(), philo.id + 1, "has taken a fork");
	}
	else if (philo.id == g_options.num_of_philo - 1)
	{
		pthread_mutex_lock(&g_options.forks_mutexes[g_options.num_of_philo \
			- 2]);
		if (!check_time_from_meal(philo))
			return (0);
		print_change(get_millisecs(), philo.id + 1, "has taken a fork");
		pthread_mutex_lock(&g_options.forks_mutexes[g_options.num_of_philo \
			- 1]);
		if (!check_time_from_meal(philo))
			return (0);
		print_change(get_millisecs(), philo.id + 1, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&g_options.forks_mutexes[philo.id]);
		if (!check_time_from_meal(philo))
			return (0);
		print_change(get_millisecs(), philo.id + 1, "has taken a fork");
		pthread_mutex_lock(&g_options.forks_mutexes[philo.id - 1]);
		if (!check_time_from_meal(philo))
			return (0);
		print_change(get_millisecs(), philo.id + 1, "has taken a fork");
	}
	return (1);
}

int		philo_eats(t_philo *philo)
{
	if (!check_time_from_meal(*philo))
		return (0);
	if (!philo_takes_forks(*philo))
		return (0);
	print_change(get_millisecs(), philo->id + 1, "is eating");
	philo->meal_time = get_millisecs();
	ft_sleep(g_options.time_to_eat);
	philo_breaks_forks(*philo);
	return (1);
}
