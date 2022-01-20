/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 08:39:26 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/31 16:44:27 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* -------------------------------------------------------------------------- */
/*
 *	void	print_matrix(t_matrix *matrix)
 *	{
 *		int	y;
 *		int	x;
 *	
 *		y = 0;
 *		while (y < matrix->max_y)
 *		{
 *			x = 0;
 *			while (x < matrix->max_x)
 *			{
 *				printf("%d-%X\t", matrix->matrix_ptr[y][x][0], \
 *					matrix->matrix_ptr[y][x][1]);
 *				x++;
 *			}
 *			putchar('\n');
 *			y++;
 *		}
 *	}
 */
/* -------------------------------------------------------------------------- */
/*
 *	int	trgb_to_int(t_uchar t, t_uchar r, t_uchar g, t_uchar b)
 *	{
 *		int	output;
 *	
 *		output = 0;
 *		output |= t;
 *		output <<= 8;
 *		output |= r;
 *		output <<= 8;
 *		output |= g;
 *		output <<= 8;
 *		output |= b;
 *		return (output);
 *	}
 */

/* -------------------------------------------------------------------------- */

static void	setup_img(t_vars *vars)
{
	vars->img.img_ptr = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img_ptr, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
}

/* -------------------------------------------------------------------------- */

static	void	init_mlx_params(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (handle_err(7));
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (!vars->win)
		return (free(vars->mlx), handle_err(8));
	setup_img(vars);
}

/* -------------------------------------------------------------------------- */

static int	get_x_offset(t_vars *vars)
{
	int	diameter;

	diameter = sqrt(pow(vars->matrix.max_x, 2) + pow(vars->matrix.max_y, 2));
	return ((diameter / 2) + (WIN_WIDTH / 2) - (diameter / 2));
}

/* -------------------------------------------------------------------------- */

void	set_default_params(t_vars *vars)
{
	vars->mapdata.zoom = 5;
	vars->mapdata.x_offset = get_x_offset(vars);
	vars->mapdata.y_offset = 50;
	vars->mapdata.z_offset = 1;
	vars->mapdata.cl_offset = 0;
	vars->mapdata.iso_pro_bool = TRUE;
	vars->mapdata.rot_x_bool = FALSE;
	vars->mapdata.rot_y_bool = FALSE;
	vars->mapdata.rot_z_bool = FALSE;
	vars->mapdata.alpha_x = 0;
}

/* -------------------------------------------------------------------------- */

void	reset_window(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img_ptr);
	setup_img(vars);
}

/* -------------------------------------------------------------------------- */

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (handle_err(6), 1);
	init_mlx_params(&vars);
	alloc_store_matrix(argv[1], &vars);
	set_default_params(&vars);
	draw_map(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr, 0, 0);
	mlx_hook(vars.win, KEYPRESS, NOEVENTMASK, handle_event, &vars);
	mlx_hook(vars.win, 17, NOEVENTMASK, xclose, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

/* -------------------------------------------------------------------------- */