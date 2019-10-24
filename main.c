/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:16:33 by ebednar           #+#    #+#             */
/*   Updated: 2019/02/13 18:07:17 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fr_number(t_fractal *fr, char *argv)
{
	if (!ft_strcmp(argv, "mandelbrot"))
		fr->fr_nb = 1;
	else if (!ft_strcmp(argv, "julia"))
		fr->fr_nb = 2;
	else if (!ft_strcmp(argv, "burning_ship"))
		fr->fr_nb = 3;
	else if (!ft_strcmp(argv, "mandelbrot_cub"))
		fr->fr_nb = 4;
	else
	{
		ft_putendl("usage: ./fractol mandelbrot / julia / burning_ship / mandelbrot_cub");
		exit(0);
	}
}

static void	init(t_fractal *fr)
{
	fr->mlx_ptr = mlx_init();
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, WIDTH, HEIGHT, "fractol");
	fr->img_ptr = mlx_new_image(fr->mlx_ptr, WIDTH, HEIGHT);
	fr->bpp = BPP;
	fr->size_line = WIDTH * BPP;
	fr->endian = 0;
	fr->img = mlx_get_data_addr(fr->img_ptr, &(fr->bpp), \
	&(fr->size_line), &(fr->endian));
}

int			main(int argc, char **argv)
{
	t_fractal	*fr;

	if (argc == 2)
	{
		fr = (t_fractal *)malloc(sizeof(t_fractal));
		init(fr);
		fr_number(fr, argv[1]);
		init_fr(fr);
		press_key(fr);
		mlx_loop(fr->mlx_ptr);
	}
	else
		ft_putendl("usage: ./fractol mandelbrot / julia / burning_ship / mandelbrot_cub");
	return (0);
}
