/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:58:46 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/08 11:15:32 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_move(int x, int y, t_env *env)
{
	env->mx = x;
	env->my = y;
	print_img(env);
	return (1);
}

int			mouse_clic(int button, int x, int y, t_env *env)
{
	if (env->fractal == 1) // rmplacer 1 par 0
	{
		env->man->zoom = 0;
		if (button == 5)
			env->man->zoom = 1;
		else if (button == 4)
			env->man->zoom = -1;
		env->man->m_x = x;
		env->man->m_y = y;
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
	if (code == 8 && env->fractal == 1)//lameme
		env->man->pattern++;
	if (env->fractal == 1)//
		env->man->c += 12;
	if (code == 49)
		env->fractal++;
	if (env->fractal == 3)
		env->fractal = 0;
	print_img(env);
	return (0);
}
