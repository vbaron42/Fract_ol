/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 02:06:05 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/22 02:44:09 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	control_display(void)
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
	if (!(env->vision = (t_vision*)malloc(sizeof(t_vision))))
		ft_error("Malloc error\n");
	env->vision->pattern = 0;
	env->vision->c = 0;
	env->vision->slow = 1;
	env->vision->mx = (WIN_LENGHT / 2);
	env->vision->my = (WIN_HEIGHT / 2);
	env->vision->cx = env->vision->mx;
	env->vision->cy = env->vision->my;
}

void	init_sierpi(t_env *env)
{
	if (!(env->sier = (t_fractal*)malloc(sizeof(t_fractal))))
		ft_error("Malloc error\n");
	env->sier->c = 0;
	env->sier->pattern = 1;
	env->sier->zoom = 0;
	env->sier->scale = WIN_LENGHT;
	env->sier->x1 = 0;
	env->sier->x2 = 1;
	env->sier->y1 = 0;
	env->sier->y2 = 1;
	env->sier->imax = 18;
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
