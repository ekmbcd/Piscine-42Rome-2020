/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:47:19 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/25 16:50:14 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int index;
	int flag;

	index = 0;
	flag = 0;
	while (str[index] != '\0')
	{
		if (str[index] <= 31 || str[index] == 127)
		{
			flag = 1;
		}
		index++;
	}
	if (flag == 1)
	{
		return (0);
	}
	return (1);
}
