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

#include "./srcs/fdf.h"

/* -------------------------------------------------------------------------- */

static	void	init_mlx_params(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (handle_err(vars, 7));
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (!vars->win)
		return (free(vars->mlx), handle_err(vars, 8));
	vars->img.img_ptr = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img_ptr, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
}

/* -------------------------------------------------------------------------- */

void	reset_window(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img_ptr);
	vars->img.img_ptr = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img_ptr, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
}

/* -------------------------------------------------------------------------- */

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 && argc != 4)
		return (handle_err(0, 6), 0);
	init_mlx_params(&vars);
	alloc_store_matrix(argv[1], &vars);
	set_default_params(&vars, argc, argv);
	draw_map(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr, 0, 0);
	write_legend(&vars);
	mlx_hook(vars.win, KEYPRESS, NOEVENTMASK, handle_event, &vars);
	mlx_hook(vars.win, 17, NOEVENTMASK, xclose, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

/* -------------------------------------------------------------------------- */