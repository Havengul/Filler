#include "filler.h"

void	ft_xoro(t_state *s)
{
	char	*str;
	char	**splitstr;

	get_next_line(0, &str);
	splitstr = ft_strsplit(str, ' ');
	if (ft_strcmp(splitstr[2], "p1") == 0)
	{
		s->xoro = 'o';
		s->enxoro = 'x';
	}
	else
	{
		s->xoro = 'x';
		s->enxoro = 'o';
	}
	free(str);
}

void	ft_get_board(t_state *s)
{
	char	*str;
	char	**splitstr;
	int		i;

	i = -1;
	get_next_line(0, &str);
	if (str == NULL)
		return ;
	splitstr = ft_strsplit(str, ' ');
	s->fnl_by = ft_atoi(splitstr[1]);
	s->fnl_bx = ft_atoi(splitstr[2]);
	s->board = (char **)ft_memalloc(sizeof(char *) * (s->fnl_by + 2));
	//line might be all fucked up below
	while (i++ < s->fnl_by)
		s->board[i] = ft_strnew(s->fnl_bx + 1);
	get_next_line(0, &str);
	i = 0;
	while (i < s->fnl_by)
	{
		get_next_line(0, &str);
		splitstr = ft_strsplit(str, ' ');
		ft_strcpy(s->board[i], splitstr[1]);
		i++;
	}
}

void	ft_get_piece(t_state *s)
{
	char	*str;
	char	**splitstr;
	int		i;

	i = 0;
	get_next_line(0, &str);
	if (str == NULL)
		return ;
	splitstr = ft_strsplit(str, ' ');
	s->fnl_py = ft_atoi(splitstr[1]);
	s->fnl_px = ft_atoi(splitstr[2]);
	s->piece = (char **)ft_memalloc(sizeof(char *) * (s->fnl_py + 1));
	while (i < s->fnl_py)
	{
		s->piece[i] = ft_strnew(s->fnl_px + 1);
		i++;
	}
	i = 0;
	while (i < s->fnl_py)
	{
		get_next_line(0, &str);
		ft_strcpy(s->piece[i], str);
		i++;
	}
}

void	ft_input(t_state *s)
{
	ft_get_board(s);
	ft_get_piece(s);
	ft_shave(s);
}
