/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:31:57 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/14 16:36:52 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>

# define TITLE "You can change this useless title in fractol.h"
# define WIN_LENGHT 900
# define WIN_HEIGHT 800
# define VISION_FOCUS 1.5
# define COS45 0.707106

typedef struct		s_cplx_nb
{
	double			r;
	double			i;
}					t_cplx_nb;

typedef struct		s_fractal
{
	double			m_x;
	double			m_y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			img_x;
	double			img_y;
	double			scale;
	int				imax;
	char			zoom;
	int				c;
	int				pattern;
	char			freeze;
	int				move_x;
	int				move_y;
	double			c_r;
	double			c_i;
}					t_fractal;

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
	t_fractal		*jul;
	t_fractal		*man;
	t_fractal		*sier;
	int				c;
	int				pattern;
	int				c1;
	int				r;
	int				cx;
	int				cy;
	int				cx2;
	int				cy2;
	double			slow;
	int				mx;
	int				mx_sign;
	int				my;
	int				my_sign;
}					t_env;

void				vision(t_env *env);
void				mandelbrot(t_env *env);
void				julia(t_env *env);
void				sierpi(t_env *env);
void				white_screen(t_env *env);
void				zoom_in_out(t_fractal *fra, double hx, double hy, int imax);
void				img_put_pixel(t_env *env, int x, int y, int c);
int					mouse_move(int x, int y, t_env *env);
int					mouse_clic(int button, int x, int y, t_env *env);
int					event(int code, t_env *env);
int					color_scale(int i, int pattern);
t_img				*new_img(t_env *env);
int					print_img(t_env *env);
#endif
