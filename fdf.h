/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 14:22:04 by mnaimi            #+#    #+#             */
/*   Updated: 2022/01/02 14:22:07 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* -------------------------------- Libraries ------------------------------- */
# include "./assets/libft/libft.h"
# include "./assets/get_next_line/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

/* --------------------------------- Macros --------------------------------- */
# define TRUE 1
# define FALSE 0
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

/* -------------------------------- Typedefs -------------------------------- */
typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

/* -------------------------------- Structs --------------------------------- */

typedef struct s_linedraw
{
	int	sx;
	int	sy;
	int	dlta_x;
	int	dlta_y;
	int	err;
	int	e2;
	int	x0;
	int	x0_bckp;
	int	y0;
	int	y0_bckp;
	int	cl0;
	int	z0;
	int	x1;
	int	y1;
	int	z1;
	int	cl1;
}	t_linedraw;

typedef struct s_mapdata
{
	int	zoom;
	int	x_offset;
	int	y_offset;
	int	z_offset;
}	t_mapdata;

typedef struct s_mapfile
{
	int		fd;
	char	*line;
	char	**spltd_line;
}	t_mapfile;

typedef struct s_matrix
{
	int	max_x;
	int	max_y;
	int	***matrix_ptr;
}	t_matrix;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_loop
{
	int	x;
	int	y;
}	t_loop;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	t_img			img;
	int				map_line_len;
	t_matrix		matrix;
	t_mapfile		mapfile;
	t_mapdata		mapdata;
	t_linedraw		linedraw;
	t_loop			loop;
}	t_vars;

/* ------------------------------- Prototypes ------------------------------- */

void	alloc_store_matrix(char *map, t_vars *vars);
void	store_pxl_data(char *map, t_vars *vars);
void	handle_err(int err_code);
int		linear_color(t_vars	*vars);
void	iter_x(t_vars *vars);
void	drawline_calcul(t_vars *vars);
void	draw_map(t_vars	*vars);

#endif
