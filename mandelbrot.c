/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:21:51 by vbaron            #+#    #+#             */
/*   Updated: 2016/12/14 23:30:13 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(t_env *env)
{
	int		i;

	i = 0;
	while (i++ < 400)
		img_put_pixel(env, i, 100, 0xFFFF5F);
}
