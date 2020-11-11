/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:54:39 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/11 16:25:11 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct		s_options
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				limit_count_eat;
	long int		start_time;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*forks_mutexes;
	int				stop;
}					t_options;

typedef struct		s_philo
{
	int				id;
	long int		meal_time;
	int				limit_count_eat;
	pthread_mutex_t	philo_mutex;
}					t_philo;

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

/*
** init.c
*/

void				init_options(int ac, char **av);
void				init_forks_mutexes(pthread_mutex_t *forks_mutexes);
void				init_philo(t_philo *philo, int id);

/*
** main.c
*/

void				*check_time(void *arg);
/*
** philo_eats.c
*/

void				philo_eats(t_philo *philo);

/*
** utils.c
*/

void				print_change(int id, char *mes, int needed_lock);
int					print_error(char *str);
int					check_options(int ac, char **av);
long int			get_millisecs(void);
void				ft_sleep(long int end_time);

t_options			g_options;

#endif
