/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init_vals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:16:15 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/05 18:46:49 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_hooks.h"
#include "cub3d_errors.h"

static void	init_player_dir(t_game *game, int i, int j);
static void	init_player_plane(t_game *game, int i, int j);

void	init_vals(t_mlx *vals, t_data *data)
{
	vals->ptr = mlx_init();
	if (!vals->ptr)
		terminate_error(ERR_WIN, SYS_WIN);
	vals->win = mlx_new_window(vals->ptr,
			WINWIDTH, WINHEIGHT, TITLE);
	data->img = mlx_new_image(vals->ptr, WINWIDTH, WINHEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	vals->data = data;
}

void	init_map(t_map *map, size_t map_len)
{
	map->map = NULL;
	map->length = map_len;
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->s_path = NULL;
	map->floor_colour = 0;
	map->ceiling_colour = 0;
	map->grid = NULL;
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (ft_strchr("NEWS", game->map.grid[i][j]))
			{
				game->player.x = i;
				game->player.y = j;
				init_player_dir(game, i, j);
				init_player_plane(game, i, j);
			}
		}
	}
	game->player.move_up = 0;
	game->player.move_down = 0;
	game->player.move_left = 0;
	game->player.move_right = 0;
	game->player.rotate_left = 0;
	game->player.rotate_right = 0;
}

static void	init_player_dir(t_game *game, int i, int j)
{
	if (game->map.grid[i][j] == P_NO)
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (game->map.grid[i][j] == P_EA)
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (game->map.grid[i][j] == P_WE)
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (game->map.grid[i][j] == P_SO)
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
}

static void	init_player_plane(t_game *game, int i, int j)
{
	if (game->map.grid[i][j] == P_NO)
	{
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (game->map.grid[i][j] == P_EA)
	{
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (game->map.grid[i][j] == P_WE)
	{
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	else if (game->map.grid[i][j] == P_SO)
	{
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}
