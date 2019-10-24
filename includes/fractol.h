/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:17:14 by ebednar           #+#    #+#             */
/*   Updated: 2019/02/13 17:56:00 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define BPP 4
# define WIDTH 1000
# define HEIGHT 1000

# include <mlx.h>
# include "libft.h"
# include <math.h>
# include <pthread.h>

typedef struct	s_fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img;
	int			fr_nb;
	int			bpp;
	int			size_line;
	int			endian;
	int			iter;
	int			colour;
	int			x;
	int			y;
	int			y_max;
	int			i;
	int			flag;
	double		xc1;
	double		yc1;
	double		zoom;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	double		tmp;
}				t_fractal;

void			press_key(t_fractal *fr);
void			init_fr(t_fractal *fr);
void			*calc_fr(void *fr);
void			fr_nb(t_fractal *fr);
void			draw_man(t_fractal *fr);
void			threads(t_fractal *fr);
void			draw_julia(t_fractal *fr);
void			draw_ship(t_fractal *fr);
void			draw_man_cub(t_fractal *fr);

#endif
