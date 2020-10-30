/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:13:00 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/26 11:28:21 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check(int index, char *str, int *flag)
{
	if (*flag == 0)
	{
		if (str[index] >= 'a' && str[index] <= 'z')
			str[index] = str[index] - 32;
		*flag = 1;
	}
	else
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
			str[index] = str[index] + 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int			index;
	int			flag;

	index = 0;
	flag = 0;
	while (str[index] != '\0')
	{
		if ((str[index] >= 'a' && str[index] <= 'z') ||
				(str[index] >= 'A' && str[index] <= 'Z') ||
				(str[index] >= '0' && str[index] <= '9'))
			check(index, str, &flag);
		else
			flag = 0;
		index++;
	}
	return (str);
}
