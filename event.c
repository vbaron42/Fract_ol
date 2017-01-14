/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:58:46 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/14 19:23:02 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_move(int x, int y, t_env *env)
{
	env->mx = x;
	env->my = y;
	if (env->fractal == 1)
	{
		env->jul->move_x = x;
		env->jul->move_y = y;
		env->jul->freeze = 0;
	}
	print_img(env);
	return (1);
}

int			mouse_clic(int button, int x, int y, t_env *env)
{
	if (env->fractal == 0)
	{
		env->man->zoom = 0;
		if (button == 5)
			env->man->zoom = 1;
		else if (button == 4)
			env->man->zoom = -1;
		env->man->m_x = x;
		env->man->m_y = y;
	}
	else if (env->fractal == 1)
	{
		env->jul->zoom = 0;
		if (button == 5)
			env->jul->zoom = 1;
		else if (button == 4)
			env->jul->zoom = -1;
		env->jul->m_x = x;
		env->jul->m_y = y;
	}
	else if (env->fractal == 2)
	{
		env->sier->zoom = 0;
		if (button == 5)
			env->sier->zoom = 1;
		else if (button == 4)
			env->sier->zoom = -1;
		env->sier->m_x = x;
		env->sier->m_y = y;
	}
	print_img(env);
	return (1);
}

int			event(int code, t_env *env)
{
	if (code == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	env->man->zoom = 0;
	env->jul->zoom = 0;
	env->sier->zoom = 0;
	if (code == 69 && env->fractal == 0)
		env->man->imax += 5;
	if (code == 78 && env->fractal == 0)
		env->man->imax -= 5;
	if (code == 69 && env->fractal == 1)
		env->jul->imax += 10;
	if (code == 78 && env->fractal == 1)
		env->jul->imax -= 10;
	if (code == 69 && env->fractal == 2)
		env->sier->imax *= 3;
	if (code == 78 && env->sier->imax >= 3 && env->fractal == 2)
		env->sier->imax /= 3;
	if (code == 8 && env->fractal == 0)
		env->man->pattern++;
	if (code == 8 && env->fractal == 1)
		env->jul->pattern++;
	if (code == 8 && env->fractal == 2)
		env->sier->pattern++;
	if (code == 8 && env->fractal == 3)
		env->pattern++;
	if (env->fractal == 0)
		env->man->c += 12;
	if (env->fractal == 1)
	{
		env->jul->c += 12;
		env->jul->freeze = 1;
	}
	if (env->fractal == 2)
		env->sier->c += 20;
	if (code == 49)
		env->fractal++;
	if (env->fractal == 4)
		env->fractal = 0;
	print_img(env);
	return (0);
}
