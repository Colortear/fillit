/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:40:05 by anieto            #+#    #+#             */
/*   Updated: 2016/12/06 11:53:29 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUF_SIZE 4096

int			g_sizes;

int			posit_check(char *str, int j);
int			val_format(char **str);
int			val_char(char **str);
int			tet_check(char **str);

void		print_square(char **m);
char		**make_map(int size);
void		free_map(char **map);
int			smallest(int n);
void		fillit_solve(char **tets);

int			solve(char **tets, char **d, int place);
void		letter_set(void);
void		fill_grid(char **d, int coord[4][2], int piece);
int			transfer(int dest[4][2], int raw_coord[4][2], char **d, int piece);
int			check(char *tets, int yx[2], char **d, int piece);
int			solve(char **tets, char **d, int piece);
void		clear_piece(int piece, char **d);
int			last_check(int dest[4][2], char **d);

void		error(void);
int			t_strlen(char *s);
char		**tet_split(char *s);
char		**fillit_read(char *file);
#endif
