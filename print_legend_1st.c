/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_legend_1st.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:58:44 by mnaimi            #+#    #+#             */
/*   Updated: 2022/01/17 13:58:54 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* -------------------------------------------------------------------------- */

void	print_projection(int y, t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 40, y * 2, 0xFFFFFF, "Projection:");
	if (vars->mapdata.iso_pro_bool)
		mlx_string_put(vars->mlx, vars->win, 160, y * 2, 0xFFFFFF, "Isometric");
	else
		mlx_string_put(vars->mlx, vars->win, 160, y * 2, 0xFFFFFF, "Parallel");
}

/* -------------------------------------------------------------------------- */

void	set_deg(int deg, char **ascii_deg)
{
	if (deg == 370)
		*ascii_deg = ft_strdup("10");
	else if (deg == 360)
		*ascii_deg = ft_strdup("0");
	else
		*ascii_deg = ft_itoa(deg);
}

/* -------------------------------------------------------------------------- */

void	print_rotation_data(int y, t_vars *vars)
{
	char	*alpha;
	char	*beta;
	char	*gamma;

	set_deg(ceil(vars->mapdata.alpha_x * (180 / M_PI)), &alpha);
	set_deg(ceil(vars->mapdata.alpha_y * (180 / M_PI)), &beta);
	set_deg(ceil(vars->mapdata.alpha_z * (180 / M_PI)), &gamma);
	mlx_string_put(vars->mlx, vars->win, 40, y * 7, 0xFFFFFF, "X Deg:");
	mlx_string_put(vars->mlx, vars->win, 160, y * 7, 0xFFFFFF, alpha);
	mlx_string_put(vars->mlx, vars->win, 40, y * 8, 0xFFFFFF, "Y Deg:");
	mlx_string_put(vars->mlx, vars->win, 160, y * 8, 0xFFFFFF, beta);
	mlx_string_put(vars->mlx, vars->win, 40, y * 9, 0xFFFFFF, "Z Deg:");
	mlx_string_put(vars->mlx, vars->win, 160, y * 9, 0xFFFFFF, gamma);
	free(alpha);
	free(beta);
	free(gamma);
}

/* -------------------------------------------------------------------------- */

void	print_xyz_offset(int y, t_vars *vars)
{
	char	*x_offset;
	char	*y_offset;
	char	*z_offset;

	x_offset = ft_itoa(vars->mapdata.x_offset - ((vars->matrix.max_x / 2) * \
		vars->mapdata.zoom));
	y_offset = ft_itoa(vars->mapdata.y_offset - ((vars->matrix.max_y / 2) * \
		vars->mapdata.zoom));
	z_offset = ft_itoa(vars->mapdata.z_offset);
	mlx_string_put(vars->mlx, vars->win, 40, y * 4, 0xFFFFFF, "x_offset:");
	mlx_string_put(vars->mlx, vars->win, 160, y * 4, 0xFFFFFF, x_offset);
	mlx_string_put(vars->mlx, vars->win, 40, y * 5, 0xFFFFFF, "y_offset:");
	mlx_string_put(vars->mlx, vars->win, 160, y * 5, 0xFFFFFF, y_offset);
	mlx_string_put(vars->mlx, vars->win, 40, y * 6, 0xFFFFFF, "z_offset:");
	mlx_string_put(vars->mlx, vars->win, 160, y * 6, 0xFFFFFF, z_offset);
	free(x_offset);
	free(y_offset);
	free(z_offset);
}

/* -------------------------------------------------------------------------- */

void	print_zoom(int y, t_vars *vars)
{
	char	*zoom;

	zoom = ft_itoa(vars->mapdata.zoom);
	mlx_string_put(vars->mlx, vars->win, 40, y * 3, 0xFFFFFF, "Zoom:");
	mlx_string_put(vars->mlx, vars->win, 160, y * 3, 0xFFFFFF, zoom);
	free(zoom);
}

/* -------------------------------------------------------------------------- */