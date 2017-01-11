/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 08:05:56 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/11 09:39:34 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			is_out_sierpi(double x, double y, t_fractal sier, t_env *env)
{
	ft_putchar('a');//draw black square
}

/*
void			color_sierpi(t_env *env)
{
	int			x;
	int			y;

	//...
	// = 0
	while ()
	{
		// = 0;
		while()
			img_put_pixel(env, x?, y?, color_scale(x + y / 10 ??));
	}
}
*/

void			sierpi(t_env *env)
{
	double		hx;
	double		hy;
	double		x;
	double		y;

	zoom_in_out(env->sier, hx, hy, 1);
//	color_sierpi;
	y = -1;
	while (y++ < env->sier->img_y)
	{
		x = -1;
		while (x++ < env->sier->img_x)
			is_out_sierpi(x, y, *env->sier, env);
	}
}
