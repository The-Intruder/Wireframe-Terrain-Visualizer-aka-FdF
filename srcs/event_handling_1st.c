/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handle_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:58:44 by mnaimi            #+#    #+#             */
/*   Updated: 2022/01/17 13:58:54 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* -------------------------------------------------------------------------- */

static int	get_x_offset(t_vars *vars)
{
	int	diameter;

	diameter = sqrt(pow(vars->matrix.max_x, 2) + pow(vars->matrix.max_y, 2));
	return (((diameter / 2) + (WIN_WIDTH / 2) - (diameter / 2)));
}

/* -------------------------------------------------------------------------- */

static void	check_args(t_vars *vars, int argc, char **argv)
{
	int	arg_zoom;
	int	arg_z;

	if (argc == 4)
	{
		arg_zoom = abs(ft_atoi(argv[2]));
		arg_z = ft_atoi(argv[3]);
		if (ft_isdigit(*argv[2]) && (ft_isdigit(*argv[3]) || (*argv[3] == '-' \
			&& ft_isdigit(argv[3][1]))) && abs(arg_zoom) != 0)
		{
			vars->mapdata.zoom = abs(ft_atoi(argv[2]));
			vars->mapdata.z_offset = ft_atoi(argv[3]);
		}
		else
			handle_err(vars, 9);
	}
	else
	{
		vars->mapdata.zoom = 15;
		vars->mapdata.z_offset = 1;
	}
}

/* -------------------------------------------------------------------------- */

int	xclose(void *v_vars)
{
	t_vars	*vars;

	vars = (t_vars *)v_vars;
	handle_err(vars, 0);
	return (0);
}

/* -------------------------------------------------------------------------- */

void	set_default_params(t_vars *vars, int argc, char **argv)
{
	check_args(vars, argc, argv);
	vars->mapdata.x_offset = get_x_offset(vars);
	vars->mapdata.y_offset = (WIN_HEIGHT - vars->matrix.max_y) / 2;
	vars->mapdata.cl_offset = 128;
	vars->mapdata.iso_pro_bool = TRUE;
	vars->mapdata.alpha_x = 0;
	vars->mapdata.alpha_y = 0;
	vars->mapdata.alpha_z = 0;
}

/* -------------------------------------------------------------------------- */

int	handle_event(int key_code, t_vars *vars, int argc, char **argv)
{
	if (!vars->is_main && (key_code == KEY_LEFT || key_code == KEY_RIGHT \
		|| key_code == KEY_DOWN || key_code == KEY_UP))
		handle_xy_offset(vars, key_code);
	else if (!vars->is_main && (key_code == KEY_PAD_ADD \
		|| key_code == KEY_PAD_SUB))
		handle_zoom_event(vars, key_code);
	else if (!vars->is_main && (key_code == KEY_PAGE_UP \
		|| key_code == KEY_PAGE_DOWN))
		handle_z_offset_event(vars, key_code);
	else if (!vars->is_main && key_code == KEY_P)
		vars->mapdata.iso_pro_bool = !vars->mapdata.iso_pro_bool;
	else if (!vars->is_main && key_code == KEY_R)
		set_default_params(vars, argc, argv);
	else if (!vars->is_main && (key_code == KEY_X \
		|| key_code == KEY_Y || key_code == KEY_Z))
		rotate_map(vars, key_code);
	else if (key_code == KEY_ESCAPE || key_code == 17)
		handle_err(vars, 0);
	reset_window(vars);
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
	if (!vars->is_main)
		write_legend(vars);
	return (0);
}

/* -------------------------------------------------------------------------- */