/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handle_translation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:58:44 by mnaimi            #+#    #+#             */
/*   Updated: 2022/01/17 13:58:54 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/* -------------------------------------------------------------------------- */

int	xclose(void *v_vars)
{
	t_vars	*vars;

	vars = (t_vars *)v_vars;
	exit(0);
}

/* -------------------------------------------------------------------------- */

int	handle_event(int key_press, t_vars *vars)
{
	if (key_press == KEY_UP)
		vars->mapdata.y_offset -= 10;
	else if (key_press == KEY_DOWN)
		vars->mapdata.y_offset += 10;
	else if (key_press == KEY_LEFT)
		vars->mapdata.x_offset -= 10;
	else if (key_press == KEY_RIGHT)
		vars->mapdata.x_offset += 10;
	else if (key_press == KEY_ESCAPE || key_press == 17)
		exit(0);
	else if (key_press == KEY_R)
		set_default_params(vars);
	reset_window(vars);
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
	return (0);
}

/* -------------------------------------------------------------------------- */
