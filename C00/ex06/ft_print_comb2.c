/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 09:23:29 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/22 09:27:32 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int a)
{
	char b[3];

	b[0] = (a / 10) + 48;
	b[1] = (a % 10) + 48;
	b[2] = '\0';
	write(1, b, 2);
}

void	print_numbers(int num1, int num2)
{
	print_number(num1);
	write(1, " ", 1);
	print_number(num2);
	if (num1 != 98 || num2 != 99)
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb2(void)
{
	int num1;
	int num2;

	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			print_numbers(num1, num2);
			num2++;
		}
		num1++;
	}
}
