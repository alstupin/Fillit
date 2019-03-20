/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alstupin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 00:36:39 by alstupin          #+#    #+#             */
/*   Updated: 2019/03/12 00:36:41 by alstupin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_piece *head;

	if (argc < 2)
	{
		ft_putendl("usage: ./fillit <valid_file>");
		return (0);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
		return (0);
	head = get_pieces(fd);
	if (head == NULL)
	{
		ft_putendl("error");
		return (0);
	}
	fillit(head);
	return (0);
}
