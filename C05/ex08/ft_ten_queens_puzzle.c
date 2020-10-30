/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:35:05 by ade-feli          #+#    #+#             */
/*   Updated: 2020/10/29 19:57:55 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		check_board(int *board, int col)
{
	int i;
	int j;

	if (col == 0)
		return (1);
	i = 0;
	while (i < col)
	{
		j = i + 1;
		while (j <= col)
		{
			if (board[i] == board[j])
				return (0);
			if (board[j] == board[i] + i - j ||
					board[j] == board[i] - i + j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	guess(int *board, int column, int i, int *total)
{
	while (i < 10)
	{
		board[column] = i;
		if (check_board(board, column))
		{
			if (column == 9)
			{
				print_board(board);
				*total = *total + 1;
			}
			else
				guess(board, column + 1, 0, total);
		}
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int board[10];
	int total;

	total = 0;
	guess(board, 0, 0, &total);
	return (total);
}
