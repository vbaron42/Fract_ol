/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:58:46 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/22 02:42:40 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_move(int x, int y, t_env *env)
{
	env->vision->mx = x;
	env->vision->my = y;
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
		zoom_event(button, x, y, env->man);
	else if (env->fractal == 1)
		zoom_event(button, x, y, env->jul);
	else if (env->fractal == 2)
		zoom_event(button, x, y, env->sier);
	print_img(env);
	return (1);
}

void		imax_event(int code, t_env *env)
{
	if (code == 69 && env->fractal == 0)
		env->man->imax += 5;
	if (code == 78 && env->fractal == 0)
		env->man->imax -= 5;
	if (code == 69 && env->fractal == 1)
		env->jul->imax += 10;
	if (code == 78 && env->fractal == 1)
		env->jul->imax -= 10;
	if (code == 69 && env->sier->imax >= 1 && env->fractal == 2)
		env->sier->imax *= 3;
	else if (code == 69 && env->sier->imax < 1 && env->fractal == 2)
		env->sier->imax = 1;
	if (code == 78 && env->sier->imax >= 3 && env->fractal == 2)
		env->sier->imax /= 3;
}

void		color_event(int code, t_env *env)
{
	if (code == 8 && env->fractal == 0)
		env->man->pattern++;
	if (code == 8 && env->fractal == 1)
		env->jul->pattern++;
	if (code == 8 && env->fractal == 2)
		env->sier->pattern++;
	if (code == 8 && env->fractal == 3)
		env->vision->pattern++;
	if (env->fractal == 0)
		env->man->c += 12;
	if (env->fractal == 1)
	{
		env->jul->c += 12;
		env->jul->freeze = 1;
	}
	if (env->fractal == 2)
		env->sier->c += 20;
}

int			event(int code, t_env *env)
{
	if (code == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		free(env->man);
		free(env->jul);
		free(env->sier);
		free(env->img);
		exit(0);
	}
	env->man->zoom = 0;
	env->jul->zoom = 0;
	env->sier->zoom = 0;
	color_event(code, env);
	imax_event(code, env);
	if (code == 49)
		env->fractal++;
	if (env->fractal == 4)
		env->fractal = 0;
	print_img(env);
	return (0);
}
