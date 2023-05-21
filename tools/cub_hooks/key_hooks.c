/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:43:37 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/21 12:29:06 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_hooks.h"
#include "cub3d_errors.h"
#include "cub3d_player.h"

static int	key_move(int keycode, t_game *game);

int	handle_keys(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window((&game->mlx)->ptr, (&game->mlx)->win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == W_KEY || keycode == S_KEY || keycode == A_KEY || keycode == D_KEY || keycode == LFT_KEY || keycode == RGT_KEY)
		key_move(keycode, game);
	return (1);
}

int	key_print_hook(int keycode, t_mlx *vals)
{
	UNUSED(vals);
	if (keycode == ESC_KEY)
		return (1);
	return (0);
}

static int	key_move(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		move_forward(game);
	else if (keycode == S_KEY)
		move_backward(game);
	else if (keycode == A_KEY)
		move_left(game);
	else if (keycode == D_KEY)
		move_right(game);
	else if (keycode == LFT_KEY)
		rotate_left(game);
	else if (keycode == RGT_KEY)
		rotate_right(game);
	return (1);
}

