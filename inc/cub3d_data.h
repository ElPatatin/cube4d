/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:54:19 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/06 17:52:14 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DATA_H
# define CUB3D_DATA_H

# include <stddef.h>

# define WINHEIGHT	(int)1080
# define WINWIDTH	(int)1920
# define TITLE		(char *)"cub3d gatito miau miau"

typedef struct s_mlx	t_mlx;
typedef struct s_data	t_data;
typedef struct s_map	t_map;

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

#endif