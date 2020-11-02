/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:17:56 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/02 12:10:30 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	concatenate(char *dest, char *src)
{
	int i;
	int destlen;

	i = 0;
	destlen = len(dest);
	while (src[i] != '\0')
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;
	int		totalsize;

	totalsize = 0;
	i = size;
	if (size == 0)
	{
		res = (char *)malloc(1);
		*res = 0;
		return (res);
	}
	while (i > 0)
		totalsize += len(strs[i-- - 1]);
	res = (char *)malloc(totalsize + (len(sep) * (size - 1)) + 1);
	while (i < size)
	{
		concatenate(res, strs[i]);
		if (i != size - 1)
			concatenate(res, sep);
		i++;
	}
	res[totalsize + (len(sep) * (size - 1))] = 0;
	return (res);
}
