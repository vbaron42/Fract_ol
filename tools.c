/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 09:11:18 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/16 22:59:02 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_square(int cx, int cy, int size, t_env *env)
{
	int			x;
	int			y;
	int			x_end;
	int			y_end;

	size /= 2;
	y = cy - size - 1;
	x_end = cx + size;
	y_end = cy + size;
	while (y++ <= y_end)
	{
		x = cx - size - 1;
		while (x++ <= x_end)
			img_put_pixel(env, x, y, 0x0);
	}
}

void			zoom_in_out(t_fractal *fra, double hx, double hy, int imax)
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
