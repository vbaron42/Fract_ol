/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:21:51 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/07 09:08:23 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		is_in_fractal(double x, double y, t_man man, t_env *env)
{
	int		i;
	double	c_r;
	double	c_i;
	double	z_r;
	double	tmp;
	double	z_i;

	i = 0;
	c_r = x / man.scale + man.x1;
	c_i = y / man.scale + man.y1;
	z_r = 0;
	z_i = 0;
//	z_r = c_r;
//	z_i = c_i;
	while ((z_r * z_r) + (z_i * z_i) < 4 && i++ < man.imax)
	{
		tmp = z_r;
		z_r = (z_r * z_r) - (z_i * z_i) + c_r;
		z_i = (2 * z_i * tmp) + c_i;
	}
	if (i == man.imax + 1)
		img_put_pixel(env, x, y, color_scale(env->man_c));
	else
		img_put_pixel(env, x, y,
				color_scale(((i + (env->man_c / 10)) * 15) + 100));
}

void		mandelbrot(t_env *env)
{
	double	hx;
	double	hy;
	double	x;
	double	y;

	if (env->man->zoom != 0)
	{
		env->man->img_x /= env->man->scale;
		env->man->img_y /= env->man->scale;
		if (env->man->zoom == 1)
		{
			hx = env->man->img_x / 4;
			hy = env->man->img_y / 4;
			env->man->scale *= 2;
			env->man->imax += 3;
		}
		else
		{
			hx = env->man->img_x;
			hy = env->man->img_y;
			env->man->scale /= 2;
			env->man->imax -= 3;
		}
		env->man->x1 += ((env->man->mouse_x / WIN_LENGHT) * env->man->img_x) - hx;
		env->man->x2 = env->man->x1 + (hx * 2);
		env->man->y1 += ((env->man->mouse_y / WIN_HEIGHT) * env->man->img_y) - hy;
		env->man->y2 = env->man->y1 + (hy * 2);
		env->man->img_x = (env->man->x2 - env->man->x1) * env->man->scale;
		env->man->img_y = (env->man->y2 - env->man->y1) * env->man->scale;
	}
	ft_putstr("\nhx : ");//
	ft_putnbr(hx);//
	ft_putstr("\nx1 : ");//
	ft_putnbr(env->man->x1);//
	ft_putstr("\nimg_x : ");//
	ft_putnbr(env->man->img_x);//
	y = -1;
	while (y++ < env->man->img_y)
	{
		x = -1;
		while (x++ < env->man->img_x)
		{
			is_in_fractal(x, y, *env->man, env);
//			ft_putstr("pix_ok ");
		}
	}
}
