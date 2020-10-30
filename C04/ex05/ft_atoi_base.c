/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:05:09 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/28 15:51:27 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		length(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ignore(char *str)
{
	int i;
	int sign;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (sign < 0)
		write(1, "-", 1);
	return (i);
}

int		check_char(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		check_base(char *base)
{
	int		i;
	int		j;
	char	*pointer;
	char	selected;

	i = length(base);
	if (i <= 1)
		return (0);
	j = 0;
	while (j < i)
	{
		selected = base[j];
		if (selected == '-' || selected == '+')
			return (0);
		pointer = base + j + 1;
		while (*pointer != 0)
		{
			if (*pointer == selected)
				return (0);
			pointer++;
		}
		j++;
	}
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int j;
	int res;

	j = 0;
	res = 0;
	i = ignore(str);
	if (check_base(base) == 0)
		return (0);
	while (check_char(str[i], base))
	{
		j = 0;
		while (base[j])
		{
			if (base[j] == str[i])
				break ;
			j++;
		}
		res = (res * length(base)) + j;
		i++;
	}
	return (res);
}
