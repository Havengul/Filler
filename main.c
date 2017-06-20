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

void	ft_printvars(t_state *s)
{
	int		i;

	i = 0;
	while (i < s->fnl_by)
	{
		ft_putendl(s->board[i]);
		i++;
	}
	i = 0;
	ft_putchar('\n');
	while (i < s->fnl_py)
	{
		ft_putendl(s->piece[i]);
		i++;
	}
}

void	ft_init(t_state *s)
{
	s->finished = 0;
	s->board = NULL;
	s->piece = NULL;
	s->fnl_bx = 0;
	s->fnl_by = 0;
	s->fnl_px = 0;
	s->fnl_py = 0;
	s->curm_x = 0;
	s->curm_y = 0;
	s->curb_x = 0;
	s->curb_y = 0;
	s->start_sector = 1;
	s->wall_complete = 0;
	s->played = 0;
	s->longest = 0;
	s->adjust_x = 0;
	s->adjust_y = 0;
	s->star_found = 0;
	s->picked_side = 0;
}

void	ft_printoutput(t_state *s)
{
	ft_putnbr(s->curb_y - s->adjust_y);
	ft_putchar(' ');
	ft_putnbr(s->curb_x - s->adjust_x);
	ft_putchar('\n');
}

void	ft_en_which_sector(t_state *s)
{
	if (s->curb_y <= s->fnl_by / 2) // if its in the top half of the board
	{
		if (s->curb_x <= s->fnl_bx / 2) // and in the left half
			s->en_start_sector = 1; // its a top left sector start;
		else
			s->en_start_sector = 2; // its a top right sector start;
	}
	else // its in the bottom half of the board
	{
		if (s->curb_x <= s->fnl_bx / 2) // and its in the left half
			s->en_start_sector = 3; // its a bottom left sector start;
		else
			s->en_start_sector = 4; // its a bottom right sector start;
	}
}

void	ft_which_sector(t_state *s)
{
	if (s->curb_y <= s->fnl_by / 2) // if its in the top half of the board
	{
		if (s->curb_x <= s->fnl_bx / 2) // and in the left half
			s->start_sector = 1; // its a top left sector start;
		else
			s->start_sector = 2; // its a top right sector start;
	}
	else // its in the bottom half of the board
	{
		if (s->curb_x <= s->fnl_bx / 2) // and its in the left half
			s->start_sector = 3; // its a bottom left sector start;
		else
			s->start_sector = 4; // its a bottom right sector start;
	}
}

void	ft_en_start_sector(t_state *s)
{
	int 	found;

	found = 0;		// var to show we have found our startpoint
	s->curb_y = 0;
	while(!found && s->curb_y <= s->fnl_by) // while we havent found a start and we are still in Y bounds
	{
		s->curb_x = 0;
		while (!found && s->curb_x <= s->fnl_bx) // same as above but for x values
		{
			if (ft_tolower(s->board[s->curb_y][s->curb_x]) == s->enxoro) // if the co-ordinates we are looking at on the board contains our piece
			{
				found = 1;
				ft_en_which_sector(s); // remember, curb_x and curb_y are being passed through the struct too, their values stay the same in both functions
			}
			s->curb_x++;
		}
		s->curb_y++;
	}
	s->curb_y = 0; // for safety's sake I reset the variables to prevent issues in other functions
	s->curb_x = 0; // I dont think it's caused problems yet but lets rather be safe.
}

void	ft_start_sector(t_state *s)
{
	int 	found;

	found = 0;		// var to show we have found our startpoint
	s->curb_y = 0;
	while(!found && s->curb_y <= s->fnl_by) // while we havent found a start and we are still in Y bounds
	{
		s->curb_x = 0;
		while (!found && s->curb_x <= s->fnl_bx) // same as above but for x values
		{
			if (ft_tolower(s->board[s->curb_y][s->curb_x]) == s->xoro) // if the co-ordinates we are looking at on the board contains our piece
			{
				found = 1;
				ft_which_sector(s); // remember, curb_x and curb_y are being passed through the struct too, their values stay the same in both functions
			}
			s->curb_x++;
		}
		s->curb_y++;
	}
	s->curb_y = 0; // for safety's sake I reset the variables to prevent issues in other functions
	s->curb_x = 0; // I dont think it's caused problems yet but lets rather be safe.
}

int 	ft_check_top_wall(t_state *s)
{
	s->curb_x = 0;
	while (s->curb_x <= s->fnl_bx) // loop through top row
	{
		if (ft_tolower(s->board[0][s->curb_x]) == s->xoro) // if we find our own piece
			return (1); // we have a wall on the top row;
		s->curb_x++;
	}
	return (0); // we have no wall on the top row;
}

int 	ft_check_bot_wall(t_state *s)
{
	s->curb_x = 0;
	while (s->curb_x <= s->fnl_bx) // loop through bot row
	{
		if (ft_tolower(s->board[s->fnl_by - 1][s->curb_x]) == s->xoro) // if we find our own piece
			return (1); // we have a wall on the bot row;
		s->curb_x++;
	}
	return (0); // we have no wall on the bot row;
}

int 	ft_check_left_wall(t_state *s)
{
	s->curb_y = 0;
	while (s->curb_y <= s->fnl_by) // loop through left row
	{
		if (ft_tolower(s->board[s->curb_y][0]) == s->xoro) // if we find our own piece
			return (1); // we have a wall on the left row;
		s->curb_y++;
	}
	return (0); // we have no wall on the left row;
}

