/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_draw_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:40:00 by mnaimi            #+#    #+#             */
/*   Updated: 2022/01/08 20:40:04 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* -------------------------------------------------------------------------- */

static void	project_iso(t_vars *vars)
{
	int	old_x;
	int	old_y;

	old_x = vars->linedraw.x0;
	old_y = vars->linedraw.y0;
	vars->linedraw.x0 = (old_x - old_y) * cos(0.523599);
	vars->linedraw.y0 = (vars->linedraw.z0 * -1) + (old_x + old_y) * \
		sin(0.523599);
	old_x = vars->linedraw.x1;
	old_y = vars->linedraw.y1;
	vars->linedraw.x1 = (old_x - old_y) * cos(0.523599);
	vars->linedraw.y1 = (vars->linedraw.z1 * -1) + (old_x + old_y) * \
		sin(0.523599);
}

/* -------------------------------------------------------------------------- */

static void	apply_zoom(t_vars *vars)
{
	vars->linedraw.x0 *= vars->mapdata.zoom;
	vars->linedraw.x1 *= vars->mapdata.zoom;
	vars->linedraw.y0 *= vars->mapdata.zoom;
	vars->linedraw.y1 *= vars->mapdata.zoom;
}

/* -------------------------------------------------------------------------- */

static void	drawline_calcul(t_vars *vars)
{
	apply_zoom(vars);
	project_iso(vars);
	vars->linedraw.dlta_x = abs(vars->linedraw.x1 - vars->linedraw.x0);
	vars->linedraw.dlta_y = -abs(vars->linedraw.y1 - vars->linedraw.y0);
	vars->linedraw.sx = -1;
	if (vars->linedraw.x0 < vars->linedraw.x1)
		vars->linedraw.sx = 1;
	vars->linedraw.sy = -1;
	if (vars->linedraw.y0 < vars->linedraw.y1)
		vars->linedraw.sy = 1;
	vars->linedraw.err = vars->linedraw.dlta_x + vars->linedraw.dlta_y;
	drawline_iter(vars);
}

/* -------------------------------------------------------------------------- */

static void	drawline_iter(t_vars *vars)
{
	while (vars->linedraw.x0 != vars->linedraw.x1 \
		|| vars->linedraw.y0 != vars->linedraw.y1)
	{
		mlx_pixel_put(vars->mlx, vars->win, \
			vars->linedraw.x0 + vars->mapdata.x_offset, \
			vars->linedraw.y0 + vars->mapdata.y_offset, \
			linear_color());
		vars->linedraw.e2 = 2 * vars->linedraw.err;
		if (vars->linedraw.err >= vars->linedraw.dlta_y)
		{
			vars->linedraw.err += vars->linedraw.dlta_y;
			vars->linedraw.x0 += vars->linedraw.sx;
		}
		if (vars->linedraw.e2 <= vars->linedraw.dlta_x)
		{
			vars->linedraw.err += vars->linedraw.dlta_x;
			vars->linedraw.y0 += vars->linedraw.sy;
		}
	}
}

/* -------------------------------------------------------------------------- */
