/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:41:51 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/27 11:42:02 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int index;

	index = 0;
	while (src[index] != '\0')
	{
		if (index < size - 1 && size > 0)
			dest[index] = src[index];
		index++;
	}
	if (size > 0)
	{
		if (size - 1 < index)
			dest[size - 1] = '\0';
		else
			dest[index] = '\0';
	}
	return (index);
}
