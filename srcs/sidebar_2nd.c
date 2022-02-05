/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_legend_2nd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:58:44 by mnaimi            #+#    #+#             */
/*   Updated: 2022/01/17 13:58:54 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* -------------------------------------------------------------------------- */

void	draw_bg(t_vars *vars, int width, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WIN_HEIGHT)
	{
		j = 0;
		while (j <= width)
			img_pixel_put(vars, j++, i, color);
		++i;
	}
}

/* -------------------------------------------------------------------------- */

static void	print_status( int y, t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 20, y * 1 - 12, 0xFFFFFF, "Status:");
	mlx_string_put(vars->mlx, vars->win, 19, y * 1 - 7, 0xFFFFFF, "_______");
	print_projection(y, vars);
	print_zoom(y, vars);
	print_xyz_offset(y, vars);
	print_rotation_data(y, vars);
}

/* -------------------------------------------------------------------------- */

static void	print_directions(int y, t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 110, y * 13 - 5, 0xFFFFFF, " ^");
	mlx_string_put(vars->mlx, vars->win, 40, y * 13, 0xFFFFFF, \
		"UP:     | (Up Arrow)");
	mlx_string_put(vars->mlx, vars->win, 40, y * 14, 0xFFFFFF, \
		"DOWN:   | (Down Arrow)");
	mlx_string_put(vars->mlx, vars->win, 110, y * 14 + 8, 0xFFFFFF, " v");
	mlx_string_put(vars->mlx, vars->win, 40, y * 15, 0xFFFFFF, \
		"RIGHT:  > (Right Arrow)");
	mlx_string_put(vars->mlx, vars->win, 115, y * 15 - 7, 0xFFFFFF, "_");
	mlx_string_put(vars->mlx, vars->win, 40, y * 16, 0xFFFFFF, \
		"LEFT:  <  (Left Arrow)");
	mlx_string_put(vars->mlx, vars->win, 115, y * 16 - 7, 0xFFFFFF, "_");
}

/* -------------------------------------------------------------------------- */

static void	print_misc_controls(int y, t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 40, y * 18, 0xFFFFFF, \
		"Rotate on x_axis:   X");
	mlx_string_put(vars->mlx, vars->win, 40, y * 19, 0xFFFFFF, \
		"Rotate on y_axis:   Y");
	mlx_string_put(vars->mlx, vars->win, 40, y * 20, 0xFFFFFF, \
		"Rotate on z_axis:   Z");
	mlx_string_put(vars->mlx, vars->win, 40, y * 21, 0xFFFFFF, \
		"Toggle Projection:  P");
	mlx_string_put(vars->mlx, vars->win, 40, y * 23, 0xFFFFFF, \
		"Zoom In:   NUM_PAD +");
	mlx_string_put(vars->mlx, vars->win, 40, y * 24, 0xFFFFFF, \
		"Zoom Out:  NUM_PAD -");
	mlx_string_put(vars->mlx, vars->win, 40, y * 26, 0xFFFFFF, \
		"Incr. Z:   Page Up");
	mlx_string_put(vars->mlx, vars->win, 40, y * 27, 0xFFFFFF, \
		"Decr. Z:   Page Down");
}

/* -------------------------------------------------------------------------- */

void	write_legend(t_vars *vars)
{
	print_status(25, vars);
	mlx_string_put(vars->mlx, vars->win, 20, 25 * 12 - 12, 0xFFFFFF, \
		"Controls:");
	mlx_string_put(vars->mlx, vars->win, 19, 25 * 12 - 7, 0xFFFFFF, \
		"_________");
	print_directions(25, vars);
	print_misc_controls(25, vars);
	mlx_string_put(vars->mlx, vars->win, 40, 25 * 29, 0xFFFFFF, \
		"Reset Map:      R");
	mlx_string_put(vars->mlx, vars->win, 40, 25 * 30, 0xFFFFFF, \
		"Exit Program:   ESC");
}

/* -------------------------------------------------------------------------- */