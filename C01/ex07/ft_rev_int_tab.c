/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:30:22 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/22 18:35:07 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int copy[size];
	int counter;

	counter = 0;
	while (counter < size)
	{
		copy[counter] = tab[counter];
		counter++;
	}
	counter = 0;
	while (counter < size)
	{
		tab[counter] = copy[size - counter - 1];
		counter++;
	}
}
