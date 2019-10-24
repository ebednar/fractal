/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:45:09 by ebednar           #+#    #+#             */
/*   Updated: 2019/02/13 18:06:21 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fr_nb(t_fractal *fr)
{
	if (fr->fr_nb == 1)
		draw_man(fr);
	if (fr->fr_nb == 2)
		draw_julia(fr);
	if (fr->fr_nb == 3)
		draw_ship(fr);
	if (fr->fr_nb == 4)
		draw_man_cub(fr);
}

void	*calc_fr(void *fr_thr)
{
	t_fractal	*fr;
	int			tmp;

	fr = (t_fractal *)fr_thr;
	fr->x = 0;
	tmp = fr->y;
	while (fr->x < WIDTH)
	{
		fr->y = tmp;
		while (fr->y < fr->y_max)
		{
			fr_nb(fr);
			fr->y++;
		}
		fr->x++;
	}
	return (fr_thr);
}
