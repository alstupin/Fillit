/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alstupin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 00:36:39 by alstupin          #+#    #+#             */
/*   Updated: 2019/03/12 00:36:41 by alstupin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_piece
{
	char			**piece;
	char			letter;
	struct s_piece	*next;
}				t_piece;

t_piece			*new_list(char **piece, char letter);
t_piece			*general_listing(char **piece);
t_piece			*get_pieces(int fd);

int				count_i(char **map, char c);
int				place(t_piece *block, char **map, int y, int x);
int				try_piece(char **map, t_piece *block, int y, int x);
int				backtracking(char **map, t_piece *block, int corr);
int				fillit(t_piece *head);

int				piece_checker(char **piece, int y, int x);
int				basic_tests(char **piece, int y, int x);

int				find_y_min(char **piece, int *y_min);
int				find_x_min(char **piece, int *x_min);
int				find_y_max(char **piece, int *y_max);
int				find_x_max(char **piece, int *x_max);
char			**resize_piece(char **piece, int i);

void			delete_letter(char **map, char lettre);
void			delete_tab(char **tab);
void			delete_map(char **map, int size);

void			show_tab(char **tab);
char			**map_creator(int size);
int				place_de_letoile(char **map, int next);
int				find_y(char **map);
int				find_x(char **map, int y);

#endif
