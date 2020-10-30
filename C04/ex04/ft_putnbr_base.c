/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:34:26 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/28 14:03:40 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		length(char *base)
{
	int i;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (i);
}

int		check_base(char *base)
{
	int		i;
	int		j;
	char	*pointer;
	char	selected;

	i = length(base);
	if (i <= 1)
		return (0);
	j = 0;
	while (j < i)
	{
		selected = base[j];
		pointer = base + j + 1;
		while (*pointer != 0)
		{
			if (*pointer == selected)
				return (0);
			pointer++;
		}
		j++;
	}
	return (1);
}

void	calculate_number(unsigned int un, unsigned int len, char *base)
{
	if (un >= len)
	{
		calculate_number(un / len, len, base);
		calculate_number(un % len, len, base);
	}
	else
		write(1, &base[un], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int len;
	unsigned int nb;

	if (check_base(base) == 0)
		return ;
	len = 0;
	while (base[len] != 0)
		len++;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = (unsigned int)(nbr * -1);
	}
	else
		nb = (unsigned int)(nbr);
	calculate_number(nb, len, base);
}
