/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:31:57 by vbaron            #+#    #+#             */
/*   Updated: 2016/12/30 19:44:51 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>

# define TITLE "You can change this useless title in fractol.h"
# define WIN_LENGHT 1600
# define WIN_HEIGHT 1000
# define VISION_FOCUS 1.5
# define VISION_SLOW 1.5

typedef struct		s_man
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				scale;
	int				imax;
}					t_man;

typedef struct		s_img
{
	void			*ptr;
	int				bpp;
	int				line_size;
	int				endian;
	char			*pxl_byt;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	int				fractal;
	int				c;
	int				c1;
	int				r;
	int				v;
	int				b;
	int				r1;
	int				v1;
	int				b1;
	int				cx;
	int				cy;
	int				slow;
	int				mx;
	int				mx_sign;
	int				my;
	int				my_sign;
}					t_env;

void				vision(t_env *env);
void				mandelbrot(t_env *env);
void				julia(t_env *env);
void				img_put_pixel(t_env *env, int x, int y, int c);
int					mouse_move(int x, int y, t_env *env);
int					mouse_clic(int button, int x, int y, t_env *env);
int					event(int code, t_env *env);
t_img				*new_img(t_env *env);
int					print_img(t_env *env);
#endif
