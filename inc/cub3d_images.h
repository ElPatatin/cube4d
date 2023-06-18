/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_images.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:32:21 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/18 17:41:57 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_IMAGES_H
# define CUB3D_IMAGES_H

# define TEXWIDTH 64
# define TEXHEIGHT 64

# include "cub3d_data.h"

typedef struct s_buffer			t_buffer;
typedef struct s_img_data		t_img_data;
typedef struct s_texture		t_texture;
typedef struct s_img_handler	t_img_handler;
typedef struct s_imgs			t_imgs;

struct s_buffer
{
	int		**buffer;
	t_bool	redo_buffer;
};

struct s_img_data
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
};

struct s_texture
{
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
};

struct s_img_handler
{
	t_img_data	image;
	t_texture	texture;
	int			*tex_buffer;
};

struct s_imgs
{
	t_img_handler	north;
	t_img_handler	south;
	t_img_handler	east;
	t_img_handler	west;
};

// struct s_sprite
// {
// 	double	sprite_x;
// 	double	sprite_y;
// 	double	inv_det;
// 	double	transform_x;
// 	double	transform_y;
// 	int		sprite_screen_x;
// 	int		sprite_height;
// 	int		sprite_width;
// 	int		draw_start_x;
// 	int		draw_start_y;
// 	int		draw_end_x;
// 	int		draw_end_y;
// 	int		tex_x;
// 	int		tex_y;
// 	int		d;
// };

#endif