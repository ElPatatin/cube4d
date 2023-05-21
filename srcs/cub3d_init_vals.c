/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init_vals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:16:15 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/21 10:34:05 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_errors.h"
#include "cub3d_parser.h"

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

void	init_map(t_game *game, char map[MAPHEIGHT][MAPWIDTH])
{
	int	i;

	game->map.width = MAPWIDTH;
	game->map.height = MAPHEIGHT;
	game->map.grid = malloc(sizeof(char *) * game->map.height);
	if (!game->map.grid)
		terminate_error(ERR_MEM, EXIT_FAILURE);
	i = -1;
	while (++i < game->map.height)
	{
		game->map.grid[i] = malloc(sizeof(char) * (game->map.width + 1));
		if (!game->map.grid[i])
			terminate_error(ERR_MEM, EXIT_FAILURE);
		ft_memcpy(game->map.grid[i], map[i], game->map.width);
		game->map.grid[i][game->map.width] = '\0';
	}
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
