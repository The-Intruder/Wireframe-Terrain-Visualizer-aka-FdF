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

static void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + (*z) * sin(alpha);
	*z = -prev_y * sin(alpha) + (*z) * cos(alpha);
}

/* -------------------------------------------------------------------------- */

void	handle_x_rotation(t_vars *vars)
{
	if (vars->mapdata.rot_x_bool)
	{
		rotate_x(&vars->linedraw.y0, &vars->linedraw.z0, vars->mapdata.alpha_x);
		rotate_x(&vars->linedraw.y1, &vars->linedraw.z1, vars->mapdata.alpha_x);
	}
}

/* -------------------------------------------------------------------------- */

void	handle_y_rotation(t_vars *vars)
{
	if (vars->mapdata.rot_y_bool)
	{
		vars->linedraw.x0 = vars->linedraw.x0 * cos(vars->mapdata.alpha_y) + vars->linedraw.z0 * sin(vars->mapdata.alpha_y);
		vars->linedraw.x1 = vars->linedraw.x1 * cos(vars->mapdata.alpha_y) + vars->linedraw.z1 * sin(vars->mapdata.alpha_y);
		vars->linedraw.z0 = vars->linedraw.x0 * -sin(vars->mapdata.alpha_y) + vars->linedraw.z0 * cos(vars->mapdata.alpha_y);
		vars->linedraw.z1 = vars->linedraw.x1 * -sin(vars->mapdata.alpha_y) + vars->linedraw.z1 * cos(vars->mapdata.alpha_y);
	}
}

/* -------------------------------------------------------------------------- */

void	handle_z_rotation(t_vars *vars)
{
	int		prev_x;
	int		prev_y;
	float	alpha_z;

	alpha_z = vars->mapdata.alpha_z;
	if (vars->mapdata.rot_z_bool)
	{
		if (!vars->mapdata.iso_pro_bool)
		{
			vars->linedraw.x0 -= (vars->matrix.max_y * vars->mapdata.zoom) / 2;
			vars->linedraw.x1 -= (vars->matrix.max_y * vars->mapdata.zoom) / 2;
		}
		vars->linedraw.y0 -= (vars->matrix.max_y * vars->mapdata.zoom) / 2;
		vars->linedraw.y1 -= (vars->matrix.max_y * vars->mapdata.zoom) / 2;
		prev_x = vars->linedraw.x0;
		prev_y = vars->linedraw.y0;
		vars->linedraw.x0 = prev_x * cos(alpha_z) - prev_y * sin(alpha_z);
		vars->linedraw.y0 = prev_x * sin(alpha_z) + prev_y * cos(alpha_z);
		prev_x = vars->linedraw.x1;
		prev_y = vars->linedraw.y1;
		vars->linedraw.x1 = prev_x * cos(alpha_z) - prev_y * sin(alpha_z);
		vars->linedraw.y1 = prev_x * sin(alpha_z) + prev_y * cos(alpha_z);
	}
}

/* -------------------------------------------------------------------------- */

int	rotate_map(t_vars *vars, int key_code)
{
	if (key_code == KEY_X)
	{
		vars->mapdata.rot_x_bool = TRUE;
		if (vars->mapdata.alpha_x >= to_rad(360))
			vars->mapdata.alpha_x -= to_rad(360);
		else
			vars->mapdata.alpha_x += to_rad(10); 
	}
	else if (key_code == KEY_Y)
	{
		vars->mapdata.rot_y_bool = TRUE;
		if (vars->mapdata.alpha_y >= to_rad(360))
			vars->mapdata.alpha_y -= to_rad(360);
		else
			vars->mapdata.alpha_y += to_rad(10);
	}
	else if (key_code == KEY_Z)
	{
		vars->mapdata.rot_z_bool = TRUE;
		if (vars->mapdata.alpha_z >= to_rad(360))
			vars->mapdata.alpha_z -= to_rad(360);
		else
			vars->mapdata.alpha_z += to_rad(10);
	}
	return(0);
}

/* -------------------------------------------------------------------------- */