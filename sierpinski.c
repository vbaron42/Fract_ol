/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 08:05:56 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/11 12:49:56 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_square(int cx, int cy, int size, t_env *env)
{
	int			x;
	int			y;
	int			x_end;
	int			y_end;

	y = cy - size - 1;// pre-diviser par 2 pour economiser des calcules
	x_end = cx + size;
	y_end = cy + size;
	while (y++ <= y_end)
	{
		x = cx - size - 1;
		while (x++ <= x_end)
			img_put_pixel(env, x, y, 0x0);
	}
}

void			is_out_sierpi(double x, double y, t_fractal sier, t_env *env)
{
//	draw_square(cx * sier->scale, cy * sier->scale, size * sier->scale / 2, env);
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
			img_put_pixel(env, x, y, color_scale(x + y / 10 ??));
	}
}
*/
void			zoom_in_out_sierpi(t_fractal *sier, int hx, int hy);
{
	if (sier->zoom != 0)
	{
		if (sier->zoom == 1)
		{
			sier->scale *= (1.4422497);//= taille du carre final/1 utilite de mettre sur 1 ?
			sier->x1 = sier->m_x;//x1 et x2 = centre du point de vue
			sier->y1 = sier->m_y;
			sier->imax++;//!! Diviser par 3 imax lors des calcules
		}
		else
		{
			sier->scale /= (1.4422497);
			sier->x2 = sier->m_x;
			sier->y2 = sier->m_y;
			sier->imax++;
		}
		sier->img_x = sier->scale //a completer taille ecran
	}
}
//tracer au moins le 1er carre puis dans le tracage des 9 carres en cas de scale
// ELEVE ne pas tracer les carres OPOSES, faire le test a chaque iteration.
void			sierpi(t_env *env)
{
	double		hx;
	double		hy;
	double		x;
	double		y;

	zoom_in_out_sierpi(env->sier, hx, hy);
	y = -1;
	while (y++ < env->sier->img_y)//a modifier, ne pas parcourir les 
	{
		x = -1;
		while (x++ < env->sier->img_x)
			img_put_pixel(env, x + env->sier->x2, y + env->sier->y2, color_scale(((x + y) / 10) + env->sier->c,//formule a modifier !couleurs!
						env->sier->pattern));
	}
//	is_out_sierpi(x, y, *env->sier, env);
}
