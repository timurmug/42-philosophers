/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:14:01 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/11 09:57:12 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int				ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	else
		return (0);
}

int				ft_str_is_num(char *str)
{
	int j;

	j = 0;
	while (str[j])
		if (!ft_isdigit(str[j++]))
			return (0);
	return (1);
}

int				ft_atoi(const char *str)
{
	int		number;
	int		negative;

	number = 0;
	negative = 1;
	while (*str == ' ' || *str == '\n'
	|| *str == '\f' || *str == '\v'
	|| *str == '\r' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	if (!((*str >= '0') && (*str <= '9')))
		return (0);
	while ((*str >= '0') && (*str <= '9'))
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * negative);
}

static size_t	ft_intlen(long long n)
{
	long long i;

	i = 0;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	return (++i);
}

char			*ft_itoa(long int n)
{
	size_t			len;
	size_t			i;
	long long		n2;
	char			*str;

	n2 = (long long)n;
	i = 0;
	if (n2 < 0)
	{
		i = 1;
		n2 *= -1;
	}
	len = ft_intlen(n2) + i;
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (NULL);
	str[len] = 0;
	while (len-- > i)
	{
		str[len] = n2 % 10 + '0';
		n2 /= 10;
	}
	if (i)
		str[0] = '-';
	return (str);
}
