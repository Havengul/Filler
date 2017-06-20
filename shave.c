/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 10:30:40 by jerasmus          #+#    #+#             */
/*   Updated: 2017/06/20 10:30:42 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_shave_xy_br(t_state *s)
{
	int		i;
	char	*ret;

	i = 0;
	s->longest = (size_t)s->fnl_px;
	s->star_found = 0;
	while (i < s->fnl_py)
	{
		if (ft_strchr(s->piece[i], '*') == NULL && s->star_found == 1)
			break ;
		if (ft_strchr(s->piece[i], '*') != NULL)
			s->star_found = 1;
		i++;
	}
	s->fnl_py = i;
	i = 0;
	while (i < s->fnl_py)
	{
		ret = ft_strrchr(s->piece[i], '*');
		if (ret != NULL)
		{
			if (ft_strlen(ret) < s->longest)
				s->longest = ft_strlen(ret);
		}
		i++;
	}
}

void	ft_shave_br(t_state *s)
{
	int		i;
	char	**temp;

	i = 0;
	s->fnl_px = (int)(ft_strlen(s->piece[0]) - s->longest + 1);
	temp = (char **)ft_memalloc(sizeof(char *) * (s->fnl_py + 1));
	while (i < s->fnl_py)
	{
		temp[i] = ft_strnew((size_t)s->fnl_px + 1);
		i++;
	}
	i = 0;
	while (i < s->fnl_py)
	{
		ft_strncpy(temp[i], s->piece[i], (size_t)s->fnl_px);
		i++;
	}
	free(s->piece);
	s->piece = temp;
}


void	ft_longest(t_state *s)
{
	int 	i;
	int 	j;

	i = 0;
	s->longest = (size_t)s->fnl_px;
	while (s->piece[i])
	{
		j = 0;
		while (j < s->fnl_px)
		{
			if (s->piece[i][j] == '*')
			{
				if (j < (int)s->longest)
					s->longest = (size_t)j;
				break;
			}
			j++;
		}
		i++;
	}
}

void	ft_shave_xy_tl(t_state *s)
{
	int		i;

	i = 0;
	s->adjust_y = 0;
	s->adjust_x = 0;
	while (i < s->fnl_py)
	{
		if (ft_strchr(s->piece[i], '*') == NULL)
			s->adjust_y++;
		i++;
	}
	s->fnl_py = s->fnl_py - s->adjust_y;
	ft_longest(s);
	s->adjust_x = (int)s->longest;
	s->fnl_px = s->fnl_px - s->adjust_x;
}

void	ft_shave_tl(t_state *s)
{
	int		i;
	int		j;
	char	**temp;

	temp = (char **)ft_memalloc(sizeof(char *) * (s->fnl_py + 1));
	i = 0;
	while (i < s->fnl_py)
	{
		temp[i] = ft_strnew((size_t)s->fnl_px + 1);
		i++;
	}
	i = 0;
	j = s->adjust_y;
	while (i < s->fnl_py)
	{
		temp[i] = ft_strsub(s->piece[j], s->adjust_x, s->fnl_px);
		j++;
		i++;
	}
	free(s->piece);
	s->piece = temp;
}

void	ft_shave(t_state *s)
{
	ft_shave_xy_br(s);
	ft_shave_br(s);
	ft_shave_xy_tl(s);
	ft_shave_tl(s);
}
