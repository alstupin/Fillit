/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juriot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 00:36:39 by juriot            #+#    #+#             */
/*   Updated: 2019/03/12 00:36:41 by juriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	piece_checker(char **piece, int y, int x)
{
	int a;

	a = 0;
	if (x < 3 && piece[y][x + 1] == '#')
		a++;
	if (x > 0 && piece[y][x - 1] == '#')
		a++;
	if (y < 3 && piece[y + 1][x] == '#')
		a++;
	if (y > 0 && piece[y - 1][x] == '#')
		a++;
	return (a);
}

int	basic_tests(char **piece, int y, int x)
{
	int	connections;
	int	sharp;

	sharp = 0;
	connections = 0;
	while (piece[++y][0])
	{
		if (ft_strlen(piece[y]) != 4)
			return (0);
		x = -1;
		while (piece[y][++x])
		{
			if (piece[y][x] != '#' && piece[y][x] != '.')
				return (0);
			if (piece[y][x] == '#')
				sharp++;
			if (piece[y][x] == '#')
				connections = connections + piece_checker(piece, y, x);
		}
	}
	if (y != 4 || sharp != 4 || (connections != 6 && connections != 8))
		return (0);
	return (1);
}
