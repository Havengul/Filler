/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 22:50:14 by lchimes           #+#    #+#             */
/*   Updated: 2017/06/20 22:53:46 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_isvalid(t_state *s)
{
	int		overlap;

	overlap = 0;
	s->curm_y = 0;
	while (s->curm_y <= s->fnl_py)
	{
		s->curm_x = 0;
		while (s->curm_x <= s->fnl_px)
		{
			if (s->curb_y + s->fnl_py >= s->fnl_by
				|| s->curb_x + s->fnl_px > s->fnl_bx)
				return (99);
			if (ft_tolower(s->board[s->curb_y + s->curm_y]
						[s->curb_x + s->curm_x])
						== s->xoro && s->piece[s->curm_y][s->curm_x] == '*')
				overlap++;
			if (ft_tolower(s->board[s->curb_y + s->curm_y][s->curb_x
						+ s->curm_x])
						== s->enxoro && s->piece[s->curm_y][s->curm_x] == '*')
				return (100);
			s->curm_x++;
		}
		s->curm_y++;
	}
	return (overlap);
}

void	ft_play_generic(t_state *s)
{
	s->curb_y = 0;
	while (s->curb_y < s->fnl_by - s->fnl_py)
	{
		s->curb_x = 0;
		while (s->curb_x <= s->fnl_bx - s->fnl_px)
		{
			if (ft_isvalid(s) == 1 && s->played == 0)
			{
				ft_printoutput(s);
				s->played = 1;
			}
			s->curb_x++;
		}
		s->curb_y = s->curb_y + 1;
	}
	if (s->played == 0)
	{
		s->finished = 1;
		ft_putendl("999 999");
	}
}
