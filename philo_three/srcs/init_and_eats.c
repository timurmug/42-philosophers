/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_eats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:35:17 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/18 12:28:57 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	check_count_eat(pid_t *pids, int i)
{
	if ((pids[i] = fork()) == -1)
		fork_error();
	else if (pids[i] == 0)
	{
		i = -1;
		while (++i < g_options.num_of_philo)
			sem_wait(g_options.sem_count_eat);
		sem_post(g_options.sem_stop);
		exit(0);
	}
}

int		init_options2(void)
{
	if ((g_options.sem_time = sem_open("sem_time", \
	O_CREAT, NULL, 1)) == SEM_FAILED)
		return (0);
	if ((g_options.sem_die = sem_open("sem_die", \
	O_CREAT, NULL, 1)) == SEM_FAILED)
		return (0);
	if ((g_options.sem_stop = sem_open("sem_stop", \
	O_CREAT, NULL, 0)) == SEM_FAILED)
		return (0);
	if ((g_options.sem_count_eat = sem_open("sem_count_eat", \
	O_CREAT, NULL, 0)) == SEM_FAILED)
		return (0);
	return (1);
}

int		init_options(int ac, char **av)
{
	g_options.num_of_philo = ft_atoi(av[1]);
	g_options.time_to_die = ft_atoi(av[2]);
	g_options.time_to_eat = ft_atoi(av[3]);
	g_options.time_to_sleep = ft_atoi(av[4]);
	g_options.limit_count_eat = (ac == 6) ? ft_atoi(av[5]) : -1;
	g_options.start_time = get_millisecs();
	g_options.stop = 0;
	if ((g_options.sem_forks = sem_open("sem_forks", \
	O_CREAT, NULL, g_options.num_of_philo)) == SEM_FAILED)
		return (0);
	if ((g_options.sem_write = sem_open("sem_write", \
	O_CREAT, NULL, 1)) == SEM_FAILED)
		return (0);
	if ((g_options.sem_steward = sem_open("sem_steward", \
	O_CREAT, NULL, 1)) == SEM_FAILED)
		return (0);
	if (!init_options2())
		return (0);
	return (1);
}

int		philo_takes_forks(t_philo *philo)
{
	sem_wait(g_options.sem_steward);
	sem_wait(g_options.sem_forks);
	if (g_options.stop)
	{
		sem_post(g_options.sem_forks);
		sem_post(g_options.sem_steward);
		return (0);
	}
	print_change(philo->id + 1, " has taken a fork\n", 0);
	sem_wait(g_options.sem_forks);
	if (g_options.stop)
	{
		sem_post(g_options.sem_forks);
		sem_post(g_options.sem_forks);
		sem_post(g_options.sem_steward);
		return (0);
	}
	print_change(philo->id + 1, " has taken a fork\n", 0);
	sem_post(g_options.sem_steward);
	return (1);
}

void	philo_eats(t_philo *philo)
{
	if (!philo_takes_forks(philo))
		return ;
	print_change(philo->id + 1, " is eating\n", 0);
	philo->limit_count_eat--;
	if (!philo->limit_count_eat)
	{
		sem_post(g_options.sem_forks);
		sem_post(g_options.sem_forks);
	}
	sem_wait(g_options.sem_time);
	philo->meal_time = get_millisecs();
	sem_post(g_options.sem_time);
	ft_sleep(g_options.time_to_eat);
	sem_post(g_options.sem_forks);
	sem_post(g_options.sem_forks);
}
