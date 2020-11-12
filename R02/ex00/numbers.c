/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-gius <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:57:21 by mde-gius          #+#    #+#             */
/*   Updated: 2020/11/08 15:57:46 by mde-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_units(char *num, char *dict)
{
	ft_search(num, 1, dict);
}

void	ft_tens(char num[2], char *dict)
{
	if (num[0] != '0')
		ft_search(num, 2, dict);
	if (num[1] != '0' && num[0] != '1')
	{
		ft_units(&num[1], dict);
	}
}

void	ft_hundreds(char num[3], char *dict)
{
	if (num[0] == '0')
		return ;
	ft_units(&num[0], dict);
	ft_search("100", 3, dict);
	if (num[1] != '0')
		ft_tens(&num[1], dict);
	else if (num[2] != '0')
		ft_units(&num[2], dict);
}
