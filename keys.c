/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:44:40 by ebednar           #+#    #+#             */
/*   Updated: 2019/02/14 14:13:46 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mouse(int key, int x, int y, t_fractal *fr)
{
	if (key == 4 || key == 1)
	{
		fr->xc1 = (x / fr->zoom + fr->xc1) - (x / (fr->zoom * 1.3));
		fr->yc1 = (y / fr->zoom + fr->yc1) - (y / (fr->zoom * 1.3));
		fr->zoom *= 1.3;
		fr->iter++;
	}
	if (key == 5 || key == 2)
	{
		fr->xc1 = (x / fr->zoom + fr->xc1) - (x / (fr->zoom / 1.3));
		fr->yc1 = (y / fr->zoom + fr->yc1) - (y / (fr->zoom / 1.3));
		fr->zoom /= 1.3;
		fr->iter--;
	}
	threads(fr);
	return (0);
}

static int	keys(int key, t_fractal *fr)
{
	if (key == 53)
		exit(0);
	if (key == 123)
		fr->xc1 += 40 / fr->zoom;
	if (key == 124)
		fr->xc1 -= 40 / fr->zoom;
	if (key == 125)
		fr->yc1 -= 40 / fr->zoom;
	if (key == 126)
		fr->yc1 += 40 / fr->zoom;
	if (key == 49)
		fr->iter += 5;
	if (key == 82)
		init_fr(fr);
	if (key == 36)
		fr->flag *= -1;
	threads(fr);
	return (0);
}

static int	cross(void *s)
{
	(void)s;
	exit(0);
}

static int	mouse_julia(int x, int y, t_fractal *fr)
{
	if (fr->fr_nb == 2 && fr->flag == -1)
	{
		fr->cr = x * 2;
		fr->ci = y * 2 - 800;
		threads(fr);
	}
	return (0);
}

void		press_key(t_fractal *fr)
{
	mlx_key_hook(fr->win_ptr, keys, fr);
	mlx_hook(fr->win_ptr, 17, 0, cross, 0);
	mlx_mouse_hook(fr->win_ptr, mouse, fr);
	mlx_hook(fr->win_ptr, 6, 1L < 6, mouse_julia, fr);
}
