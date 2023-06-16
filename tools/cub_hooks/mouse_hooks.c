/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:43:51 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/16 18:01:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_hooks.h"
#include "cub3d_errors.h"

int	mouse_close_onclick(t_mlx *vals)
{
	mlx_destroy_window(vals->ptr, vals->win);
	exit(EXIT_SUCCESS);
}

int	mouse_camera_handler(int x, int y, t_game *game)
{
	int		delta_x;

	UNUSED(y);
	game->player.mouse_pos = x - (WINWIDTH / 2);
	delta_x = game->player.mouse_pos - game->player.mouse_last_pos;
	if (delta_x > 0)
	{
		game->player.rotate_left = 0;
		game->player.rotate_right = 1;
	}
	else if (delta_x < 0)
	{
		game->player.rotate_right = 0;
		game->player.rotate_left = 1;
	}
	else
	{
		game->player.rotate_right = 0;
		game->player.rotate_left = 0;
	}
	game->player.mouse_last_pos = game->player.mouse_pos;
	return (0);
}
