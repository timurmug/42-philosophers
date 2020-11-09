/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:54:39 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/09 15:57:41 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct	s_options
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			limit_count_eat;
}				t_options;

/*
** ft_check_num.c and ft_putall.c
*/

int				ft_atoi(const char *str);
int				ft_str_is_num(char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** utils.c
*/

int				print_error(char *str);
void			print_change(int timestamp_in_ms, int philo_num, char *mes);
int				check_options(int ac, char **av);

t_options		g_options;
pthread_mutex_t	g_mutex;

#endif
