/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handle_translation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:58:44 by mnaimi            #+#    #+#             */
/*   Updated: 2022/01/17 13:58:54 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* -------------------------------------------------------------------------- */

void	handle_zoom_event(t_vars *vars, int key_code)
{
	if (key_code == KEY_PAD_ADD && vars->mapdata.zoom + 1 <= 2147483647)
		vars->mapdata.zoom += 1;
	else if (key_code == KEY_PAD_SUB && vars->mapdata.zoom - 1 >= 1)
		vars->mapdata.zoom -= 1;
}

/* -------------------------------------------------------------------------- */

void	handle_z_offset_event(t_vars *vars, int key_code)
{
	if (key_code == KEY_PAGE_UP && vars->mapdata.z_offset + 1 <= 2147483647)
		vars->mapdata.z_offset += 1;
	else if (key_code == KEY_PAGE_DOWN \
		&& vars->mapdata.z_offset - 1 >= -2147483648)
		vars->mapdata.z_offset -= 1;
}

/* -------------------------------------------------------------------------- */

void	handle_xy_offset(t_vars *vars, int key_code)
{
	if (!vars->is_main)
	{
		if (key_code == KEY_LEFT)
			vars->mapdata.x_offset -= 2 * vars->mapdata.zoom;
		else if (key_code == KEY_RIGHT)
			vars->mapdata.x_offset += 2 * vars->mapdata.zoom;
		else if (key_code == KEY_DOWN)
			vars->mapdata.y_offset += 2 * vars->mapdata.zoom;
		else if (key_code == KEY_UP)
			vars->mapdata.y_offset -= 2 * vars->mapdata.zoom;
	}
}

/* -------------------------------------------------------------------------- */
/* --- Function below has it role in matrix_initialization.c -----------------*/

int	check_cols(char **spltd_line)
{
	int	i;

	i = 0;
	while (spltd_line[i] && *spltd_line[i] != '\n')
		i++;
	return (i);
}

/* -------------------------------------------------------------------------- */