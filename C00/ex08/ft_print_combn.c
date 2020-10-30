/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:12:32 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/23 10:28:11 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int *numbers, int n)
{
	int	i;
	int	check;

	check = 1;
	i = 0;
	while (++i < n)
		if (numbers[i - 1] >= numbers[i])
			check = 0;
	if (!check)
		return ;
	i = -1;
	while (++i < n)
		ft_putchar(numbers[i] + 48);
	if (numbers[0] < (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	numbers[n];

	if (n > 9 || n < 1)
		return ;
	i = -1;
	while (++i < n)
		numbers[i] = i;
	i = n - 1;
	while (numbers[0] <= 10 - n)
	{
		if (numbers[i] < 9)
		{
			print(numbers, n);
			numbers[i]++;
			while (i < n - 1)
			{
				numbers[++i] = 1;
			}
		}
		else
			i--;
	}
}
