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
	if (vars->mapdata.rot_x_bool == TRUE)
	{
		vars->linedraw.y0 =  vars->linedraw.y0 - (vars->matrix.max_y / 2);
		vars->linedraw.y1 =  vars->linedraw.y1 - (vars->matrix.max_y / 2);
		vars->linedraw.y0 = vars->linedraw.y0 * cos(vars->mapdata.alpha_x) - vars->linedraw.z0 * sin(vars->mapdata.alpha_x);
		vars->linedraw.y1 = vars->linedraw.y1 * cos(vars->mapdata.alpha_x) - vars->linedraw.z1 * sin(vars->mapdata.alpha_x);
		vars->linedraw.z0 = vars->linedraw.y0 * sin(vars->mapdata.alpha_x) + vars->linedraw.z0 * cos(vars->mapdata.alpha_x);
		vars->linedraw.z1 = vars->linedraw.y1 * sin(vars->mapdata.alpha_x) + vars->linedraw.z1 * cos(vars->mapdata.alpha_x);
		if (vars->mapdata.alpha_x <= to_rad(180))
		{
			vars->linedraw.z0 = abs(vars->linedraw.z0);
			vars->linedraw.z1 = abs(vars->linedraw.z1);
		}
		else
		{
			vars->linedraw.z0 = -abs(vars->linedraw.z0);
			vars->linedraw.z1 = -abs(vars->linedraw.z1);
		}
	}
}

/* -------------------------------------------------------------------------- */

void	handle_y_rotation(t_vars *vars)
{
	if (vars->mapdata.rot_y_bool == TRUE)
	{
		vars->linedraw.x0 =  vars->linedraw.x0 - (vars->matrix.max_x / 2);
		vars->linedraw.x1 =  vars->linedraw.x1 - (vars->matrix.max_x / 2);
		vars->linedraw.x0 = vars->linedraw.x0 * cos(vars->mapdata.alpha_y) + vars->linedraw.z0 * sin(vars->mapdata.alpha_y);
		vars->linedraw.x1 = vars->linedraw.x1 * cos(vars->mapdata.alpha_y) + vars->linedraw.z1 * sin(vars->mapdata.alpha_y);
		vars->linedraw.z0 = vars->linedraw.x0 * -sin(vars->mapdata.alpha_y) + vars->linedraw.z0 * cos(vars->mapdata.alpha_y);
		vars->linedraw.z1 = vars->linedraw.x1 * -sin(vars->mapdata.alpha_y) + vars->linedraw.z1 * cos(vars->mapdata.alpha_y);
	}
}

/* -------------------------------------------------------------------------- */

void	handle_z_rotation(t_vars *vars)
{
	if (vars->mapdata.rot_z_bool == TRUE)
	{
		vars->linedraw.x0 = vars->linedraw.x0 * cos(vars->mapdata.alpha_z) - vars->linedraw.y0 * sin(vars->mapdata.alpha_z);
		vars->linedraw.x1 = vars->linedraw.x1 * cos(vars->mapdata.alpha_z) - vars->linedraw.y1 * sin(vars->mapdata.alpha_z);
		vars->linedraw.y0 = vars->linedraw.x0 * cos(vars->mapdata.alpha_z) + vars->linedraw.y0 * sin(vars->mapdata.alpha_z);
		vars->linedraw.y1 = vars->linedraw.x1 * cos(vars->mapdata.alpha_z) + vars->linedraw.y1 * sin(vars->mapdata.alpha_z);
	}
}

/* -------------------------------------------------------------------------- */

int	rotate_map(t_vars *vars, int key_code)
{
	if (key_code == KEY_X)
	{
		vars->mapdata.rot_x_bool = TRUE;
		if (vars->mapdata.alpha_x >= to_rad(360))
			vars->mapdata.alpha_x = 0;
		else
			vars->mapdata.alpha_x += to_rad(10);
	}
	else if (key_code == KEY_Y)
	{
		vars->mapdata.rot_y_bool = TRUE;
		vars->mapdata.alpha_y += to_rad(10);
	}
	else if (key_code == KEY_Z)
	{
		vars->mapdata.rot_z_bool = TRUE;
		vars->mapdata.alpha_z += 0.2;
	}
	return(0);
}

/* -------------------------------------------------------------------------- */