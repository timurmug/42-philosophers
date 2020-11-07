/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:51:12 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/07 11:37:52 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

#include <stdint.h>
#define BIG 1000000000UL
uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *count_to_big(void *arg)
{
	uint32_t i = 0;
	(void)arg;
	while (i++ < BIG)
	{
		// thread will wait here until it can get the lock
		pthread_mutex_lock(&lock);
		counter++;
		// other thread releases lock here
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t newthread;

	pthread_create(&newthread, NULL, count_to_big, NULL);
	count_to_big(NULL);
	pthread_join(newthread, NULL);

	ft_putnbr_fd(counter, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	return (0);
}
