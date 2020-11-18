/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:16:57 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/17 10:57:55 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, sizeof(char));
}

void			ft_putstr_fd(char *s, int fd)
{
	int i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}
