/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:14:01 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/10 11:58:27 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	else
		return (0);
}

int	ft_str_is_num(char *str)
{
	int j;

	j = 0;
	while (str[j])
		if (!ft_isdigit(str[j++]))
			return (0);
	return (1);
}

int	ft_atoi(const char *str)
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
