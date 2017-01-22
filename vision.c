/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:22:41 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/22 06:36:51 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		get_m2(double m, int r)
{
	double	m2;

	m2 = m / r;
	if (m2 > PI / 2.00000000)
		m2 = PI / 2.00000000;
	m2 = sin(m2) * (r / PI);
	return (m2);
}

void		rec_circle2(int cx, int cy, t_circle cir, t_env *env)
{
	int		r;

	r = cir.r;
	if (r > 4)
	{
		if (cir.thick < 1)
			cir.thick = 2;
		draw_circle(cx, cy, cir, env);
		cir.thick /= 3;
		cir.r /= 4;
		rec_circle2(cx + (r / 2), cy, cir, env);
		rec_circle2(cx - (r / 2), cy, cir, env);
		rec_circle2(cx, cy + (r / 2), cir, env);
		rec_circle2(cx, cy - (r / 2), cir, env);
		rec_circle2(cx + (COS45 * r), cy + (COS45 * r), cir, env);
		rec_circle2(cx - (COS45 * r), cy + (COS45 * r), cir, env);
		rec_circle2(cx + (COS45 * r), cy - (COS45 * r), cir, env);
		rec_circle2(cx - (COS45 * r), cy - (COS45 * r), cir, env);
	}
}

void		rec_circle(int cx, int cy, t_circle cir, t_env *env)
{
	double	mx2;
	double	my2;

	if (cir.thick < 1)
		cir.thick = 2;
	draw_circle(cx, cy, cir, env);
	mx2 = get_m2(env->vision->mx, cir.r);
	my2 = get_m2(env->vision->my, cir.r);
	env->vision->mx -= (mx2 * VISION_FOCUS);
	env->vision->my -= (my2 * VISION_FOCUS);
	if (env->vision->mx_sign == -1)
		mx2 = -mx2;
	if (env->vision->my_sign == -1)
		my2 = -my2;
	cir.r /= 2;
	cir.thick /= 3;
	env->vision->c += 1;
	cir.thick *= 2;
	if ((cir.r = cir.r * 1.5) > 2)
		rec_circle((cx + mx2), (cy + my2), cir, env);
	if ((cir.r / 1.5) * 2 >= WIN_HEIGHT * 3)
	{
		env->vision->cx2 = cx + mx2;
		env->vision->cy2 = cy + my2;
	}
}

/*
**	rec_circle2((cx + mx2) + cir.r, (cy + my2), cir, env);
**	rec_circle2((cx + mx2) - cir.r, (cy + my2), cir, env);
**	rec_circle2((cx + mx2), (cy + my2) + cir.r, cir, env);
**	rec_circle2((cx + mx2), (cy + my2) - cir.r, cir, env);
**  a placer a la ligne 69 pour perdre la vue.
*/

void		get_m(int cx, int cy, t_vision *vision, t_env *env)
{
	vision->mx = (vision->mx - cx) / 2;
	if (vision->mx < 0)
	{
		vision->mx_sign = -1;
		vision->mx = -vision->mx;
	}
	else
		vision->mx_sign = 1;
	vision->my = (vision->my - cy) / 2;
	if (vision->my < 0)
	{
		vision->my_sign = -1;
		vision->my = -vision->my;
	}
	else
		vision->my_sign = 1;
}

void		vision(t_env *env)
{
	t_circle	cir;
	int			cx;
	int			cy;

	if (env->vision->c >= 12288)
		env->vision->c = 0;
	cir.r = WIN_HEIGHT + 100;
	if ((env->vision->slow) + cir.r >= cir.r * 3)
	{
		env->vision->slow = 1;
		env->vision->cx = env->vision->cx2;
		env->vision->cy = env->vision->cy2;
	}
	cir.thick = 50;
	env->vision->slow = (1.01 * env->vision->slow) + 6;
	get_m(env->vision->cx, env->vision->cy, env->vision, env);
	white_screen(env);
	cir.r += env->vision->slow;
	cir.thick += env->vision->slow / 10;
	rec_circle(env->vision->cx, env->vision->cy, cir, env);
}
