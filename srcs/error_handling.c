/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handle_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:59:19 by mnaimi            #+#    #+#             */
/*   Updated: 2022/01/15 16:59:21 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* -------------------------------------------------------------------------- */

static void	print_colored_error(int err_code, char *message, char *color)
{
	char	*ascii_err_code;

	write(2, color, ft_strlen(color));
	if (err_code != -1)
	{
		ascii_err_code = ft_itoa(err_code);
		write(2, "(code ", 6);
		write(2, ascii_err_code, ft_strlen(ascii_err_code));
		write(2, ") ", 2);
		free(ascii_err_code);
	}
	write(2, message, ft_strlen(message));
	write(2, NC, 7);
}

/* -------------------------------------------------------------------------- */

static void	check_err_num(int err_code)
{
	print_colored_error(-1, "\n=> ERROR:  ", RED);
	if (err_code == 1)
		print_colored_error(err_code, "Empty file\n\n", BLD);
	else if (err_code == 2)
		print_colored_error(err_code, "Y_AXIS allocation failure\n\n", BLD);
	else if (err_code == 3)
		print_colored_error(err_code, "X_AXIX allocation failure\n\n", BLD);
	else if (err_code == 4)
		print_colored_error(err_code, "Z & Color allocation failure\n\n", BLD);
	else if (err_code == 5)
		print_colored_error(err_code, "File not found\n\n", BLD);
	else if (err_code == 6)
		print_colored_error(err_code, "Invalid argument count\n\n", BLD);
	else if (err_code == 7)
		print_colored_error(err_code, "MLX_PTR allocation failure\n\n", BLD);
	else if (err_code == 8)
		print_colored_error(err_code, "WIN_PTR allocation failure\n\n", BLD);
	else if (err_code == 9)
		print_colored_error(err_code, "Incorrect argument\n\n", BLD);
	else if (err_code == 10)
		print_colored_error(err_code, "Invalid map\n\n", BLD);
	else if (err_code == 11)
		print_colored_error(err_code, "Undefined Error\n\n", BLD);
}

/* -------------------------------------------------------------------------- */

void	handle_err(t_vars *vars, int err_code)
{
	if (err_code == 0)
		print_colored_error(-1, "\n... Quitting Program Successfully\n\n", GRN);
	else
		check_err_num(err_code);
	ft_putchar_fd('\n', 2);
	if (vars->matrix.matrix_ptr != NULL)
		deallocate_data(&vars->matrix);
	mlx_destroy_image(vars->mlx, vars->img.img_ptr);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(err_code);
}

/* -------------------------------------------------------------------------- */
