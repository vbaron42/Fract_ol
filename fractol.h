/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:31:57 by vbaron            #+#    #+#             */
/*   Updated: 2016/12/15 06:48:51 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>

# define TITLE "You can change this useless title in fractol.h"
# define WIN_LENGHT 1200
# define WIN_HEIGHT 900

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
	int				r;
	int				v;
	int				b;
	int				v1;
	int				b1;
}					t_env;

void				autre(t_env *env);//tmp
void				mandelbrot(t_env *env);
void				julia(t_env *env);
void				img_put_pixel(t_env *env, int x, int y, int c);
int					mouse_move(int x, int y, t_env *env);
int					mouse_clic(int button, int x, int y, t_env *env);
int					event(int code, t_env *env);
t_img				*new_img(t_env *env);
int					print_img(t_env *env);
#endif
