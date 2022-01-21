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

int	xclose(void *v_vars)
{
	t_vars	*vars;

	vars = (t_vars *)v_vars;
	exit(0);
}

/* -------------------------------------------------------------------------- */

void	handle_zoom_event(t_vars *vars, int key_code)
{
	if (key_code == KEY_PAD_ADD && vars->mapdata.zoom + 1 <= 50)
		vars->mapdata.zoom += 1;
	else if (key_code == KEY_PAD_SUB && vars->mapdata.zoom - 1 >= 1)
		vars->mapdata.zoom -= 1;
}

/* -------------------------------------------------------------------------- */

void	handle_z_offset_event(t_vars *vars, int key_code)
{
	if (key_code == KEY_PAGE_UP && vars->mapdata.z_offset + 1 <= 255)
		vars->mapdata.z_offset += 1;
	else if (key_code == KEY_PAGE_DOWN && vars->mapdata.z_offset - 1 >= -255)
		vars->mapdata.z_offset -= 1;
}

/* -------------------------------------------------------------------------- */

void	handle_iso_pro(t_vars *vars)
{
	if (vars->mapdata.iso_pro_bool)
		vars->mapdata.iso_pro_bool = FALSE;
	else
		vars->mapdata.iso_pro_bool = TRUE;
}

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
