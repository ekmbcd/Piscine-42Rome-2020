/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:07:50 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/30 12:04:39 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printa(char **a, int size)
{
	int i;
	int j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (a[i][j])
		{
			write(1, &a[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (1)
	{
		if ((unsigned int)s1[i] > (unsigned int)s2[i])
			return (1);
		if ((unsigned int)s1[i] < (unsigned int)s2[i])
			return (-1);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
}

void	ft_swep(char **one, char **two)
{
	char *temp;

	temp = *one;
	*one = *two;
	*two = temp;
}

int		main(int argc, char **argv)
{
	int counter1;
	int counter2;

	counter1 = 0;
	while (counter1 < argc - 1)
	{
		counter2 = 1;
		while (counter2 < argc - 1)
		{
			if (ft_strcmp(argv[counter2], argv[counter2 + 1]) > 0)
			{
				ft_swep(&argv[counter2], &argv[counter2 + 1]);
			}
			counter2++;
		}
		counter1++;
	}
	printa(argv, argc);
}
