/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:55:26 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/10 16:09:42 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		print_change(long int timestamp_in_ms, int id, char *mes)
{
	pthread_mutex_lock(&g_options.mutex);
	ft_putnbr_fd(timestamp_in_ms, STDOUT_FILENO);
	ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putnbr_fd(id, STDOUT_FILENO);
	ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putendl_fd(mes, STDOUT_FILENO);
	pthread_mutex_unlock(&g_options.mutex);
}

int			print_error(char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
	return (0);
}

int			check_options(int ac, char **av)
{
	int i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (print_error("Incorrect number of params"));
	while (av[i])
	{
		if (!ft_str_is_num(av[i]) || ft_atoi(av[i]) <= 0)
			return (print_error("Incorrect param format"));
		if (i == 1 && ft_atoi(av[i]) > 200)
			return (print_error("Number of philos shouldn't be more than 200"));
		if (i >= 2 && i <= 4 && ft_atoi(av[i]) < 60)
			return (print_error("Time shouldn't be less than 60"));
		i++;
	}
	init_options(ac, av);
	return (1);
}

long int	get_millisecs(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void		ft_sleep(long int end_time)
{
	long int	start_time;

	start_time = get_millisecs();
	while (get_millisecs() - start_time < end_time)
		usleep(10);
}
