/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:07:27 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/01 23:14:13 by atortora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_factorial(int n);
void	wrong_n(int *n, int *j, int fact);
int		gen_n(int **matrix, int row, int col, int range);
int		call_gen(int **matrix, int row, int col, int range);
int		gen_rec(int **matrix, int row, int col, int range);
int		new_max(int *reads, int **matrix, int row, int col);
void	generate_borders(int **matrix, int range, int rows);
void	excludecombs(int **combs, int i, int row, int size);
void	clearcombs(int **combs, int row, int size);
int		recursive(int ***very_big_pp, int riga, int size);
int		get_inputs(char *str, int **inputs, int size);
int		check_args(char *str);
void	error();
void	print_matrix(int **matrix, int size);
void	tana_libera_tutti(int ***very_big_pp, int max);

int		memory_ended(int ***very_big_pp, int max)
{
	tana_libera_tutti(very_big_pp, max);
	error();
	return (1);
}

int		alloc_submemory(int ***very_big_pp, int max)
{
	int i;

	i = -1;
	while (++i < ft_factorial(max))
	{
		very_big_pp[0][i] = (int *)(malloc((max + 3) * sizeof(int)));
		if (!very_big_pp[0][i])
			return (memory_ended(very_big_pp, max));
	}
	i = -1;
	while (++i < 4)
	{
		very_big_pp[1][i] = (int *)(malloc(max * sizeof(int)));
		if (!very_big_pp[1][i])
			return (memory_ended(very_big_pp, max));
	}
	i = -1;
	while (++i < max)
	{
		very_big_pp[2][i] = (int *)(malloc(max * sizeof(int)));
		if (!very_big_pp[1][i])
			return (memory_ended(very_big_pp, max));
	}
	return (0);
}

int		alloc_memory(int ***very_big_pp, int max)
{
	very_big_pp[0] = (int **)(malloc(ft_factorial(max) * sizeof(int *)));
	very_big_pp[1] = (int **)(malloc(4 * sizeof(int *)));
	very_big_pp[2] = (int **)(malloc(max * sizeof(int *)));
	if (!very_big_pp[0] || !very_big_pp[1] || !very_big_pp[2])
		return (0);
	return (alloc_submemory(very_big_pp, max));
}

int		get_max(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	return (check_args(argv[1]));
}

int		main(int argc, char **argv)
{
	int		***very_big_pp;
	int		max;

	very_big_pp = (int ***)malloc(sizeof(int **) * 3);
	if (!very_big_pp)
		return (1);
	max = get_max(argc, argv);
	if (max == 0 || max > 9)
		error();
	if (max == 0 || max > 9)
		return (1);
	if (alloc_memory(very_big_pp, max))
		return (1);
	if (get_inputs(argv[1], very_big_pp[1], max) == 0)
		error();
	if (get_inputs(argv[1], very_big_pp[1], max) == 0)
		return (1);
	gen_rec(very_big_pp[0], 0, 0, max);
	generate_borders(very_big_pp[0], max, ft_factorial(max));
	if (recursive(very_big_pp, 0, max) != 0)
		print_matrix(very_big_pp[0], max);
	else
		error();
	tana_libera_tutti(very_big_pp, max);
	return (0);
}
