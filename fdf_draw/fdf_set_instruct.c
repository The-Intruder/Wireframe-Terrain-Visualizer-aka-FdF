/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_instruct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:25:56 by mnaimi            #+#    #+#             */
/*   Updated: 2022/01/16 15:25:58 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/* -------------------------------------------------------------------------- */

int	linear_color(t_vars *vars)
{
	t_uint	color;
	t_uint	count;
	t_uint	min;
	t_uint	max;
	t_uint	x;

	count = (vars->linedraw.x0 + vars->linedraw.y0) / 2;
	min = (vars->linedraw.x0_bckp + vars->linedraw.y0_bckp) / 2;
	max = (vars->linedraw.x1 + vars->linedraw.y1) / 2;
	x = (count - min) / (max - min);
	color = (x * vars->linedraw.cl0) + ((x - 1) * vars->linedraw.cl1);
	printf("%u\n", (t_uint)color);
	return (color ^ UINT_MAX);
}

/* -------------------------------------------------------------------------- */

static void	set_xy_offset(t_vars *vars)
{
	int	diameter;

	diameter = sqrt(pow(vars->matrix.max_x, 2) + pow(vars->matrix.max_y, 2));
	vars->mapdata.x_offset = (diameter / 2);
	vars->mapdata.x_offset += (WIN_WIDTH / 2) - vars->mapdata.x_offset;
	vars->mapdata.y_offset = 10;
}

/* -------------------------------------------------------------------------- */

void	draw_map(t_vars	*vars)
{
	vars->mapdata.zoom = 5;
	set_xy_offset(vars);
	iter_x(vars);
}

/* -------------------------------------------------------------------------- */
