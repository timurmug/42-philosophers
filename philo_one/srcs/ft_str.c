/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:15:38 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/11 10:15:52 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *s)
{
	int		length;
	char	*str;

	length = ft_strlen(s);
	str = NULL;
	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	ft_strcpy(str, s);
	return (str);
}

char	*ft_strjoin_new(char *s1, char *s2)
{
	char		*strjoin;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	strjoin = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	if (!(strjoin = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[j])
		strjoin[i++] = s1[j++];
	free(s1);
	j = 0;
	while (s2[j])
		strjoin[i++] = s2[j++];
	strjoin[i] = '\0';
	return (strjoin);
}
