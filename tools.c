/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 09:11:18 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/22 06:34:27 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void		zoom_in_out(t_fractal *fra, double hx, double hy, int imax)
{
	if (fra->zoom != 0)
	{
		fra->img_x /= fra->scale;
		fra->img_y /= fra->scale;
		if (fra->zoom == 1)
		{
			hx = fra->img_x / 4;
			hy = fra->img_y / 4;
			fra->scale *= 2;
			fra->imax += imax;
		}
		else
		{
			hx = fra->img_x;
			hy = fra->img_y;
			fra->scale /= 2;
			fra->imax -= imax;
		}
		fra->x1 += ((fra->m_x / WIN_LENGHT) * fra->img_x) - hx;
		fra->x2 = fra->x1 + (hx * 2);
		fra->y1 += ((fra->m_y / WIN_HEIGHT) * fra->img_y) - hy;
		fra->y2 = fra->y1 + (hy * 2);
		fra->img_x = (fra->x2 - fra->x1) * fra->scale;
		fra->img_y = (fra->y2 - fra->y1) * fra->scale;
	}
}

void		zoom_event(int button, int x, int y, t_fractal *fra)
{
	fra->zoom = 0;
	if (button == 5)
		fra->zoom = 1;
	else if (button == 4)
		fra->zoom = -1;
	fra->m_x = x;
	fra->m_y = y;
}

void		move_fractal(int code, t_fractal *fra)
{
	if (code == 123 || code == 0)
	{
		fra->x1 -= 20 / fra->scale;
		fra->x2 -= 20 / fra->scale;
	}
	else if (code == 124 || code == 2)
	{
		fra->x1 += 20 / fra->scale;
		fra->x2 += 20 / fra->scale;
	}
	else if (code == 125 || code == 1)
	{
		fra->y1 += 20 / fra->scale;
		fra->y2 += 20 / fra->scale;
	}
	else if (code == 126 || code == 13)
	{
		fra->y1 -= 20 / fra->scale;
		fra->y2 -= 20 / fra->scale;
	}
}

void		move_event(int code, int fractal, t_env *env)
{
	if (fractal == 0)
		move_fractal(code, env->man);
	else if (fractal == 1)
		move_fractal(code, env->jul);
	else if (fractal == 2)
		move_fractal(code, env->sier);
	else
	{
		if (code == 123 || code == 0)
			env->vision->cx += 20;
		else if (code == 124 || code == 2)
			env->vision->cx -= 20;
		else if (code == 125 || code == 1)
			env->vision->cy -= 20;
		else if (code == 126 || code == 13)
			env->vision->cy += 20;
	}
}
