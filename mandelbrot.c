/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:21:51 by vbaron            #+#    #+#             */
/*   Updated: 2016/12/30 21:46:36 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			get_man_color(double div)
{
	return (0xFFFFFF - (div * 2000));
}

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
		img_put_pixel(env, x, y, 0x903020);
	else
		img_put_pixel(env, x, y, get_man_color((z_r * z_r) + (z_i * z_i)));
}

void		mandelbrot(t_env *env)
{
	t_man	man;
	double	img_x;//int ? double ?
	double	img_y;
	double	x;
	double	y;

	man.x1 = -2.1;
	man.x2 = 0.6;
	man.y1 = -1.2;
	man.y2 = 1.2;
	man.scale = 300;
	man.imax = 1000;
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
