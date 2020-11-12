/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-gius <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:40:38 by mde-gius          #+#    #+#             */
/*   Updated: 2020/11/08 15:52:22 by mde-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_handleten(char *num, char *line)
{
	if (num[0] == '1')
	{
		if (ft_checkteens(line, num))
			return (1);
	}
	else if (ft_checktens(line, num) != 0)
		return (1);
	return (0);
}

int		ft_insidesearch(char *num, int len, char *line)
{
	if (len == 1)
	{
		if (ft_checkunits(line, num) != 0)
			return (1);
	}
	else if (len == 2)
	{
		if (num[0] == '1')
		{
			if (ft_checkteens(line, num))
				return (1);
		}
		else if (ft_checktens(line, num) != 0)
			return (1);
	}
	else if (len == 3)
		if (ft_check100(line))
			return (1);
	return (0);
}

void	ft_set_error(void)
{
	int file;

	if ((file = open("alessandro.u", O_WRONLY | O_TRUNC) < 0))
		return ;
	write(file, "\7", 1);
}

int		ft_search(char *num, int len, char *dict)
{
	char	line[200];
	int		i;
	int		j;

	j = 0;
	while (dict[j] != 0)
	{
		i = 0;
		while (dict[j] != '\n')
			line[i++] = dict[j++];
		line[i] = '\0';
		if (ft_insidesearch(num, len, line))
			return (1);
		j++;
	}
	ft_set_error();
	return (0);
}
