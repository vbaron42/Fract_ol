/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:58:46 by vbaron            #+#    #+#             */
/*   Updated: 2016/12/14 23:04:29 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_move(int x, int y, t_env *env)
{
/*	ft_putstr("Move : ");
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');*/
	return (1);
}

int			mouse_clic(int button, int x, int y, t_env *env)
{
/*	ft_putstr("Clic : ");
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');*/
	return (1);
}

int			event(int code, t_env *env)
{
//	ft_putnbr(code);//tmp
	if (code == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	if (code == 49)
		env->fractal++;
	if (env->fractal == 3)
		env->fractal = 0;
	ft_putnbr(env->fractal);
	print_img(env);
	return (0);
}
