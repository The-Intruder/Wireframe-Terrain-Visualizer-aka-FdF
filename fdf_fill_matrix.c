/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fill_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:46:53 by mnaimi            #+#    #+#             */
/*   Updated: 2022/01/08 20:46:54 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* -------------------------------------------------------------------------- */

static int	ft_hextoi(char *ptr)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	if (ptr[i] == '0' && ft_tolower(ptr[i + 1]) == 'x')
	{
		i += 2;
		while (ft_isdigit(ptr[i]) || ((ptr[i] >= 'a' && ptr[i] <= 'f')
				|| (ptr[i] >= 'A' && ptr[i] <= 'F')))
		{
			if (ft_isdigit(ptr[i]))
				result = (result * 16) + (ptr[i++] - '0');
			if (((ptr[i] >= 'a' && ptr[i] <= 'f') || (ptr[i] >= 'A'
						&& ptr[i] <= 'F')))
			{
				if (ft_tolower(ptr[i]) >= 'a' && ft_tolower(ptr[i]) <= 'f')
					result = (result * 16) + (ft_tolower(ptr[i++]) - 87);
			}
		}
		return (result);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

static void	free_splt_str(char **splt_str)
{
	int	i;

	i = 0;
	while (splt_str[i])
		free(splt_str[i++]);
	free(splt_str);
}

/* -------------------------------------------------------------------------- */

static void	store_z_cl(t_vars *vars, char **splt_line, int x, int y)
{
	char	**z_cl;

	if (ft_strchr(splt_line[x], ','))
	{
		z_cl = ft_split(splt_line[x], ',');
		vars->matrix.matrix_ptr[y][x][0] = ft_atoi(z_cl[0]);
		vars->matrix.matrix_ptr[y][x][1] = ft_hextoi(z_cl[1]);
		free_splt_str(z_cl);
	}
	else
	{
		vars->matrix.matrix_ptr[y][x][0] = ft_atoi(splt_line[x]);
		// vars->matrix.matrix_ptr[y][x][1] = 0x00FFFFFF;
		vars->matrix.matrix_ptr[y][x][1] = (0xD9534F + (vars->matrix.matrix_ptr[y][x][0] * 10));
		printf("\n1.%X\n", vars->matrix.matrix_ptr[y][x][1]);
		vars->matrix.matrix_ptr[y][x][1] <<= 8;
		printf("2.%X\n", vars->matrix.matrix_ptr[y][x][1]);
		vars->matrix.matrix_ptr[y][x][1] >>= 8;
		printf("3.%X\n\n", vars->matrix.matrix_ptr[y][x][1]);
	}
}

/* -------------------------------------------------------------------------- */

static void	iter_matr(t_vars *vars)
{
	char	**splt_line;
	int		x;
	int		y;

	y = 0;
	while (y < vars->matrix.max_y && vars->mapfile.line)
	{
		x = 0;
		splt_line = ft_split(vars->mapfile.line, ' ');
		while (x < vars->matrix.max_x && splt_line[x] && *splt_line[x] != '\n')
			store_z_cl(vars, splt_line, x++, y);
		free_splt_str(splt_line);
		free(vars->mapfile.line);
		vars->mapfile.line = get_next_line(vars->mapfile.fd, \
			vars->map_line_len);
		y++;
	}
	free(vars->mapfile.line);
	close(vars->mapfile.fd);
}

/* -------------------------------------------------------------------------- */

void	store_pxl_data(char *map, t_vars *vars)
{
	vars->mapfile.fd = open(map, O_RDONLY);
	if (vars->mapfile.fd < 0)
		return (handle_err(5));
	vars->mapfile.line = get_next_line(vars->mapfile.fd, vars->map_line_len);
	iter_matr(vars);
}

/* -------------------------------------------------------------------------- */
