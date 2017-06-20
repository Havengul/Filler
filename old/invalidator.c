/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newval.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 13:03:33 by lchimes           #+#    #+#             */
/*   Updated: 2017/06/13 12:48:29 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_putboard(char **arr) // FOR TESTING PURPOSES ONLY
{
	int		i;

	i = 0;
	while (arr[i])
	{
		ft_putstr(arr[i]);
		ft_putchar('\n');
		i++;
	}
}

static char		ft_curbcal(t_state s, t_temp t)
{
	if ((t.y > s.fnl_by - s.fnl_py) || (t.x > s.fnl_bx - s.fnl_px))
		return ('a');
	else if (t.y < 0 || t.x < 0)
		return ('a');
	else
		return (s.board[t.y + t.curm_y][t.x + t.curm_x]);
}

static void		ft_changepiece(t_state s, char ***piece)
{
	int		x;
	int		y;
	char	***useless;

	useless = piece;
	y = 0;
	while (y <= s.fnl_py)
	{
		x = 0;
		while (x <= s.fnl_px)
		{
			//if (s.piece[y][x] == '*')
			//	(*piece[y][x]) = s.xoro;
			x++;
		}
		y++;
	}
}

static int		ft_isvalid(t_state state, t_temp temp)
{
	int		overlap;
	char	curm;
	char	curb;

	temp.curm_y = 0;
	temp.curm_x = 0;
	overlap = 0;
	while (temp.curm_y <= state.fnl_py)
	{
		while (temp.curm_x <= state.fnl_px)
		{
			curb = ft_curbcal(state, temp);
			curm = (state.piece[temp.curm_y][temp.curm_x]);
			if ((ft_toupper(curm) == ft_toupper(curb)) && (curm != '.'))
				overlap++;
			else if ((curm != '.') && (curb != '.'))
				return (9);
			temp.curm_x++;
		}
		temp.curm_y++;
		temp.curm_x = 0;
	}
	return (overlap);
}

static void		ft_printoutput(t_state s, t_temp t)
{
	ft_putstr("<got (");
	ft_putchar(ft_toupper(s.xoro));
	ft_putstr(") : [");
	ft_putnbr(t.y);
	ft_putchar(' ');
	ft_putnbr(t.x);
	ft_putstr("] (");
	ft_putnbr(t.y);
	ft_putchar(',');
	ft_putnbr(t.x);
	ft_putstr(")\n");
}

static void		ft_bottomright(t_state s, t_temp t)
{
	t.y = 0;
	t.x = 0;
	ft_changepiece(s, &s.piece);
	while (t.y <= s.fnl_by - s.fnl_py)
	{
		while (t.x <= s.fnl_bx - s.fnl_px)
		{
			if (ft_isvalid(s, t) == 1)
			{
				ft_printoutput(s, t);
				t.x = s.fnl_bx - s.fnl_px;
				t.y = s.fnl_by - s.fnl_py;
			}
			t.x++;
		}
		t.x = 0;
		t.y++;
	}
}

static void		ft_bottomleft(t_state s, t_temp t)
{
	t.y = 0;
	t.x = s.fnl_bx - s.fnl_px;
	ft_changepiece(s, &s.piece);
	while (t.y <= s.fnl_by - s.fnl_py)
	{
		while (t.x >= 0)
		{
			if (ft_isvalid(s, t) == 1)
			{
				ft_printoutput(s, t);
				t.x = 0;
				t.y = s.fnl_by - s.fnl_py;
			}
			t.x--;
		}
		t.x = s.fnl_bx - s.fnl_px;
		t.y++;
	}
}

static void		ft_topright(t_state s, t_temp t)
{
	t.y = s.fnl_by - s.fnl_py;
	t.x = 0;
	//ft_changepiece(s, &s.piece);
	//ft_putboard(s.piece);
	while (t.y >= 0)
	{
		while (t.x <= s.fnl_bx - s.fnl_px)
		{
			if (ft_isvalid(s, t) == 1)
			{
				ft_printoutput(s, t);
				t.x = s.fnl_bx - s.fnl_px;
				t.y = s.fnl_by - s.fnl_py;
			}
			t.x++;
		}
		t.x = 0;
		t.y--;
	}
}

static void		ft_topleft(t_state s, t_temp t)
{
	t.y = s.fnl_by - s.fnl_py;
	t.x = s.fnl_bx - s.fnl_px;
	//ft_changepiece(s, &s.piece);
	//ft_putboard(s.piece);
	while (t.y >= 0)
	{
		while (t.x >= 0)
		{
			if (ft_isvalid(s, t) == 1)
			{
				ft_printoutput(s, t);
				t.x = s.fnl_bx - s.fnl_px;
				t.y = s.fnl_by - s.fnl_py;
			}
			t.x--;
		}
		t.x = -(s.fnl_px);
		t.y--;
	}
}

int			ft_findstart2(t_state s, t_temp t)
{
	t.y = 0;
	t.x = 0;
	while (t.y <= s.fnl_by)
	{
		while (t.x <= s.fnl_bx)
		{
			if (s.board[t.y][t.x] == s.xoro)
			{
				if (t.y >= s.fnl_by / 2 && t.x >= s.fnl_bx / 2)
					return (1); // bottom right start
				else if (t.y >= s.fnl_by / 2 && t.x < s.fnl_bx / 2)
					return (2); // bottom left start
				else if (t.y < s.fnl_by / 2 && t.x >= s.fnl_bx / 2)
					return (3); // top right start
				else
					return (4); // top left start
			}
			t.x++;
		}
		t.x = 0;
		t.y++;
	}
	return (1);
}

void		ft_validator(t_state s, t_temp t)
{
	if (s.startpos == 2)
	{
		ft_bottomleft(s, t);
		ft_putstr("botleft\n");
	}
	else if (s.startpos == 3)
	{
		ft_topright(s, t);
		ft_putstr("topright\n");
	}
	else if (s. startpos == 4)
	{
		ft_topleft(s, t);
		ft_putstr("topleft\n");
	}
	else
	{
		ft_bottomright(s, t);
		ft_putstr("botright\n");
	}
}

/*
void			ft_validator(t_state s, t_temp t)
{
	t.y = 0;
	t.x = 0;
	ft_changepiece(s, &s.piece);
	//ft_putboard(s.piece);
	while (t.y <= s.fnl_by - s.fnl_py)
	{
		while (t.x <= s.fnl_bx - s.fnl_px)
		{
			if (ft_isvalid(s, t) == 1)
			{
				ft_printoutput(s, t);
				t.x = s.fnl_bx - s.fnl_px;
				t.y = s.fnl_by - s.fnl_py;
			}
			t.x++;
		}
		t.x = 0;
		t.y++;
	}
}*/
