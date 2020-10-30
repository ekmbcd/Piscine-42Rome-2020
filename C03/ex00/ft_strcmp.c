/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:51:37 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/26 12:05:08 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
