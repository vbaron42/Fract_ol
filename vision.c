/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:22:41 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/11 07:21:37 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		octant_put_pixel(int cx, int cy, int x, int y, t_env *env)
{
	int		c;

	c = color_scale(env->c, env->pattern);
	if (env->c != 0)
	{
		img_put_pixel(env, cx + x, cy + y, c);
		img_put_pixel(env, cx - x, cy + y, c);
		img_put_pixel(env, cx + x, cy - y, c);
		img_put_pixel(env, cx - x, cy - y, c);
		img_put_pixel(env, cx + y, cy + x, c);
		img_put_pixel(env, cx - y, cy + x, c);
		img_put_pixel(env, cx + y, cy - x, c);
		img_put_pixel(env, cx - y, cy - x, c);
	}
}

void		draw_circle(int cx, int cy, int r, int thick,t_env *env)
{
	int		x;
	int		y;
	int		d;
	int		rt;

	rt = r - thick;
	while (rt++ != r + thick - 1)
	{
		env->c += 4;
		x = 0;
		y = rt;
		d = rt - 1;
		while (y >= x)
		{
			octant_put_pixel(cx, cy, x, y, env);
			if (d >= (2 * x))
			{
				d = (d - (2 * x) - 1);
				x++;
			}
			else if (d < (2 * (rt - y)))
			{
				d = (d + (2 * y) -1);
				y--;
			}
			else
			{
				d = (d + 2 * (y - x - 1));
				y--;
				x++;
			}
		}
	}
	env->c -= (8 * thick) - 4;
}

double		get_m2(double m, int r)
{
	double	m2;

	m2 = m / r;
	if (m2 > PI / 2.00000000)
		m2 = PI / 2.00000000;
	m2 = sin(m2) * (r / PI);
	return (m2);
}

void		rec_circle2(int cx, int cy, int r, int thick, t_env *env)
{
	int		comp;
	double	mx2;
	double	my2;

	comp = 0;
	if (r > 4)//
	{
		if (thick < 1)
			thick = 2;
		draw_circle(cx, cy, r, thick, env);
//		mx2 = env->mx;//permet d'avoir un double au denominateur
		rec_circle2(cx + (r / 2), cy, r / 4, thick / 3, env);
		rec_circle2(cx - (r / 2), cy, r / 4, thick / 3, env);
		rec_circle2(cx, cy + (r / 2), r / 4, thick / 3, env);
		rec_circle2(cx, cy - (r / 2), r / 4, thick / 3, env);
		rec_circle2(cx + (COS45 * r), cy + (COS45 * r), r / 4, thick / 3, env);
		rec_circle2(cx - (COS45 * r), cy + (COS45 * r), r / 4, thick / 3, env);
		rec_circle2(cx + (COS45 * r), cy - (COS45 * r), r / 4, thick / 3, env);
		rec_circle2(cx - (COS45 * r), cy - (COS45 * r), r / 4, thick / 3, env);

	}
}
void		rec_circle(int cx, int cy, int r, int thick, t_env *env)
{
	int		comp;
	double	mx2;
	double	my2;

	comp = 0;
	if (r > 2)
	{
		if (thick < 1)
			thick = 2;
		draw_circle(cx, cy, r, thick, env);
//		mx2 = env->mx;//permet d'avoir un double au denominateur
		mx2 = get_m2(env->mx, r);
		my2 = get_m2(env->my, r);
		env->mx -= (mx2 * VISION_FOCUS);// /2 ? (de base absent)
		env->my -= (my2 * VISION_FOCUS);
		if (env->mx_sign == -1)
			mx2 = -mx2;
		if (env->my_sign == -1)
			my2 = -my2;
		rec_circle2((cx + mx2) + (r / 2), (cy + my2), r / 2, thick / 3, env);
		rec_circle2((cx + mx2) - (r / 2), (cy + my2), r / 2, thick / 3, env);
		rec_circle2((cx + mx2), (cy + my2) + (r / 2), r / 2, thick / 3, env);
		rec_circle2((cx + mx2), (cy + my2) - (r / 2), r / 2, thick / 3, env);
		env->c += 1;
		rec_circle((cx + mx2), (cy + my2), r / 1.5, thick / 1.5, env);
	}
	if (r >= WIN_HEIGHT * 3)
	{
		env->cx2 = cx + mx2;
		env->cy2 = cy + my2;
	}
}

void		white_screen(t_env *env)
{
	int		l;
	int		h;

	h = WIN_HEIGHT;
	while (h-- >= 0)
	{
		l = WIN_LENGHT;
		while (l-- >= 0)
			img_put_pixel(env, l, h, 0xFFFFFF);
	}
}
void		get_m(int cx, int cy, t_env *env)
{
	env->mx = (env->mx - cx) / 2;
	if (env->mx < 0)
	{
		env->mx_sign = -1;
		env->mx = -env->mx;
	}
	else
		env->mx_sign = 1;
	env->my = (env->my - cy) / 2;
	if (env->my < 0)
	{
		env->my_sign = -1;
		env->my = -env->my;
	}
	else
		env->my_sign = 1;
}

//Avoir Julia en fond c = -1.417022285618

void		vision(t_env *env)
{
	int		x;
	int		y;
	int		d;
	int		r;
	int		cx;
	int		cy;
	int		thick;

	if (env->c >= 12288)
		env->c = 0;
	r = (WIN_HEIGHT + 100/* /2 */);//passer a 2 ou moins
	if ((env->slow) + r >= r * 3)
	{
		env->slow = 1;
		env->cx = env->cx2;
		env->cy = env->cy2;
	}
	thick = 50;
	env->slow = (1.01 * env->slow) + 6; //3;
	get_m(env->cx, env->cy, env);
	white_screen(env);
//	get_c(cx, cy, r, thick, env);
	rec_circle(env->cx, env->cy, r + (env->slow), thick + (env->slow / 10), env);
}
