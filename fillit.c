/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juriot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 00:36:39 by juriot            #+#    #+#             */
/*   Updated: 2019/03/12 00:36:41 by juriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_i(char **map, char c)
{
	int y;
	int x;
	int i;

	y = 0;
	i = 0;
	while (map[y][0])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

int		place(t_piece *block, char **map, int y, int x)
{
	int		y_p;
	int		x_p;

	y_p = 0;
	while (block->piece[y_p][0])
	{
		x_p = 0;
		while (block->piece[y_p][x_p])
		{
			if (!map[y][0] || !map[y][x])
				return (0);
			if (map[y][x] == '.' && block->piece[y_p][x_p] != '.')
				map[y][x] = block->letter;
			x++;
			x_p++;
		}
		x = x - x_p;
		y++;
		y_p++;
	}
	return (count_i(map, block->letter));
}

int		try_piece(char **map, t_piece *block, int y, int x)
{
	int		i;
	int		y_p;

	y_p = 0;
	i = 0;
	if (block->piece[y_p][0] == '.')
	{
		if (block->piece[y_p][1] == '.')
			x--;
		x--;
	}
	i = place(block, map, y, x);
	return (i == 4 ? 1 : 0);
}

int		backtracking(char **map, t_piece *block, int corr)
{
	if (!block)
		return (1);
	while (place_de_letoile(map, corr++))
	{
		if (try_piece(map, block, find_y(map), find_x(map, find_y(map))))
		{
			if (backtracking(map, block->next, 0))
				return (1);
		}
		delete_letter(map, block->letter);
	}
	return (0);
}

int		fillit(t_piece *head)
{
	int		size;
	char	**map;

	size = 2;
	map = map_creator(size);
	while (!(backtracking(map, head, 0)))
	{
		delete_map(map, size);
		free(map);
		map = NULL;
		size++;
		map = map_creator(size);
	}
	show_tab(map);
	delete_map(map, size);
	free(map);
	return (0);
}
