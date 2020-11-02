/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:32:53 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/02 14:58:36 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_itoa_base(int n, char *base, char *res, int *i)
{
	int l_base;

	l_base = len(base);
	if (n < 0)
	{
		res[*i] = '-';
		n = n * -1;
		*i = *i + 1;
	}
	if (n >= l_base)
	{
		ft_itoa_base(n / l_base, base, res, i);
		ft_itoa_base(n % l_base, base, res, i);
	}
	else
	{
		res[*i] = base[n];
		*i = *i + 1;
		res[*i] = 0;
	}
}
