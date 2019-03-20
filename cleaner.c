/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alstupin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 00:36:39 by alstupin          #+#    #+#             */
/*   Updated: 2019/03/12 00:36:41 by alstupin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_letter(char **map, char lettre)
{
	int x;
	int	y;

	y = 0;
	while (map[y][0] != '\0')
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if ((map[y][x] == lettre) || (map[y][x] == '*'))
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}

void	delete_tab(char **tab)
{
	while (**tab)
		ft_strdel(&(*tab++));
}

void	delete_map(char **map, int size)
{
	int	i;

	i = 0;
	while (i <= size)
		ft_strdel(&map[i++]);
}
