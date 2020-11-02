/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tana.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:33:02 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/01 19:46:27 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_factorial(int n);

void	tana_libera_tutti(int ***very_big_pp, int max)
{
	int i;

	i = 0;
	while (i < ft_factorial(max))
	{
		free(very_big_pp[0][i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		free(very_big_pp[1][i]);
		i++;
	}
	i = 0;
	while (i < max)
	{
		free(very_big_pp[2][i]);
		i++;
	}
	while (i < 2)
		free(very_big_pp[i++]);
	free(very_big_pp);
}
