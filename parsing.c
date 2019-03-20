/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juriot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 00:36:39 by juriot            #+#    #+#             */
/*   Updated: 2019/03/12 00:36:41 by juriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_y_min(char **piece, int *y_min)
{
	int y;
	int x;
	int flag;

	y = 0;
	flag = 0;
	while (y < 4)
	{
		x = 0;
		while (piece[y][x])
		{
			if (piece[y][x] == '#')
			{
				if (*y_min > y || flag == 0)
				{
					flag = 1;
					*y_min = y;
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		find_x_min(char **piece, int *x_min)
{
	int y;
	int x;
	int flag;

	y = 0;
	flag = 0;
	while (y < 4)
	{
		x = 0;
		while (piece[y][x])
		{
			if (piece[y][x] == '#')
			{
				if (*x_min > x || flag == 0)
				{
					flag = 1;
					*x_min = x;
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		find_y_max(char **piece, int *y_max)
{
	int y;
	int x;
	int flag;

	flag = 0;
	y = 3;
	while (y >= 0)
	{
		x = 3;
		while (x >= 0)
		{
			if (piece[y][x] == '#')
			{
				if (*y_max < y || flag == 0)
				{
					flag = 1;
					*y_max = y;
				}
			}
			x--;
		}
		y--;
	}
	return (0);
}

int		find_x_max(char **piece, int *x_max)
{
	int y;
	int x;
	int flag;

	flag = 0;
	y = 3;
	while (y >= 0)
	{
		x = 3;
		while (x >= 0)
		{
			if (piece[y][x] == '#')
			{
				if (*x_max < x || flag == 0)
				{
					flag = 1;
					*x_max = x;
				}
			}
			x--;
		}
		y--;
	}
	return (0);
}

char	**resize_piece(char **piece, int i)
{
	int		x_min;
	int		y_min;
	int		x_max;
	int		y_max;
	char	**dst;

	find_y_min(piece, &y_min);
	find_x_min(piece, &x_min);
	find_y_max(piece, &y_max);
	find_x_max(piece, &x_max);
	if (!(dst = (char **)malloc(sizeof(char *) * (y_max - y_min + 1) + 1)))
		return (NULL);
	while (y_min < y_max + 1)
	{
		dst[i] = ft_strsub(piece[y_min], x_min, x_max - x_min + 1);
		y_min++;
		i++;
	}
	delete_tab(piece);
	free(piece);
	piece = NULL;
	dst[i] = "\0";
	return (dst);
}
