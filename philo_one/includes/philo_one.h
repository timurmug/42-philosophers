/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:54:39 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/10 15:53:30 by qtamaril         ###   ########.fr       */
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
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks_mutexes;
}					t_options;

typedef struct		s_philo
{
	int				id;
	long int		meal_time;
	int				limit_count_eat;
}					t_philo;

/*
** ft_check_num.c and ft_putall.c
*/

int					ft_atoi(const char *str);
int					ft_str_is_num(char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(long int n, int fd);

/*
** init.c
*/

void				init_options(int ac, char **av);
void				init_forks_mutexes(pthread_mutex_t *forks_mutexes);
void				init_philo(t_philo *philo, int id);

/*
** philo_eats.c
*/

int					check_time_from_meal(t_philo philo);
int					philo_eats(t_philo *philo);

/*
** utils.c
*/

int					print_error(char *str);
void				print_change(long int timestamp_in_ms, int id, char *mes);
int					check_options(int ac, char **av);
long int			get_millisecs(void);
void				ft_sleep(long int end_time);

t_options			g_options;

#endif
