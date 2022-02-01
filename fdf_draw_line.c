/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
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

	if (vars->mapdata.iso_pro_bool)
	{
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
}

/* -------------------------------------------------------------------------- */

static void	apply_zoom(t_vars *vars)
{
	vars->linedraw.x0 *= vars->mapdata.zoom;
	vars->linedraw.x1 *= vars->mapdata.zoom;
	vars->linedraw.y0 *= vars->mapdata.zoom;
	vars->linedraw.y1 *= vars->mapdata.zoom;
	vars->linedraw.y0 -= (vars->matrix.max_y * vars->mapdata.zoom) / 2;
	vars->linedraw.y1 -= (vars->matrix.max_y * vars->mapdata.zoom) / 2;
	vars->linedraw.x0 -= (vars->matrix.max_y * vars->mapdata.zoom) / 2;
	vars->linedraw.x1 -= (vars->matrix.max_y * vars->mapdata.zoom) / 2;
}

/* -------------------------------------------------------------------------- */

static void	img_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*pxl_ptr;

	if ((x >= 0 && x < WIN_WIDTH) && (y >= 0 && y < WIN_HEIGHT))
	{
		pxl_ptr = vars->img.addr;
		pxl_ptr += y * vars->img.line_length;
		pxl_ptr += x * (vars->img.bits_per_pixel / 8);
		*(unsigned int *)pxl_ptr = color;
	}
}

/* -------------------------------------------------------------------------- */

static void	drawline_iter(t_vars *vars)
{
	while (vars->linedraw.x0 != vars->linedraw.x1 \
		|| vars->linedraw.y0 != vars->linedraw.y1)
	{
		img_pixel_put(vars, \
			vars->linedraw.x0 + vars->mapdata.x_offset, \
			vars->linedraw.y0 + vars->mapdata.y_offset, \
			vars->linedraw.cl);
		vars->linedraw.e2 = 2 * vars->linedraw.err;
		if (vars->linedraw.e2 >= vars->linedraw.dlta_y)
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

void	drawline_calcul(t_vars *vars)
{
	apply_zoom(vars);
	project_iso(vars);
	handle_x_rotation(vars);
	handle_y_rotation(vars);
	handle_z_rotation(vars);
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
