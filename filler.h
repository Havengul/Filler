/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 17:33:42 by lchimes           #+#    #+#             */
/*   Updated: 2017/06/13 12:50:53 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_state
{
	char	**board;
	char	**piece;
	int		fnl_bx;
	int		fnl_by;
	int		fnl_px;
	int		fnl_py;
	int		curm_y;
	int		curm_x;
	int		curb_y;
	int		curb_x;
	int 	finished;
	char	xoro;
	char	enxoro;
	int 	start_sector;
	int		en_start_sector;
	int 	wall_complete;
	int 	played;
	size_t	longest;
	int		adjust_x;
	int 	adjust_y;
	int 	star_found;
	int 	picked_side;

}				t_state;

void	ft_input(t_state *s);
void	ft_xoro(t_state *s);
void	ft_play_generic(t_state *s);
void    ft_printoutput(t_state *s);
int		ft_isvalid(t_state *s);
void	ft_shave(t_state *s);
void	ft_printvars(t_state *s);

#endif
