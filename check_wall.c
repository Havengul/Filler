//
// Created by Jahne ERASMUS on 2017/06/20.
//

# include "filler.h"

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
}