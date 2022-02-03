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

void	print_colored_error(char *message, char *color)
{
	write(2, color, ft_strlen(color));
	write(2, message, ft_strlen(message));
	write(2, NC, 7);
}

/* -------------------------------------------------------------------------- */

void	handle_err(int err_code)
{
	print_colored_error("\nerror: ", RED);
	if (err_code == 1)
		print_colored_error("Empty file\n", BLD);
	else if (err_code == 2)
		print_colored_error("y_axis allocation failure\n", BLD);
	else if (err_code == 3)
		print_colored_error("x_axis allocation failure\n", BLD);
	else if (err_code == 4)
		print_colored_error("z & cl allocation failure\n", BLD);
	else if (err_code == 5)
		print_colored_error("No such File\n", BLD);
	else if (err_code == 6)
		print_colored_error("Invalid argc\n", BLD);
	else if (err_code == 7)
		print_colored_error("mlx_ptr allocation failure\n", BLD);
	else if (err_code == 8)
		print_colored_error("win_ptr allocation failure\n", BLD);
	ft_putchar_fd('\n', 2);
	exit(err_code);
}
