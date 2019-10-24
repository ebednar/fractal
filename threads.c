/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:12:55 by ebednar           #+#    #+#             */
/*   Updated: 2019/02/13 16:55:11 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	threads(t_fractal *fr)
{
	t_fractal	fr_thr[200];
	pthread_t	t[200];
	int			i;

	i = 0;
	while (i < 200)
	{
		ft_memcpy((void *)&fr_thr[i], (void *)fr, sizeof(t_fractal));
		fr_thr[i].y = 5 * i;
		fr_thr[i].y_max = 5 * (i + 1);
		pthread_create(&t[i], NULL, calc_fr, &fr_thr[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
}
