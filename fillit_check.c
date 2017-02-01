/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 22:03:00 by wdebs             #+#    #+#             */
/*   Updated: 2016/11/03 16:28:39 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		last_check(int dest[4][2], char **d)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (dest[i][0] > g_sizes - 1 || dest[i][0] < 0 ||
				d[dest[i][0]][dest[i][1]] != '.')
			return (0);
		if (dest[i][1] > g_sizes - 1 || dest[i][1] < 0)
			return (0);
		i++;
	}
	return (1);
}

int		check_shape(char *str)
{
	int units;
	int i;

	units = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				units++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				units++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				units++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				units++;
		}
		i++;
	}
	return (units == 6 || units == 8);
}

int		val_format(char **str)
{
	int		i;
	int		j;
	int		check;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (j > 20)
				return (0);
			check = 0;
			while (str[i][j] != '\n')
			{
				j++;
				check++;
			}
			if (check > 4)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		val_char(char **str)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		count = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '#')
				count++;
			if (str[i][j] != '#' && str[i][j] != '.'
					&& str[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
		if (count != 4)
			return (0);
	}
	if (val_format(str) == 0)
		return (0);
	return (1);
}

int		tet_check(char **str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (check_shape(str[i]) == 0)
			error();
		i++;
	}
	return (1);
}
