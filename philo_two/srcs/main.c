/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:24:24 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/17 10:47:23 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	*check_time(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(g_options.sem_time);
		if (get_millisecs() - philo->meal_time > g_options.time_to_die)
			break ;
		sem_post(g_options.sem_time);
		usleep(10);
	}
	sem_post(g_options.sem_time);
	if (!g_options.stop && philo->limit_count_eat)
	{
		sem_wait(g_options.sem_die);
		print_change((philo->id) + 1, " died\n");
		g_options.stop = 1;
		sem_post(g_options.sem_die);
	}
	return (NULL);
}

void	*philo_life(void *arg)
{
	t_philo		*philo;
	pthread_t	tid;

	pthread_create(&tid, NULL, check_time, arg);
	philo = (t_philo *)arg;
	while (philo->limit_count_eat)
	{
		if (g_options.stop)
			break ;
		philo_eats(philo);
		if (g_options.stop)
			break ;
		print_change(philo->id + 1, " is sleeping\n");
		ft_sleep(g_options.time_to_sleep);
		if (g_options.stop)
			break ;
		print_change(philo->id + 1, " is thinking\n");
	}
	pthread_join(tid, NULL);
	return (NULL);
}

void	all_threads_create_join(void)
{
	t_philo		philo[g_options.num_of_philo];
	pthread_t	tids[g_options.num_of_philo];
	int			i;

	i = 0;
	while (i < g_options.num_of_philo)
	{
		philo[i].id = i;
		philo[i].meal_time = get_millisecs();
		philo[i].limit_count_eat = g_options.limit_count_eat;
		pthread_create(&tids[i], NULL, philo_life, &philo[i]);
		i++;
	}
	i = 0;
	while (i < g_options.num_of_philo)
		pthread_join(tids[i++], NULL);
}

int		main(int ac, char **av)
{
	sem_unlink("sem_forks");
	sem_unlink("sem_write");
	sem_unlink("sem_steward");
	sem_unlink("sem_time");
	sem_unlink("sem_die");
	if (!check_options(ac, av))
		return (1);
	all_threads_create_join();
	sem_close(g_options.sem_forks);
	sem_close(g_options.sem_write);
	sem_close(g_options.sem_steward);
	sem_close(g_options.sem_time);
	sem_close(g_options.sem_die);
	return (0);
}
