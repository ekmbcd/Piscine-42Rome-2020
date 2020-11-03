/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:04:25 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/03 16:32:02 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

struct s_stock_str	single_element(char *str)
{
	int					l;
	struct s_stock_str	res;
	char				*copy;

	l = len(str);
	copy = (char *)malloc(sizeof(char) * (l + 1));
	ft_strcpy(copy, str);
	res.size = l;
	res.str = str;
	res.copy = copy;
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*array;
	int					i;

	i = 0;
	if (!(array = malloc(sizeof(struct s_stock_str) * (ac + 2))))
		return (0);
	while (i < ac)
	{
		array[i] = single_element(av[i]);
		i++;
	}
	array[i].str = 0;
	return (array);
}
