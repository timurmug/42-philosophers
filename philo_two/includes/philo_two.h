/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:54:39 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/12 11:37:18 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

// # include <unistd.h>
// # include <pthread.h>
// # include <stdlib.h>
// # include <sys/time.h>

typedef struct		s_options
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				limit_count_eat;
	long int		start_time;
	// pthread_mutex_t	write_mutex;
	// pthread_mutex_t	*forks_mutexes;
	// int				stop;
}					t_options;

// typedef struct		s_philo
// {
// 	int				id;
// 	long int		meal_time;
// 	int				limit_count_eat;
	// pthread_mutex_t	philo_mutex;
// }					t_philo;

/*
** ft_num.c
*/

int					ft_atoi(const char *str);
int					ft_str_is_num(char *str);
char				*ft_itoa(long int n);

/*
** ft_put.c
*/

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);

/*
** ft_str.c
*/

size_t				ft_strlen(char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(char *s);
char				*ft_strjoin_new(char *s1, char *s2);

t_options			g_options;

#endif
