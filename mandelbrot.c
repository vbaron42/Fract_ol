/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:21:51 by vbaron            #+#    #+#             */
/*   Updated: 2016/12/15 01:55:58 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(t_env *env)
{
	int		i;
	int		f;
	int		f2;
	int		s;
	int		max;
	int		imax;
	int		c;

	c = 1;
	f2 = 0;
	f = 6;
	s = 10;
	max = 900;
	imax = max;
	while (f-- >= 0)
	{
		imax = imax / 3;
		i = 0;
		c = 1;
		while (i++ < max)
		{
			if (i < (imax * c) || ((i > (imax * c) * 2)))
				img_put_pixel(env, i, (f2 * s) + 100, 0xFFFF5F);
			if (i == imax)
				c++;
		}
		f2++;
	}
}
