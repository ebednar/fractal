/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:24:27 by ebednar           #+#    #+#             */
/*   Updated: 2019/02/13 17:55:03 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot(t_fractal *fr)
{
	fr->xc1 = -2.3;
	fr->yc1 = -1.5;
	fr->iter = 10;
	fr->colour = 46462;
	fr->zoom = 200;
	threads(fr);
}

static void	julia(t_fractal *fr)
{
	fr->xc1 = -2.5;
	fr->yc1 = -2.5;
	fr->iter = 10;
	fr->colour = 26265;
	fr->zoom = 200;
	fr->cr = 1;
	fr->ci = 1.1;
	fr->flag = 1;
	threads(fr);
}

static void	burning_ship(t_fractal *fr)
{
	fr->xc1 = -2.3;
	fr->yc1 = -1.5;
	fr->iter = 10;
	fr->colour = 0xFF8800;
	fr->zoom = 200;
	threads(fr);
}

static void	mandelbrot_cub(t_fractal *fr)
{
	fr->xc1 = -2.3;
	fr->yc1 = -1.5;
	fr->iter = 10;
	fr->colour = 46462;
	fr->zoom = 200;
	threads(fr);
}

void		init_fr(t_fractal *fr)
{
	if (fr->fr_nb == 1)
		mandelbrot(fr);
	if (fr->fr_nb == 2)
		julia(fr);
	if (fr->fr_nb == 3)
		burning_ship(fr);
	if (fr->fr_nb == 4)
		mandelbrot_cub(fr);
}
