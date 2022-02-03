/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_alloc_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:36:21 by mnaimi            #+#    #+#             */
/*   Updated: 2022/01/08 20:36:22 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* -------------------------------------------------------------------------- */

void	deallocate_data(t_matrix *matrix)
{
	int	y;
	int	x;

	y = 0;
	while (y < matrix->max_y)
	{
		x = 0;
		if (matrix->matrix_ptr[y])
		{
			while (x < matrix->max_x)
			{
				if (matrix->matrix_ptr[y][x])
					free(matrix->matrix_ptr[y][x]);
				x++;
			}
			free(matrix->matrix_ptr[y]);
		}
		y++;
	}
}

/* -------------------------------------------------------------------------- */

static int	count_rows(char *map, int *line_length)
{
	int		row_count;
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (handle_err(5), 0);
	row_count = 0;
	line = get_next_line(fd, 1);
	if (!line)
		return (0);
	*line_length = ft_strlen(line);
	while (line)
	{
		++row_count;
		free(line);
		line = get_next_line(fd, *line_length);
	}
	close(fd);
	free(line);
	line = get_next_line(-1, -1);
	return (row_count);
}

/* -------------------------------------------------------------------------- */

static int	count_cols(char *map)
{
	int		col_count;
	char	*line;
	char	**dummy_ptr;
	char	**spltd_line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	col_count = 0;
	line = get_next_line(fd, 1);
	if (!line)
		return (0);
	spltd_line = ft_split(line, ' ');
	dummy_ptr = spltd_line;
	free(line);
	while (*spltd_line && *(spltd_line)[0] != '\n')
	{
		++col_count;
		free(*(spltd_line++));
	}
	return (close(fd), free(dummy_ptr), col_count);
}

/* -------------------------------------------------------------------------- */

static void	alloc_z_clr(t_matrix *matrix)
{
	int			y;
	int			x;

	y = 0;
	while (y < matrix->max_y)
	{
		x = 0;
		while (x < matrix->max_x)
		{
			matrix->matrix_ptr[y][x] = (int *)ft_calloc(2, sizeof(int));
			if (!matrix->matrix_ptr[y][x])
				return (handle_err(4), deallocate_data(matrix));
			x++;
		}
		y++;
	}
}

/* -------------------------------------------------------------------------- */

void	alloc_store_matrix(char *map, t_vars *vars)
{
	int	i;

	vars->matrix.max_y = count_rows(map, &(vars->map_line_len));
	vars->matrix.max_x = count_cols(map);
	if (!vars->matrix.max_y || !vars->matrix.max_x)
		return (handle_err(1));
	vars->matrix.matrix_ptr = (int ***)ft_calloc(vars->matrix.max_y, \
		sizeof(int **));
	if (!vars->matrix.matrix_ptr)
		return (handle_err(2));
	i = 0;
	while (i < vars->matrix.max_y)
	{
		vars->matrix.matrix_ptr[i] = (int **)ft_calloc(vars->matrix.max_x, \
			sizeof(int *));
		if (!vars->matrix.matrix_ptr[i++])
			return (deallocate_data(&(vars->matrix)), handle_err(3));
	}
	alloc_z_clr(&(vars->matrix));
	store_pxl_data(map, vars);
}

/* -------------------------------------------------------------------------- */
