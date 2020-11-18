/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:04:54 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/18 12:29:35 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	endless_check(t_philo *philo)
{
	while (1)
	{
		sem_wait(g_options.sem_time);
		if (get_millisecs() - philo->meal_time > g_options.time_to_die)
			break ;
		if (!philo->limit_count_eat)
		{
			sem_post(g_options.sem_time);
			sem_post(g_options.sem_count_eat);
			sem_wait(g_options.sem_die);
			exit(0);
		}
		sem_post(g_options.sem_time);
		usleep(10);
	}
}

void	*check_time(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	endless_check(philo);
	sem_post(g_options.sem_time);
	if (!g_options.stop && philo->limit_count_eat)
	{
		sem_wait(g_options.sem_die);
		print_change((philo->id) + 1, " died\n", 1);
		g_options.stop = 1;
		sem_post(g_options.sem_stop);
		sem_post(g_options.sem_die);
	}
	return (NULL);
}

void	philo_life(t_philo *philo)
{
	pthread_t	tid;

	pthread_create(&tid, NULL, check_time, philo);
	while (philo->limit_count_eat && !g_options.stop)
	{
		if (g_options.stop)
			break ;
		philo_eats(philo);
		if (g_options.stop)
			break ;
		print_change(philo->id + 1, " is sleeping\n", 0);
		ft_sleep(g_options.time_to_sleep);
		if (g_options.stop)
			break ;
		print_change(philo->id + 1, " is thinking\n", 0);
	}
	pthread_join(tid, NULL);
}

void	all_forks_create(void)
{
	t_philo		philo[g_options.num_of_philo];
	pid_t		pids[g_options.num_of_philo + 1];
	int			i;

	i = 0;
	while (i < g_options.num_of_philo)
	{
		philo[i].id = i;
		philo[i].meal_time = get_millisecs();
		philo[i].limit_count_eat = g_options.limit_count_eat;
		if ((pids[i] = fork()) == -1)
			fork_error();
		else if (pids[i] == 0)
			philo_life(&philo[i]);
		i++;
	}
	if (g_options.limit_count_eat != -1)
		check_count_eat(pids, i);
	sem_wait(g_options.sem_stop);
	i = 0;
	while (i <= g_options.num_of_philo)
		kill(pids[i++], SIGKILL);
}

int		main(int ac, char **av)
{
	sem_unlink("sem_forks");
	sem_unlink("sem_write");
	sem_unlink("sem_steward");
	sem_unlink("sem_time");
	sem_unlink("sem_die");
	sem_unlink("sem_stop");
	sem_unlink("sem_count_eat");
	if (!check_options(ac, av))
		return (1);
	all_forks_create();
	sem_close(g_options.sem_forks);
	sem_close(g_options.sem_write);
	sem_close(g_options.sem_steward);
	sem_close(g_options.sem_time);
	sem_close(g_options.sem_die);
	sem_close(g_options.sem_stop);
	sem_close(g_options.sem_count_eat);
	return (0);
}
