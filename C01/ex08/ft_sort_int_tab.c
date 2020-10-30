/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:47:31 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/22 18:57:52 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int memory;
	int counter1;
	int counter2;

	counter1 = 0;
	while (counter1 < size - 1)
	{
		counter2 = 0;
		while (counter2 < size - 1)
		{
			if (tab[counter2] > tab[counter2 + 1])
			{
				memory = tab[counter2];
				tab[counter2] = tab[counter2 + 1];
				tab[counter2 + 1] = memory;
			}
			counter2++;
		}
		counter1++;
	}
}
