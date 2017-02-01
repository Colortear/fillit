/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:27:06 by anieto            #+#    #+#             */
/*   Updated: 2016/10/27 17:44:25 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		piece_check(char **tets)
{
	int i;

	i = 0;
	while (tets[i] != NULL)
		i++;
	if (i > 25)
		return (0);
	return (1);
}

void	print_square(char **m)
{
	int i;
	int j;

	i = 0;
	while (m[i] != 0)
	{
		j = 0;
		while (m[i][j] != '\0')
		{
			write(1, &m[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

char	**make_map(int size)
{
	char	**p;
	int		i;
	int		j;

	i = 0;
	p = (char **)malloc(sizeof(char *) * (size + 1));
	if (!p)
		return (NULL);
	while (i < size)
	{
		p[i] = malloc(sizeof(char) * (size + 1));
		j = 0;
		while (j < size)
		{
			p[i][j] = '.';
			j++;
		}
		p[i][j] = '\0';
		i++;
	}
	p[i] = 0;
	return (p);
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != 0)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	fillit_solve(char **tets)
{
	char	**d;
	int		solved;

	solved = 0;
	g_sizes = 2;
	d = NULL;
	while (solved == 0 && g_sizes < 10)
	{
		d = make_map(g_sizes);
		if (solve(tets, d, 0) == 1)
		{
			solved = 1;
			print_square(d);
		}
		free_map(d);
		g_sizes++;
	}
}
