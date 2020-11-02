/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:11:16 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/02 15:16:59 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		len(char *str);
void	ft_itoa_base(int n, char *base, char *res, int *i);

int		check_base(char *base)
{
	int i;
	int k;

	i = 0;
	if (base == 0 || base[0] == 0 || base[1] == 0)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || base[i] <= 31)
			return (0);
		k = 1;
		while (base[i + k])
		{
			if (base[i + k] == base[i])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int		check_num(char *base, char *to_find)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (*to_find == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	unsigned int	num;
	int				sign;
	char			*charptr;

	num = 0;
	sign = 1;
	charptr = str;
	while (*charptr == ' ' || (*charptr >= 9 && *charptr <= 13))
		charptr++;
	while (*charptr == '-' || *charptr == '+')
	{
		if (*charptr == '-')
			sign *= -1;
		charptr++;
	}
	while (check_num(base, charptr) != -1)
	{
		num *= len(base);
		num += (unsigned int)(check_num(base, charptr));
		charptr++;
	}
	return (int)(num * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		n;
	int		i;

	if (!(check_base(base_from) && check_base(base_to)))
		return (0);
	i = 0;
	if (res = (char *)malloc(sizeof(char) * 34) == 0)
		return (0);
	n = ft_atoi_base(nbr, base_from);
	ft_itoa_base(n, base_to, res, &i);
	return (res);
}
