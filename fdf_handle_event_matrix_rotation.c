/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrix_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:17:52 by mnaimi            #+#    #+#             */
/*   Updated: 2022/01/18 16:17:53 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* -------------------------------------------------------------------------- */

static double to_rad(int deg)
{
    return deg * (M_PI / 180);
}

/* -------------------------------------------------------------------------- */

void	handle_x_rotation(t_vars *vars)
{
	int	prev_y;

	prev_y = vars->linedraw.y0;
	vars->linedraw.y0 = prev_y * cos(vars->mapdata.alpha_x) + \
		(vars->linedraw.z0) * sin(vars->mapdata.alpha_x);
	vars->linedraw.z0 = -prev_y * sin(vars->mapdata.alpha_x) + \
		(vars->linedraw.z0) * cos(vars->mapdata.alpha_x);
	prev_y = vars->linedraw.y1;
	vars->linedraw.y1 = prev_y * cos(vars->mapdata.alpha_x) + \
		(vars->linedraw.z1) * sin(vars->mapdata.alpha_x);
	vars->linedraw.z1 = -prev_y * sin(vars->mapdata.alpha_x) + \
		(vars->linedraw.z1) * cos(vars->mapdata.alpha_x);
}

/* -------------------------------------------------------------------------- */

void	handle_y_rotation(t_vars *vars)
{
	int	prev_x;

	prev_x = vars->linedraw.x0;
	vars->linedraw.x0 = prev_x * cos(vars->mapdata.alpha_y) + \
		vars->linedraw.z0 * sin(vars->mapdata.alpha_y);
	vars->linedraw.z0 = prev_x * -sin(vars->mapdata.alpha_y) + \
		vars->linedraw.z0 * cos(vars->mapdata.alpha_y);

	prev_x = vars->linedraw.x1;
	vars->linedraw.x1 = prev_x * cos(vars->mapdata.alpha_y) + \
		vars->linedraw.z1 * sin(vars->mapdata.alpha_y);
	vars->linedraw.z1 = prev_x * -sin(vars->mapdata.alpha_y) + \
		vars->linedraw.z1 * cos(vars->mapdata.alpha_y);
}

/* -------------------------------------------------------------------------- */

void	handle_z_rotation(t_vars *vars)
{
	int	prev_x;
	int	prev_y;

	prev_x = vars->linedraw.x0;
	prev_y = vars->linedraw.y0;
	vars->linedraw.x0 = prev_x * cos(vars->mapdata.alpha_z) - \
		prev_y * sin(vars->mapdata.alpha_z);
	vars->linedraw.y0 = prev_x * sin(vars->mapdata.alpha_z) + \
		prev_y * cos(vars->mapdata.alpha_z);
	prev_x = vars->linedraw.x1;
	prev_y = vars->linedraw.y1;
	vars->linedraw.x1 = prev_x * cos(vars->mapdata.alpha_z) - \
		prev_y * sin(vars->mapdata.alpha_z);
	vars->linedraw.y1 = prev_x * sin(vars->mapdata.alpha_z) + \
		prev_y * cos(vars->mapdata.alpha_z);
}

/* -------------------------------------------------------------------------- */

int	rotate_map(t_vars *vars, int key_code)
{
	if (key_code == KEY_X)
	{
		if (vars->mapdata.alpha_x >= to_rad(360))
			vars->mapdata.alpha_x -= to_rad(360);
		else
			vars->mapdata.alpha_x += to_rad(10);
	}
	else if (key_code == KEY_Y)
	{
		if (vars->mapdata.alpha_y >= to_rad(360))
			vars->mapdata.alpha_y -= to_rad(360);
		else
			vars->mapdata.alpha_y += to_rad(10);
	}
	else if (key_code == KEY_Z)
	{
		if (vars->mapdata.alpha_z >= to_rad(360))
			vars->mapdata.alpha_z -= to_rad(360);
		else
			vars->mapdata.alpha_z += to_rad(10);
	}
	return(0);
}

/* -------------------------------------------------------------------------- */