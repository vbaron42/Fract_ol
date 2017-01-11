/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:18:17 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/11 09:19:26 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			is_in_julia(double x, double y, t_fractal jul, t_env *env)
{
	int			i;
	t_cplx_nb	c;
	t_cplx_nb	z;
	double		tmp;

	i = 0;
	c.r = env->jul->c_r;
	c.i = env->jul->c_i;
	z.r = x / jul.scale + jul.x1;
	z.i = y / jul.scale + jul.y1;
	while ((z.r * z.r) + (z.i * z.i) < 4 && i++ < jul.imax)
	{
		tmp = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * z.i * tmp) + c.i;
	}
	if (i == jul.imax + 1)
		img_put_pixel(env, x, y, color_scale(env->jul->c, env->jul->pattern));
	else
		img_put_pixel(env, x, y, color_scale(((i + (env->jul->c / 10))
						* 15) + 100, env->jul->pattern));
}

void			julia(t_env *env)
{
	double		hx;
	double		hy;
	double		x;
	double		y;

	if (env->jul->zoom == 0 && env->jul->freeze == 0)
	{
		env->jul->c_r = env->jul->move_x / env->jul->scale + env->jul->x1;
		env->jul->c_i = env->jul->move_y / env->jul->scale + env->jul->y1;
	}
	else
		zoom_in_out(env->jul, hx, hy, 4);
	y = -1;
	while (y++ < env->jul->img_y)
	{
		x = -1;
		while (x++ < env->jul->img_x)
			is_in_julia(x, y, *env->jul, env);
	}
}
