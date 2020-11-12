/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:08:54 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/24 11:48:19 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	firstline(int x)
{
	int countx;

	countx = 1;
	while (countx <= x)
	{
		if (countx == 1)
		{
			ft_putchar('/');
		}
		else
		{
			if (countx == x)
			{
				ft_putchar('\\');
			}
			else
				ft_putchar('*');
		}
		countx++;
	}
	ft_putchar('\n');
}

void	lastline(int x)
{
	int countx;

	countx = 1;
	while (countx <= x)
	{
		if (countx == 1)
		{
			ft_putchar('\\');
		}
		else
		{
			if (countx == x)
			{
				ft_putchar('/');
			}
			else
				ft_putchar('*');
		}
		countx++;
	}
	ft_putchar('\n');
}

void	middleline(int x)
{
	int countx;

	countx = 1;
	while (countx <= x)
	{
		if (countx == 1)
		{
			ft_putchar('*');
		}
		else
		{
			if (countx == x)
			{
				ft_putchar('*');
			}
			else
				ft_putchar(' ');
		}
		countx++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int county;

	county = 1;
	while (county <= y)
	{
		if (county == 1)
		{
			firstline(x);
		}
		if (county < y && county > 1)
		{
			middleline(x);
		}
		if (county == y && y != 1)
		{
			lastline(x);
		}
		county++;
	}
}
