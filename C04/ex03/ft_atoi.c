/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:13:14 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/28 15:52:32 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		res;
	int		sign;
	char	*pointer;

	res = 0;
	sign = 1;
	pointer = str;
	while (*pointer == ' ' || (*pointer >= 9 && *pointer <= 13))
		pointer++;
	while (*pointer == '-' || *pointer == '+')
	{
		if (*pointer == '-')
			sign *= -1;
		pointer++;
	}
	while (*pointer >= '0' && *pointer <= '9')
	{
		res = (res * 10) + (*pointer - '0');
		pointer++;
	}
	return (res * sign);
}
