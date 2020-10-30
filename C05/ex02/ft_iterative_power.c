/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:38:06 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/28 18:44:21 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	i = nb;
	while (power > 1)
	{
		i *= nb;
		power--;
	}
	return (i);
}
