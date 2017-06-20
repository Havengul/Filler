/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_corner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 22:27:42 by lchimes           #+#    #+#             */
/*   Updated: 2017/06/20 22:28:19 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_fill_tl(t_state *s)
{
	s->curb_y = 0;
	while (s->curb_y < s->fnl_by)
	{
		s->curb_x = 0;
		while (s->curb_x < s->fnl_bx && s->curb_x < ft_ffxl(s) + s->fnl_px)
		{
			if (ft_isvalid(s) == 1 && s->played == 0)
			{
				ft_printoutput(s);
				s->played = 1;
			}
			s->curb_x++;
		}
		s->curb_y++;
	}
}

void	ft_fill_tr(t_state *s)
{
	s->curb_y = 0;
	while (s->curb_y < s->fnl_by)
	{
		s->curb_x = s->fnl_bx;
		while (s->curb_x >= 0 && s->curb_x > ft_ffxr(s) - s->fnl_px)
		{
			if (ft_isvalid(s) == 1 && s->played == 0)
			{
				ft_printoutput(s);
				s->played = 1;
			}
			s->curb_x--;
		}
		s->curb_y++;
	}
}

void	ft_fill_bl(t_state *s)
{
	s->curb_y = s->fnl_by;
	while (s->curb_y >= 0)
	{
		s->curb_x = 0;
		while (s->curb_x < s->fnl_bx && s->curb_x < ft_ffxl(s) + s->fnl_px)
		{
			if (ft_isvalid(s) == 1 && s->played == 0)
			{
				ft_printoutput(s);
				s->played = 1;
			}
			s->curb_x++;
		}
		s->curb_y--;
	}
}

void	ft_fill_br(t_state *s)
{
	s->curb_y = s->fnl_by;
	while (s->curb_y >= 0)
	{
		s->curb_x = s->fnl_bx;
		while (s->curb_x >= 0 && s->curb_x > ft_ffxr(s) - s->fnl_px)
		{
			if (ft_isvalid(s) == 1 && s->played == 0)
			{
				ft_printoutput(s);
				s->played = 1;
			}
			s->curb_x--;
		}
		s->curb_y--;
	}
}
