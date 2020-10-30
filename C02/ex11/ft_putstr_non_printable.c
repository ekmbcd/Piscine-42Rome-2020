/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:19:59 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/27 11:43:48 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	hexa(int n)
{
	char *numbers;

	numbers = "0123456789abcdef";
	ft_putchar(numbers[n / 16]);
	ft_putchar(numbers[n % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > 31 && str[i] != 127) || str[i] < 0)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			hexa(str[i]);
		}
		i++;
	}
}
