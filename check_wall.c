/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 22:27:13 by lchimes           #+#    #+#             */
/*   Updated: 2017/06/20 22:27:15 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_top_wall(t_state *s)
{
	s->curb_x = 0;
	while (s->curb_x <= s->fnl_bx)
	{
		if (ft_tolower(s->board[0][s->curb_x]) == s->xoro)
			return (1);
		s->curb_x++;
	}
	return (0);
}

int		ft_check_bot_wall(t_state *s)
{
	s->curb_x = 0;
	while (s->curb_x <= s->fnl_bx)
	{
		if (ft_tolower(s->board[s->fnl_by - 1][s->curb_x]) == s->xoro)
			return (1);
		s->curb_x++;
	}
	return (0);
}

int		ft_check_left_wall(t_state *s)
{
	s->curb_y = 0;
	while (s->curb_y <= s->fnl_by)
	{
		if (ft_tolower(s->board[s->curb_y][0]) == s->xoro)
			return (1);
		s->curb_y++;
	}
	return (0);
}

int		ft_check_right_wall(t_state *s)
{
	s->curb_y = 0;
	while (s->curb_y <= s->fnl_by)
	{
		if (ft_tolower(s->board[s->curb_y][s->fnl_bx]) == s->xoro)
			return (1);
		s->curb_y++;
	}
	return (0);
}

void	ft_check_walls(t_state *s)
{
	s->curb_y = 0;
	s->curb_x = 0;
	if (s->start_sector == 2 || s->start_sector == 3)
		if (ft_check_top_wall(s) == 1 || ft_check_right_wall(s) == 1)
			if (ft_check_bot_wall(s) == 1 || ft_check_left_wall(s) == 1)
				s->wall_complete = 1;
	if (s->start_sector == 1 || s->start_sector == 4)
		if (ft_check_top_wall(s) == 1 || ft_check_left_wall(s) == 1)
			if (ft_check_bot_wall(s) == 1 || ft_check_right_wall(s) == 1)
				s->wall_complete = 1;
	s->curb_y = 0;
	s->curb_x = 0;
}
