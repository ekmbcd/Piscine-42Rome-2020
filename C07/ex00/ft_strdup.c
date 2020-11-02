/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:13:47 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/30 13:51:00 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	strcopy(char *a, char *b)
{
	int i;

	i = 0;
	while (b[i])
	{
		a[i] = b[i];
		i++;
	}
	a[i] = 0;
}

char	*ft_strdup(char *src)
{
	int i;
	char *dest;

	i = 0;
	while (src[i])
	{
		i++;
	}
	dest = (char *)malloc(i + 1);
	strcopy(dest, src);
	return (dest);
}
#include <stdio.h>
int main()
{
	char *a;
	char *b = "pippo";
	
	a = ft_strdup( b);
	printf("%s", a);
}
