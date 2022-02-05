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

#include "fdf_bonus.h"

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