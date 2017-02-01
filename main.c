/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 02:02:37 by wdebs             #+#    #+#             */
/*   Updated: 2016/10/29 11:17:44 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

int		t_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	**tet_split(char *s)
{
	int		i;
	int		j;
	int		count;
	char	**new;
	int		k;

	i = 0;
	k = 0;
	count = (t_strlen(s) + 1) / 21;
	new = (char**)malloc(sizeof(char*) * (count + 1));
	while (s[i] != '\0')
	{
		j = 0;
		new[k] = (char *)malloc(sizeof(char) * 22);
		while (j < 21 && s[i] != '\0')
			new[k][j++] = s[i++];
		new[k][j] = '\0';
		k++;
	}
	if (k > 26)
		error();
	new[k] = NULL;
	return (new);
}

char	**fillit_read(char *file)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	**str;
	int		index;

	fd = open(file, O_RDONLY);
	index = -1;
	while (++index < BUF_SIZE + 1)
		buf[index] = '\0';
	ret = 0;
	if (fd == -1)
		error();
	else
		ret = read(fd, buf, BUF_SIZE);
	index = t_strlen(buf);
	if (buf[index - 2] == '\n')
		error();
	str = tet_split(buf);
	return (str);
}

int		main(int argc, char **argv)
{
	char	**tets;

	if (argc < 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		exit(0);
	}
	if (argc > 2)
		error();
	if ((tets = fillit_read(argv[1])) == 0)
		error();
	if (val_char(tets) == 0)
		error();
	if (tet_check(tets) == 0)
		error();
	fillit_solve(tets);
	return (0);
}
