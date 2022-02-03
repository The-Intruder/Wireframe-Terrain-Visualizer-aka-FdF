#include "fdf.h"

void	draw_bg(t_vars *vars, int width, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WIN_HEIGHT)
	{
		j = 0;
		while (j <= width)
			img_pixel_put(vars, j++, i, color);
		++i;
	}
}

void	write_legend(t_vars *vars)
{
	int	y;

	y = 30;
	mlx_string_put(vars->mlx, vars->win, 20, y * 1 - 15, 0xFFFFFF, "Status:");
	mlx_string_put(vars->mlx, vars->win, 20, y * 1, 0xFFFFFF, "~~~~~~~");
	mlx_string_put(vars->mlx, vars->win, 40, y * 2, 0xFFFFFF, "Projection:");
	if (vars->mapdata.iso_pro_bool)
		mlx_string_put(vars->mlx, vars->win, 160, y * 2, 0xFFFFFF, "Isometric");
	else
		mlx_string_put(vars->mlx, vars->win, 160, y * 2, 0xFFFFFF, "Parallel");
	mlx_string_put(vars->mlx, vars->win, 40, y * 3, 0xFFFFFF, "Zoom:");
	mlx_string_put(vars->mlx, vars->win, 160, y * 3, 0xFFFFFF, ft_itoa(vars->mapdata.zoom));
	mlx_string_put(vars->mlx, vars->win, 40, y * 4, 0xFFFFFF, "x_offset:");
	mlx_string_put(vars->mlx, vars->win, 160, y * 4, 0xFFFFFF, ft_itoa(vars->mapdata.x_offset - ((vars->matrix.max_x / 2) * vars->mapdata.zoom)));
	mlx_string_put(vars->mlx, vars->win, 40, y * 5, 0xFFFFFF, "y_offset:");
	mlx_string_put(vars->mlx, vars->win, 160, y * 5, 0xFFFFFF, ft_itoa(vars->mapdata.y_offset - ((vars->matrix.max_y / 2) * vars->mapdata.zoom)));
	mlx_string_put(vars->mlx, vars->win, 40, y * 6, 0xFFFFFF, "z_offset:");
	mlx_string_put(vars->mlx, vars->win, 160, y * 6, 0xFFFFFF, ft_itoa(vars->mapdata.z_offset));
	mlx_string_put(vars->mlx, vars->win, 40, y * 7, 0xFFFFFF, "alpha:");
	mlx_string_put(vars->mlx, vars->win, 160, y * 7, 0xFFFFFF, ft_itoa(ceil(vars->mapdata.alpha_x * (180 / M_PI))));
	mlx_string_put(vars->mlx, vars->win, 40, y * 8, 0xFFFFFF, "beta:");
	mlx_string_put(vars->mlx, vars->win, 160, y * 8, 0xFFFFFF, ft_itoa(ceil(vars->mapdata.alpha_y * (180 / M_PI))));
	mlx_string_put(vars->mlx, vars->win, 40, y * 9, 0xFFFFFF, "gamma:");
	mlx_string_put(vars->mlx, vars->win, 160, y * 9, 0xFFFFFF, ft_itoa(ceil(vars->mapdata.alpha_z * (180 / M_PI))));
	mlx_string_put(vars->mlx, vars->win, 20, y * 12 - 15, 0xFFFFFF, "Controls:");
	mlx_string_put(vars->mlx, vars->win, 20, y * 12, 0xFFFFFF, "~~~~~~~~~");
}