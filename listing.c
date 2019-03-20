/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alstupin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 00:36:39 by alstupin          #+#    #+#             */
/*   Updated: 2019/03/12 00:36:41 by alstupin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*new_list(char **piece, char letter)
{
	t_piece	*new;

	if (!(new = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	new->piece = resize_piece(piece, 0);
	new->letter = letter;
	new->next = NULL;
	return (new);
}

t_piece	*general_listing(char **piece)
{
	static t_piece	*head;
	static char		letter;
	t_piece			*current;

	if (!head)
	{
		letter = 'A';
		head = new_list(piece, letter);
		return (head);
	}
	letter++;
	current = head;
	while (current)
	{
		if (current->next == NULL)
		{
			current->next = new_list(piece, letter);
			break ;
		}
		current = current->next;
	}
	return (head);
}

t_piece	*get_pieces(int fd)
{
	int		y;
	char	*line;
	char	**piece;
	t_piece *head;

	y = 0;
	while (get_next_line(fd, &line) && y != -2)
	{
		if (y == 0 && !(piece = (char**)malloc(sizeof(char*) * 5)))
			return (NULL);
		if (y != 4)
			piece[y] = ft_strdup(line);
		else if (ft_strlen(line) == 0)
			y = -1;
		else
			y = -3;
		if (y++ == 3)
		{
			piece[4] = "\0";
			if (!basic_tests(piece, -1, 0) || !(head = general_listing(piece)))
				return (NULL);
		}
		ft_strdel(&line);
	}
	return (y != 4 ? NULL : head);
}
