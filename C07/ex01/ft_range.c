/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:56:28 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/02 10:56:13 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *res;
	int i;

	if (max <= min)
		return (0);
	i = 0;
	res = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		res[i] = min;
		min++;
		i++;
	}
	return (res);
}
