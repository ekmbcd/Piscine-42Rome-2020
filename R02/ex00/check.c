/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-gius <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:00:56 by mde-gius          #+#    #+#             */
/*   Updated: 2020/11/08 16:01:08 by mde-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_checkunits(char *str, char *to_search)
{
	int		i;

	i = 0;
	while (str[i] != ':')
	{
		if (str[i] == '\n')
		{
			return (0);
		}
		if (str[i] == to_search[0] && (str[i + 1] == ' ' ||
		str[i + 1] == ':' || str[i + 1] == '\t') && (i == 0))
		{
			while (str[i] != ':')
				i++;
			i++;
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			ft_prints(&str[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_checkteens(char *str, char to_search[2])
{
	int		i;

	i = 0;
	while (str[i] != ':')
	{
		if (str[i] == '\n' || str[i] == 0)
		{
			return (0);
		}
		if (str[i] == to_search[0] && str[i + 1] == to_search[1] &&
			(str[i + 2] < '0' || str[i + 2] > '9'))
		{
			while (str[i] != ':' && str[i])
				i++;
			i++;
			while (str[i] == ' ' && str[i])
				i++;
			ft_prints(&str[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_checktens(char *str, char to_search[2])
{
	int		i;

	i = 0;
	while (str[i] != ':')
	{
		if (str[i] == '\n' || str[i] == 0)
		{
			return (0);
		}
		if (str[i] == to_search[0] && str[i + 1] == '0' &&
			(str[i + 2] < '0' || str[i + 2] > '9'))
		{
			while (str[i] != ':' && str[i])
				i++;
			i++;
			while (str[i] == ' ' && str[i])
				i++;
			ft_prints(&str[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check100(char *str)
{
	int			i;

	i = 0;
	while (str[i] != ':')
	{
		if (str[i] == '\n' || str[i] == 0)
		{
			return (0);
		}
		if (str[i] == '1' && str[i + 1] == '0' && str[i + 2] == '0' &&
		(str[i + 3] < '0' || str[i + 3] > '9'))
		{
			while (str[i] != ':' && str[i])
				i++;
			i++;
			while (str[i] == ' ' && str[i])
				i++;
			ft_prints(&str[i]);
			return (1);
		}
		i++;
	}
	return (0);
}
