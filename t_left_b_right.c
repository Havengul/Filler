//
// Created by Jahne ERASMUS on 2017/06/20.
//


#include "filler.h"

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

void	ft_tl_br_wall(t_state *s)
{
	if (ft_check_top_wall(s) == 0 && ft_check_left_wall(s) == 0) // if we arnt touching top or left with our pieces
		ft_tl_wall(s); // build a wall to the top left
	else
		ft_br_wall(s); // otherwise build a wall to the bottom right
}