/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:55:26 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/09 15:55:46 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	init_options(int ac, char **av)
{
	g_options.num_of_philo = ft_atoi(av[1]);
	g_options.time_to_die = ft_atoi(av[2]);
	g_options.time_to_eat = ft_atoi(av[3]);
	g_options.time_to_sleep = ft_atoi(av[4]);
	g_options.limit_count_eat = (ac == 6) ? ft_atoi(av[5]) : -1;
}

int		print_error(char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
	return (0);
}

void	print_change(int timestamp_in_ms, int philo_num, char *mes)
{
	ft_putnbr_fd(timestamp_in_ms, STDOUT_FILENO);
	ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putnbr_fd(philo_num, STDOUT_FILENO);
	ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putendl_fd(mes, STDOUT_FILENO);
}

int		check_options(int ac, char **av)
{
	int i;

	i = 1;
	if (ac != 5 && ac != 6)
		print_error("Incorrect number of params");
	while (av[i])
	{
		if (!ft_str_is_num(av[i]) || ft_atoi(av[i]) <= 0)
			print_error("Incorrect param format");
		if (i == 1 && ft_atoi(av[i]) > 200)
			print_error("Number of philos shouldn't be more than 200");
		if (i >= 2 && i <= 4 && ft_atoi(av[i]) < 60)
			print_error("Time shouldn't be less than 60");
		i++;
	}
	init_options(ac, av);
	return (1);
}
