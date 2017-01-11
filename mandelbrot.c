/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:21:51 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/11 09:26:54 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			is_in_mandelbrot(double x, double y, t_fractal man, t_env *env)
{
	int			i;
	t_cplx_nb	c;
	t_cplx_nb	z;
	double		tmp;

	i = 0;
	c.r = x / man.scale + man.x1;
	c.i = y / man.scale + man.y1;
	z.r = 0;
	z.i = 0;
	while ((z.r * z.r) + (z.i * z.i) < 4 && i++ < man.imax)
	{
		tmp = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * z.i * tmp) + c.i;
	}
	if (i == man.imax + 1)
		img_put_pixel(env, x, y, color_scale(env->man->c, env->man->pattern));
	else
		img_put_pixel(env, x, y, color_scale(((i + (env->man->c / 10))
						* 15) + 100, env->man->pattern));
}

void			mandelbrot(t_env *env)
{
	double		hx;
	double		hy;
	double		x;
	double		y;

	zoom_in_out(env->man, hx, hy, 4);
	y = -1;
	while (y++ < env->man->img_y)
	{
		x = -1;
		while (x++ < env->man->img_x)
			is_in_mandelbrot(x, y, *env->man, env);
	}
}
