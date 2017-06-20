//
// Created by Jahne ERASMUS on 2017/06/20.
//

#include "filler.h"

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