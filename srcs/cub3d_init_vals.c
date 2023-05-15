/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init_vals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:16:15 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/14 18:53:07 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_errors.h"

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

void	init_player(t_game *game, char map[5][6])
{
	int	i;
	int	j;

	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	i = -1;
	while (++i < 5) //TODO: sub for width
	{
		j = -1;
		while (++j < 6) //TODO: sub for height
		{
			if (ft_strchr("NEOS", map[i][j]))
			{
				game->player.x = i;
				game->player.y = j;
				if (map[i][j] == 'N')
				{
					game->player.dir_x = 0;
					game->player.dir_y = 1;
				}
				else if (map[i][j] == 'E')
				{
					game->player.dir_x = 1;
					game->player.dir_y = 0;
				}
				else if (map[i][j] == 'O')
				{
					game->player.dir_x = -1;
					game->player.dir_y = 0;
				}
				else if (map[i][j] == 'S')
				{
					game->player.dir_x = 0;
					game->player.dir_y = -1;
				}
			}
		}
	}
}
