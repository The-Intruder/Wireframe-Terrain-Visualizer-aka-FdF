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

void	handle_zoom_event(t_vars *vars, int key_code)
{
	if (key_code == KEY_PAD_ADD && vars->mapdata.zoom + 1 <= 50)
		vars->mapdata.zoom += 1;
	else if (key_code == KEY_PAD_SUB && vars->mapdata.zoom - 1 >= 1)
		vars->mapdata.zoom -= 1;
	if (vars->mapdata.iso_pro_bool)
		vars->mapdata.y_offset = 50;
}

/* -------------------------------------------------------------------------- */

void	handle_z_offset_event(t_vars *vars, int key_code)
{
	if (key_code == KEY_PAGE_UP && vars->mapdata.z_offset + 1 <= 255)
		vars->mapdata.z_offset += 1;
	else if (key_code == KEY_PAGE_DOWN && vars->mapdata.z_offset - 1 >= -255)
		vars->mapdata.z_offset -= 1;
}

/* -------------------------------------------------------------------------- */

void	handle_iso_pro(t_vars *vars)
{
	if (vars->mapdata.iso_pro_bool)
		vars->mapdata.iso_pro_bool = FALSE;
	else
		vars->mapdata.iso_pro_bool = TRUE;
}

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
