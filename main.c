/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:05:02 by jerasmus          #+#    #+#             */
/*   Updated: 2017/06/19 08:48:24 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_play(t_state *s)
{
	s->fnl_py--;
	ft_check_walls(s); // checks to see if a wall has been completed;
	if (s->wall_complete == 0) // if we dont have a finished wall
	{
		if (s->start_sector == 1 || s->start_sector == 4) // if top left or bottom right start
			ft_tl_br_wall(s); // make a wall from top left to bottom right
		else if (s->start_sector == 2 || s->start_sector == 3) // if top right or bottom left start
			ft_tr_bl_wall(s); // make a wall from top right to bottom left
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
	ft_input(&s); // first time reading map
	ft_start_sector(&s); // finds which section we start in and puts it in s->start_sector
	// 1 = topleft			 _____
	// 2 = top right		|1_|_2|
	// 3 = bottom left		|3_|_4|
	// 4 = bottom right
	ft_en_start_sector(&s);
	ft_play(&s); // chooses a direction to play and does it;
	while (s.finished == 0)
	{
		ft_input(&s);
		s.played = 0;
		ft_play(&s);
	}
	return (0);
}
