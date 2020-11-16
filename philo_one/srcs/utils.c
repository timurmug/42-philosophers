/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:55:26 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/16 15:16:53 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		print_change(int id, char *mes)
{
	char		*time_str;
	char		*id_str;
	char		*strjoin;

	pthread_mutex_lock(&g_options.mutex_write);
	if (g_options.stop)
	{
		pthread_mutex_unlock(&g_options.mutex_write);
		return ;
	}
	time_str = ft_itoa(get_millisecs() - g_options.start_time);
	strjoin = ft_strdup(time_str);
	free(time_str);
	id_str = ft_itoa(id);
	strjoin = ft_strjoin_new(strjoin, " ");
	strjoin = ft_strjoin_new(strjoin, id_str);
	free(id_str);
	strjoin = ft_strjoin_new(strjoin, mes);
	ft_putstr_fd(strjoin, STDOUT_FILENO);
	free(strjoin);
	pthread_mutex_unlock(&g_options.mutex_write);
}

int			print_error(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	return (0);
}

int			check_options(int ac, char **av)
{
	int i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (print_error("Incorrect number of params\n"));
	while (av[i])
	{
		if (!ft_str_is_num(av[i]) || ft_atoi(av[i]) <= 0)
			return (print_error("Incorrect param format\n"));
		if (i == 1 && ft_atoi(av[i]) > 200)
			return (print_error("Number of philos shouldn't be more than 200\
			\n"));
		if (i >= 2 && i <= 4 && ft_atoi(av[i]) < 60)
			return (print_error("Time shouldn't be less than 60\n"));
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
