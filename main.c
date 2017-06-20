/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 22:48:40 by lchimes           #+#    #+#             */
/*   Updated: 2017/06/20 22:48:42 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_play(t_state *s)
{
	s->fnl_py--;
	ft_check_walls(s);
	if (s->wall_complete == 0)
	{
		if (s->start_sector == 1 || s->start_sector == 4)
			ft_tl_br_wall(s);
		else if (s->start_sector == 2 || s->start_sector == 3)
			ft_tr_bl_wall(s);
	}
	else if (s->en_start_sector == 1)
		ft_fill_tl(s);
	else if (s->en_start_sector == 2)
		ft_fill_tr(s);
	else if (s->en_start_sector == 3)
		ft_fill_bl(s);
	else
		ft_fill_br(s);
	if (s->played == 0)
		ft_play_generic(s);
}

int		main(void)
{
	t_state s;

	ft_init(&s);
	ft_xoro(&s);
	ft_input(&s);
	ft_start_sector(&s);
	ft_en_start_sector(&s);
	ft_play(&s);
	while (s.finished == 0)
	{
		ft_input(&s);
		s.played = 0;
		ft_play(&s);
	}
	return (0);
}
