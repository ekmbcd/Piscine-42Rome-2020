/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:46:45 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/27 13:55:23 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlength(char *str)
{
	char			*ptr;
	unsigned int	index;

	ptr = str;
	index = 0;
	while (*ptr != 0)
	{
		index++;
		ptr++;
	}
	return (index);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dlength;
	char			*dest2;
	char			*src2;

	dest2 = dest;
	src2 = src;
	index = size;
	while (index-- != 0 && *dest2 != '\0')
		dest2++;
	dlength = dest2 - dest;
	index = size - dlength;
	if (index == 0)
		return (dlength + ft_strlength(src2));
	while (*src2)
	{
		if (index != 1)
		{
			*dest2++ = *src2;
			index--;
		}
		src2++;
	}
	*dest2 = '\0';
	return (dlength + (src2 - src));
}
