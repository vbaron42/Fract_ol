/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 08:05:56 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/22 01:26:31 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			is_out_sierpi(double cx, double cy, double l, t_env *env)
{
	if (ft_abs_d((cx + env->sier->x1) - env->sier->c_r) - (l * 1.5)
			<= env->sier->dx
			&& ft_abs_d((cy + env->sier->y1) - env->sier->c_i) - (l * 1.5)
			<= env->sier->dy
			&& l * 9 * env->sier->imax >= 1)
	{
		if (ft_abs_d((cx + env->sier->x1) - env->sier->c_r) - (l / 2)
				<= env->sier->dx
				&& ft_abs_d((cy + env->sier->y1) - env->sier->c_i) - (l / 2)
				<= env->sier->dy)
			draw_square(cx * env->sier->scale, cy * env->sier->scale,
					l * env->sier->scale, env);
		is_out_sierpi(cx - l, cy + l, l / 3, env);
		is_out_sierpi(cx, cy + l, l / 3, env);
		is_out_sierpi(cx + l, cy + l, l / 3, env);
		is_out_sierpi(cx - l, cy, l / 3, env);
		is_out_sierpi(cx + l, cy, l / 3, env);
		is_out_sierpi(cx - l, cy - l, l / 3, env);
		is_out_sierpi(cx, cy - l, l / 3, env);
		is_out_sierpi(cx + l, cy - l, l / 3, env);
	}
}

void			sierpi(t_env *env)
{
	double		hx;
	double		hy;
	double		x;
	double		y;

	zoom_in_out(env->sier, hx, hy, 6);
	env->sier->c_r = (env->sier->x1 + env->sier->x2) / 2;
	env->sier->c_i = (env->sier->y1 + env->sier->y2) / 2;
	y = -env->sier->y1 * env->sier->scale;
	while (y++ < (1 - env->sier->y1) * env->sier->scale)
	{
		x = -env->sier->x1 * env->sier->scale;
		while (x++ < (1 - env->sier->x1) * env->sier->scale)
			img_put_pixel(env, x, y, color_scale((((x + (env->sier->x1 *
				env->sier->scale)) / env->sier->scale + (y + (env->sier->y1 *
					env->sier->scale)) / env->sier->scale) * 242)
						+ env->sier->c, env->sier->pattern));
	}
	env->sier->dx = env->sier->img_x / (2 * env->sier->scale);
	env->sier->dy = env->sier->img_y / (2 * env->sier->scale);
	is_out_sierpi(0.5 - env->sier->x1, 0.5 - env->sier->y1, (double)1 / 3, env);
}
