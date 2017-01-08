/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:22:41 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/08 19:55:53 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		octant_put_pixel(int cx, int cy, int x, int y, t_env *env)
{
	if (env->c != 0)
	{
		img_put_pixel(env, cx + x, cy + y, env->c);
		img_put_pixel(env, cx - x, cy + y, env->c);
		img_put_pixel(env, cx + x, cy - y, env->c);
		img_put_pixel(env, cx - x, cy - y, env->c);
		img_put_pixel(env, cx + y, cy + x, env->c);
		img_put_pixel(env, cx - y, cy + x, env->c);
		img_put_pixel(env, cx + y, cy - x, env->c);
		img_put_pixel(env, cx - y, cy - x, env->c);
	}
	if (env->r >= 50)
		env->r1 = 1;
	if (env->r <= 10)
		env->r1 = 0;
	if (env->r1 == 0)
		env->r++;
	else
		env->r--;
//	if (env->c1 > 90)
//		env->c = 0;
//	else)
	env->c = env->b + (env->v * 256) + ((env->r + env->c1) * 65536);
/*	ft_putnbr(env->b);
	ft_putchar(' ');
	ft_putnbr(env->v);
	ft_putchar('\n');*/
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
//		env->c = 0;
//		env->r = 20;
//		env->v++;
//		env->b = 0;
//		env->c *= 0.998;
	if (env->b >= 190)
		env->b1 = 1;
	if (env->b <= 140)
		env->b1 = 0;
	if (env->b1 == 0)
		env->b++;
	else
		env->b--;
	if (env->v >= 200)
		env->v1 = 1;
	if (env->v <= 100)
		env->v1 = 0;
	if (env->v1 == 0)
		env->v += 2;
	else
		env->v--;
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

void		rec_circle(int cx, int cy, int r, int thick, t_env *env)
{
	int		comp;
	double	mx2;
	double	my2;

	comp = 0;
	if (r > 1)
	{
		if (thick < 1)
			thick = 2;
		draw_circle(cx, cy, r, thick, env);
		env->c1 += 90;
		if (env->c1 > 200)
			env->c1 -= 200;
//		mx2 = env->mx;//permet d'avoir un double au denominateur
		mx2 = get_m2(env->mx, r);
		my2 = get_m2(env->my, r);
		env->mx -= (mx2 * VISION_FOCUS);// /2 ? (de base absent)
		env->my -= (my2 * VISION_FOCUS);
		if (env->mx_sign == -1)
			mx2 = -mx2;
		if (env->my_sign == -1)
			my2 = -my2;
		rec_circle((cx + mx2), (cy + my2), r / 2, thick / 2, env);
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

	r = (WIN_HEIGHT / 2);//passer a 2 ou moins
	if ((env->slow / VISION_SLOW) + r >= r * 2)
		env->slow = 0;
	thick = 20;
	env->slow += 3;
	get_m(env->cx, env->cy, env);
	white_screen(env);
//	get_c(cx, cy, r, thick, env);
	rec_circle(env->cx, env->cy, r + (env->slow / VISION_SLOW), thick + (env->slow / (10 * VISION_SLOW)), env);
}
