/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-gius <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:59:01 by mde-gius          #+#    #+#             */
/*   Updated: 2020/11/08 15:59:55 by mde-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_cut_string(char *str)
{
	int i;

	if (ft_strlen(str) < 4)
		return ("");
	i = ft_strlen(str) % 3;
	if (i == 0)
		i = 3;
	while (str[i] == '0' && str[i])
		i++;
	return (&str[i]);
}

void	ft_zeroes(char *num, char *dict)
{
	int		i;
	char	*to_find;
	int		num_zeroes;
	int		len;

	len = ft_strlen(num);
	if (len < 4)
		return ;
	(len % 3 == 0) ? (len -= 3) : (len += 0);
	i = 2;
	num_zeroes = (len / 3) * 3;
	to_find = malloc(sizeof(char) * (num_zeroes + 3));
	to_find[0] = '\n';
	to_find[1] = '1';
	while (i < num_zeroes + 2)
		to_find[i++] = '0';
	to_find[i] = 0;
	dict = ft_strstr(dict, to_find);
	while (*dict != ':')
		dict++;
	dict++;
	while (*dict == ' ')
		dict++;
	ft_prints(dict);
	free(to_find);
}

void	ft_rec(char *str, char *dict)
{
	int i;

	if (*str == 0)
		return ;
	i = ft_strlen(str) % 3;
	if (i == 0)
		i = 3;
	if (i == 3)
		ft_hundreds(str, dict);
	else if (i == 2)
		ft_tens(str, dict);
	else if (i == 1)
		ft_units(str, dict);
	if (ft_strlen(str) < 4)
	{
		return ;
	}
	ft_zeroes(str, dict);
	str = ft_cut_string(str);
	ft_rec(str, dict);
}
