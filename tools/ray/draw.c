/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:35:26 by ogonzale          #+#    #+#             */
/*   Updated: 2023/06/18 18:14:34 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_ray.h"
#include "cub3d_images.h"
#include "cub3d_errors.h"

void	draw_wall_and_background(t_game *game, int x)
{
	int	y;

	y = -1;
	game->wall.tex_x = (int)(game->wall.wall_x * (double)TEXWIDTH);
	if (game->ray.side == 0 && game->ray.dir_x > 0)
		game->wall.tex_x = TEXWIDTH - game->wall.tex_x - 1;
	if (game->ray.side == 1 && game->ray.dir_y < 0)
		game->wall.tex_x = TEXWIDTH - game->wall.tex_x - 1;
	while (++y < WINHEIGHT)
	{
		if (y < game->wall.draw_start)
			ft_mlx_put_pixels(game->mlx.data, x, y, game->map.ceiling_colour);
		else if (y >= game->wall.draw_start && y <= game->wall.draw_end)
		{
			game->wall.tex_y = (int)game->wall.tex_pos & (TEXHEIGHT - 1);
			game->wall.tex_pos += game->wall.tex_step;
			game->wall.color = game->imgs.north.tex_buffer[TEXHEIGHT
				* game->wall.tex_y + game->wall.tex_x];
			if (game->ray.side == 1)
				game->wall.color = (game->wall.color >> 1) & 8355711;
		}
		else
			ft_mlx_put_pixels(game->mlx.data, x, y, game->map.floor_colour);
		game->buffer.buffer[y][x] = game->wall.color;
		game->buffer.redo_buffer = TRUE;
	}
}

int	**build_buffer(t_game *game)
{
	int	**buffer;
	int	idx;

	if (game->buffer.redo_buffer == FALSE)
		return (NULL);
	idx = -1;
	buffer = (int **)ft_calloc(sizeof(char *), (WINHEIGHT + 1));
	if (!buffer)
		terminate_error(ERR_MEM, SYS_MEM);
	while (++idx < WINHEIGHT)
	{
		buffer[idx] = (int *)ft_calloc(sizeof(char), (WINWIDTH + 1));
		if (!buffer[idx])
			terminate_error(ERR_MEM, SYS_MEM);
	}
	game->buffer.redo_buffer = FALSE;
	return (buffer);
}

void	draw_buffer(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WINHEIGHT)
	{
		x = -1;
		while (++x < WINWIDTH)
			game->imgs.north.image.addr[y * game->imgs.north.image.width + x] = \
			game->buffer.buffer[y][x];
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
	game->imgs.north.image.img, 0, 0);
}
