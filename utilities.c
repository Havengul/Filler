//
// Created by Jahne ERASMUS on 2017/06/20.
//

# include "filler.h"

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
}

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

void	ft_printoutput(t_state *s)
{
	ft_putnbr(s->curb_y - s->adjust_y);
	ft_putchar(' ');
	ft_putnbr(s->curb_x - s->adjust_x);
	ft_putchar('\n');
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