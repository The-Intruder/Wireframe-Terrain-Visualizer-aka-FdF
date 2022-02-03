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
# define TRUE			1
# define FALSE			0

# define WIN_WIDTH		1920
# define WIN_HEIGHT		1080

# define NOEVENTMASK	0L
# define KEYPRESS		2

# define KEY_ESCAPE		53
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_LEFT		123
# define KEY_C			8
# define KEY_R			15
# define KEY_P			35
# define KEY_X			7
# define KEY_Y			16
# define KEY_Z			6
# define KEY_PAD_SUB	78
# define KEY_PAD_ADD	69
# define KEY_PAGE_UP	116
# define KEY_PAGE_DOWN	121

# define BLD "\033[1m"
# define NC "\033[31;0m"
# define RED "\033[0;31;1m"
# define YEL "\033[0;33;1m"
# define GRA "\033[0;37;1m"
# define CYN "\033[0;36;1m"
# define GRN "\033[0;32;1m"
# define MGN "\033[0;35;1m"
# define BLU "\033[0;34;1m"

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
	int	org_x0;
	int	org_y0;
	int	x0;
	int	y0;
	int	cl0;
	int	z0;
	int	x1;
	int	y1;
	int	z1;
	int	cl1;
	int	cl;
}	t_linedraw;

typedef struct s_mapdata
{
	int		zoom;
	int		x_offset;
	int		y_offset;
	int		z_offset;
	int		cl_offset;
	int		iso_pro_bool;
	double	alpha_x;
	double	alpha_y;
	double	alpha_z;	
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
	int				map_line_len;
	t_img			img;
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
void	iter_x(t_vars *vars);
void	drawline_calcul(t_vars *vars);
void	draw_map(t_vars	*vars);
void	reset_window(t_vars *vars);
void	set_default_params(t_vars *vars);
int		xclose(void *v_vars);
int		handle_event(int key_press, t_vars *vars);
void	handle_x_rotation(t_vars *vars);
void	handle_y_rotation(t_vars *vars);
void	handle_z_rotation(t_vars *vars);
int		rotate_map(t_vars *vars, int key_code);
void	handle_zoom_event(t_vars *vars, int key_code);
void	handle_z_offset_event(t_vars *vars, int key_code);
void	handle_iso_pro(t_vars *vars);
int		trgb_to_int(int r, int g, int b);
void	img_pixel_put(t_vars *vars, int x, int y, int color);
void	draw_bg(t_vars *vars, int width, int color);
void	write_legend(t_vars *vars);

void	deallocate_data(t_matrix *matrix);

/* print_legend_1st.c */
void	print_projection(int y, t_vars *vars);
void	set_deg(int deg, char **ascii_deg);
void	print_rotation_data(int y, t_vars *vars);
void	print_xyz_offset(int y, t_vars *vars);
void	print_zoom(int y, t_vars *vars);

/* print_legend_2nd.c */
void	draw_bg(t_vars *vars, int width, int color);
void	print_status( int y, t_vars *vars);
void	print_directions(int y, t_vars *vars);
void	print_misc_controls(int y, t_vars *vars);
void	write_legend(t_vars *vars);

#endif
