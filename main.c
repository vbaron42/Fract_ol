/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:32:16 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/07 08:23:11 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_env		*env;
	void		*mlx;
	void		*win;//useless ?
	int			i;

	i = 0;
	if (WIN_LENGHT > 2500 || WIN_HEIGHT > 1500
			|| WIN_LENGHT < 200 || WIN_HEIGHT < 200)
		ft_error("Choose a correct window's size\n");
	if (argc != 2 || ((!(ft_strstr(argv[1], "Mandelbrot")))
						&& ((!(ft_strstr(argv[1], "Man"))) || (i < 0))
						&& ((!(ft_strstr(argv[1], "Julia"))) || (i++ < 0))
						&& (!(ft_strstr(argv[1], "Vision")) || ((i += 2) < 0))))
		ft_error("Usage : ./fractol [Mandelbrot, Man, Julia, Vision]\n");
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		ft_error("Malloc error\n");
	if (!(env->mlx = mlx_init()))
		ft_error("mlx_init() error\n");
	if (!(env->win = mlx_new_window(env->mlx, WIN_LENGHT, WIN_HEIGHT, TITLE)))
		ft_error("mlx_new_window() error\n");
	if (!(env->man = (t_man*)malloc(sizeof(t_man))))
		ft_error("Malloc error\n");
	env->img = new_img(env);
	env->fractal = i;
	env->c = 0;
	env->c1 = 0;
	env->r = 30;
	env->v = 120;
	env->b = 120;
	env->slow = 0;
	env->man_c = 0;
	env->man->zoom = 0;
	env->man->scale = (WIN_LENGHT / 2.7);
	env->man->x1 = -2.1;
	env->man->x2 = 0.6;
	env->man->y1 = -1.2;
	env->man->y2 = 1.2;
	env->man->imax = 42;
	env->man->img_x = (env->man->x2 - env->man->x1) * env->man->scale;
	env->man->img_y = (env->man->y2 - env->man->y1) * env->man->scale;
	env->mx = (WIN_LENGHT / 2);
	env->my = (WIN_HEIGHT / 2);
	env->cx = env->mx;
	env->cy = env->my;
	mlx_key_hook(env->win, event, env);
	mlx_mouse_hook(env->win, mouse_clic, env);
	mlx_hook(env->win, 6, 64, &mouse_move, env);
	mlx_expose_hook(env->win, print_img, env);
	mlx_loop(env->mlx);
	return (0);
}
