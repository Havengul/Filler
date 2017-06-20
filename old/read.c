/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscheepe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:49:58 by fscheepe          #+#    #+#             */
/*   Updated: 2017/06/13 09:46:08 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_input(void)
{
	t_state		v;
	char		*str;
	char		**list;
	int			i;
	int			firsttime;
	t_temp		x;

	v.walls = 1;
	firsttime = 1;
	x.x = 1;
	i = 0;
	get_next_line(0, &str);
	list = ft_strsplit(str, ' ');
	if (ft_strcmp(list[2], "p1") == 0)
	{
		v.xoro = 'o';
		v.enxoro = 'x';
	}
	else
	{
		v.xoro = 'x';
		v.enxoro = 'o';
	}
	while (1)
	{
		v.board = NULL;
		v.piece = NULL;
		v.fnl_by = 0;
		v.fnl_bx = 0;
		v.fnl_py = 0;
		v.fnl_px = 0;
		get_next_line(0, &str);
		if (str != NULL)
		{
			list = ft_strsplit(str, ' ');
			v.fnl_by = ft_atoi(list[1]);
			v.fnl_bx = ft_atoi(list[2]);
			get_next_line(0, &str);
			v.board = malloc(v.fnl_by * sizeof(*v.board) + 
					(v.fnl_by * (v.fnl_bx * sizeof(**v.board))));
			i = 0;
			while (get_next_line(0, &str))
			{
				list = ft_strsplit(str, ' ');
				v.board[i] = list[1];
				i++;
				if (i == v.fnl_by)
					break;
			}
			get_next_line(0, &str);
			list = ft_strsplit(str, ' ');
			v.fnl_py = ft_atoi(list[1]);
			v.fnl_px = ft_atoi(list[2]);
			v.piece = malloc(v.fnl_py * sizeof(*v.piece) + 
					(v.fnl_py * (v.fnl_px * sizeof(**v.piece))));
			i = 0;
			while (get_next_line(0, &str))
			{
				v.piece[i] = str;
				i++;
				if (i == v.fnl_py)
					break;
			}
			v.fnl_by--;
			v.fnl_bx--;
			v.fnl_py--;
			v.fnl_px--;
			if (firsttime == 1)
			{
				firsttime = 0;
				v.startpos = ft_findstart(v, x);
				v.enstartpos = ft_findenstart(v, x);
			}
			ft_validator(v, x);
			free(v.board);
			free(v.piece);
		}
		else
			break;
	}
}

int		main(void)
{
	ft_input();
	return (0);
}
