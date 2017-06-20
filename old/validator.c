/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newval.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 13:03:33 by lchimes           #+#    #+#             */
/*   Updated: 2017/06/13 12:21:12 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*void			ft_putboard(char **arr) // FOR TESTING PURPOSES ONLY
{
	int		i;

	i = 0;
	while (arr[i])
	{
		ft_putstr(arr[i]);
		ft_putchar('\n');
		i++;
	}
}*/

static char		ft_curbcal(t_state s, t_temp t)
{
	if ((t.y > s.fnl_by - s.fnl_py) || (t.x > s.fnl_bx - s.fnl_px))
		return ('a');
	else if (t.y < 0 || t.x < 0)
		return ('a');
	else
		return (s.board[t.y + t.curm_y][t.x + t.curm_x]);
}

static void		ft_changepiece(t_state *s)
{
	int		x;
	int		y;

	y = 0;
	while (y <= s->fnl_py)
	{
		x = 0;
		while (x <= s->fnl_px)
		{
			if (s->piece[y][x] == '*')
				(s->piece[y][x]) = s->xoro;
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
	s.fnl_bx = 1;
	//ft_putstr("<got (");
	//ft_putchar(ft_toupper(s.xoro));
	//ft_putstr(") : [");
	ft_putnbr(t.y);
	//ft_putchar(' ');
	//ft_putnbr(t.x);
	//ft_putstr("] (");
	//ft_putnbr(t.y);
	//ft_putchar(',');
	ft_putchar(' ');
	ft_putnbr(t.x);
	ft_putchar('\n');
	//ft_putstr(")\n");
}

static void		ft_bottomright(t_state s, t_temp t)
{
	int		done;

	done = 0;
	t.y = 0;
	t.x = 0;
	ft_changepiece(&s);
	while (t.y <= s.fnl_by - s.fnl_py)
	{
		while (t.x <= s.fnl_bx - s.fnl_px)
		{
			if (ft_isvalid(s, t) == 1)
			{
				ft_printoutput(s, t);
				done = 1;
				t.x = s.fnl_bx - s.fnl_px;
				t.y = s.fnl_by - s.fnl_py;
			}
			t.x++;
		}
		t.x = 0;
		t.y++;
	}
	if (done == 0)
		ft_putstr("0 0\n");
}

static void		ft_bottomleft(t_state s, t_temp t)
{
	int		done;

	done = 0;
	t.y = 0;
	t.x = s.fnl_bx - s.fnl_px;
	ft_changepiece(&s);
	while (t.y <= s.fnl_by - s.fnl_py)
	{
		while (t.x >= 0)
		{
			if (ft_isvalid(s, t) == 1)
			{
				ft_printoutput(s, t);
				done = 1;
				t.x = 0;
				t.y = s.fnl_by - s.fnl_py;
			}
			t.x--;
		}
		t.x = s.fnl_bx - s.fnl_px;
		t.y++;
	}
	if (done == 0)
		ft_putstr("0 0\n");
}

static void		ft_topright(t_state s, t_temp t)
{
	int		done;

	done = 0;
	t.y = s.fnl_by - s.fnl_py;
	t.x = 0;
	ft_changepiece(&s);
	while (t.y >= 0)
	{
		while (t.x <= s.fnl_bx - s.fnl_px)
		{
			if (ft_isvalid(s, t) == 1)
			{
				ft_printoutput(s, t);
				done = 1;
				t.x = s.fnl_bx - s.fnl_px;
				t.y = 0;
			}
			t.x++;
		}
		t.x = 0;
		t.y--;
	}
	if (done == 0)
		ft_putstr("0 0\n");
}


static void		ft_topleft(t_state s, t_temp t)
{
	int		done;

	done = 0;
	t.y = s.fnl_by - s.fnl_py;
	t.x = s.fnl_bx - s.fnl_px;
	ft_changepiece(&s);
	//ft_putboard(s.piece);
	while (t.y >= 0)
	{
		while (t.x >= 0)
		{
			if (ft_isvalid(s, t) == 1)
			{
				ft_printoutput(s, t);
				done = 1;
				t.x = 0;
				t.y = 0;
			}
			t.x--;
		}
		t.x = s.fnl_bx - s.fnl_px;
		t.y--;
	}
	if (done == 0)
		ft_putstr("0 0\n");
}

/*void			ft_validator(t_state s, t_temp t)
{
	int		done;

	done = 0;
	t.y = 0;
	t.x = 0;
	ft_changepiece(&s);
	//ft_putboard(s.piece);
	while (t.y <= s.fnl_by - s.fnl_py)
	{
		while (t.x <= s.fnl_bx - s.fnl_px)
		{
			if (ft_isvalid(s, t) == 1)
			{
				ft_printoutput(s, t);
				done = 1;
				t.x = s.fnl_bx - s.fnl_px;
				t.y = s.fnl_by - s.fnl_py;
			}
			t.x++;
		}
		t.x = -(s.fnl_px);
		t.y++;
	}
	if (done == 0)
		ft_putstr("0 0\n");
}
*/

int			ft_findstart(t_state s, t_temp t)
{
	t.y = 0;
	t.x = 0;
	while (t.y <= s.fnl_by)
	{
		while (t.x <= s.fnl_bx)
		{
			if (ft_toupper(s.board[t.y][t.x]) == ft_toupper(s.enxoro))
			{
				if (t.y >= s.fnl_by / 2 && t.x >= s.fnl_bx / 2)
					return (1); // bottom right start
				if (t.y >= s.fnl_by / 2 && t.x < s.fnl_bx / 2)
					return (2); // bottom left start
				if (t.y < s.fnl_by / 2 && t.x >= s.fnl_bx / 2)
					return (3); // top right start
				if (t.y < s.fnl_by / 2 && t.x < s.fnl_bx / 2)
					return (4); // top left start
			}
			t.x++;
		}
		t.x = 0;
		t.y++;
	}
	return (4);
}

int			ft_findenstart(t_state s, t_temp t)
{
	t.y = 0;
	t.x = 0;
	while (t.y <= s.fnl_by)
	{
		while (t.x <= s.fnl_bx)
		{
			if (ft_toupper(s.board[t.y][t.x]) == ft_toupper(s.enxoro))
			{
				if (t.y >= s.fnl_by / 2 && t.x >= s.fnl_bx / 2)
					return (1); // bottom right start
				if (t.y >= s.fnl_by / 2 && t.x < s.fnl_bx / 2)
					return (2); // bottom left start
				if (t.y < s.fnl_by / 2 && t.x >= s.fnl_bx / 2)
					return (3); // top right start
				if (t.y < s.fnl_by / 2 && t.x < s.fnl_bx / 2)
					return (4); // top left start
			}
			t.x++;
		}
		t.x = 0;
		t.y++;
	}
	return (4);
}
/*
static int	ft_bldir(int dir, t_state s)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y <= s.fnl_by)
	{
		if (s.board[y][s.fnl_bx] == s.xoro || s.board[y][s.fnl_bx - 1] == s.xoro)
			return (3);
		y++;
	}
	while (x <= s.fnl_bx)
	{
		if (s.board[0][x] == s.xoro || s.board[1][x] == s.xoro)
			return (3);
		y++;
	}
	return (dir);
}

static int	ft_trdir(int dir, t_state s)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y <= s.fnl_by)
	{
		if (s.board[y][0] == s.xoro || s.board[y][1] == s.xoro)
			return (2);
		y++;
	}
	while (x <= s.fnl_bx)
	{
		if (s.board[s.fnl_by][x] == s.xoro || s.board[s.fnl_by - 1][x] == s.xoro)
			return (2);
		y++;
	}
	return (dir);
}

static int	ft_tldir(int dir, t_state s)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y <= s.fnl_by)
	{
		if (s.board[y][s.fnl_bx] == s.xoro || s.board[y][s.fnl_bx - 1] == s.xoro)
			return (1);
		y++;
	}
	while (x <= s.fnl_bx)
	{
		if (s.board[s.fnl_by][x] == s.xoro || s.board[s.fnl_by - 1][x] == s.xoro)
			return (1);
		y++;
	}
	return (dir);
}

static int	ft_brdir(int dir, t_state s)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y <= s.fnl_by)
	{
		if (s.board[y][0] == s.xoro || s.board[y][1] == s.xoro)
			return (4);
		y++;
	}
	while (x <= s.fnl_bx)
	{
		if (s.board[0][x] == s.xoro || s.board[1][x] == s.xoro)
			return (4);
		y++;
	}
	return (dir);
}

static int	ft_newdir(int dir, t_state s)
{
	if (dir == 2)
		return (ft_bldir(dir, s));
	else if (dir == 3)
		return (ft_trdir(dir, s));
	else if (dir == 4)
		return (ft_tldir(dir, s));
	else
		return (ft_brdir(dir, s));
	
}
*/
void    	ft_validator(t_state s, t_temp t)
{
	int		dir;

	dir = s.startpos;
	//if (s.walls <= 2 && dir != newdir(dir, s))
	//{
	//	dir = newdir(dir, s);
	//	s.walls++;
	//}
	//if (s.walls == 3)
	//	dir = ft_fnldir(s, t);
	if (dir == 2)
		ft_bottomleft(s, t);
	else if (dir == 3)
		ft_topright(s, t);
	else if (dir == 4)
		ft_topleft(s, t);
	else
		ft_bottomright(s, t);
}

/*void			ft_validator(t_state s, t_temp t)
{
	int		done;

	done = 0;
	t.y = 0;
	t.x = 0;
	ft_changepiece(&s);
	//ft_putboard(s.piece);
	while (t.y <= s.fnl_by - s.fnl_py)
	{
		while (t.x <= s.fnl_bx - s.fnl_px)
		{
			if (ft_isvalid(s, t) == 1)
			{
				ft_printoutput(s, t);
				done = 1;
				t.x = s.fnl_bx - s.fnl_px;
				t.y = s.fnl_by - s.fnl_py;
			}
			t.x++;
		}
		t.x = -(s.fnl_px);
		t.y++;
	}
	if (done == 0)
		ft_putstr("0 0\n");
}
*/
