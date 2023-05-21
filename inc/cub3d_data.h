/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:54:19 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/21 10:58:59 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DATA_H
# define CUB3D_DATA_H

# include <stddef.h>

# define WINHEIGHT	(int)1080
# define WINWIDTH	(int)1920
# define TITLE		(char *)"cub3d gatito miau miau"

# define MAPHEIGHT	12
# define MAPWIDTH	24

typedef struct s_mlx	t_mlx;
typedef struct s_data	t_data;
typedef struct s_map	t_map;
typedef struct s_player	t_player;
typedef struct s_ray	t_ray;
typedef struct s_wall	t_wall;
typedef struct s_game	t_game;

struct s_player {
	float	x;
	float	y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
};

struct s_ray
{
	float	dir_x;
	float	dir_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	side_dist_x;
	float	side_dist_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	float	distance;
	int		hit;
	int		side;
};

struct s_wall
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
};

struct s_map {
	int		width;
	int		height;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*s_path;
	int		f_color;
	int		c_color;
	char	**grid;
};

struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
};

struct s_mlx
{
	void	*ptr;
	void	*win;
	t_data	*data;
	t_map	*map;
};

struct s_game
{
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_wall		wall;
	double		time;
	double		old_time;
};

#endif