/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:53:08 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/04 14:53:11 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		is_separator(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int i;
	int num_words;
	int is_word;

	i = 0;
	num_words = 0;
	is_word = 0;
	while (str[i])
	{
		if (is_word == 0)
		{
			if (!(is_separator(str[i], charset)))
			{
				is_word = 1;
				num_words++;
			}
		}
		else
		{
			if (is_separator(str[i], charset))
				is_word = 0;
		}
		i++;
	}
	return (num_words);
}

char	*put_word(char *str, char *charset)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !(is_separator(str[i], charset)))
		i++;
	if (!(word = (char *)malloc(sizeof(char) * i + 1)))
		return (word);
	i = 0;
	while (str[i] && !(is_separator(str[i], charset)))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**res;
	int		num_words;

	i = 0;
	num_words = count_words(str, charset);
	if (!(res = malloc(sizeof(char *) * num_words + 1)))
		return (0);
	num_words = 0;
	while (str[i])
	{
		while (is_separator(str[i], charset) && str[i])
			i++;
		if (str[i])
		{
			res[num_words] = put_word(&str[i], charset);
			num_words++;
		}
		while (!(is_separator(str[i], charset)) && str[i])
			i++;
	}
	res[num_words] = 0;
	return (res);
}
