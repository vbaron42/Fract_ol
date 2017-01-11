/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:32:16 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/11 12:51:31 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	control_display()
{
	ft_putstr("    </> </> </> </> </> </> </> </> </> </> </> </>\n");
	ft_putstr("    </>                                         </>\n");
	ft_putstr("    </>   Control :                             </>\n");
	ft_putstr("    </>                                         </>\n");
	ft_putstr("    </>  - Press SPACE to swap fractal.         </>\n");
	ft_putstr("    </>  - Press + or - to change accuracy.     </>\n");
	ft_putstr("    </>  - Press any key to change color.       </>\n");
	ft_putstr("    </>  - Press C to swap pattern.             </>\n");
	ft_putstr("    </>  - Scroll to zoom in/out.               </>\n");
	ft_putstr("    </>  - Keep left clic press to change       </>\n");
	ft_putstr("    </>     the fractal's parameters.           </>\n");
	ft_putstr("    </>  - Press Esc to leave.                  </>\n");
	ft_putstr("    </>                                         </>\n");
	ft_putstr("    </> </> </> </> </> </> </> </> </> </> </> </>\n");
}

void	init_vision(t_env *env)
{
	env->pattern = 0;
	env->c = 0;
	env->slow = 1;
	env->mx = (WIN_LENGHT / 2);
	env->my = (WIN_HEIGHT / 2);
	env->cx = env->mx;
	env->cy = env->my;
}

void	init_sierpi(t_env *env)
{
	if (!(env->sier = (t_fractal*)malloc(sizeof(t_fractal))))
		ft_error("Malloc error\n");
	env->sier->c = 0;
	env->sier->pattern = 1;
	env->sier->zoom = 0;
	env->sier->scale = (WIN_HEIGHT / 4);
	env->sier->x1 = (WIN_LENGHT / 2);
	env->sier->x2 = env->sier->x1;
	env->sier->y1 = (WIN_HEIGHT / 2);
	env->sier->y2 = env->sier->y1;
	env->sier->imax = 18;//valeur multiplier par 3 volontairement
	env->sier->img_x = (env->sier->x2 - env->sier->x1) * env->sier->scale;
	env->sier->img_y = (env->sier->y2 - env->sier->y1) * env->sier->scale;
}

void	init_julia(t_env *env)
{
	if (!(env->jul = (t_fractal*)malloc(sizeof(t_fractal))))
		ft_error("Malloc error\n");
	env->jul->c = 0;
	env->jul->pattern = 1;
	env->jul->zoom = 0;
	env->jul->scale = (WIN_LENGHT / 3);
	env->jul->x1 = -1.5;
	env->jul->x2 = 1.5;
	env->jul->y1 = -1.5;
	env->jul->y2 = 1.5;
	env->jul->imax = 142;
	env->jul->img_x = (env->jul->x2 - env->jul->x1) * env->jul->scale;
	env->jul->img_y = (env->jul->y2 - env->jul->y1) * env->jul->scale;
	env->jul->move_x = 1.785 * env->jul->scale;
	env->jul->move_y = 1.51 * env->jul->scale;
	env->jul->freeze = 0;
}

void	init_man(t_env *env)
{
	if (!(env->man = (t_fractal*)malloc(sizeof(t_fractal))))
		ft_error("Malloc error\n");
	env->man->c = 0;
	env->man->pattern = 0;
	env->man->zoom = 0;
	env->man->scale = (WIN_LENGHT / 2.7);
	env->man->x1 = -2.1;
	env->man->x2 = 0.6;
	env->man->y1 = -1.2;
	env->man->y2 = 1.2;
	env->man->imax = 42;
	env->man->img_x = (env->man->x2 - env->man->x1) * env->man->scale;
	env->man->img_y = (env->man->y2 - env->man->y1) * env->man->scale;
}

int		main(int argc, char **argv)
{
	t_env		*env;
	int			i;

	i = 0;
	if (WIN_LENGHT > 2500 || WIN_HEIGHT > 1500
			|| WIN_LENGHT < 200 || WIN_HEIGHT < 200)
		ft_error("Choose a correct window's size\n");
	if (argc != 2 || ((!(ft_strstr(argv[1], "Mandelbrot")))
						&& ((!(ft_strstr(argv[1], "Man"))) || (i < 0))
						&& ((!(ft_strstr(argv[1], "Julia"))) || (i++ < 0))
						&& ((!(ft_strstr(argv[1], "Sierpi"))) || ((i += 2) < 0))
						&& ((!(ft_strstr(argv[1], "Vision"))) || ((i += 3) < 0))))
		ft_error("Usage : ./fractol [Mandelbrot, Man, Julia, Sierpi, Vision]\n");
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		ft_error("Malloc error\n");
	if (!(env->mlx = mlx_init()))
		ft_error("mlx_init() error\n");
	if (!(env->win = mlx_new_window(env->mlx, WIN_LENGHT, WIN_HEIGHT, TITLE)))
		ft_error("mlx_new_window() error\n");
	control_display();
	env->img = new_img(env);
	env->fractal = i;
	init_man(env);
	init_julia(env);
	init_sierpi(env);
	init_vision(env);
	mlx_key_hook(env->win, event, env);
	mlx_mouse_hook(env->win, mouse_clic, env);
	mlx_hook(env->win, 6, (1L << 6), &mouse_move, env);
	mlx_expose_hook(env->win, print_img, env);
	mlx_loop(env->mlx);
	return (0);
}
