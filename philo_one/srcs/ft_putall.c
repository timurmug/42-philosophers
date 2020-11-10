/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:16:57 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/10 11:58:06 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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

void			ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

static void		ft_putnbr_recursion(long long nb, int fd)
{
	if (nb > 9)
		ft_putnbr_recursion(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void			ft_putnbr_fd(long int n, int fd)
{
	long long	nb;

	nb = (long long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	ft_putnbr_recursion(nb, fd);
}
