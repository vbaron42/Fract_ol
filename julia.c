/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:18:17 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/11 08:39:02 by vbaron           ###   ########.fr       */
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

void			zoom_in_out2(t_env *env, double hx, double hy)
{
	env->jul->img_x /= env->jul->scale;
	env->jul->img_y /= env->jul->scale;
	if (env->jul->zoom == 1)
	{
		hx = env->jul->img_x / 4;
		hy = env->jul->img_y / 4;
		env->jul->scale *= 2;
		env->jul->imax += 4;
	}
	else
	{
		hx = env->jul->img_x;
		hy = env->jul->img_y;
		env->jul->scale /= 2;
		env->jul->imax -= 4;
	}
	env->jul->x1 += ((env->jul->m_x / WIN_LENGHT) * env->jul->img_x) - hx;
	env->jul->x2 = env->jul->x1 + (hx * 2);
	env->jul->y1 += ((env->jul->m_y / WIN_HEIGHT) * env->jul->img_y) - hy;
	env->jul->y2 = env->jul->y1 + (hy * 2);
	env->jul->img_x = (env->jul->x2 - env->jul->x1) * env->jul->scale;
	env->jul->img_y = (env->jul->y2 - env->jul->y1) * env->jul->scale;
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
	else if (env->jul->zoom != 0)
		zoom_in_out2(env, hx, hy);
	y = -1;
	while (y++ < env->jul->img_y)
	{
		x = -1;
		while (x++ < env->jul->img_x)
			is_in_julia(x, y, *env->jul, env);
	}
}
