/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 08:05:56 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/11 08:48:40 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
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
*/
void		sierpi(t_env *env)
{
/*	double		hx;
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
	}*/
}
