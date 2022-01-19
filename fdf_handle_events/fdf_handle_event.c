/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handle_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:58:44 by mnaimi            #+#    #+#             */
/*   Updated: 2022/01/17 13:58:54 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/* -------------------------------------------------------------------------- */

int	handle_event(int key_code, t_vars *vars)
{
	if (key_code == KEY_UP)
		vars->mapdata.y_offset += 20 * vars->mapdata.zoom;
	else if (key_code == KEY_DOWN)
		vars->mapdata.y_offset -= 20 * vars->mapdata.zoom;
	else if (key_code == KEY_LEFT)
		vars->mapdata.x_offset += 20 * vars->mapdata.zoom;
	else if (key_code == KEY_RIGHT)
		vars->mapdata.x_offset -= 20 * vars->mapdata.zoom;
	else if (key_code == KEY_PAD_ADD || key_code == KEY_PAD_SUB)
		handle_zoom_event(vars, key_code);
	else if (key_code == KEY_PAGE_UP || key_code == KEY_PAGE_DOWN)
		handle_z_offset_event(vars, key_code);
	else if (key_code == KEY_P)
		handle_iso_pro(vars);
	else if (key_code == KEY_R)
		set_default_params(vars);
	else if (key_code == KEY_ESCAPE || key_code == 17)
		exit(0);
	reset_window(vars);
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
	return (0);
}

/* -------------------------------------------------------------------------- */

// void	translate_x_right(t_vars *vars)
// {
// }

/* -------------------------------------------------------------------------- */

// void	translate_x_left(t_vars *vars)
// {
// }

/* -------------------------------------------------------------------------- */

// void	translate_y_up(t_vars *vars)
// {
// }

/* -------------------------------------------------------------------------- */

// void	translate_y_down(t_vars *vars)
// {
// }

/* -------------------------------------------------------------------------- */
