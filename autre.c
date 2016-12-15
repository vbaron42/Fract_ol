/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:22:41 by vbaron            #+#    #+#             */
/*   Updated: 2016/12/15 06:45:50 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void		octant_put_pixel(int cx, int cy, int x, int y, t_env *env)
{
	img_put_pixel(env, cx + x, cy + y, env->c);
	img_put_pixel(env, cx - x, cy + y, env->c);
	img_put_pixel(env, cx + x, cy - y, env->c);
	img_put_pixel(env, cx - x, cy - y, env->c);
	img_put_pixel(env, cx + y, cy + x, env->c);
	img_put_pixel(env, cx - y, cy + x, env->c);
	img_put_pixel(env, cx + y, cy - x, env->c);
	img_put_pixel(env, cx - y, cy - x, env->c);
	if (env->b == 12)
	{
		env->b1 = 1;
		if (env->v == 12)
			env->v1 = 1;
		if (env->v == 0)
			env->v1 = 0;
		if (env->v1 == 0)
			env->v++;
		else
			env->v--;
	}
	if (env->b == 0)
	{
		env->b1 = 0;
		if (env->v == 12)
			env->v1 = 1;
		if (env->v == 0)
			env->v1 = 0;
		if (env->v1 == 0)
			env->v++;
		else
			env->v--;
	}
	if (env->b1 == 0)
		env->b++;
	else
		env->b--;
	env->c = env->b + (env->v * 16) + (env->r * 256);
	ft_putnbr(env->b);
	ft_putchar(' ');
	ft_putnbr(env->v);
	ft_putchar('\n');
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
		env->c = 0;
		env->r++;
		env->v++;
		env->b = 0;
//		env->c *= 0.998;
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
	r = (cy / 2);
	thick = 40;
	draw_circle(cx, cy, r, thick, env);

}

