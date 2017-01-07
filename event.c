/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:58:46 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/07 09:04:53 by vbaron           ###   ########.fr       */
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
	env->mx = x;
	env->my = y;
	print_img(env);
	return (1);
}

int			mouse_clic(int button, int x, int y, t_env *env)
{
	ft_putstr("Clic : ");
	ft_putnbr(button);
/*	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');*/
	if (env->fractal == 0)
	{
		env->man->zoom = 0;
		if (button == 5)
		{
			env->man->zoom = 1;
			env->man_c += 8;// deplacer ? modifier valeur ? par un multiple ?
		}
		else if (button == 4)
		{
			env->man->zoom = -1;
			env->man_c -= 8;// deplacer ? modifier valeur ? par un multiple ?
		}
		env->man->mouse_x = x;
		env->man->mouse_y = y;
	}
	print_img(env);
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
	env->man->zoom = 0;
	env->man_c += 16;// deplacer ? modifier valeur ? par un multiple ?
	if (code == 49)
		env->fractal++;
	if (env->fractal == 3)
		env->fractal = 0;
	print_img(env);
	return (0);
}
