/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juriot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 22:49:01 by juriot            #+#    #+#             */
/*   Updated: 2019/03/11 22:49:04 by juriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	show_tab(char **tab)
{
	if (!tab)
		return ;
	while (**tab)
		ft_putendl(*tab++);
}

char	**map_creator(int size)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (x <= size)
	{
		map[x] = ft_strnew(size);
		x++;
	}
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

int		place_de_letoile(char **map, int next)
{
	int		x;
	int		y;

	y = 0;
	while (map[y][0])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '.')
			{
				if (next == 0)
				{
					map[y][x] = '*';
					return (1);
				}
				next--;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		find_y(char **map)
{
	int	y;

	y = 0;
	while (ft_strchr(map[y], '*') == 0)
		y++;
	return (y);
}

int		find_x(char **map, int y)
{
	int x;

	x = 0;
	while (map[y][x] != '*')
		x++;
	map[y][x] = '.';
	return (x);
}
