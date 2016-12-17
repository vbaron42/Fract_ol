/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:22:41 by vbaron            #+#    #+#             */
/*   Updated: 2016/12/17 09:44:50 by vbaron           ###   ########.fr       */
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

void		rec_circle(int cx, int cy, int r, int thick, t_env *env)
{
	int		comp;

	comp = 0;
	if (r > 4)
	{
		if (thick < 1)
			thick = 1;
		draw_circle(cx, cy, r, thick, env);
		env->c1 += 90;
		if (env->c1 > 200)
			env->c1 -= 200;
		rec_circle((cx + env->mx), (cy + env->my) / 2, r / 2, thick / 2, env);
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

void		autre(t_env *env)
{
	int		x;
	int		y;
	int		d;
	int		r;
	int		cx;
	int		cy;
	int		thick;

	cx = (WIN_LENGHT / 2);
	cy = (WIN_HEIGHT / 2);
	r = cy;
	thick = 160;
	env->slow++;
	if (env->mx < (WIN_LENGHT / 2))
		env->mx = (-1 * (WIN_LENGHT - env->mx));
	else
		env->mx = (-1 * (100 / env->mx));
	white_screen(env);
	draw_circle(cx, cy, r, thick, env);
	rec_circle(cx, cy, r, thick, env);
}

