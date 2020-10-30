/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:19:47 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/23 16:38:25 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int index;
	int flag;

	index = 0;
	flag = 0;
	while (str[index] != '\0')
	{
		if (!(str[index] >= 'a' && str[index] <= 'z'))
		{
			if (!(str[index] >= 'A' && str[index] <= 'Z'))
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
