/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:01:53 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/11 08:58:37 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		img_put_pixel(t_env *env, int x, int y, int c)
{
	int		pxl;

	if (y < WIN_HEIGHT && x < WIN_LENGHT && y > 0 && x > 0)
	{
		pxl = y * env->img->line_size + (env->img->bpp / 8) * x;
		env->img->pxl_byt[pxl] = c;
		env->img->pxl_byt[++pxl] = c >> 8;
		env->img->pxl_byt[++pxl] = c >> 16;
	}
}

void		draw_img(t_env *env)
{
	if (env->fractal == 0)
		mandelbrot(env);
	else if (env->fractal == 1)
		julia(env);
	else if (env->fractal == 2)
		sierpi(env);
	else
		vision(env);
}

void		string_display(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 48, 22, 0x0, "Fractal :");
	mlx_string_put(env->mlx, env->win, 50, 20, 0xFF6FFF, "Fractal :");
	if (env->fractal == 0)
	{
		mlx_string_put(env->mlx, env->win, 148, 22, 0x0, "Mandelbrot");
		mlx_string_put(env->mlx, env->win, 150, 20, 0x6FFFFF, "Mandelbrot");
	}
	else if (env->fractal == 1)
	{
		mlx_string_put(env->mlx, env->win, 148, 22, 0x0, "Julia");
		mlx_string_put(env->mlx, env->win, 150, 20, 0xFFFF6F, "Julia");
	}
	else if (env->fractal == 2)
	{
		mlx_string_put(env->mlx, env->win, 148, 22, 0x0, "Sierpinski");
		mlx_string_put(env->mlx, env->win, 150, 20, 0x6F6FFF, "Sierpinski");
	}
	else
	{
		mlx_string_put(env->mlx, env->win, 148, 22, 0x0, "Vision");
		mlx_string_put(env->mlx, env->win, 150, 20, 0x4FFF4F, "Vision");
	}
}

t_img		*new_img(t_env *env)
{
	t_img	*img;

	if (!(img = (t_img*)malloc(sizeof(t_img))))
		ft_error("Malloc error\n");
	if (!(img->ptr = mlx_new_image(env->mlx, WIN_LENGHT, WIN_HEIGHT)))
		ft_error("mlx_new_image() error\n");
	if (!(img->pxl_byt = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_size, &img->endian)))
		ft_error("mlx_get_data_addr() error\n");
	return (img);
}

int			print_img(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img->ptr);
	env->img = new_img(env);
	draw_img(env);
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr, 0, 0);
	string_display(env);
	return (1);
}
