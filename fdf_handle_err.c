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
	if (err_code == 0)
		print_colored_error("\n... Quitting Program Successfully\n\n", GRN);
	else
	{
		print_colored_error("\n=> ERROR:\n\n", RED);
		if (err_code == 1)
			print_colored_error("Empty file\n\n", BLD);
		else if (err_code == 2)
			print_colored_error("Y_AXIS allocation failure\n\n", BLD);
		else if (err_code == 3)
			print_colored_error("X_AXIX allocation failure\n\n", BLD);
		else if (err_code == 4)
			print_colored_error("Z & Color allocation failure\n\n", BLD);
		else if (err_code == 5)
			print_colored_error("File not found\n\n", BLD);
		else if (err_code == 6)
			print_colored_error("Invalid argument count\n\n", BLD);
		else if (err_code == 7)
			print_colored_error("MLX_PTR allocation failure\n\n", BLD);
		else if (err_code == 8)
			print_colored_error("WIN_PTR allocation failure\n\n", BLD);
		else if (err_code == 9)
			print_colored_error("Incorrect argument\n\n", BLD);
		else if (err_code == 10)
			print_colored_error("Invalid map\n\n", BLD);
	}
	ft_putchar_fd('\n', 2);
	// sleep(30);
	exit(err_code);
}
