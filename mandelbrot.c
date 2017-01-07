/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:21:51 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/07 05:49:43 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		is_in_fractal(double x, double y, t_man man, t_env *env)
{
	int		i;
	double	c_r;
	double	c_i;
	double	z_r;
	double	tmp;
	double	z_i;

	i = 0;
	c_r = x / man.scale + man.x1;
	c_i = y / man.scale + man.y1;
	z_r = 0;
	z_i = 0;
//	z_r = c_r;
//	z_i = c_i;
	while ((z_r * z_r) + (z_i * z_i) < 4 && i++ < man.imax)
	{
		tmp = z_r;
		z_r = (z_r * z_r) - (z_i * z_i) + c_r;
		z_i = (2 * z_i * tmp) + c_i;
	}
	if (i == man.imax + 1)
		img_put_pixel(env, x, y, color_scale(env->man_c));
	else
		img_put_pixel(env, x, y,
				color_scale(((i + (env->man_c / 10)) * 15) + 100));
}

void		mandelbrot(t_env *env)
{
	t_man	man;
	double	img_x;
	double	img_y;
	double	x;
	double	y;

	man.scale = (WIN_LENGHT / 2.7) + env->man_zoom;
	man.x1 = -2.1;
	man.x2 = 0.6;
	man.y1 = -1.2;
	//plus man.scale/zoom > moins les changements ont d'effet
	man.y2 = 1.2;
	man.imax = 42;
	img_x = (man.x2 - man.x1) * man.scale;
	img_y = (man.y2 - man.y1) * man.scale;
	y = -1;
	while (y++ < img_y)
	{
		x = -1;
		while (x++ < img_x)
			is_in_fractal(x, y, man, env);
	}
}
