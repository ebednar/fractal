/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:36:01 by ebednar           #+#    #+#             */
/*   Updated: 2019/02/13 18:06:40 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	img_pxl(int x, int y, t_fractal *fr, int colour)
{
	if (fr->x < WIDTH && fr->y < HEIGHT)
	{
		colour = mlx_get_color_value(fr->mlx_ptr, colour);
		ft_memcpy(fr->img + 4 * WIDTH * y + x * 4, &colour, sizeof(int));
	}
}

void		draw_man(t_fractal *fr)
{
	fr->cr = fr->x / fr->zoom + fr->xc1;
	fr->ci = fr->y / fr->zoom + fr->yc1;
	fr->zr = 0;
	fr->zi = 0;
	fr->i = 0;
	while (fr->zr * fr->zr + fr->zi * fr->zi < 4 && fr->i < fr->iter)
	{
		fr->tmp = fr->zr * fr->zr - fr->zi * fr->zi + fr->cr;
		fr->zi = 2 * fr->zr * fr->zi + fr->ci;
		fr->zr = fr->tmp;
		fr->i++;
	}
	if (fr->i == fr->iter)
		img_pxl(fr->x, fr->y, fr, 0x000000);
	else
		img_pxl(fr->x, fr->y, fr, (fr->colour * fr->i));
}

void		draw_julia(t_fractal *fr)
{
	fr->zr = fr->x / fr->zoom + fr->xc1;
	fr->zi = fr->y / fr->zoom + fr->yc1;
	fr->i = 0;
	while (fr->zr * fr->zr + fr->zi * fr->zi < 4 && fr->i < fr->iter)
	{
		fr->tmp = fr->zr;
		fr->zr = fr->zr * fr->zr - fr->zi * fr->zi - 1 + (fr->cr / WIDTH);
		fr->zi = 2 * fr->zi * fr->tmp + fr->ci / HEIGHT;
		fr->i++;
	}
	if (fr->i == fr->iter)
		img_pxl(fr->x, fr->y, fr, 0x000000);
	else
		img_pxl(fr->x, fr->y, fr, ((fr->colour * fr->i) << 6));
}

void		draw_ship(t_fractal *fr)
{
	fr->cr = fr->x / fr->zoom + fr->xc1;
	fr->ci = fr->y / fr->zoom + fr->yc1;
	fr->zr = 0;
	fr->zi = 0;
	fr->i = 0;
	while (fr->zr * fr->zr + fr->zi * fr->zi < 4 && fr->i < fr->iter)
	{
		fr->tmp = fabsl(fr->zr * fr->zr - fr->zi * fr->zi + fr->cr);
		fr->zi = fabsl(2 * fr->zr * fr->zi + fr->ci);
		fr->zr = fr->tmp;
		fr->i++;
	}
	if (fr->i == fr->iter)
		img_pxl(fr->x, fr->y, fr, 0x000000);
	else
		img_pxl(fr->x, fr->y, fr, (fr->colour * fr->i));
}

void		draw_man_cub(t_fractal *fr)
{
	fr->cr = fr->x / fr->zoom + fr->xc1;
	fr->ci = fr->y / fr->zoom + fr->yc1;
	fr->zr = 0;
	fr->zi = 0;
	fr->i = 0;
	while (fr->zr * fr->zr + fr->zi * fr->zi < 4 && fr->i < fr->iter)
	{
		fr->tmp = fr->zr * fr->zr * fr->zr - 3 * fr->zr * fr->zi \
		* fr->zi + fr->cr;
		fr->zi = 3 * fr->zr * fr->zr * fr->zi - fr->zi * fr->zi \
		* fr->zi + fr->ci;
		fr->zr = fr->tmp;
		fr->i++;
	}
	if (fr->i == fr->iter)
		img_pxl(fr->x, fr->y, fr, 0x000000);
	else
		img_pxl(fr->x, fr->y, fr, (fr->colour * fr->i));
}
