/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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
void	print_matrix(t_matrix *matrix)
{
	int	y;
	int	x;

	y = 0;
	while (y < matrix->max_y)
	{
		x = 0;
		while (x < matrix->max_x)
		{
			printf("%d-%X\t", matrix->matrix_ptr[y][x][0], \
				matrix->matrix_ptr[y][x][1]);
			x++;
		}
		putchar('\n');
		y++;
	}
}
*/
/* -------------------------------------------------------------------------- */
/*
int	trgb_to_int(t_uchar t, t_uchar r, t_uchar g, t_uchar b)
{
	int	output;

	output = 0;
	output |= t;
	output <<= 8;
	output |= r;
	output <<= 8;
	output |= g;
	output <<= 8;
	output |= b;
	return (output);
}
*/
/* -------------------------------------------------------------------------- */

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (handle_err(6), 1);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (handle_err(7), 1);
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (!vars.win)
		return (handle_err(8), 1);
	vars.img.img_ptr = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img_ptr, \
		&vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	alloc_store_matrix(argv[1], &vars);
	printf("Image loading ...\n\n");
	draw_map(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}

/* -------------------------------------------------------------------------- */