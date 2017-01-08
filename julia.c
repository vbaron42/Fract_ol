/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:18:17 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/08 11:38:02 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			is_in_fractal2(double x, double y, t_man man, t_env *env)
{
	int			i;
	t_cplx_nb	c;
	t_cplx_nb	z;
	double		tmp;

	i = 0;
	c.r = 0.285;
	c.i = 0.01;
	z.r = x / man.scale + man.x1;
	z.i = y / man.scale + man.y1;
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

void			zoom_in_out2(t_env *env, double hx, double hy)
{
	if (env->man->zoom != 0)
	{
		env->man->img_x /= env->man->scale;
		env->man->img_y /= env->man->scale;
		if (env->man->zoom == 1)
		{
			hx = env->man->img_x / 4;
			hy = env->man->img_y / 4;
			env->man->scale *= 2;
			env->man->imax += 4;
		}
		else
		{
			hx = env->man->img_x;
			hy = env->man->img_y;
			env->man->scale /= 2;
			env->man->imax -= 4;
		}
		env->man->x1 += ((env->man->m_x / WIN_LENGHT) * env->man->img_x) - hx;
		env->man->x2 = env->man->x1 + (hx * 2);
		env->man->y1 += ((env->man->m_y / WIN_HEIGHT) * env->man->img_y) - hy;
		env->man->y2 = env->man->y1 + (hy * 2);
		env->man->img_x = (env->man->x2 - env->man->x1) * env->man->scale;
		env->man->img_y = (env->man->y2 - env->man->y1) * env->man->scale;
	}
}

void		julia(t_env *env)
{
	double		hx;
	double		hy;
	double		x;
	double		y;

	zoom_in_out2(env, hx, hy);
	y = -1;
	while (y++ < env->man->img_y)
	{
		x = -1;
		while (x++ < env->man->img_x)
			is_in_fractal2(x, y, *env->man, env);
	}
}
