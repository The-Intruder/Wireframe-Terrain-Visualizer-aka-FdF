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

static void	apply_3d_rot_x(t_vars *vars)
{
	
	vars->linedraw.y0 = vars->linedraw.y0 * cos(vars->mapdata.alpha_x) - vars->linedraw.z0 * sin(vars->mapdata.alpha_x);
	vars->linedraw.y1 = vars->linedraw.y1 * cos(vars->mapdata.alpha_x) - vars->linedraw.z1 * sin(vars->mapdata.alpha_x);
	vars->linedraw.z0 = vars->linedraw.y0 * sin(vars->mapdata.alpha_x) + vars->linedraw.z0 * cos(vars->mapdata.alpha_x);
	vars->linedraw.z1 = vars->linedraw.y1 * sin(vars->mapdata.alpha_x) + vars->linedraw.z1 * cos(vars->mapdata.alpha_x);

}

/* -------------------------------------------------------------------------- */

void	handle_x_rotation(t_vars *vars)
{
	if (vars->mapdata.rot_x_bool == TRUE)
	{
		printf("Here i am again\n");
		apply_3d_rot_x(vars);
		vars->mapdata.rot_x_bool = FALSE;
	}
}

/* -------------------------------------------------------------------------- */

void	handle_y_rotation(t_vars *vars)
{
	if (vars->mapdata.rot_y_bool == TRUE)
	{
		// apply_3d_rot(&vars->linedraw.x0, cos(0.2), 0, sin(0.2));
		// apply_3d_rot(&vars->linedraw.x1, cos(0.2), 0, sin(0.2));
		// apply_3d_rot(&vars->linedraw.z0, -sin(0.2), 0, cos(0.2));
		// apply_3d_rot(&vars->linedraw.z1, -sin(0.2), 0, cos(0.2));
		vars->mapdata.rot_y_bool = FALSE;
	}
}

/* -------------------------------------------------------------------------- */

void	handle_z_rotation(t_vars *vars)
{
	if (vars->mapdata.rot_z_bool == TRUE)
	{
		// apply_3d_rot(&vars->linedraw.x0, cos(0.2), -sin(0.2), 0);
		// apply_3d_rot(&vars->linedraw.x1, cos(0.2), -sin(0.2), 0);
		// apply_3d_rot(&vars->linedraw.y0, sin(0.2), cos(0.2), 0);
		// apply_3d_rot(&vars->linedraw.y1, sin(0.2), cos(0.2), 0);
		vars->mapdata.rot_z_bool = FALSE;
	}
}

/* -------------------------------------------------------------------------- */

int	rotate_map(t_vars *vars, int key_code)
{
	printf("Here i am\n");
	if (key_code == KEY_X)
	{
		vars->mapdata.rot_x_bool = TRUE;
		vars->mapdata.alpha_x += 0.2;
	}
	else if (key_code == KEY_Y)
		vars->mapdata.rot_y_bool = TRUE;
	else if (key_code == KEY_Z)
		vars->mapdata.rot_z_bool = TRUE;
	return(0);
}

/* -------------------------------------------------------------------------- */