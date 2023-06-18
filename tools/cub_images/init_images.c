/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:18:07 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/18 18:21:05 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_images.h"
#include "cub3d_errors.h"

void	init_imgs(t_game *game)
{
	t_imgs	imgs;

	imgs.north.image = init_img_data(game);
	game->imgs = imgs;
}

t_img_data	init_img_data(t_game *game)
{
	t_img_data	img_data;

	img_data.img = mlx_xpm_file_to_image(game->mlx.ptr, game->map.no_path,
			&img_data.width, &img_data.height);
	if (!img_data.img)
		terminate_error(ERR_IMG, SYS_IMG);
	img_data.addr = (int *)mlx_get_data_addr(img_data.img, &img_data.bpp,
			&img_data.line_len, &img_data.endian);
	if (!img_data.addr)
		terminate_error(ERR_IMG, SYS_IMG);
	game->imgs.north.tex_buffer = load_img(&img_data);
	mlx_destroy_image(game->mlx.ptr, img_data.img);
	return (img_data);
}

int	*load_img(t_img_data *img_data)
{
	int	*img;
	int	x;
	int	y;

	img = (int *)ft_calloc(sizeof(int), (img_data->width * img_data->height));
	if (!img)
		terminate_error(ERR_MEM, SYS_MEM);
	y = -1;
	while (++y < img_data->height)
	{
		x = -1;
		while (++x < img_data->width)
		{
			img[y * img_data->width + x] = \
			img_data->addr[y * img_data->width + x];
		}
	}
	return (img);
}
