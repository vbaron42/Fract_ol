/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 08:05:56 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/14 22:13:05 by vbaron           ###   ########.fr       */
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

int				is_in_win(double cx, double cy, double l, t_env *env)
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;

	l *= 1.5;
	x1 = cx - l;
	x2 = cx + l;
	y1 = cy - l;
	y2 = cy + l;// A transcrire (ou pas)
	if (((env->sier->x1 >= x1 && env->sier->x1 <= x2)
			|| (env->sier->x2 >= x1 && env->sier->x2 <= x2))
			&& ((env->sier->y1 >= y1 && env->sier->y1 <= y2)
			|| (env->sier->y2 >= y1 && env->sier->y2 <= y2)))
		return (1);// = au moins 1 coin de l'ecran dans la zone
	else if (((x1 >= env->sier->x1 && x1 <= env->sier->x2)
			|| (x2 >= env->sier->x1 && x2 <= env->sier->x2))
			&& ((y1 >= env->sier->y1 && y1 <= env->sier->y2)
			|| (y2 >= env->sier->y1 && y2 <= env->sier->y2)))
		return (1);// = au moins 1 coin de la zone dans l'ecran
	else
		return (1);//remettre a 0 plus tard
}

void			is_out_sierpi(double cx, double cy, double l, t_env *env)
{
	if (is_in_win(cx, cy, l, env) == 1 && l * 3 * env->sier->imax >= ((double)1 / 3))
	{
		draw_square(cx * env->sier->scale, cy * env->sier->scale,
				l * env->sier->scale, env);//ajout de + sier->x1 a garder ?
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
/*void			zoom_in_out_sierpi(t_fractal *sier, int hx, int hy);
{
	if (sier->zoom != 0)
	{*/
/*		if (sier->zoom == 1)
		{
			sier->scale *= (1.4422497);//= taille du carre final/1 utilite de mettre sur 1 ?
			sier->imax++;//!! Diviser par 3 imax lors des calcules
		}
		else
		{
			sier->scale /= (1.4422497);
			sier->imax++;
		}
		sier->x1 = (sier->m_x) / sier->scale;//x1 et x2 = centre du point de vue
		sier->x2 = sier->m_x;
		sier->y1 = sier->m_y;
		sier->y2 = sier->m_y;
		sier->img_x = sier->scale //a completer taille ecran
	}

*/
/*		fra->img_x /= fra->scale;
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
}*/

void			zoom_in_out2(t_fractal *fra, double hx, double hy, int imax)
{
	if (fra->zoom != 0)
	{
		fra->img_x /= fra->scale;
		fra->img_y /= fra->scale;
		if (fra->zoom == 1)
		{
			hx = fra->img_x / 2.8844994;
			hy = fra->img_y / 2.8844994;
			fra->scale *= 1.4422497;
			fra->imax += imax;
		}
		else
		{
			hx = fra->img_x * 0.7;
			hy = fra->img_y * 0.7;
			fra->scale /= 1.4422497;
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

void			sierpi(t_env *env)
{
	double		hx;
	double		hy;
	double		x;
	double		y;

	zoom_in_out2/*_sierpi*/(env->sier, hx, hy, 6);
	white_screen(env);//
	y = - env->sier->y1 * env->sier->scale;//-1;
	while (y++ < (- env->sier->y1 + 1) * env->sier->scale)//env->sier->img_y)//a modifier, ne pas parcourir les 
	{
		x = - env->sier->x1 * env->sier->scale;//-1;
		while (x++ < (- env->sier->x1 + 1) * env->sier->scale)//env->sier->img_x)
			img_put_pixel(env, x, y,
					color_scale((((x + (env->sier->x1 * env->sier->scale)) / env->sier->scale + (y + (env->sier->y1 * env->sier->scale)) / env->sier->scale) * 242)
						+ env->sier->c, env->sier->pattern));
	}
	ft_putstr("\n\nx1 : ");
	ft_putnbr(env->sier->x1 * 100);
	ft_putstr("\nx2 : ");
	ft_putnbr(env->sier->x2 * 100);
	ft_putstr("\ny1 : ");
	ft_putnbr(env->sier->y1 * 100);
	ft_putstr("\ny2 : ");
	ft_putnbr(env->sier->y2 * 100);
	ft_putstr("\nimg_x : ");
	ft_putnbr(env->sier->img_x * 100);
	ft_putstr("\nimg_y : ");
	ft_putnbr(env->sier->img_y * 100);
	ft_putstr("\nimg_x : ");
	ft_putnbr(env->sier->img_x / env->sier->scale * 100);
	ft_putstr("\nimg_y : ");
	ft_putnbr(env->sier->img_y / env->sier->scale * 100);
	ft_putstr("\nscale : ");
	ft_putnbr(env->sier->scale);
	is_out_sierpi(0.5 - env->sier->x1, 0.5 - env->sier->y1, (double)1 / 3, env);
}
