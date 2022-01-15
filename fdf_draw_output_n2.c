/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_output_n2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:00:05 by mnaimi            #+#    #+#             */
/*   Updated: 2022/01/14 18:00:06 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* -------------------------------------------------------------------------- */

static void	assign_x(t_vars *vars, int x0, int x1)
{
	vars->linedraw.x0 = x0;
	vars->linedraw.x1 = x1;
}

/* -------------------------------------------------------------------------- */

static void	assign_y(t_vars *vars, int y0, int y1)
{
	vars->linedraw.y0 = y0;
	vars->linedraw.y1 = y1;
	assign_z(vars);
}

/* -------------------------------------------------------------------------- */

static void	assign_z(t_vars *vars)
{
	vars->linedraw.z0 = \
		vars->matrix.matrix_ptr[vars->linedraw.y0][vars->linedraw.x0][0];
	vars->linedraw.z1 = \
		vars->matrix.matrix_ptr[vars->linedraw.y1][vars->linedraw.x1][0];
	drawline(vars);
}

/* -------------------------------------------------------------------------- */

static void	assign_c(t_vars *vars)
{
	vars->linedraw.cl0 = \
		vars->matrix.matrix_ptr[vars->linedraw.y0][vars->linedraw.x0][1];
	vars->linedraw.cl1 = \
		vars->matrix.matrix_ptr[vars->linedraw.y1][vars->linedraw.x1][1];
	drawline(vars);
}

/* -------------------------------------------------------------------------- */

static void	iter_x(t_vars *vars, int y)
{	
	int	x;

	x = 0;
	while (x < vars->matrix.max_x - 1)
	{
		assign_x(vars, x, x + 1);
		assign_y(vars, y, y);
		assign_x(vars, x, x);
		assign_y(vars, y, y + 1);
		if (x == vars->matrix.max_x - 2)
		{
			assign_x(vars, x + 1, x + 1);
			assign_y(vars, y, y + 1);
		}
		if (y == vars->matrix.max_y - 2)
		{
			assign_x(vars, x, x + 1);
			assign_y(vars, y + 1, y + 1);
		}
		x++;
	}
}

/* -------------------------------------------------------------------------- */

void	draw_map(t_vars	*vars)
{
	int	y;

	vars->mapdata.zoom = 35;
	vars->mapdata.x_offset = ((sqrt(pow(vars->matrix.max_x, 2) + \
		pow(vars->matrix.max_y, 2)) / 2) * vars->mapdata.zoom) + \
		(1920 / 2) - vars->mapdata.x_offset;
	vars->mapdata.y_offset = 100;
	y = 0;
	while (y < vars->matrix.max_y - 1)
	{
		iter_x(vars, y);
		y++;
	}
}

/* -------------------------------------------------------------------------- */
