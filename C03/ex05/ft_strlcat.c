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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	len = 0;
	while (dest[len] != '\0')
		len++;
	while (src[i] != '\0' && len + i + 1 < size)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i + len);
}