int 	ft_check_right_wall(t_state *s)
{
	s->curb_y = 0;
	while (s->curb_y <= s->fnl_by) // loop through right row
	{
		if (ft_tolower(s->board[s->curb_y][s->fnl_bx]) == s->xoro) // if we find our own piece
			return (1); // we have a wall on the right row;
		s->curb_y++;
	}
	return (0); // we have no wall on the right row;
}

int		ft_ffxr(t_state *s) // find first xoro right
{
	int 	ret;

	ret = s->fnl_bx; //start at the right
	while (ret >= 0)
	{
		if (ft_tolower(s->board[s->curb_y][ret]) == s->xoro)  //moving left, if you find an allied piece thats where the right most one is
			return (ret);
		ret--;
	}
	return (ret);
}

int		ft_ffxl(t_state *s) // find first xoro left
{
	int 	ret;

	ret = 0; //start at the left
	while (ret < s->fnl_bx)
	{
		if (ft_tolower(s->board[s->curb_y][ret]) == s->xoro)  //moving right, if you find an allied piece thats where the left most one is
			return (ret);
		ret++;
	}
	return (ret);
}

void	ft_pick_side(t_state *s)
{
	s->wall_complete = 1;
}

void	ft_check_walls(t_state *s)
{
	s->curb_y = 0;
	s->curb_x = 0;
	if (s->start_sector == 2 || s->start_sector == 3) // if we building a wall from top right to bot left
		if (ft_check_top_wall(s) == 1 || ft_check_right_wall(s) == 1) // we dont want the wall to be considered done until it reaches opposite ends
			if (ft_check_bot_wall(s) == 1 || ft_check_left_wall(s) == 1)
				s->wall_complete = 1; // we have a wall;
	if (s->start_sector == 1 || s->start_sector == 4) // if we building a wall from top left to bot right
		if (ft_check_top_wall(s) == 1 || ft_check_left_wall(s) == 1) // we dont want the wall to be considered done until it reaches opposite ends
			if (ft_check_bot_wall(s) == 1 || ft_check_right_wall(s) == 1)
				s->wall_complete = 1; // we have a wall;
	s->curb_y = 0; // for safety's sake I reset the variables to prevent issues in other functions
	s->curb_x = 0; // I dont think it's caused problems yet but lets rather be safe.
	if (s->wall_complete == 1 && s->picked_side == 0)
	{
		ft_pick_side(s);
		s->picked_side = 1;
	}
}

void	ft_tl_wall(t_state *s)
{
	// builds a wall to the top left
	s->curb_y = 0; // starts on top
	while (s->curb_y < s->fnl_by) // and goes down
	{
		s->curb_x = 0;	//starts on left
		while (s->curb_x <= s->fnl_bx) // and goes right
		{
			if (ft_isvalid(s) == 1 && s->played == 0) // if the move is legal
			{
				ft_printoutput(s); // play it
				s->played = 1;  // and end
			}
			s->curb_x++;
		}
		s->curb_y = s->curb_y + 1;
	}
}

void	ft_br_wall(t_state *s)
{
	// builds a wall to the bottom right
	s->curb_y = s->fnl_by; // starts on bot (and a little up to prevent out of bounds)
	while (s->curb_y >= 0) // and goes up
	{
		s->curb_x = s->fnl_bx;	//starts on right (and a little left to prevent out of bounds)
		while (s->curb_x >= 0) // and goes right
		{
			if (ft_isvalid(s) == 1 && s->played == 0) // if the move is legal
			{
				ft_printoutput(s); // play it
				s->played = 1;  // and end
			}
			s->curb_x--;
		}
		s->curb_y--;
	}
}

void	ft_tr_wall(t_state *s)
{
	// builds a wall to the top right
	s->curb_y = 0; // starts on top
	while (s->curb_y < s->fnl_by) // and goes down
	{
		s->curb_x = s->fnl_bx;	//starts on right (and a little left to prevent out of bounds)
		while (s->curb_x >= 0) // and goes right
		{
			if (ft_isvalid(s) == 1 && s->played == 0) // if the move is legal
			{
				ft_printoutput(s); // play it
				s->played = 1;  // and end
			}
			s->curb_x--;
		}
		s->curb_y++;
	}
}

void	ft_bl_wall(t_state *s)
{
	// builds a wall to the bottom left
	s->curb_y = s->fnl_by; // starts on bot (and a little up to prevent out of bounds)
	while (s->curb_y >= 0) // and goes up
	{
		s->curb_x = 0;	//starts on right (and a little left to prevent out of bounds)
		while (s->curb_x < s->fnl_bx - s->fnl_px) // and goes right
		{
			if (ft_isvalid(s) == 1 && s->played == 0) // if the move is legal
			{
				ft_printoutput(s); // play it
				s->played = 1;  // and end
			}
			s->curb_x++;
		}
		s->curb_y--;
	}
}

void	ft_tl_br_wall(t_state *s)
{
	if (ft_check_top_wall(s) == 0 && ft_check_left_wall(s) == 0) // if we arnt touching top or left with our pieces
		ft_tl_wall(s); // build a wall to the top left
	else
		ft_br_wall(s); // otherwise build a wall to the bottom right
}

void	ft_tr_bl_wall(t_state *s)
{
	if (ft_check_top_wall(s) == 0 && ft_check_right_wall(s) == 0) // if we arnt touching top or right with our pieces
		ft_tr_wall(s); // build a wall to the top right
	else
		ft_bl_wall(s); // otherwise build a wall to the bottom left
}

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
