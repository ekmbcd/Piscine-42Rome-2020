/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-gius <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:10:37 by mde-gius          #+#    #+#             */
/*   Updated: 2020/11/08 16:27:05 by mde-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_open_dict(char *filename)
{
	int		i;
	int		file;
	char	c;
	char	*dict;

	i = 0;
	if ((file = open(filename, O_RDONLY)) < 0)
		return (0);
	while (read(file, &c, 1))
		i++;
	if (!(dict = (char *)malloc(sizeof(char) * (i + 3))))
		return (0);
	i = 1;
	close(file);
	if ((file = open(filename, O_RDONLY)) < 0)
		return (0);
	dict[0] = '\n';
	while (read(file, &c, 1))
		dict[i++] = c;
	dict[i + 1] = '\n';
	dict[i + 2] = '\0';
	close(file);
	return (dict);
}

int		ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int		ft_checkinput(char *num)
{
	int i;

	i = 0;
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9' || i > 38)
			return (0);
		i++;
	}
	return (1);
}

int		ft_clear_file(void)
{
	int file;

	if ((file = open("alessandro.u", O_WRONLY | O_TRUNC) < 0))
		return (0);
	write(1, "", 1);
	close(file);
	return (1);
}

int		main(int argc, char **argv)
{
	char *dict;
	char *num;
	char *filename;

	filename = "numbers.dict";
	if (argc == 2)
		num = argv[1];
	else if (argc == 3)
	{
		filename = argv[1];
		num = argv[2];
	}
	else
		return (ft_error());
	if ((dict = ft_open_dict(filename)) == 0 || (ft_checkinput(num) == 0 ||
		ft_clear_file() == 0))
	{
		free(dict);
		return (ft_error());
	}
	ft_start_program(num, dict);
}
