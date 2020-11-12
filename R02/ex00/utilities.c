/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-gius <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:58:05 by mde-gius          #+#    #+#             */
/*   Updated: 2020/11/08 15:58:52 by mde-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_prints_from_file(void)
{
	int		fout;
	char	output[500];
	int		i;

	i = 0;
	fout = open("alessandro.u", O_RDONLY);
	while ((read(fout, &output[i], 1)))
		i++;
	output[i] = 0;
	close(fout);
	i = 0;
	if (output[i] == '\7')
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	while (output[i])
	{
		write(1, &output[i], 1);
		if (output[i + 2] == 0)
			break ;
		i++;
	}
}

void	ft_prints(char *str)
{
	int i;
	int fout;

	fout = open("alessandro.u", O_WRONLY | O_APPEND);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			write(fout, " ", 1);
		}
		write(fout, &str[i], 1);
		i++;
	}
	write(fout, " ", 1);
	close(fout);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	if (*to_find == 0)
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0' && (str[i + j + 1] < '0' ||
				str[i + j + 1] > '9'))
				return (str + i);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_start_program(char *num, char *dict)
{
	while (*num == '0' && ft_strlen(num) > 1)
		num++;
	ft_rec(num, dict);
	free(dict);
	ft_prints_from_file();
}
